//
//  MyFunc.hpp
//  BookAnalyzer
//
//  Created by Jinny on 2022/9/1.
//

#ifndef MyFunc_hpp
#define MyFunc_hpp

#include <stdio.h>
#include <string>
using namespace std;

// save each word and number of chars in struc
struct Word{
    string word;
    int numChar;
};

// save title and author in struc
struct BookInfo{
    string title;
    string author;
};

vector<Word> getWord(string);
BookInfo getInfo(vector<Word>&);

int sumChar(vector<Word>&);
string shortWord (vector<Word>&);
string longWord (vector<Word>&);

void search(string,vector<Word>&);
int posInChar(int,vector<Word>&);

#endif /* MyFunc_hpp */
