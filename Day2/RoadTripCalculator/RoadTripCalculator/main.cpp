//
//  main.cpp
//  RoadTripCalculator
//
//  Created by Jinny on 2022/8/23.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    float total_dist;
    float mile_per_gallon;
    float cost_per_gallon;
    float total_gallon;
    float total_cost;
    
    cout << "Please enter the driving distance, in (whole) miles:" << endl;
    cin >> total_dist;
    cout << "Please enter the vehicle's miles per gallon efficiency:" << endl;
    cin >> mile_per_gallon;
    cout << "Please enter the cost of gas in dollars per gallon:" << endl;
    cin >> cost_per_gallon;
    
    total_gallon = total_dist / mile_per_gallon;
    total_cost = total_gallon * cost_per_gallon;
    
    cout << endl << "The cost of your trip will be $"<< fixed << setprecision(2) << total_cost << endl;

    return 0;
}
