//
//  MyFunc.cpp
//  DiyVector
//
//  Created by Jinny Jeng on 9/13/22.
//

#include "MyFunc.hpp"
#include <iostream>

using std::cout;
using std::endl;

// constructor
MyVector::MyVector( size_t initialCapacity){
    data = new int[initialCapacity];
    capacity = initialCapacity;
    size = 0;
}

// constructor with value
MyVector::MyVector( size_t initialCapacity, size_t size, int arr[]){
    data = new int[initialCapacity];
    for(int i = 0; i < size; i++){
        data[i] = arr[i];
    }
    capacity = initialCapacity;
    this->size = size;
}

// destructor
MyVector::~MyVector(){
    delete [] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

// copy constructor
MyVector::MyVector(const MyVector& v1){
    size = v1.size;
    capacity = v1.capacity;
    data = new int[capacity];
    for(size_t i = 0; i < size; i++){
        data[i] = v1.data[i];
    }
}

// operator=
MyVector& MyVector::operator= (const MyVector& v1){
    if(this == &v1 && size == v1.size && capacity == v1.capacity){
        return *this;
    }
    size = v1.size;
    capacity = v1.capacity;
//    data = new int[capacity];
    for(size_t i = 0; i < size; i++){
        data[i] = v1.data[i];
    }
    return *this;
}

// operator[]
int MyVector::operator[] (int index){
    return getValue(index);
}

// operator==
bool MyVector::operator== (const MyVector& v1){
    if (size != v1.getSize()){
        return false;
    }
    for (int i = 0; i < size; i++){
        if ( data[i] != v1.getValue(i)){
            return false;
        }
    }
    return true;
}

// operator!=
bool MyVector::operator!= (const MyVector& v1){
    return !MyVector::operator==(v1);
}

// operator<
bool MyVector::operator< (const MyVector& v1){
    // choose the smaller size for comparing range
    size_t smallerSize = v1.getSize();
    if ( size < v1.getSize()){
        smallerSize = size;
    }
    // compare value
    for (int i = 0; i < smallerSize; i++){
        if ( data[i] < v1.getValue(i)){
            return true;
        }
        else if( data[i] > v1.getValue(i)){
            return false;
        }
    }
    // if value are same, compare size
    if (smallerSize == size){
        return true;
    }
    return false;
}
// operator<=
bool MyVector::operator<= (const MyVector& v1){
    return ( MyVector::operator<(v1) || MyVector::operator==(v1));
}
// operator>=
bool MyVector::operator>= (const MyVector& v1){
    return ( !MyVector::operator<(v1) );
}
// operator>
bool MyVector::operator> (const MyVector& v1){
    return ( !MyVector::operator<=(v1));
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
int MyVector::getValue(int index)const{
    return data[index];
}

// set the appropriate value in the vector.
void MyVector::set(int index, int newValue){
    if(index < size){ //
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
//        freeVector();                              // free the space for old data
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
        std::cout<< v1.getValue((int)i)<< std:: endl;
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
    assert(v1.getValue(0) == 1);
    assert(v1.getValue(4) == 5);
    assert(v1.getSize() == 5);
    assert(v1.getCapacity() == initialSize);
    
    // pushBack no.6 value, getCapacity should double
    // v1 = {1,2,3,4,5,6}
    v1.pushBack(6);
    assert(v1.getValue(5) == 6);
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
    assert(v1.getValue(0) == -1);
    assert(v1.getValue(3) == 4);
    assert(v1.getValue(4) == -1);
    
    // get
    // v1 = {-1,2,3,4,-1}
    assert(v1.getValue(0) == -1);
    assert(v1.getValue(2) == 3);
    assert(v1.getValue(3) == 4);
    
    // constructor
    MyVector v2 = MyVector(5);
    assert(v2.getData() != nullptr);
    assert(v2.getCapacity() == 5);
    assert(v2.getSize() == 0);
    
    // destructor (how to test?)
    
//    int* temp;
//    if (true){
//        MyVector v3 = MyVector(5); // v3 only exist inside{}
//        v3.pushBack(1);
//        std::cout<< "data position before destructor: "<< v3.getData() << std::endl;
//        temp =v3.getData();
//    }
//    std::cout<< "data position after delete: "<< *temp << std::endl;  // can't compile cause v3 doesn't exist.

    // operator=
    // v1 = {-1,2,3,4,-1}
    MyVector v4 = MyVector(5);
    v4.pushBack(1);
    assert(v4.getValue(0) == 1);
    v4 = v1;
    assert(v4.getValue(0) == -1);
    assert(v4.getValue(4) == -1);
    assert(v4.getSize() == 5);
    
    // operator[]
    // make a copy and modify it, the original should remain unchanged, but the copy should reflect the changes.
    MyVector v5(v1);
    v5.set(0, 10);
    // v1 = {-1,2,3,4,-1}
    // v5 = {10,2,3,4,-1}
    assert( v1[0] == -1);
    assert( v5[0] == 10);
    
    // operator
    
    // v1 = {-1,2,3,4,-1}
    // v5 = {10,2,3,4,-1}
    int arr1[5] = {1,2,3,4,5};
    int arr2[7] = {1,2,3,4,5,6,7};
    int arr3[5] = {1,1,1,1,1};
    int arr4[5] = {2,2,2,2,2};
    MyVector v6(10,5,arr1); // {1,2,3,4,5}
    MyVector v7(10,7,arr2); // {1,2,3,4,5,6,7};
    MyVector v8(10,5,arr3); // {1,1,1,1,1};
    MyVector v9(10,5,arr4); // {2,2,2,2,2};
    assert( v6 < v7 );
    assert( ! (v6 >= v7) );
    assert( v6 > v8 );
    assert( ! (v6 <= v8) );
    assert( v6 < v9 );
    v9 = v6; // copy {1,2,3,4,5}
    assert( v6 == v9 );
    
    

}
