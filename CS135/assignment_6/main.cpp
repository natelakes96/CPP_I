/*
 * Name:Nathaniel Stone, 8000617279, CS 135, assignment6
 * Description: this program will help the airport find the shortest
 *              distance flight, the longest distance flight, and
 *              total flights, and other metrics
 * Input: input csv file name
 * Output: csv file with metrics requested by airport
 */
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    // declaring file stream vars
    ifstream iFile;
    ofstream oFile;

    // initialize input file name
    string inputFile = "(:";

    do
    {
        // prompt for input file
        cout << "Enter a file name: ";
        cin >> inputFile;
        // checks if file is open
        iFile.open(inputFile);
        if (!iFile.is_open())
        {
            cout << "Error: Invalid filename\n"
                 << endl;
        }

    } while (!iFile.is_open());

    // initalize parallel arrays and counter
    const int arraySize = 50;
    string flightNums[arraySize] = {":)"},
           airlines[arraySize] = {":)"},
           holder1 = ":)";
    int distances[arraySize] = {}, counter = 0;

    // skips headers
    string headers = ":)";
    getline(iFile, headers);

    // extracts info into arrays
    while (getline(iFile, holder1))
    {
        // extracts flight numb
        int loc = holder1.find(',');
        string flightnumber = holder1.substr(0, loc);
        flightNums[counter] = flightnumber;
        holder1 = holder1.substr(loc + 1, holder1.size());

        // extracts airline
        loc = holder1.find(',');
        string airline = holder1.substr(0, loc);
        airlines[counter] = airline;
        holder1 = holder1.substr(loc + 1, holder1.size());

        // extracts distance
        int distance = stoi(holder1);
        distances[counter++] = distance;
    }

    // closes iFile
    iFile.close();

    // sorting based on distance
    for (int i = 0; i < counter - 1; i++)
    {
        for (int j = 0; j < counter - i - 1; j++)
        {
            if (distances[j] > distances[j + 1])
            {
                // swap distances
                int temp = distances[j];
                distances[j] = distances[j + 1];
                distances[j + 1] = temp;
                // swap airlines
                string s_temp = airlines[j];
                airlines[j] = airlines[j + 1];
                airlines[j + 1] = s_temp;
                // swap flight numbers
                s_temp = flightNums[j];
                flightNums[j] = flightNums[j + 1];
                flightNums[j + 1] = s_temp;
            }
        }
    }

    // put the three arrays into a new sorted csv
    oFile.open("sortedFlights.csv");

    // read in headers
    oFile << headers << endl;

    // read in sorted flights
    for (int i = 0; i < counter; i++)
    {
        oFile << flightNums[i] << ',' << airlines[i] << ','
              << distances[i] << endl;
    }

    // closes sorted flights file
    oFile.close();

    // find minimum and maximum flight
    int pcmin = 50000, pcmax = 0, minIdx = 0, maxIdx = 0;
    for (int i = 0; i < counter; i++)
    {
        // tests if min
        if (pcmin < distances[i])
        {
            minIdx = i;
        }
        // tests if max
        if (distances[i] > pcmax)
        {
            maxIdx = i;
        }
    }

    // adds up the distances
    int totalDistance = 0;
    for (int i = 0; i < counter; i++)
    {
        totalDistance = totalDistance + distances[i];
    }
    // calculates the average
    int average = 0;
    if (counter > 0)
    {
        average = totalDistance / counter;
    }
    // opens stats file
    oFile.open("statistics.txt");

    // reads in information

    // min
    oFile << "MINIMUM\n"
          << "Flight Number: " << flightNums[minIdx] << endl
          << "Airline: " << airlines[minIdx] << endl
          << "Distance: " << distances[minIdx] << endl
          << endl
          // max
          << "MAXIMUM\n"
          << "Flight Number: " << flightNums[maxIdx] << endl
          << "Airline: " << airlines[maxIdx] << endl
          << "Distance: " << distances[maxIdx] << endl
          << endl
          // summary
          << "Total Flights: " << counter << endl
          << "Sum of Distances: " << totalDistance << endl
          << "Average Distance: " << average;

    // closes file
    oFile.close();
}