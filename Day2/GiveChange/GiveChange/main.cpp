//
//  main.cpp
//  GiveChange
//
//  Created by Jinny on 2022/8/24.
//
/*
    Goal:
    Computes the set of fewest coins possible to return a customer's change
    after purchasing something from a vending machine.
 
    Assume:
    The user will always enter an amount paid that is greater than or equal
    to the item price, and that neither of them are less than or equal to 0.
*/

#include <iostream>
using namespace std;

int main() {
    
    int item_price;
    int amount_paid;
    int amount_return;
    
    int num_quarter;
    int num_dime;
    int num_nickel;
    int num_penny;
    
    cout << "Enter item price in cents:" << endl;
    cin >> item_price;
    cout << "Enger amount paid in cents:" << endl;
    cin >> amount_paid;
    
    amount_return = amount_paid - item_price;
    cout << "Change = " << amount_return << "cents" << endl;
    
    
    num_quarter = amount_return / 25;
    amount_return -= num_quarter * 25;
    
    num_dime = amount_return / 10;
    amount_return -= num_dime * 10;

    num_nickel = amount_return / 5;
    amount_return -= num_nickel * 5;
    
    num_penny = amount_return;
    
    
    cout << " Quarters:" << num_quarter << endl;
    cout << " Dimes:" << num_dime << endl;
    cout << " Nickels:" << num_nickel << endl;
    cout << " Pennies:" << num_penny << endl;
    
    
    return 0;
}
