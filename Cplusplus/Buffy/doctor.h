/************************************************                
 ** File:     doctor.h                                                         
 ** Project:  Cmsc 202 Project 4, Fall 2015                                    
 ** Author:   Brianna Richardson                                               
 ** Date:     11/19/2015                                                       
 ** Section:  0104                                                             
 ** Email:    bricha2@gl.umbc.edu                                              
 **                                                                            
 ** This is the header file for the Doctor class.                              
 **                                                                            
 **                                                                            
 ***********************************************/

#ifndef _DOCTOR_H_
#define _DOCTOR_H_
#include "character.h"

using namespace std;

class Doctor : public Character {

 public:

  Doctor();
  ~Doctor();

  //-------------------------------------------------------
  // Name: encounter
  // PreCondition:  Character encountering doctor
  // PostCondition: returns nothing
  //---------------------------------------------------------
  void encounter(Character *ptr); 

  //-------------------------------------------------------
  // Name: morph
  // PreCondition:  nothing
  // PostCondition: returns the character which bit it 
  //---------------------------------------------------------
  Character *morph(); 

  //-------------------------------------------------------
  // Name: biteMe
  // PreCondition:  new pointer to character which bit it
  // PostCondition: returns nothing
  //---------------------------------------------------------
  void biteMe(Character *ptr); 

  //-------------------------------------------------------
  // Name: hitMe
  // PreCondition:  nothing
  // PostCondition: returns nothing
  //---------------------------------------------------------
  void hitMe(); 

  //-------------------------------------------------------
  // Name: cureMe
  // PreCondition:  nothing
  // PostCondition: returns nothing
  //---------------------------------------------------------
  void cureMe(); 

  //-------------------------------------------------------
  // Name: identify
  // PreCondition:  nothing
  // PostCondition: returns string with Doctor and ID number
  //---------------------------------------------------------
  string identify();

 private:
  // pointer for when Doctor can be changed.
  Character* newChar;
  // counter once Doc is bit
  int m_stepsTillTurn;
  // boolean to determine if doc has been bit
  bool m_turning;
};
#endif
