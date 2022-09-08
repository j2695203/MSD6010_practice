//
//  main.cpp
//  NumberRepresentations
//
//  Created by Jinny Jeng on 9/7/22.
//

#include <iostream>
#include <cstdint> // types
#include <math.h>
#include <iomanip> // ?
#include <fstream>
#include <vector>
#include "NumberConvert.hpp"
using namespace std;

int main() {
/*
 PART 1
 */
    // check size of types
    cout<< "size of char: "<< sizeof( char ) << endl;
    cout<< "size of int: "<< sizeof( int ) << endl;
    int a[] = { 7, 2, -56, 32, 1, 7, -2, 7 };
    cout << "size of a[7]: " << sizeof( a ) << endl;

    cout<< "size of int8_t: "<< sizeof( int8_t ) << endl;
    cout<< "size of int16_t: "<< sizeof( int16_t ) << endl;
    cout<< "size of uint8_t: "<< sizeof( uint8_t ) << endl;
    cout<< "size of uint16_t: "<< sizeof( uint16_t ) << endl << endl;
    
    /*
     uint8_t, uint16_t, and uint64_t
     Define variables and assign them the min/max values using hexadecimal constants and print
     */
    
    uint8_t uint8_min = 0x0;
    uint8_t uint8_max = 0xFF;
    uint16_t uint16_min = 0x0;
    uint16_t uint16_max = 0xFFFF;
    uint64_t uint64_min = 0x0;
    uint64_t uint64_max = 0xFFFFFFFFFFFFFFFF;
    
    int8_t int8_min = 0x80;
    int8_t int8_max = 0x7F;
    int16_t int16_min = 0x8000;
    int16_t int16_max = 0x7FFF;
    int64_t int64_min = 0x8000000000000000;
    int64_t int64_max = 0x7FFFFFFFFFFFFFFF;
    
    // max and min for Unsigned type
    cout << "unsigned: \n";
    cout << " uint8_t min: " << +uint8_min << endl;
    cout << " uint8_t max: " << +uint8_max << endl;
    cout << " uint16_t min: " << +uint16_min << endl;
    cout << " uint16_t max: " << +uint16_max << endl;
    cout << " uint64_t min: " << +uint64_min << endl;
    cout << " uint64_t max: " << +uint64_max << endl;
    
    // Try adding 1 to the max-value variables, subtracting 1 from the min values.
    uint8_max += 1;
    uint16_max += 1;
    uint64_max += 1;
    
    cout << "unsigned max + 1: \n";
    cout << " uint8_t max + 1 : " << +uint8_max << endl;
    cout << " uint16_t max + 1: " << +uint16_max << endl;
    cout << " uint64_t max + 1: " << +uint64_max << endl;
    
    uint8_min -= 1;
    uint16_min -= 1;
    uint64_min -= 1;
    
    cout << "unsigned min - 1: \n";
    cout << " uint8_t min - 1 : " << +uint8_min << endl;
    cout << " uint16_t min - 1: " << +uint16_min << endl;
    cout << " uint64_t min - 1: " << +uint64_min << endl << endl;

    // max and min for Signed type
    cout << "signed: \n";
    cout << " int8_t min: " << +int8_min << endl;
    cout << " int8_t max: " << +int8_max << endl;
    cout << " int16_t min: " << +int16_min << endl;
    cout << " int16_t max: " << +int16_max << endl;
    cout << " int64_t min: " << +int64_min << endl;
    cout << " int64_t max: " << +int64_max << endl;
    
    // Try adding 1 to the max-value variables, subtracting 1 from the min values.
    int8_max += 1;
    int16_max += 1;
    int64_max += 1;
    
    cout << "signed max + 1: \n";
    cout << " int8_t max + 1 : " << +int8_max << endl;
    cout << " int16_t max + 1: " << +int16_max << endl;
    cout << " int64_t max + 1: " << +int64_max << endl;
    
    int8_min -= 1;
    int16_min -= 1;
    int64_min -= 1;
    
    cout << "signed min - 1: \n";
    cout << " int8_t min - 1 : " << +int8_min << endl;
    cout << " int16_t min - 1: " << +int16_min << endl;
    cout << " int64_t min - 1: " << +int64_min << endl << endl;

    /*
     part 2
     */
    double x;
    x = .1 + .2;
    cout << "add double: " << x << endl;
    assert( x - .3 != 0 );
    cout << "add double: " << setprecision(18) << x << endl;

    float y;
    y = .1 + .2;
    cout << "add float:  " << y << endl;
    cout << "add float:  " << setprecision(18) << y << endl;

    double z = 0.3;
    cout << "0.3 double: " << z << endl;
    cout << "0.3 double: " << setprecision(18) << z << endl;

    cout << "diviation: " << z-x << endl;

    if ( approxEquals( x, z, 5.5511151231257827e-17) ){
        cout << " equal " << endl;
    }
    else{
        cout << " not equal " << endl;
    }
/*
 PART 3
 */
    string filename = "UTF-8-demo.txt";
    charCount(filename);
    
    return 0;
}
