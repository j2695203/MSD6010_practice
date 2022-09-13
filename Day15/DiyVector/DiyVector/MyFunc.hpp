//
//  MyFunc.hpp
//  DiyVector
//
//  Created by Jinny Jeng on 9/13/22.
//

#ifndef MyFunc_hpp
#define MyFunc_hpp

#include <stdio.h>

struct MyVector{
    int* data;
    size_t capacity;
    size_t size;
};

// should return a vector with the given capacity and a size of 0
MyVector makeVector( size_t initialCapacity);
// should deallocate any heap memory used by the MyVector object
void freeVector(MyVector);
// only data, void??
void pushBack(MyVector& v1, int);
void popBack(MyVector& v1);

//return the appropriate value in the vector. This should work like [] does for std::vectors
int get(MyVector& v1, int index);

// set the appropriate value in the vector. This should work like [] for std::vector when they're on the left of an equals sign (vec[3] = 10;).
void set(MyVector& v1, int index, int newValue);

// should double the capacity of the vector. The values should be copied from the old array to the new array

void growVector(MyVector&);

void print(MyVector&);
void testCases();

#endif /* MyFunc_hpp */
