//
//  main.cpp
//  CommandLineArgs
//
//  Created by Jinny on 2022/9/2.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    for(int i = 0 ; i < argc ; i++ ){
        std::cout << argv[i];
    }
    return 0;
}
