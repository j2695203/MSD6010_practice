//
//  main.cpp
//  FunctionPractice
//
//  Created by Jinny on 2022/8/26.
//

#include <iostream>
#include <cmath>
using namespace std;


float hypotenuse( float a, float b){
    float c = sqrt( pow(a,2) + pow (b,2) );
    return (c);
}

double speed_x ( double speed , double angle){
    double speedX = speed * cos(angle);
    return speedX;
}
double speed_y ( double speed , double angle){
    double speedY = speed * sin(angle);
    return speedY;
}

bool isCapitalized(string s){
    
    if(s[0]>=65 && s[0]<=90){
        return(true);
    }
    else{
        return(false);
    }
    
    
}

//double speedXY( double speed, double angle){
//    double arr[2];
//    arr[0] = speed * cos(angle);
//    arr[1] = speed * sin(angle);
//    return arr[];
//}



int main() {
    // PART 1 (A) //////
    float sideA;
    float sideB;
    float sideC;

    cout << "Enter the right-angle side: \n";
    cin >> sideA >> sideB;

    sideC = hypotenuse( sideA , sideB );
    // don't get input from cin caused the input parameter should be the right type float first

    cout << "The length of the hypotenuse: \n" << sideC << endl;


    // PART 1 (B) //////
    double speed;
    double angle;
    double speedX;
    double speedY;
    cout << "Enter the speed: \n";
    cin >> speed >> angle;

    speedX = speed * cos(angle);
    speedY = speed * sin(angle);

    cout << "x velocity:" << speedX << endl;
    cout << "y velocity:" << speedY << endl;
    // hard to turn into a function because there are two values needed to be return, but function can return one value. Maybe return an array then read values in array?
    // PART 1 (B) WITH FUNCTIONS //////
    double speedXX;
    double speedYY;
    speedXX = speed_x(speed, angle);
    speedYY = speed_y(speed, angle);

    cout << "x velocity:" << speedXX << endl;
    cout << "y velocity:" << speedYY << endl;


    // PART 1 (C) //////
    std::time_t result = std::time(nullptr);
    std::cout << std::asctime(std::localtime(&result))
                  << result << " seconds since the Epoch\n";
    // functions being called: time(), asctime(), localtime()

    
    // PART 2 //////
    string stringInput;
    cout << "Enter a string: \n";
    cin >> stringInput;
//    if (isCapitalized){
//        cout << "string starts with a capital letter";
//    }
//    else{
//        cout << "string DOESN'T start with a capital letter";
//    }
    
    
}

