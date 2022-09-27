//
//  testFunc.hpp
//  DiyVector
//
//  Created by Jinny Jeng on 9/16/22.
//

#ifndef testFunc_hpp
#define testFunc_hpp

#include <stdio.h>
#include "MyFunc.hpp"
#include <string>

template<typename T>
void testInt(MyVector<T> v1){
    
    // PushBack
    assert(v1.getCapacity() == 5);
    v1.pushBack(6);                // v1 = {1,2,3,4,5,6}
    assert(v1.getValue(5) == 6);
    assert(v1.getSize() == 6);
    assert(v1.getCapacity() == 10); // pushBack 6th value, Capacity should be double
    
    // PopBack
    v1.popBack();                 // v1 = {1,2,3,4,5}
    assert(v1.getSize() == 5);
    
    // Set and Get
    v1.set(4, 1);                 // v1 = {1,2,3,4,1}
    assert(v1.getValue(4) == 1);
    
    // Constructor without value
    MyVector<T> v = MyVector<T>(5);
    assert(v.getData() != nullptr);
    assert(v.getCapacity() == 5);
    assert(v.getSize() == 0);
    
    // operator=
    MyVector<T> v2(5);
    v2 = v1;                      // v2 = {1,2,3,4,1}
    assert(v2.getValue(4) == 1);
    assert(v2.getSize() == 5);
    
    // operator[] and copy constructor
    MyVector<T> v3(v1);           // v3 = {1,2,3,4,1}
    v3.set(0, 10);                 // v3 = {10,2,3,4,1}
    assert( v1[0] == 1);          // no change for original v1
    assert( v3[0] == 10);         // change for copied v3
    
    // logical operators
    MyVector<T> v4(v3);
    assert( v3 == v4 );
    v4.pushBack(10);             // v4 ={10,2,3,4,1,10} to test diff size
    assert( v1 < v4 );
    assert( ! (v1 >= v4) );
    
    std::cout<< " Pass test for Type int."<<std::endl;
}

template<typename T>
void testDouble(MyVector<T> v1){
    
    // PushBack
    v1.pushBack(6.2);                // v1 = {1.0, 2.0, 3.0, 4.0, 5.3, 6.2}
    assert(v1.getValue(5) == 6.2);
    assert(v1.getSize() == 6);
    
    // PopBack
    v1.popBack();                 // v1 = {1.0, 2.0, 3.0, 4.0, 5.3}
    assert(v1.getSize() == 5);
    
    // Set and Get
    v1.set(4, 1.2);                 // v1 = {1.0, 2.0, 3.0, 4.0, 1.2}
    assert(v1.getValue(4) == 1.2);
    
    // operator=
    MyVector<T> v2(5);
    v2 = v1;                      // v2 = {1.0, 2.0, 3.0, 4.0, 1.2}
    assert(v2.getValue(4) == 1.2);
    assert(v2.getSize() == 5);

    // operator[] and copy constructor
    MyVector<T> v3(v1);           // v3 = {1.0, 2.0, 3.0, 4.0, 1.2}
    v3.set(0, 8.8);                 // v3 = {8.8, 2.0, 3.0, 4.0, 1.2}
    assert( v1[0] == 1.0);          // no change for original v1
    assert( v3[0] == 8.8);         // change for copied v3

    // logical operators
    MyVector<T> v4(v3);
    assert( v3 == v4 );
    v4.pushBack(8.8);             // v4 ={8.8, 2.0, 3.0, 4.0, 1.2, 8.8} to test diff size
    assert( v1 < v4 );
    assert( ! (v1 >= v4) );
    
    std::cout<< " Pass test for Type double."<<std::endl;
    
}

#endif /* testFunc_hpp */
