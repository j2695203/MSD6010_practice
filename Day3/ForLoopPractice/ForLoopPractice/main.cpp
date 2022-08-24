//
//  main.cpp
//  ForLoopPractice
//
//  Created by Jinny on 2022/8/24.
//

#include <iostream>
using namespace std;

int main() {
    
    // TWO DIFFERENT LOOPS FOR 1-10 ////// For loop is more appropriate when 1~10!
    
    // for loop
    for ( int i=1 ; i<=10 ; i++){
        cout << i << " ";
    }
    cout << endl;

    // while loop
    int j=1 ;
    while ( j <= 10 ){
        cout << j << " ";
        j++;
    }
    cout << endl;


    // NUMBERS BETWEEN TWO INPUTS //////
    
    int num_big, num_small;
    int num_check;

    cout << "Enter 2 numbers:" << endl;
    cin >> num_big;
    cin >> num_small;

    // check bigger number
    if ( num_small > num_big ){
        num_check = num_small;
        num_small = num_big;
        num_big = num_check;
    }
    // print numbers
    while(num_small <= num_big){
        cout << num_small << " ";
        num_small++;
    }
    cout << endl;

    
    // ODD NUMBERS BETWEEN 1-20 //////
    
    // loop+if
    for( int num=1 ; num <= 20 ; num++ ){
        if ( num % 2 == 1 ){
            cout << num << " ";
        }
    }
    cout << endl;
    
    // no if
    for( int num=1 ; (num <= 20) && (num % 2 == 1) ; num += 2 ){
        cout << num << " ";
    }
    cout << endl;
    


    // SUM UP NUMBERS //////
    int numInput = 0;
    int numSum = 0;
    cout << "Enter positive numbers: ( <0: exit ) \n";

    // keep input numbers
    while( numInput >= 0){
        cin >> numInput;
        // check if end up
        if ( numInput >= 0){
            numSum += numInput;
        }
    }
    cout << "Sum up:" << numSum << endl;


    // MULTIPLICATION TABLE FOR 1-5 //////
    int row;
    int column;

    for ( row = 1 ; row <= 5 ; row ++ ){
        cout << row << "x*: ";
        for ( column = 1 ; column <= 5 ; column ++ ){
            cout << column * row << " ";
        }
        cout << endl;
    }


    return 0;
}
