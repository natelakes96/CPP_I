/*
 * Name:Nathaniel Stone, 8000617279, CS 135, assignment1
 * Description: A program for a traveling nail sales person.
 * Input: price of bulk crate, and quantity of bulk crates needed
 * Output: "HELLO CODEGRADE"
 */

#include <iostream>
using namespace std;
int main()
{
    // setting up all of the static variables

    int BULK_CRATE_SIZE = 10000;
    int BOX_SIZE = 100;
    float MARKUP = 1.6;

    // 1. Ask for the price of bulk crates of nails,
    // and read the price into a floating-
    // point variable in main memory.
    float price = 1;

    cout << "Enter today’s bulk crate price: ";

    cin >> price;

    // 2. Ask for the quantity of bulk crates wanted,
    // and read the price into an
    // integer variable in main memory.
    float crates = 0;

    cout << "Enter the quantity of bulk crates wanted: ";

    cin >> crates;

    cout << "\n";

    // 3. Calculate the total amount of nails
    // being purchased using the formula
    // below, then save that value into an
    // integer variable in main memory.

    float TOTAL_NAILS = BULK_CRATE_SIZE * crates;

    // 4. Calculate how many boxes of 100
    // can be made using the formula below,
    // then save that value into an integer variable
    // in main memory.

    float TOTAL_BOXES = TOTAL_NAILS / BOX_SIZE;

    // 5. Calculate the cost of a single
    // nail from the distributor using the formula
    // below, then save that value into a floating-point
    // variable in main memory.

    float SINGLE_NAIL_COST = price / BULK_CRATE_SIZE;

    // 6. Calculate the cost of a single nail to
    // the consumer at a 60% markup using
    // the formula below, then save that value into
    // a floating-point variable in
    // main memory.

    float SINGLE_NAIL_SALE_PRICE = SINGLE_NAIL_COST * MARKUP;

    // 7. Calculate the profit on a single
    // nail using the formula below, then save
    // that value into a floating-point variable
    // in main memory.

    float SINGLE_NAIL_PROFIT = SINGLE_NAIL_SALE_PRICE - SINGLE_NAIL_COST;

    // 8. Calculate the cost of a box of
    // nails from the distributor using the formula
    // below, then save that value into a floating-point
    // variable in main memory.

    float BOX_COST = SINGLE_NAIL_COST * BOX_SIZE;

    // 9. Calculate the cost of a box of nails
    // to the consumer at a 60% markup using
    // the formula below, then save that value
    // into a floating-point variable in
    // main memory.

    float BOX_SALE_PRICE = SINGLE_NAIL_SALE_PRICE * BOX_SIZE;

    // 10. Calculate the profit on a box
    // of nails using the formula below, then save
    // that value into a floating-point variable
    // in main memory.

    float BOX_PROFIT = BOX_SALE_PRICE - BOX_COST;

    // 11. Calculate the total profit for
    // the purchase order using the formula below,
    // then save that value into a floating-point
    // variable in main memory.

    float TOTAL_PROFIT = BOX_PROFIT * TOTAL_BOXES;

    // 12. Output the values from the steps above
    // in the format of the formatting
    // example below.

    cout << "Total quantity to order: " << TOTAL_NAILS << endl
         << "Number of boxes of 100: " << TOTAL_BOXES << endl
         << "Single nail cost: " << SINGLE_NAIL_COST << endl
         << "Single nail sale price: " << SINGLE_NAIL_SALE_PRICE << endl
         << "Single nail profit: " << SINGLE_NAIL_PROFIT << endl
         << "Box cost: " << BOX_COST << endl
         << "Box sale price: " << BOX_SALE_PRICE << endl
         << "Box profit: " << BOX_PROFIT << endl
         << "Total profit: " << TOTAL_PROFIT << endl;
}