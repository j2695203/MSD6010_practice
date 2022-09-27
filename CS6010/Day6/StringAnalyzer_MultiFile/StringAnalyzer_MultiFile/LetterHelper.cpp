//
//  LetterHelper.cpp
//  StringAnalyzer
//
//  Created by Jinny on 2022/8/29.
//

#include "LetterHelper.hpp"

bool isSpace(char c){
    if ( c == ' '){
        return true;
    }
    else{
        return false;
    }
}
bool isTerminator(char c){
    if ( c == '.' || c == '!' || c == '?'){
        return true;
    }
    else{
        return false;
    }
}
bool isPunctuation(char c){
    if ( c == '.' || c == '!' || c == '?' || c == ','){
        return true;
    }
    else{
        return false;
    }
}
bool isVowel(char c){
    // turn all words into lower case
    if ( c >= 'A' && c <= 'Z'){
        c += 32;
    }
    if ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y'){
        return true;
    }
    else{
        return false;
    }
}
bool isConsonant(char c){
    if ( isPunctuation(c) || isVowel(c) || isSpace(c) ){
        return false;
    }
    else{
        return true;
    }
}
