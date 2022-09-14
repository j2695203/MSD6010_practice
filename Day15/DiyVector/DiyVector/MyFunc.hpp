//
//  MyFunc.hpp
//  DiyVector
//
//  Created by Jinny Jeng on 9/13/22.
//

#ifndef MyFunc_hpp
#define MyFunc_hpp

#include <stdio.h>

class MyVector{
private:
    int* data;
    size_t capacity;
    size_t size;
public:
    // constructor
    MyVector(size_t initialCapacity);
    // methods
    void freeVector();
    void pushBack(int);
    void popBack();
    int get(int index);
    void set(int index, int newValue);
    void growVector();
    size_t getSize() {
        return size;
    }
    size_t getCapacity(){
        return capacity;
    }
    int* getData(){
        return data;
    }
};

void printFunc(MyVector&);
void testCases();

#endif /* MyFunc_hpp */
