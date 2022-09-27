//
//  NumberConvert.hpp
//  NumberRepresentations
//
//  Created by Jinny Jeng on 9/7/22.
//

#ifndef NumberConvert_hpp
#define NumberConvert_hpp

#include <stdio.h>
#include <string>

std::string intToBinaryString( int numerical);
std::string intToHexadecimalString( int numerical);
void charCount(std::string filename);
bool approxEquals( double a, double b, double tolerance );

#endif /* NumberConvert_hpp */
