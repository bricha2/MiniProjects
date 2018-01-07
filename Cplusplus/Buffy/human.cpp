/************************************************
 ** File:     human.cpp
 ** Project: CMSC 202 Project 4, Fall 2015
 ** Author: Brianna RIchardson
 ** Date: 11/19/2015
 ** Section 0104
 ** Email: bricha2@gl.umbc.edi
 **
 ** This file contains the implementation for the Human Class
 **
 ***********************************************/

#include <iostream>
#include <sstream>
using namespace std;

#include "human.h"

// constructor changes private variables
Human::Human() {
  newChar = NULL;
  m_turning = false;
  m_stepsTillTurn = 0;
}

// destructor gets rid of pointer
Human::~Human() {
  if (newChar != NULL)
    delete newChar;
}

// encounter
// human does nothing but count up
void Human::encounter(Character *ptr) {
  cout << identify() << " does nothing." << endl;

  // if the human has been bit, add and additional turn
  if (m_turning) {
    m_stepsTillTurn += 1;
  }

}

// biteMe
// human turns into whatever bit it after 3 turns
void Human::biteMe(Character *ptr) { 

  //if human has not already been bit, begin process
  if (!m_turning) {
    m_turning = true;
    newChar = ptr;
    
    // or delete the ptr
  } else {
    delete ptr;
  }

}

// morph
// returns pointer to the object that bit it
Character *Human::morph(){ 
  if (m_stepsTillTurn == 3) {
    cout << identify() << " turns into " << newChar->identify() << endl;
    return newChar;
  }

  return NULL;

}

// cureMe
// Human can be cured if it was bitten
void Human::cureMe(){ 

  //if the human has been bitten, stop the process
  if(m_turning) {
    m_turning = false;
    m_stepsTillTurn = 0;
    delete newChar;
    newChar = NULL;
  }

}

//hitMe
// humans can't be hit.
void Human::hitMe(){ 
}

//identify()
// returns string with Human and id Number
string Human::identify(){
  ostringstream out;
  out <<  "Human #" << getId();
  return out.str();
}

