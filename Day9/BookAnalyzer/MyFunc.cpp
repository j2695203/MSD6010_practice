//
//  MyFunc.cpp
//  BookAnalyzer
//
//  Created by Jinny on 2022/9/1.
//

#include "MyFunc.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// open file, save all words in vector
vector<Word> getWord(string filename){
    ifstream myStream(filename);  
    // fail to open files
    if(myStream.fail()){
        cout << "Failed to open file. \n" ;
        exit(1); 
    }
    // Get one word at a time automatically
    string singleWord;
    vector<Word> allWords;
    int numChar;
    while(myStream >> singleWord){
        numChar = int (singleWord.length());
        allWords.push_back( (Word) {singleWord,numChar});
    }
    myStream.close();
    return allWords;
}


BookInfo getInfo(vector<Word>& allWords){
    // search title, author pos
    int titlePos = 0;
    int authorPos = 0;
    int releasePos = 0;
    
    for(int i = 0; i < allWords.size(); i++){
        if ( allWords[i].word == "Title:"){
            titlePos = i;
        }
        if ( allWords[i].word == "Author:"){
            authorPos = i;
        }
        if (allWords[i].word == "Release"){
            releasePos = i;
        }
    }
    
    BookInfo thisBookInfo;
    // read title
    if ( titlePos != 0 && authorPos < titlePos + 100 ){
        for (int i = titlePos+1 ; i < authorPos ; i++){
            thisBookInfo.title += allWords[i].word + " ";
        }
    }
    else{
        thisBookInfo.title = "unknown";
    }
    // read author
    if ( authorPos != 0 && releasePos < authorPos + 100 ){
        for (int i = authorPos+1 ; i < releasePos ; i++){
            thisBookInfo.author += allWords[i].word + " ";
        }
    }
    else{
        thisBookInfo.author = "unknown";
    }
    cout << "Title: " << thisBookInfo.title << endl;
    cout << "Author: " << thisBookInfo.author << endl;
    return thisBookInfo;
}


int sumChar(vector<Word>& allWords){
    int sum = 0;
    for (Word el: allWords){
        sum += el.numChar;
    }
    return sum;
}

string shortWord(vector<Word>& allWords){
    string shortCheck;
    int charCheck = allWords[0].numChar;
    for(Word el: allWords){
        if (el.numChar < charCheck){
            charCheck = el.numChar;
            shortCheck = el.word;
        }
    }
    return shortCheck;
}

string longWord(vector<Word>& allWords){
    string longCheck;
    int charCheck = allWords[0].numChar;
    for(Word el: allWords){
        if (el.numChar > charCheck){
            charCheck = el.numChar;
            longCheck = el.word;
        }
    }
    return longCheck;
}

void search(string wordInput,vector<Word>& allWords){
    
    int count = 0;
    int pos;
    for (int i = 0; i < allWords.size() ; i++ ){
        if ( allWords[i].word == wordInput){
            pos = posInChar(i, allWords); // the word's position
            count++;
            if (i == 0){  // the first word
                cout << " at "<< pos <<"%: \"" << allWords[i].word + " " + allWords[i+1].word + "\"\n";
            }else if( i == allWords.size()-1){  // the last word
                cout << " at "<< pos <<"%: \"" << allWords[i-1].word + " " + allWords[i].word + "\"\n";
            }else{
                cout << " at "<< pos <<"%: \"" << allWords[i-1].word + " " + allWords[i].word + " " + allWords[i+1].word + "\"\n";
            }
        }
    }
    cout << "The word \"" << wordInput << "\" appears " << count << " times. \n";
}

// estimate the position of a word (using characters)
int posInChar(int posInWord,vector<Word>& allWords){
    int frontChar = 0; // all characters before the word
    for (int i = 0 ; i < posInWord ; i++){
        frontChar += allWords[i].numChar;
    }
    int posPercent =  (float)(frontChar + 1)/ sumChar(allWords) * 100 ;
    return posPercent ;
}
