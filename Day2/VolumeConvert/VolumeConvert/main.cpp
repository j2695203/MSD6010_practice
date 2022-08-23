//
//  main.cpp
//  VolumeConvert
//
//  Created by Jinny on 2022/8/23.
//  Group Lab Partner: Chun-Hao Hsu
//

#include <iostream>
using namespace std;

int main() {
    
    float ounces, cups, pints, gallons, liters, cubic_inches;
    
    cout << "Please input the number of ounces:" << endl;
    cin >> ounces;
    
    cups = ounces * 1/8 ;
    pints = ounces * 1/16 ;
    gallons = ounces * 1/128 ;
    liters = ounces * 0.0296 ;
    cubic_inches = ounces * 1.8 ;
    
    cout << "Ounces:" << ounces << endl;
    cout << "Cups:" << cups << endl;
    cout << "Pints:" << pints << endl;
    cout << "Gallons:" << gallons << endl;
    cout << "Liters:" << liters << endl;
    cout << "Cubic Inches:" << cubic_inches << endl;
    
    return 0;
}
