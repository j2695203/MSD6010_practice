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
    return (speedX);
}

double speed_y ( double speed , double angle){
    double speedY = speed * sin(angle);
    return (speedY);
}

//double speedXY( double speed, double angle){
//    double arr[2];
//    arr[0] = speed * cos(angle);
//    arr[1] = speed * sin(angle);
//    return arr[];
//}

bool isCapitalized(string s){
    if(s[0]>=65 && s[0]<=90){
        return(true);
    }
    else{
        return(false);
    }
}

string boolToString(bool captialResult){
    if(captialResult){
        return "true";
    }
    else{
        return "false";
    }
}

bool isPrime(int numberInput){
    int divisor = 0;
    for ( int i=1; i<=numberInput ; i++){
        if (numberInput % i == 0){
            divisor += 1;
        }
    }
    if (divisor == 2){
        return true;
    }
    else{
        return false;
    }
}


int main() {
    
    // PART 1 (A) //////
    float sideA;
    float sideB;
    float sideC;

    cout << "Enter the right-angle side: \n";
    cin >> sideA >> sideB;

    sideC = hypotenuse( sideA , sideB );
    // don't get input from cin because the input parameter should be the right type float first

    cout << "The length of the hypotenuse: \n" << sideC << endl;


    // PART 1 (B) //////
    double speed;
    double angle;
    double speedX;
    double speedY;
    cout << "Enter the speed and angle: \n";
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


    // PART 2 CAPITAL//////
    string stringInput;
    cout << "Enter a string: \n";
    cin >> stringInput;


    if (isCapitalized(stringInput)){
        cout << stringInput << " starts with a capital letter. \n";
    }
    else{
        cout << stringInput << " DOESN'T start with a capital letter. \n";
    }
    cout << boolToString (isCapitalized(stringInput)) << endl;
    
    
    // PART 2 PRIME //////
    int numberInput;
    cout << "Enter a number: \n";
    cin >> numberInput;
    
    if (isPrime(numberInput)){
        cout << numberInput << " is a prime number. \n";
    }
    else{
        cout << numberInput << " is NOT a prime number. \n";
    }
    
}

