//
//  main.cpp
//  IfStatementPractice
//
//  Created by Jinny on 2022/8/24.
//

#include <iostream>
using namespace std;

int main() {
    
    int age;
    cout << "Enter your age: \n";
    cin >> age;
    
    // AGE TO VOTE (18)
    if ( age < 18 ){
        cout << "You are NOT old enough to vote.\n";
    }
    else{
        cout << "You are old enough to vote.\n";
    }
    
    // AGE TO RUN FOR SENATE (30)
    if ( age < 30 ){
        cout << "You are NOT old enough to run for senate.\n";
    }
    else{
        cout << "You are old enough to run for senate.\n";
    }
    
    // GENERATION
    if ( age >= 80 ){
        cout << "You're part of greatest generation\n.";
    }
    else if ( 60 <= age ){
        cout << "You're part of baby boomers.\n";
    }
    else if ( 40 <= age ){
        cout << "You're part of generation X.\n";
    }
    else if ( 20 <= age ){
        cout << "You're part of millennial.\n";
    }
    else{
        cout << "You're part of iKid.\n";
    }
    
    return 0;
}
