/******************************                                                
 ** File:     sos.h
 ** Project:  CMSC 202 Proj 2, Fall 2015
 ** Author:   Brianna Richardson
 ** Date:     10/12/2015
 ** Section:  0104
 ** Email:    bricha2@gl.umbc.edu
 ** 
 **  This file contains testing of each public function within
 ** SoS class in Project 2. Each member function worked based on these
 ** results. Each test was done with a mixture of cofinite and
 ** finite situations.
 **
*****************************/

#include <iostream>
#include <algorithm>
#include "sos.h"
using namespace std;

int main() {
  // Five finite SoS objects are made.
  SoS finiteOne;
  SoS finiteTwo;
  SoS finiteThree;
  SoS finiteFour;
  SoS finiteFive; 

  // Using the insert() function, components are added
  // to the finite vectors
  finiteOne.insert("A");
  finiteOne.insert("B");
  finiteOne.insert("C");
  finiteOne.insert("D");
  finiteTwo.insert("E");
  finiteTwo.insert("F");
  finiteTwo.insert("G");
  finiteTwo.insert("H");
  finiteThree.insert("D");
  finiteThree.insert("I");
  finiteThree.insert("J");
  finiteThree.insert("K");
  finiteFour.insert("A");
  finiteFour.insert("B");
  finiteFour.insert("C");
  finiteFour.insert("D");
  finiteFour.insert("E");
  finiteFive.insert("A");
  finiteFive.insert("B");
  finiteFive.insert("C");
  
  // Each finite SoS m_vos is printed using the print()
  // This ouputs correctly, meaning insert() and print() worked
  cout << "This Test file utilizes the following SoS objects: " << endl;
  cout << endl;
  cout << "finiteOne:" << endl;
  finiteOne.print();
  cout << "finiteTwo:" << endl;
  finiteTwo.print();
  cout << "finiteThree:" << endl;
  finiteThree.print();
  cout << "finiteFour:" << endl;
  finiteFour.print();
  cout << "finiteFive:" << endl;
  finiteFive.print();
  cout << endl; 
  
  // Now the makeComplement is tested.
  // A cofinite SoS object is made for each finite one.
  SoS cofiniteOne = finiteOne.makeComplement();
  SoS cofiniteTwo = finiteTwo.makeComplement();
  SoS cofiniteThree = finiteThree.makeComplement();
  SoS cofiniteFour = finiteFour.makeComplement();
  SoS cofiniteFive = finiteFive.makeComplement();
  
  // cofiniteOne is printed and it returns the right output.
  // Therefore, makeComplement works.
  cout << "Each has it's own complement. For example, cofiniteOne: " << endl;
  cofiniteOne.print();
  cout << endl; 

  // Now, test the makeUnion function
  // This also outputted the correct results.
  cout << "First we will test the makeUnion function." << endl;
  cout << "The union of cofiniteOne and cofiniteTwo should be empty: " << endl;
  SoS unionOne = cofiniteOne.makeUnion(cofiniteTwo); 
  unionOne.print();
  cout << "The union of cofiniteOne and cofiniteThree should have 1 element: " 
       << endl;
  SoS unionTwo = cofiniteOne.makeUnion(cofiniteThree);
  unionTwo.print();
  cout << "The union of finiteOne and finiteTwo should 8 elements: " << endl;
  SoS unionThree = finiteOne.makeUnion(finiteTwo);
  unionThree.print();
  cout << "The union of finiteOne and finiteThree should have 7 elements: " 
       << endl;
  SoS unionFour = finiteOne.makeUnion(finiteThree);
  unionFour.print();
  
  // Test the makeIntersection function
  // This also outputted correctly, passing the test
  cout << "Now, we will test the makeIntersection function. " << endl;
  cout << "The intersection of cofiniteOne and cofiniteTwo" 
       << " should have 8 elements. Answer: " << endl;
  SoS intersectOne = cofiniteOne.makeIntersection(cofiniteTwo);
  intersectOne.print();
  cout << "The intersection of cofiniteOne and cofiniteThree should" 
       << " have 7 elements. Answer: " << endl;
  SoS intersectTwo = cofiniteOne.makeIntersection(cofiniteThree);
  intersectTwo.print();
  cout << "The intersection of finiteOne and finiteTwo should" 
       << " be empty. Answer: " << endl;
  SoS intersectThree = finiteOne.makeIntersection(finiteTwo); 
  intersectThree.print();
  cout << "The intersection of finiteOne and finiteThree should" 
       << " have 1 element. Answer:  " << endl;
  SoS intersectFour = finiteOne.makeIntersection(finiteThree);
  intersectFour.print();
  
  // This tests the isMember function
  // The output is correct.
  cout << "Now we're going to test the isMember function!" << endl;
  cout << "Is 'E' a str in cofiniteOne? Answer: " 
       << cofiniteOne.isMember("E") << endl;
  cout << "Should return 1. " << endl;
  cout << "Is 'B' a str in cofiniteOne? Answer: " 
       << cofiniteOne.isMember("B") << endl;
  cout << "Should return 0. " << endl;
  cout << "Is 'E' a str in finiteOne? Answer: " 
       << finiteOne.isMember("E") << endl;
  cout << "Should return 0. " << endl;
  cout << "Is 'B' a str in finiteOne? Answer: " 
       << finiteOne.isMember("B") << endl;
  cout << "Should return 1. " << endl << endl;
  
  // This tests the isSubset
  // The output is correct.
  cout << "Now we're going to test the isSubset function!" << endl;
  cout << "Is cofiniteFour a subset of cofiniteOne? Answer: " 
       << cofiniteFour.isSubset(cofiniteOne) << endl;
  cout << "Should return 1. " << endl;
  cout << "Is cofiniteFive a subset of cofiniteOne? Answer: "
       << cofiniteFive.isSubset(cofiniteOne) << endl;
  cout << "Should return 0. " << endl;
  cout << "Is finiteTwo a subset of cofiniteOne? Answer: "
       << finiteTwo.isSubset(cofiniteOne) << endl;
  cout << "Should return 1. " << endl;
  cout << "Is finiteThree a subset of cofiniteOne? Answer: "
       << finiteThree.isSubset(cofiniteOne) << endl;
  cout << "Should return 0. " << endl;
  cout << "Is cofiniteOne a subset of finiteOne? Answer: "
       << cofiniteOne.isSubset(finiteOne) << endl;
  cout << "Should return 0. " << endl;
  cout << "Is finiteFive a subset of finiteOne? Answer: "
       << finiteFive.isSubset(finiteOne) << endl;
  cout << "Should return 1. " << endl;
  cout << "Is finiteOne a subset of finiteFive? Answer: "
       << finiteOne.isSubset(finiteFive) << endl;
  cout << "Should return 0. " << endl << endl;

  // This tests the insert() function on cofinite sets.
  cout << "Now we will run the insert() function with cofinite" 
       << " and finite objects." << endl;
  cofiniteOne.insert("E");
  cout << "If you insert 'E' into cofiniteOne, then "
       << "it should NOT change. Answer: " << endl;
  cofiniteOne.print();
  cout << "If you insert 'E' into finiteOne, then "
       << "it should change. Answer: " << endl;
  finiteOne.insert("E");
  finiteOne.print();
  cout << "Test complete!" << endl;
  return 0;
}
