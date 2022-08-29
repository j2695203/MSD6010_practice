//
//  MyFunc.cpp
//  StringAnalyzer
//
//  Created by Jinny on 2022/8/29.
//

#include "MyFunc.hpp"
#include "LetterHelper.hpp"
#include <string>
using namespace std;

int NumSpace(string s){
    int count = 0;
    for (int i = 0; i < s.length() ; i++){
        if ( isSpace(s[i]) ){
            count += 1;
        }
    }
    return count;
}
int NumWords(string s){
    return ( NumSpace(s) + 1);
}
int NumSentences(string s){
    int count = 0;
    for (int i = 0; i < s.length() ; i++){
        if ( isTerminator(s[i]) ){
            count += 1;
        }
    }
    return count;
}

int NumVowel(string s){
    int count = 0;
    for (int i = 0; i < s.length() ; i++){
        if ( isVowel(s[i]) ){
            count += 1;
        }
    }
    return count;
}

int NumConsonant(string s){
    int count = 0;
    for (int i = 0; i < s.length() ; i++){
        if ( isConsonant(s[i]) ){
            count += 1;
        }
    }
    return count;
}

double AverageWordLength(string s){
    return ( ( (double) NumVowel(s) + NumConsonant(s) ) / NumWords(s) );
}

double AverageVowelsPerWord(string s){
    return ( (double) NumVowel(s) / NumWords(s) );
}

