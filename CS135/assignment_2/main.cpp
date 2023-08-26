/*
 * Name:Nathaniel Stone, 8000617279, CS 135, assignment2
 * Description: takes the side of an octogon and gives the area,
 *              and the incircle and circumcircle radius.
 * Input: side length of octogon
 * Output: table with area and radius of the octogon.
 */
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    // 1. Ask for the side length of the
    // octagon, and read the side length into a
    // floating-point variable in main memory.
    float side_length = 0.0;

    cout << "Enter octagon’s side length: ";
    cin >> side_length;
    cout << "\n";

    // 2. Calculate the area of the octagon using
    // the formula below, then save that
    // value into a floating-point variable in
    // main memory. You will need to use
    // <cmath> to perform this calculation.

    double _sq = sqrt(2);

    float AREA = 2 * pow(side_length, 2) * (1 + sqrt(2));

    // 3. Calculate the circumcircle radius
    // of the octagon using the formula below,
    // then save that value into a floating-point
    // variable in main memory. You
    // will need to use <cmath> to perform this calculation.
    double sec_part = sqrt(4 + 2 * _sq);

    double RADIUS_c = ((1.0 / 2) * side_length) * sec_part;

    // 4. Calculate the incircle radius of the octagon
    // using the formula below, then
    // save that value into a floating-point
    // variable in main memory. You will
    // need to use <cmath> to perform this calculation.

    double RADIUS_i = ((1.0 / 2) * side_length) * (1 + _sq);

    // 5. Output the values from the steps above
    // in the format of the formatting
    // example below. The <iomanip> library
    // will need to be used to properly
    // match the formatting.

    string separator =
        "+--------------+--------------+--------------+--------------+";
    string h1 = "side length", h2 = "area",
           h3 = "circumcircle", h4 = "incircle";

    cout << separator << endl
         << left
         << "| " << setw(12) << "side length"
         << " | " << setw(12) << "area"
         << " | " << setw(12) << "circumcircle"
         << " | " << setw(12) << "incircle"
         << " |\n"
         << separator << endl
         << fixed
         << setprecision(2)
         << "| " << setw(12) << side_length
         << " | " << setw(12) << AREA
         << " | " << setw(12) << RADIUS_c
         << " | " << setw(12) << RADIUS_i << " |\n"
         << separator;
}
