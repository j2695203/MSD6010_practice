//
//  MyFunc.hpp
//  DiyVector
//
//  Created by Jinny Jeng on 9/13/22.
//

#ifndef MyFunc_hpp
#define MyFunc_hpp
#include <stdio.h>
#include <iostream>


template<typename T>
class MyVector{
private:
    T* data;
    size_t capacity;
    size_t size;
public:
    // constructors and deconstructor
    MyVector(size_t initialCapacity);
    MyVector(size_t initialCapacity, size_t size, T arr[] );
    ~MyVector();
    MyVector(const MyVector& v1); // copy constructor
    
    // Arithmetic operators
    MyVector& operator= (const MyVector& v1);
    T operator[] (int index);
    
    // Logical operators
    bool operator== (const MyVector& v1);
    bool operator!= (const MyVector& v1);
    bool operator< (const MyVector& v1);
    bool operator<= (const MyVector& v1);
    bool operator>= (const MyVector& v1);
    bool operator> (const MyVector& v1);
    
    // Methods
    void pushBack(T);
    void popBack();
    T getValue(int index)const;
    void set(int index, T newValue);
    void growVector();
    size_t getSize()const{
        return size;
    }
    size_t getCapacity()const{
        return capacity;
    }
    T* getData()const{
        return data;
    }
    void print()const;
};

// constructor
template<typename T>
MyVector<T>::MyVector( size_t initialCapacity){
    data = new T[initialCapacity];
    capacity = initialCapacity;
    size = 0;
}

// constructor with value
template<typename T>
MyVector<T>::MyVector( size_t initialCapacity, size_t size, T arr[size]){
    data = new T[initialCapacity];
    for(int i = 0; i < size; i++){
        data[i] = arr[i];
    }
    capacity = initialCapacity;
    this->size = size;
}

// destructor
template<typename T>
MyVector<T>::~MyVector(){
    delete [] data;
    data = nullptr;
    size = 0;
    capacity = 0;
    std::cout<< "destructor called.\n";
}

// copy constructor
template<typename T>
MyVector<T>::MyVector(const MyVector& v1){
    if(this != &v1){ // avoid original v1 leak   MyVector v1(v1)
        size = v1.size;
        capacity = v1.capacity;
        data = new T[capacity];
        for(size_t i = 0; i < size; i++){
            data[i] = v1.data[i];
        }
    }
}

// operator=
template<typename T>
MyVector<T>& MyVector<T>::operator= (const MyVector<T>& v1){
    if(this == &v1 && size == v1.size && capacity == v1.capacity){
        return *this;
    }
    size = v1.size;
    capacity = v1.capacity;
//    data = new T[capacity];
    for(size_t i = 0; i < size; i++){
        data[i] = v1.data[i];
    }
    return *this;
}

// operator[]
template<typename T>
T MyVector<T>::operator[] (int index){
    return data[index];
}

// operator==
template<typename T>
bool MyVector<T>::operator== (const MyVector<T>& v1){
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
template<typename T>
bool MyVector<T>::operator!= (const MyVector<T>& v1){
    return !MyVector<T>::operator==(v1);
}

// operator<
template<typename T>
bool MyVector<T>::operator< (const MyVector<T>& v1){
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
template<typename T>
bool MyVector<T>::operator<= (const MyVector<T>& v1){
    return ( MyVector<T>::operator<(v1) || MyVector<T>::operator==(v1));
}
// operator>=
template<typename T>
bool MyVector<T>::operator>= (const MyVector<T>& v1){
    return ( !MyVector<T>::operator<(v1) );
}
// operator>
template<typename T>
bool MyVector<T>::operator> (const MyVector<T>& v1){
    return ( !MyVector<T>::operator<=(v1));
}


///
template<typename T>
void MyVector<T>::pushBack(T dataValue){
    growVector();
    data[ size ] = dataValue;
    size += 1;
}

template<typename T>
void MyVector<T>::popBack(){
    size -= 1;
}

//return the appropriate value in the vector.
template<typename T>
T MyVector<T>::getValue(int index)const{
    return data[index];
}

// set the appropriate value in the vector.
template<typename T>
void MyVector<T>::set(int index, T newValue){
    if(index < size){ //
        data[index] = newValue;
    }
    else{
        std::cout << "value should be set within size" << std::endl;
    }
}

// should double the capacity of the vector. The values should be copied from the old array to the new array
template<typename T>
void MyVector<T>::growVector(){
    if (size == capacity){
        
        T* tempArray = new T [size * 2];  // temporary array with twice the size of the original.
        
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

template<typename T>
void printFunc(MyVector<T>& v1){
    for (size_t i = 0; i < v1.getSize(); i++){
        std::cout<< v1.getValue((int)i)<< " ";
    }
    std::cout<< std::endl << "size: " << v1.getSize() << std:: endl ;
    std::cout<< "capacity: " << v1.getCapacity() << std:: endl << std:: endl;
}

template<typename T>
void MyVector<T>::print()const{
    for(size_t i = 0; i < size; i++){
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}



#endif /* MyFunc_hpp */
