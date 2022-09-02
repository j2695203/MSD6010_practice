//
//  main.cpp
//  BookAnalyzer
//
//  Created by Jinny on 2022/9/1.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "MyFunc.hpp"
using namespace std;

int main() {
    string filename;
    cout << "Enter the name of file: \n";
    getline(cin , filename);
    
    // open files and get all words
    vector<Word> allWords;
    allWords = getWord(filename);
    
    // get title and author
    getInfo(allWords);

    // total num of words
    cout << "Number of words: " << allWords.size() << endl;

    // total num of characters
    int sum = sumChar(allWords);
    cout << "Number of characters: " << sum << endl;

    // shortest word
    string shortest = shortWord(allWords);
    cout << "The shortest word: " << shortest << endl;
    
    // longest word
    string longest = longWord(allWords);
    cout << "The longest word: " << longest << endl;
    
    // search for certain word and its position
    string wordInput;
    cout << "Enter a word to search: ";
    cin >> wordInput;
    search(wordInput , allWords);
    
    return 0;
}
