/************************************************                              
 ** File:     redshirt.cpp
 ** Project:  Cmsc 202 Project 4, Fall 2015                                    
 ** Author:   Brianna Richardson                                               
 ** Date:     11/19/2015                                                       
 ** Section:  0104                                                             
 ** Email:    bricha2@gl.umbc.edu                                              
 **                                                                            
 ** This is the implementation file for the RedShirt class
 **                                                                            
 **                                                                            
 **                                                                            
 ***********************************************/

#include <iostream>
#include <sstream>
using namespace std;

#include "redshirt.h"

//constructor
RedShirt::RedShirt() { 
  // does nothing
}

// destructor
RedShirt::~RedShirt() {
  // does nothing
}

// enounter
// Redshirt hits anything it encounters,
// method returns nothing
void RedShirt::encounter(Character *ptr) {
  ptr->hitMe();
  cout << identify() << " hits " << ptr->identify() << endl;
}

// morph
// RedShirt turns to nothing, so returns NULL 
Character *RedShirt::morph() { 
  return NULL;
}  

// biteMe
// RedShirt will die if bit.
void RedShirt::biteMe(Character *ptr) { 
  m_isDead = true;
  delete ptr;
}

//hitMe
// does nothing if hit
void RedShirt::hitMe() { 
  //does nothing
}

// cureMe
// does nothing if cured
void RedShirt::cureMe() {
  //does nothing
}  

//identify
// returns a string with RedShirt and id number
string RedShirt::identify() {
  ostringstream out;
  out << "RedShirt #" << getId();
  return out.str();
}

// migrates()
// does nothing migrate
bool RedShirt::migrates() { 
  return false;
}

