/*
 * Name:Nathaniel Stone, 8000617279, CS 135, assignment2
 * Description: takes the side of an octogon and gives the area,
 *              and the incircle and circumcircle radius.
 * Input: side length of octogon
 * Output: one of the three calculated numbers from the
 */
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{

    char contin = 'y';

    do
    {

        // intilize side variable
        double side_length = 0.0;

        // starts running the error checker for the first input
        do
        {
            // prompt for side length
            cout << "Enter octagon’s side length: ";
            // read in side length
            cin >> side_length;

            // checks to see if user is entering a valid data type
            if (cin.fail())
            {
                // outputs error
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Error: Invalid data type.\n";
            }
            // checks to see if side length is larger than zero
            else if (side_length <= 0)
            {
                // outputs error
                cout << "Error: Input value must be greater than 0.\n";
            }

            // checks to see if side length is smaller than 100
            else if (side_length >= 100)
            {
                // outputs error
                cout << "Error: Input value must be less than 100.\n";
            }

        } while (cin.fail() || side_length <= 0 || side_length >= 100);

        // Calculate the area of the octagon
        double _a = pow(side_length, 2.0);
        double _sq = sqrt(2.0);

        double AREA = 2.0 * _a * (1.0 + _sq);

        // Calculate the circumcircle radius
        double sec_part = sqrt(4 + 2 * _sq);

        double RADIUS_c = ((1.0 / 2) * side_length) * sec_part;

        // Calculate the incircle radius of the octagon
        double RADIUS_i = ((1.0 / 2) * side_length) * (1 + _sq);

        // initalizes the calculation selector
        int calc_select = 0;
        do
        {
            // gives user a list of choices
            cout << "\nAvailable Calculations\n1) Area\n"
                 << "2) Circumcircle Radius\n3) Incircle Radius\n"
                 << "Selection: ";
            // reads in the user selection
            cin >> calc_select;

            // checks for errors on user selection
            if (cin.fail() || calc_select > 3 || calc_select <= 0)
            {
                cin.clear();
                cin.ignore(100, '\n');
                // returns error is user selection is not valid
                cout << "Error: Invalid option." << endl;
            }
        } while (cin.fail() || calc_select > 3 || calc_select <= 0);

        // checks in user selected area
        if (calc_select == 1)
        {
            // if user selected this it returns area
            cout << fixed << setprecision(2)
                 << "Area = " << AREA << endl;
        }
        // checks if user selected circumcircle radius
        else if (calc_select == 2)
        {
            // returns circumcircle radius
            cout << fixed << setprecision(2)
                 << "Circumcircle Radius = " << RADIUS_c << endl;
        }
        // checks if user selected incircle radius
        else if (calc_select == 3)
        {
            // returns incircle radius
            cout << fixed << setprecision(2)
                 << "Incircle Radius = " << RADIUS_i << endl;
        }

        cout << "\nEnter y/Y to continue. Enter any other key to exit: ";

        cin >> contin;

    } while (contin == 'y' || contin == 'Y');
}
