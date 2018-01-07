/************************************************                              
 ** File:     vampire.cpp
 ** Project:  Cmsc 202 Project 4, Fall 2015                                    
 ** Author:   Brianna Richardson                                               
 ** Date:     11/19/2015                                                       
 ** Section:  0104                                                             
 ** Email:    bricha2@gl.umbc.edu                                              
 **                                                                            
 ** Implementation file for the Vampire class
 **                                                                            
 **                                                                            
 **                                                                            
 ***********************************************/

#include <iostream>
#include <sstream>
using namespace std;

#include "vampire.h"

// constructor
Vampire::Vampire() {
  m_hit = 0;
}

//destructor
Vampire::~Vampire() {
}

// encounter
// Vampires will bite what they encounter
void Vampire::encounter(Character *ptr) { 
  // New Pointer for biteMe of class which it bites
  Vampire* newV = new Vampire();
  ptr->biteMe(newV);
  cout << identify() << " bites " << ptr->identify() << endl;
}

//biteMe
// Vampires can't be bitten, so nothing happens
void Vampire::biteMe(Character *ptr) { 
  delete ptr;
}

//morph
// Can't morph, so nothing happens
Character *Vampire::morph() { 
  return NULL;
}

// cureMe
// Vampires can't be cured, so nothing happens
void Vampire::cureMe() {
  //do nothing
}

//hitMe
// if hit three times, it will die
void Vampire::hitMe() { 
  // increase number of hits
  m_hit+=1;

  //if hits == 3, die
  if (m_hit == 3)
    m_isDead = true;
}

//identify()
//returns string with Vampire and ID number
string Vampire::identify() {
  ostringstream out;
  out << "Vampire #" << getId();
  return out.str();
}

