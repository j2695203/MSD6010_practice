//
//  main.cpp
//  DateFormats
//
//  Created by Jinny on 2022/8/26.
//

#include <iostream>
using namespace std;

int main() {
    
    string inputDate;
    int posSlash;
    string splitDate[3]; // why [2] will alarm with size error? it's size!
    
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
    splitDate[2] = inputDate;

    
    // convert string to number
    int mm = std::stoi(splitDate[0]);
    int dd = std::stoi(splitDate[1]);
    int yyyy = std::stoi(splitDate[2]);
    
    string mmEng;


    // range check and convert number mm to English
    if( mm>=1 && mm<=12 && dd>=1 && dd<=31 && yyyy>=1000 && yyyy<=9999 ){
        if( mm == 1){
            mmEng = "January";
        }
        else if ( mm == 2){
            mmEng = "Feburary";
        }
        else if ( mm == 3){
            mmEng = "March";
        }
        else if ( mm == 4){
            mmEng = "April";
        }
        else if ( mm == 5){
            mmEng = "May";
        }
        else if ( mm == 6){
            mmEng = "June";
        }
        else if ( mm == 7){
            mmEng = "July";
        }
        else if ( mm == 8){
            mmEng = "August";
        }
        else if ( mm == 9){
            mmEng = "September";
        }
        else if ( mm == 10){
            mmEng = "October";
        }
        else if ( mm == 11){
            mmEng = "November";
        }
        else{
            mmEng = "December";
        }
        cout << mmEng << " " << dd << ", " << yyyy << endl;
    }
    else{
        cout << "wrong range! \n";
    }
    
    return 0;
}
