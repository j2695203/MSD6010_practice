/*
  Author: Daniel Kopta and ??
  July 2017
  
  CS 6010 Fall 2019
  Vector util library tests
  Compile this file together with your VectorUtil library with the following command:
  clang++ -std=c++11 VectorTest.cpp VectorUtil.cpp
  Most of the provided tests will fail until you have provided correct 
  implementations for the VectorUtil library functions.
  You will need to provide more thorough tests.
*/

#include <iostream>
#include <string>

// Include the VectorUtil library
#include "VectorUtil.h"

/*
 * Helper function for failing a test.
 * Prints a message and exits the program.
 */
void ErrorExit( std::string message )
{
  std::cerr << "Failed test: " << message << std::endl;
  exit(1); // Causes the entire program to exit.
}


int main()
{
    // Set up some input vectors for testing purposes.

    // We can use list initialization syntax:
    vector<int> v1 = {3, 1, 0, -1, 5};

    // Or we can repeatedly push_back items
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);

    // When testing, be sure to check boundary conditions, such as an empty vector
    vector<int> empty;
    
    vector<int> v3 = {-2, 0, 3, 3, 5}; // ascending w/ some same number inside
    vector<int> v4 = {1, 1, 1, 1, 1}; // ascending w/ all same number inside
  
    /*
    * Contains tests
    */

    // v1 doesn't contain 4, so this should return false
    if( Contains(v1, 4) ) {
    ErrorExit( "Contains() - test 1" );
    }

    // v1 does contain -1, so this should return true
    if(!Contains(v1, -1)) {
    ErrorExit("Contains() - test 2");
    }
    
    // v1 does contain 5 (corner case), so this should return true
    if(!Contains(v1, 5)) {
      ErrorExit("Contains() - test 3");
    }
    // v1 does contain 3 (corner case), so this should return true
    if(!Contains(v1, 3)) {
      ErrorExit("Contains() - test 4");
    }

    /*
    * The vector 'empty' doesn't contain anything, so this should return false
    * The specific value we're looking for here (99) is not important in this test.
    * This test is designed to find any general errors caused by the array being empty.
    * That type of error is unlikely to depend on the value we are looking for.
    */
    if( Contains(empty, 99) ) {
    ErrorExit("Contains() - empty");
    }
    
    
    /*
     * FindMin tests
     */

    // v1 min number is -1, so this should return false
    if( FindMin(v1) == 0 ) {
      ErrorExit( "FindMin() - test 1" );
    }
    
    // v1 min number is -1, so this should return false
    if( FindMin(v1) != -1 ) {
      ErrorExit( "FindMin() - test 2" );
    }
    
    // v2 min number is 1, so this should return false
    if( FindMin(v2) == -2 ) {
      ErrorExit( "FindMin() - test 3" );
    }
    
    // v2 min number is 1, so this should return false
    if( FindMin(v2) != 1 ) {
      ErrorExit( "FindMin() - test 4" );
    }
    
    // v4 min number is 1, so this should return false
    if( FindMin(v4) != 1 ) {
      ErrorExit( "FindMin() - test 5" );
    }
    
    
    /*
     * FindMax tests
     */

    // v1 max number is 5, so this should return false
    if( FindMax(v1) == 3 ) {
      ErrorExit( "FindMax() - test 1" );
    }
    
    // v1 max number is 5, so this should return false
    if( FindMax(v1) != 5 ) {
      ErrorExit( "FindMax() - test 2" );
    }
    
    // v2 max number is 3, so this should return false
    if( FindMax(v2) == 2 ) {
      ErrorExit( "FindMax() - test 3" );
    }
    
    // v2 max number is 3, so this should return false
    if( FindMax(v2) != 3 ) {
      ErrorExit( "FindMax() - test 4" );
    }
    
    // v4 max number is 1, so this should return false
    if( FindMax(v4) != 1 ) {
      ErrorExit( "FindMax() - test 5" );
    }
    
    
    /*
     * Average tests
     */

    // v1 avg is 8/5 = 1, so this should return false
    if( Average(v1) != 1 ) {
      ErrorExit( "Average() - test 1" );
    }
    
    // v1 avg is 8/5 = 1, so this should return false
    if( Average(v1) == 2 ) {
      ErrorExit( "Average() - test 2" );
    }
    
    // v1 avg is 8/5 = 1, so this should return false
    if( Average(v1) == 1.6 ) {
      ErrorExit( "Average() - test 3" );
    }
    
    // v2 avg is 2, so this should return false
    if( Average(v2) != 2 ) {
      ErrorExit( "Average() - test 4" );
    }
    
    // v2 avg is 2, so this should return false
    if( Average(v2) == 3 ) {
      ErrorExit( "Average() - test 5" );
    }
    
    /*
     * IsSorted tests
     */

    // v1 is not sorted, so this should return false
    if( IsSorted(v1) ) {
      ErrorExit( "IsSorted() - test 1" );
    }
    
    // v2 is sorted, so this should return false
    if( !IsSorted(v2) ) {
      ErrorExit( "IsSorted() - test 2" );
    }
    
    // v3 is sorted, so this should return false
    if( !IsSorted(v3) ) {
      ErrorExit( "IsSorted() - test 3" );
    }
    
    // v4 is sorted, so this should return false
    if( !IsSorted(v4) ) {
      ErrorExit( "IsSorted() - test 4" );
    }
  

  // Since any failed test exits the program, if we made it this far, we passed all tests.
  std::cout << "All tests passed!\n";

}
