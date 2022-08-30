//
//  main.cpp
//  VectorPractice
//
//  Created by Jinny on 2022/8/29.
//

#include <iostream>
#include <vector>
using namespace std;


int sum( vector<int> NumInput){
    int NumSum = 0;
    for ( int i = 0 ; i < NumInput.size() ; i++){
        NumSum += NumInput[i];
    }
    return NumSum;
}

vector<char> StringToVec (string StrInput){
    vector<char> vecSaveChar;
    for ( int i = 0 ; i < StrInput.length() ; i++){
        vecSaveChar.push_back( StrInput[i] );
    }
    return vecSaveChar;
}

vector<int> reverse (vector<int> IntInput){
    vector<int> vecReverse;
    for ( int i = 0 ; i < IntInput.size() ; i++){
        vecReverse.push_back( IntInput [IntInput.size()-i-1] );
    }
    return vecReverse;
}

int main() {
    
    vector<int> v1 = {1, 4, 2, 6, 5, -1};
    string s1 = "LetMeGo!";
    
    assert( sum(v1) == 17);
    assert( StringToVec(s1)[0] == 'L');
    assert( StringToVec(s1)[2] == 't');
    assert( StringToVec(s1)[7] == '!');
    assert( reverse(v1)[0] == -1);
    assert( reverse(v1)[5] == 1);
  
    return 0;
}
