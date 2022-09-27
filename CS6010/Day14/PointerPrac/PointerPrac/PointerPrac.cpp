//
//  main.cpp
//  PointerPrac
//
//  Created by Jinny Jeng on 9/12/22.
//

#include <iostream>
#include <array>
//using namespace std;

struct MyVector{
    double* data;
    int size;
    int capacity;
};

// arrayModSum that takes as arguments a reference to a MyVector variable (MyVector& someVar) and the size of the array inside that variable. The function must first modify someVar.data by adding 1 to each element, then return the sum of the modified array.

double arrayModSum(MyVector& someVar){
    double arraySum = 0;
    for (int i = 0; i < someVar.size; i++){
        *(someVar.data + i) += 1;
        arraySum += *(someVar.data + i);
    }
    return arraySum;
}

//takes a single input: a MyVector& someVar. If someVar.size == someVar.capacity, this function grows someVar.data (without losing any of its contents).

void growMyVector(MyVector& someVar){
    if (someVar.size == someVar.capacity){
        
        double* tempArray = new double [someVar.size * 2];  // temporary array with twice the size of the original.
        
        for (int i = 0; i < someVar.size; i++){             // copy content to temporary array
            * (tempArray + i) = * (someVar.data + i);
        }
        delete[] someVar.data;                              // free the space for old data
        someVar.data = tempArray;                           // point to new copied data (temporary array)
        tempArray = nullptr;
        
        // update capacity
        someVar.capacity *= 2;
        
        // fill the empty spots with -1.0.
        for(int i = someVar.size; i < someVar.capacity; i++){
            *(someVar.data + i) = -1.0;
        }
    }
}


int main(int argc, const char * argv[]) {
    MyVector vec1;
    int arraySize;
    
    // read in the array size,
    std::cout << "Enter the array size: \n";
    std::cin >> arraySize;
    
    //allocate an array on the heap using new. Store it in vec1.data so that vec1.data is now pointing to the first element of the array.
    vec1.data = new double [arraySize];
    vec1.size = arraySize;
    vec1.capacity = vec1.size;
   
    // loop over the newly created array and fill each element with 1.0
    for(int i = 0; i < vec1.capacity; i++){
        *(vec1.data + i) = 1.0;
    }
    
    // modify array's value and print out the summary
    std::cout<< arrayModSum(vec1) << std::endl;
    
    // PART 2
    growMyVector(vec1);
    for (int i = 0; i < vec1.capacity; i++){
        std::cout<< vec1.data[i] << std::endl;
    }

    delete[] vec1.data;
    vec1.data = nullptr;
    
    return 0;
}
