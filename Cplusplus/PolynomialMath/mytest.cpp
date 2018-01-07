/*****************************************
 ** File:    Polynomial.cpp
 ** Project: CMSC 202 Project 3, Fall 2015
 ** Author:  Brianna Richardson
 ** Date:    10/30/15
 ** Section: 0104
 ** E-mail:  bricha2@gl.umbc.edu
 **
 **   This file contains the main test driver for Project 3. This program tests
 ** all the working functions within the Polynomial class. Through examples shown,
 ** functions are proven to work.
 **
 **                                                                                                                                                                                  
 ***********************************************/

#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {

  cout << endl;
  
  cout << "Creating the polynomial a..." << endl << endl;
  
  // Through the creation of Polynomial a and b, I show that the insertMonomial
  // function works, as well as the the evaluate() and degree(), even when 
  // under the pressure of different int types (+, -, 0)

  Polynomial a;
  a.insertMonomial(1,0);
  a.insertMonomial(2,1);
  a.insertMonomial(1,2);
 
  cout << "a(x) = " << a << endl;
  cout << "a has a degree of " << a.degree() << endl;
  cout << "a(0) = " << a.evaluate(0) << endl;
  cout << "a(1) = " << a.evaluate(1) << endl << endl;
  
  cout << "Creating the polynomial b... " << endl << endl;

  Polynomial b;
  
  b.insertMonomial(-3,0);
  b.insertMonomial(2,2);
  b.insertMonomial(4,4);
  b.insertMonomial(5,2);
  
  cout << "b(x) = " << b << endl;
  cout << "b has a degree of " << b.degree() << endl;
  cout << "b(10) = " << b.evaluate(10) << endl;
  cout << "b(-1) = " << b.evaluate(-1) << endl;
  cout << "b(-3) = " << b.evaluate(-3) << endl << endl;
  
  // Through the Polynomial sum, I show that the add() function works
  // creating a polynomial that can be used in both the evaluate()
  // and the degree() function, retrieving correct answers

  cout << "Adding a and b ... " << endl << endl;

  Polynomial sum = b.add(a);
  
  cout << "a(x) + b(x) = " << sum << endl;
  cout << "The sum has degree " << sum.degree() << endl;
  cout << "sum(1) = " << sum.evaluate(1) << endl << endl;

  cout << "Subtracting b from a ... " << endl << endl;

  //Through the Polynomial diff and diff2, I show that subtract()
  // funciton creates a polynomial that can also be used within other 
  // functions within the class

  Polynomial diff = a.subtract(b);

  cout << "a(x) - b(x) = " << diff << endl;
  cout << "The difference has a degree of " << diff.degree() << endl;
  cout << "diff(0) = " << sum.evaluate(0) << endl << endl;

  cout << "Subtracting a from b ... " << endl << endl;

  Polynomial diff2 = b.subtract(a);

  cout << "b(x) - a(x) = " << diff2 << endl;
  cout << "This difference has a degree of " << diff2.degree() << endl << endl;

  cout << "Multiplying a times b .... " << endl << endl;

  // Through the Polynomial product class, I show that multoply()
  // creates a correct(unsimplified) answer that works with other
  // class functions.

  Polynomial product = a.multiply(b);
  
  cout << "a(x)*b(x) = " << product << endl;
  cout << "prod(2) = " << product.evaluate(2) << endl << endl;

  // Through the use of the add/subtract/multiply methods, I showed
  // that my overload= operator is working.

  // Through the use of the sout << polynomial lines, I showed that
  // my overload operator<< is working properly

  // PROBLEMS: The add function did not add repeat Nodes correctly, resulting in 
  // equations that were not simplified for both add and multiply


  return 0;
}
  
