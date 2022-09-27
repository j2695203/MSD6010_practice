//
//  main.cpp
//  DiyVector
//
//  Created by Jinny Jeng on 9/13/22.
//

#include<iostream>
#include<numeric>

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
    
    // STL algorithms check
    // print
    v1.set(3, 10); // v1 = {1,2,10,4,5}
    for(auto el: v1){
        std::cout<< el << " ";
    }
    // sort
    std::sort(v1.begin(), v1.end());
    for(auto el: v1){
        std::cout<< el << " ";
    }
    // min
    std::cout<<"\n";
    auto minValue = *std::min_element(v1.begin(), v1.end());
    std::cout<< minValue << std::endl;
    // accumulate
    std::cout<<"\n";
    auto sumValue = std::accumulate(v1.begin(), v1.end(),0);
    std::cout<< sumValue << std::endl;
    // count_if
    std::cout<<"\n";
    auto evenCount = std::count_if(v1.begin(), v1.end(), [](auto i){return i % 2 == 0;});
    std::cout<< evenCount << std::endl;
    
    // remove even numbers
    std::cout<<"\n";
    std::remove_if(v1.begin(), v1.end(), [](auto i){return i % 2 == 0;});
    for (int count = 0; count < evenCount; count++){
        v1.popBack();
    }
    for(auto el: v1){
        std::cout<< el << " ";
    }

    return 0;
}
