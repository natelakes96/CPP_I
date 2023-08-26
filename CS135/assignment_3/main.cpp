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
    // Ask for the side length of the octagon
    double side_length = 0.0;
    cout << "Enter octagon’s side length: ";

    // read in side length
    cin >> side_length;

    // Calculate the area of the octagon
    double _a = pow(side_length, 2.0);
    double _sq = sqrt(2.0);

    double AREA = 2.0 * _a * (1.0 + _sq);

    // Calculate the circumcircle radius
    double sec_part = sqrt(4 + 2 * _sq);

    double RADIUS_c = ((1.0 / 2) * side_length) * sec_part;

    // Calculate the incircle radius of the octagon
    double RADIUS_i = ((1.0 / 2) * side_length) * (1 + _sq);

    // checks to see if user is entering a valid data type
    if (cin.fail())
    {
        // outputs error
        cout << "Error: Invalid data type.\n";
        return 0;
    }
    // checks to see if side length is larger than zero
    if (side_length <= 0)
    {
        // outputs error
        cout << "Error: Input value must be greater than 0.\n";
        return 0;
    }
    // checks to see if side length is smaller than 100
    if (side_length >= 100)
    {
        // outputs error
        cout << "Error: Input value must be less than 100.\n";
        return 0;
    }
    if (side_length > 0 && side_length < 100)
    {
        // initalizes the calculation selector
        int calc_select = 0;

        // gives user a list of choices
        cout << "\nAvailable Calculations\n1) Area\n"
             << "2) Circumcircle Radius\n3) Incircle Radius\n"
             << "Selection: ";
        // reads in the user selection
        cin >> calc_select;

        // checks for errors on user selection
        if (cin.fail() || calc_select > 3 || calc_select <= 0)
        {
            // returns error is user selection is not valid
            cout << "Error: Invalid option.";
            return 0;
        }

        // checks in user selected area
        if (calc_select == 1)
        {
            // if user selected this it returns area
            cout << fixed << setprecision(2)
                 << "Area = " << AREA;
        }
        // checks if user selected circumcircle radius
        if (calc_select == 2)
        {
            // returns circumcircle radius
            cout << fixed << setprecision(2)
                 << "Circumcircle Radius = " << RADIUS_c;
        }
        // checks if user selected incircle radius
        if (calc_select == 3)
        {
            // returns incircle radius
            cout << fixed << setprecision(2)
                 << "Incircle Radius = " << RADIUS_i;
        }
    }
}
