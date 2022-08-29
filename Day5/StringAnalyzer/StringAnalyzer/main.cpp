//
//  main.cpp
//  StringAnalyzer
//
//  Created by Jinny on 2022/8/28.
//

#include <iostream>
using namespace std;

bool isSpace(char c){
    if ( c == ' '){
        return true;
    }
    else{
        return false;
    }
}
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
int NumSentences(string s){
    int count = 0;
    for (int i = 0; i < s.length() ; i++){
        if ( isTerminator(s[i]) ){
            count += 1;
        }
    }
    return count;
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
int NumVowel(string s){
    int count = 0;
    for (int i = 0; i < s.length() ; i++){
        if ( isVowel(s[i]) ){
            count += 1;
        }
    }
    return count;
}
bool isConsonant(char c){
    if ( isPunctuation(c) || isVowel(c) || isSpace(c) ){
        return false;
    }
    else{
        return true;
    }
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

int main() {
    string sentenceInput = "defalt";
    
    while(sentenceInput != "done"){
        cout << "Enter a string containing one or more sentences: (end: 'done') \n";
        getline ( cin , sentenceInput );
       
        if (sentenceInput!="done"){
            cout << "Numbers of words: " << NumWords(sentenceInput) << endl;
            cout << "Numbers of sentences : " << NumSentences(sentenceInput) << endl;
            cout << "Numbers of vowels: " << NumVowel(sentenceInput) << endl;
            cout << "Numbers of consonants: " << NumConsonant(sentenceInput) << endl;
            cout << "Reading Level (average word length): " << AverageWordLength(sentenceInput) << endl;
            cout << "Average vowels per word: " << AverageVowelsPerWord(sentenceInput) << endl;
        }
    }
    cout << "Goodbye \n";
    return 0;
}
