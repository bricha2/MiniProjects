/************************************************                              
  ** File:     human.h                                                         
  ** Project:  Cmsc 202 Project 4, Fall 2015                                   
  ** Author:   Brianna Richardson                                              
  ** Date:     11/19/2015                                                      
  ** Section:  0104                                                            
  ** Email:    bricha2@gl.umbc.edu                                             
  **                                                                           
  ** This is the implementation file for Buffy. It includes the virtual
  ** functions.
  **                                                                           
  **                                                                           
  ***********************************************/

#include <iostream>
#include <sstream>
using namespace std;

#include "buffy.h"

// Constructor
Buffy::Buffy() { //does nothing 
}

// Destructor
Buffy::~Buffy() { //does nothing
}

// encounter
// Buffy will hit anything she encounters
void Buffy::encounter(Character *ptr) { 
  ptr->hitMe();
  cout << identify() << " hits " << ptr->identify() << endl;
}

// morph
// Buffy cannot morph. So this returns nothing
Character *Buffy::morph() { 
  return NULL;
}

// biteMe
// Buffy cannnot be bit. So the ptr is deleted.
void Buffy::biteMe(Character *ptr) { 
  cout << "Missed me!" << endl;
  delete ptr;
}

// hitMe
// Buffy cannot be hit. 
void Buffy::hitMe() { //do nothing
}

// cureMe
// Buffy does not get sick.
// So she doesn't need to be cured.
void Buffy::cureMe() { 
}

// identify()
// Returns string with Buffy and
// and id number
string Buffy::identify() {
  ostringstream out;
  out << "Buffy #" << getId();
  return out.str();
}

