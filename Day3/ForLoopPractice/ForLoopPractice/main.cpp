//
//  main.cpp
//  ForLoopPractice
//
//  Created by Jinny on 2022/8/24.
//

#include <iostream>
using namespace std;

int main() {
    
//    // LOOP FOR 1-10 ///////////
//    cout << "For Loop" <<endl; // for loop
//    int i;
//    for ( i=1 ; i<=10 ; i++){
//        cout << i << " ";
//    }
//    cout << endl;
//
//    cout << "While Loop" <<endl; // while loop
//    int j=1 ;
//    while ( j<=10 ){
//        cout << j << " ";
//        j++;
//    }
//    cout << endl;
//
//    // For loop is more appropriate when 1~10
//
//
//    // NUMBERS BETWEEN TWO INPUT //////
//    int num_big, num_small;
//    int num_check;
//
//    cout << "Enter 2 numbers:" << endl;
//    cin >> num_big;
//    cin >> num_small;
//
//    //check bigger number
//    if ( num_small > num_big ){
//        num_check = num_small;
//        num_small = num_big;
//        num_big = num_check;
//    }
//    //print numbers
//    while(num_small <= num_big){
//        cout << num_small << " ";
//        num_small++;
//    }
//
//    // ODD NUMBERS BETWEEN 1-20 //////
//    // loop+if
//    int num;
//    for( num=1 ; num <= 20 ; num++ ){
//        if ( num % 2 == 1 ){
//            cout << num << " ";
//        }
//    }
//    // no if
//    for( num=1 ; (num <= 20) && (num % 2 == 1) ; num += 2 ){
//        cout << num << " ";
//    }
    
    
    // SUM UP NUMBERS
    int numInput;
    int numSum = 0;
    cout << "Enter positive numbers: ( <0: exit ) \n";
 
    while( numInput >= 0){
        cin >> numInput;
        numSum += numInput;
    }
    cout << "Sum up:" << numSum << endl;
    
    
    return 0;
}