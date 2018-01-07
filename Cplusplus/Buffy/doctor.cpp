/************************************************           
** File:     doctor.cpp
** Project:  Cmsc 202 Project 4, Fall 2015                                     
** Author:   Brianna Richardson                                                
** Date:     11/19/2015                                                        
** Section:  0104                                                              
** Email:    bricha2@gl.umbc.edu                                               
**                                                                             
**                                                                             
** The implementation file for the Doctor class.
**                                                                             
**                                                                             
***********************************************/

#include <iostream>
#include <sstream>
using namespace std;

#include "doctor.h"

// constructor changes select private variables
Doctor::Doctor() {
  newChar = NULL;
  m_turning = false;
  m_stepsTillTurn = 0;
}

// Destructor gets rid of pointer value
Doctor::~Doctor() {
  if (newChar != NULL)
    delete newChar;
}

// encounter
// Doctor will cure whatever it encounters
void Doctor::encounter(Character *ptr) {
  cout << identify() << " cures " << ptr->identify() << endl;

  // if doctor has been bit, increase the number of steps
  if (m_turning) {
    m_stepsTillTurn += 1;
  }

  // call the CureMe of the object cured.
  ptr->cureMe();
}

// biteMe
// Doctor gets bit, and cycle begins
void Doctor::biteMe(Character *ptr) {

  //if doctor has not already been bit, begin process
  if (!m_turning) {
    m_turning = true;
    newChar = ptr;
    
  // if doctor has been bit, get rid of pointer
  } else {
    delete ptr;
  }

}
//morph
//will morph into whatever bit it after 3 cycles
Character *Doctor::morph() { 

  // if it has been three cycles, turn
  if (m_stepsTillTurn == 3) {
    cout << identify() << " turns into " << newChar->identify() << endl;
    return newChar;
  }

  return NULL;

}

// cureMe
// Doctor gets cured if bitten
void Doctor::cureMe() {

  //if the human has been bitten, stop the process
  if(m_turning) {
    m_turning = false;
    m_stepsTillTurn = 0;
    delete newChar;
    newChar = NULL;
  }

}

// hitMe()
// Doctor can't be hit
void Doctor::hitMe(){ 
}

// identify()
// returns string with Doctor and id number
string Doctor::identify(){
  ostringstream out;
  out <<  "Doctor #" << getId();
  return out.str();
}

