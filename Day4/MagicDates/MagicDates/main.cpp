//
//  main.cpp
//  MagicDates
//
//  Created by Jinny on 2022/8/26.
//

#include <iostream>
using namespace std;

// MAGIC DATES //////

int main() {
    
    string inputDate;
    int posSlash;
    string splitDate[3]; // why [2] will alarm with size error?
    
    cout << "Enter a date (mm/dd/yyyy): \n";
    cin >> inputDate;
        
    
    // split strings
    for ( int i=0 ; i<2 ; i++){ // assume the user type in right format, there will be 2 "/"
        // find slash position
        posSlash = inputDate.find("/");
        // save string before slash
        splitDate[i] = inputDate.substr(0,posSlash);
        // delete saved string
        inputDate = inputDate.erase(0,posSlash+1);
    }
    // save the last string (no slash behind)
    splitDate[2] = inputDate.substr(0,4);

    
    // convert string to number
    int mm = std::stoi(splitDate[0]);
    int dd = std::stoi(splitDate[1]);
    int yyyy = std::stoi(splitDate[2]);
    int yy = yyyy % 100; // last 2 digit for yyyy
    
    
    // range check
    if( mm>=1 && mm<=12 && dd>=1 && dd<=31 && yyyy>=1000 && yyyy<=9999 ){
        
        // magic date or not
        if ( mm * dd == yy){
            cout << mm << "/" << dd << "/" << yyyy << " IS a magic date.\n";
        }
        else{
            cout << inputDate + " is NOT a magic date.\n";
        }
    }
    
    return 0;
}
