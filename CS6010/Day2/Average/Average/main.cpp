//
//  main.cpp
//  Average
//
//  Created by Jinny on 2022/8/24.
//  Group Lab Partner: Chun-Hao Hsu
//

#include <iostream>
using namespace std;

int main() {
    
    float score_1, score_2, score_3, score_4, score_5;
    float score_average;
    
    cout << "Please enter 5 assignment scores:" << endl; //Assume the user will type intergers
    cin >> score_1;
    cin >> score_2;
    cin >> score_3;
    cin >> score_4;
    cin >> score_5;
    
    score_average = ( score_1 + score_2 + score_3 + score_4 + score_5 ) / 5 ;
    
    cout << "Average Score:" << score_average << endl;
    
    return 0;
}
