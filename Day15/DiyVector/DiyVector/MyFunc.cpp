//
//  MyFunc.cpp
//  DiyVector
//
//  Created by Jinny Jeng on 9/13/22.
//

#include "MyFunc.hpp"
#include <iostream>

// constructor
MyVector::MyVector( size_t initialCapacity){
    data = new int[initialCapacity];
    capacity = initialCapacity;
    size = 0;
}

// should deallocate any heap memory used by the MyVector object
void MyVector::freeVector(){
    delete [] data;
    data = nullptr;
}

void MyVector::pushBack(int dataValue){
    growVector();
    data[ size ] = dataValue;
    size += 1;
}

void MyVector::popBack(){
    size -= 1;
}

//return the appropriate value in the vector.
int MyVector::get(int index){
    return data[index];
}

// set the appropriate value in the vector.
void MyVector::set(int index, int newValue){
    if(index < size){
        data[index] = newValue;
    }
    else{
        std::cout << "value should be set within size" << std::endl;
    }
}

// should double the capacity of the vector. The values should be copied from the old array to the new array
void MyVector::growVector(){
    if (size == capacity){
        
        int* tempArray = new int [size * 2];  // temporary array with twice the size of the original.
        
        for (int i = 0; i < size; i++){             // copy content to temporary array
            * (tempArray + i) = * (data + i);
        }
        freeVector();                              // free the space for old data
        data = tempArray;                           // point to new copied data (temporary array)
        tempArray = nullptr;
        
        // update capacity
        capacity *= 2;
        
        // fill the empty spots with -1.
        for(size_t i = size; i < capacity; i++){
            *(data + i) = -1;
        }
    }
}

void printFunc(MyVector& v1){
    for (size_t i = 0; i < v1.getSize(); i++){
        std::cout<< v1.get((int)i)<< std:: endl;
    }
    std::cout<< "size: " << v1.getSize() << std:: endl ;
    std::cout<< "capacity: " << v1.getCapacity() << std:: endl << std:: endl;
}

void testCases(){
    
    size_t initialSize = 5;
    MyVector v1 = MyVector(initialSize);
    
    // pushBack 5 values, test get, getSize, getCapacity
    // v1 = {1,2,3,4,5}
    v1.pushBack(1);
    v1.pushBack(2);
    v1.pushBack(3);
    v1.pushBack(4);
    v1.pushBack(5);
    assert(v1.get(0) == 1);
    assert(v1.get(4) == 5);
    assert(v1.getSize() == 5);
    assert(v1.getCapacity() == initialSize);
    
    // pushBack no.6 value, getCapacity should double
    // v1 = {1,2,3,4,5,6}
    v1.pushBack(6);
    assert(v1.get(5) == 6);
    assert(v1.getSize() == 6);
    assert(v1.getCapacity() == initialSize * 2);
    
    // popBack
    // v1 = {1,2,3,4,5}
    v1.popBack();
    assert(v1.getSize() == 5);

    // set
    // v1 = {-1,2,3,4,-1}
    v1.set(0, -1);
    v1.set(4, -1); // out of size
    assert(v1.get(0) == -1);
    assert(v1.get(3) == 4);
    assert(v1.get(4) == -1);
    
    // get
    // v1 = {-1,2,3,4,-1}
    assert(v1.get(0) == -1);
    assert(v1.get(2) == 3);
    assert(v1.get(3) == 4);
    
    // test freeVector
    std::cout<< "data position before delete: "<< v1.getData() << std::endl;
    v1.freeVector();
    std::cout<< "data position after delete: "<< v1.getData() << std::endl;
    assert(v1.getData() == nullptr);

}
