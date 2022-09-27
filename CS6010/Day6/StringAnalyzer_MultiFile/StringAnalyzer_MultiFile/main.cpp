//
//  main.cpp
//  StringAnalyzer
//
//  Created by Jinny on 2022/8/28.
//

#include <iostream>
#include "MyFunc.hpp"
#include "LetterHelper.hpp"


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
