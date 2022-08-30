//
//  main.cpp
//  status-1
//
//  Created by Jinny on 2022/8/29.
//

#include <iostream>
using namespace std;

int main() {
    int numInput;
    int numTotal = 0;
    
    for (int i=0 ; i<4 ; i++){
        cout << "Enter 4 numbers between 1-10 (ends:-99) \n";
        cin >> numInput;
        if (numInput == -99){
            cout << "goodbye \n";
            exit(0);
        }
        else if ( numInput >= 1 && numInput <= 10 ){
            numTotal += numInput;
        }
    }

    cout << "Sum: " << numTotal << endl;

    return 0;
}
