/*
 * Name:Nathaniel Stone, 8000617279, CS 135, assignment5
 * Description: this program takes in a file of random
 *              random metric weights, and returns two files
 *              with conversions and totals
 * Input: input txt file name
 * Output: txt file with conversions
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

        iFile.open(inputFile);
        if (!iFile.is_open())
        {
            cout << "Error: Invalid filename\n"
                 << endl;
        }

    } while (!iFile.is_open());
    cout << endl;

    // opens conversions file
    oFile.open("conversions.txt");

    // initalzies the needed variables.
    int conversions = 0;
    float weight = 0.0, totalWeights = 0.0;
    string massUnit = "";

    while (!iFile.eof())
    {
        // reads in weight and units
        iFile >> weight >> massUnit;
        // checks if its a valid data type
        if (iFile.fail())
        {
            if (!iFile.eof())
            {
                iFile.clear();
                iFile.ignore(256, '\n');
                cout << "Error: Invalid weight \n";
            }
            // cout << "Error: Invalid weight \n";
            continue;
        }
        // checks if the units are grams
        if (massUnit == "g")
        {
            // converts
            float lbs = weight / 453.6;
            // writes to output file
            oFile << lbs << " lbs" << endl;
            // adds to total weight
            totalWeights += lbs;
        }
        // checks if units are kilos
        else if (massUnit == "kg")
        {
            // converts
            float lbs = weight * 2.205;
            // writes to output file
            oFile << lbs << " lbs" << endl;
            // adds to total weight
            totalWeights += lbs;
        }
        // checks if units are metric tons
        else if (massUnit == "mt")
        {
            // converts
            float lbs = weight * 2205.0;
            // write it to conversions file
            oFile << lbs << " lbs" << endl;
            // adds to total weight
            totalWeights += lbs;
        }
        // if all is good itll add to array size
        conversions++;
    }

    // closes input and conversions output file
    iFile.close();
    oFile.close();

    // opens totals output file
    oFile.open("totals.txt");

    // reads info into totals file
    oFile << "Total conversions: " << conversions << endl
          << "Total weight in pounds: " << totalWeights;

    // closes totals file
    oFile.close();
}
