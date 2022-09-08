//
//  NumberConvert.cpp
//  NumberRepresentations
//
//  Created by Jinny Jeng on 9/7/22.
//

#include "NumberConvert.hpp"
#include <iostream>
#include <cstdint>
#include <math.h>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

/*
 PART 2
 */
bool approxEquals( double a, double b, double tolerance ){
    return( abs(a-b) <= tolerance );
}


/*
 PART 3
 */
void charCount(std::string filename){

    char singleChar;
    vector<char> allChars;

    // read file and print
    ifstream myStream ("UTF-8-demo.txt");
    if(myStream.fail()){
        cout << "Failed to open file.\n";
    }
    while(myStream >> singleChar){
        allChars.push_back(singleChar);
        cout << singleChar <<" ";
    }
    myStream.close();
    
    // count ASCII and UNICODE characters
    int countASC = 0;
    int countUni = 0;
    for (char el: allChars){
        if ( el >= 0 && el <=127){
            countASC++;
        }
        else{
            countUni++;
        }
    }
    
    // print numbers of ASCII and UNICODE characters
    cout<< "Number of ASCII characters:   " << countASC <<endl;
    cout<< "Number of Unicode characters: " << countUni <<endl;
}


