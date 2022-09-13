//
//  MyFunc.cpp
//  DiyVector
//
//  Created by Jinny Jeng on 9/13/22.
//

#include "MyFunc.hpp"
#include <iostream>

// should return a vector with the given capacity and a size of 0
MyVector makeVector( size_t initialCapacity){
    MyVector v1;
    v1.data = new int[initialCapacity];
    v1.capacity = initialCapacity;
    v1.size = 0;
    return v1;
}

// should deallocate any heap memory used by the MyVector object
void freeVector(MyVector v1){
    delete [] v1.data;
    v1.data = nullptr;
}

void pushBack(MyVector& v1, int dataValue){
    growVector(v1);
    v1.data[ v1.size ] = dataValue;
    v1.size += 1;
}

void popBack(MyVector& v1){
    v1.size -= 1;
}

//return the appropriate value in the vector.
int get(MyVector& v1, int index){
    return v1.data[index];
}

// set the appropriate value in the vector.
void set(MyVector& v1, int index, int newValue){
    v1.data[index] = newValue;
}

// should double the capacity of the vector. The values should be copied from the old array to the new array
void growVector(MyVector& v1){
    if (v1.size == v1.capacity){
        
        int* tempArray = new int [v1.size * 2];  // temporary array with twice the size of the original.
        
        for (int i = 0; i < v1.size; i++){             // copy content to temporary array
            * (tempArray + i) = * (v1.data + i);
        }
        freeVector(v1);                              // free the space for old data
        v1.data = tempArray;                           // point to new copied data (temporary array)
        tempArray = nullptr;
        
        // update capacity
        v1.capacity *= 2;
        
        // fill the empty spots with -1.
        for(size_t i = v1.size; i < v1.capacity; i++){
            *(v1.data + i) = -1;
        }
    }
}



void print(MyVector& v1){
    for (size_t i = 0; i < v1.size; i++){
        std::cout<< v1.data[i] << std:: endl;
    }
    std::cout<< "size: " << v1.size << std:: endl ;
    std::cout<< "capacity: " << v1.capacity << std:: endl << std:: endl;
}

void testCases(){
    
    MyVector v1 = makeVector(5);
    pushBack(v1, 1);
    pushBack(v1, 2);
    pushBack(v1, 3);
    pushBack(v1, 4);
    print(v1);
    
    popBack(v1);
    print(v1);
    
    // test freeVector
    
    // test set and get
    set(v1, 0, -1);
    set(v1, 2, -3);
    print(v1);
    std::cout<< get(v1, 2) << std::endl << std::endl;
    
    // test growVector
    pushBack(v1, 4);
    pushBack(v1, 5);
    pushBack(v1, 6);
    growVector(v1);
    print(v1);
    
}
