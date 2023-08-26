/*
 * Name:Nathaniel Stone, 8000617279, CS 135, assignment7
 * Description: This program takes in a name of a file
 *              that has names of shapes and side lengths
 *              then will calculate area and return two txt
 *              files.
 * Input: input txt file name
 * Output: txt file with metrics
 */
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

// initalizes all of the functions that will be used
void openFile(ifstream &);
void readFile(ifstream &, string[], double[], int &, int);
void calculateArea(string[], double[], double[], int);
int minIndex(double[], int);
int maxIndex(double[], int);
void writeAreasToFile(ofstream &, string[], double[], double[],
                      int);
void writeStatsToFile(ofstream &, string[], double[], double[],
                      int, int, int);

int main()
{
    // opens ifile and ofile
    ifstream iFile;
    ofstream oFile;

    // opens a file
    openFile(iFile);

    // initalizes arrays
    const int maxArraysize = 100;
    int counter = 0;
    string shapes[maxArraysize] = {":)"};
    double sideLength[maxArraysize] = {0.0};

    // reads file into arrays that are above
    readFile(iFile, shapes, sideLength, counter, maxArraysize);

    // creates a 3rd array
    double areas[maxArraysize] = {0.0};

    // calculates areas and assigns them to array
    calculateArea(shapes, sideLength, areas, counter);

    // find the min index loc
    int minIdx = minIndex(areas, counter);

    // find max index loc
    int maxIdx = maxIndex(areas, counter);

    // writes stats to file
    writeStatsToFile(oFile, shapes, sideLength, areas, minIdx,
                     maxIdx, counter);

    // writes areas to file
    writeAreasToFile(oFile, shapes, sideLength, areas, counter);

    // cout << counter << endl;

    return 0;
}

void openFile(ifstream &iFile)
{
    // initalize input file string
    string inputFile = ":)";

    // loop to until file is open
    do
    {
        // prompt for input file
        cout << "Enter a file name: ";
        getline(cin, inputFile);
        // checks if file is open
        iFile.open(inputFile);
        if (!iFile.is_open())
        {
            cout << "Error: Invalid filename\n"
                 << endl;
        }

    } while (!iFile.is_open());
}

void readFile(ifstream &iFile, string shapes[], double sideLength[],
              int &counter, const int maxArraySize)
{
    // loops through file
    for (int i = 0; i < maxArraySize; i++)
    {
        // reads in weight and units
        iFile >> shapes[counter] >> sideLength[counter];
        // checks for extra line
        if (iFile.fail())
        {
            if (iFile.eof())
            {
                // skips incramenting if invalid input and not end
                // of file
                continue;
            }
        }
        counter++;
    }
    // checks to see if the file is done yet
    if (!iFile.eof())
    {
        // tells you it didnt read all of the file
        cout << "Error: Max input size read in";
    }
}

void calculateArea(string shapes[], double sideLength[], double areas[],
                   const int counter)
{
    // intialize temp var
    double area = 0.0;

    // loops through all of the array
    for (int i = 0; i < counter; i++)
    {
        // checks for which shape
        if (shapes[i] == "hexagon")
        {
            // calcs area
            area = ((3 * sqrt(3)) / 2) * (pow(sideLength[i], 2));
        }
        else if (shapes[i] == "octagon")
        {
            // calcs area
            area = 2 * (1 + sqrt(2)) * pow(sideLength[i], 2);
        }
        else if (shapes[i] == "decagon")
        {
            // calcs area
            area = (5.0 / 2.0) * pow(sideLength[i], 2) *
                   (sqrt(5 + (2 * sqrt(5))));
        }

        // assigns the area in the array
        areas[i] = area;
    }
}

int minIndex(double areas[], const int counter)
{
    // initalize lil guy and index holder
    double littleGuy = 0.0;
    int idx = 0;
    // loops to check for smallest area
    for (int i = 0; i < counter; i++)
    {
        if (areas[i] < littleGuy)
        {
            littleGuy = areas[i];
            idx = i;
        }
    }
    // gives back the min index
    return idx;
}

int maxIndex(double areas[], const int counter)
{
    // initalize big guy and index hodler
    double bigGuy = 0.0;
    int idx = 0;

    // loops to find min
    for (int i = 0; i < counter; i++)
    {
        if (areas[i] > bigGuy)
        {
            bigGuy = areas[i];
            idx = i;
        }
    }

    // returns min index
    return idx;
}

void writeAreasToFile(ofstream &oFile, string shapes[],
                      double sideLenght[], double areas[],
                      const int counter)
{
    // cout << counter << endl;
    // opens file
    oFile.open("areas.txt");

    // writes to area file
    for (int i = 0; i < counter; i++)
    {
        oFile << fixed << setprecision(2)
              << shapes[i] << " " << sideLenght[i]
              << " " << areas[i] << endl;
    }

    // closes file
    oFile.close();
}

void writeStatsToFile(ofstream &oFile, string shapes[],
                      double sideLenght[], double areas[],
                      const int minIdx,
                      const int maxIdx, const int counter)
{
    // opens file
    oFile.open("stats.txt");

    // reads the info into
    oFile << fixed << setprecision(2)
          << "MINIMUM AREA" << endl
          << "Index: " << minIdx << endl
          << "Type: " << shapes[minIdx] << endl
          << "Side Length: " << sideLenght[minIdx] << endl
          << "Area: " << areas[minIdx] << endl
          << endl
          << "MAXIMUM AREA" << endl
          << "Index: " << maxIdx << endl
          << "Type: " << shapes[maxIdx] << endl
          << "Side Length: " << sideLenght[maxIdx] << endl
          << "Area: " << areas[maxIdx] << endl;

    // closes file
    oFile.close();
}