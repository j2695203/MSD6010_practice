//
//  main.cpp
//  DiyVector
//
//  Created by Jinny Jeng on 9/13/22.
//

#include <iostream>
#include "MyFunc.hpp"
#include "testFunc.hpp"
using std::string;


int main(int argc, const char * argv[]) {
    
    // Test case: int
    int arr1[5] = {1,2,3,4,5};
    MyVector<int> v1(5,5,arr1);
    testInt(v1);
    
    // Test case: double
    double arr2[5] = {1.0, 2.0, 3.0, 4.0, 5.3};
    MyVector<double> v2(5,5,arr2);
    testDouble(v2);
    
    // Test case: string
    string s1[3] = {"Hello,", "I", "am"};
    MyVector<string> v3(3, 3, s1);

    v3.pushBack("Jinny.");
    v3.print();
    
    MyVector<string> v4(v3); // copy
    
    v4.set(3, "Varun.");
    printFunc(v4);
    
    assert(v3 < v4);   // J < V
    std::cout<< " Pass test for Type string."<<std::endl;

    return 0;
}
