/************************************************                  
 ** File:     vampire.h                           
 ** Project:  Cmsc 202 Project 4, Fall 2015                
 ** Author:   Brianna Richardson                    
 ** Date:     11/19/2015                                 
 ** Section:  0104                                                    
 ** Email:    bricha2@gl.umbc.edu                       
 **
 ** Header file for the Vampire class.
 **
 ***********************************************/

#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_
#include "character.h"

using namespace std;

class Vampire : public Character {

public:
  Vampire();
  ~Vampire();

  //-------------------------------------------------------
  // Name: encounter
  // PreCondition:  pointer of type it's encountering
  // PostCondition: Returns nothing, bites the object it encounters
  //---------------------------------------------------------
  void encounter(Character *ptr);

  //-------------------------------------------------------
  // Name: biteMe
  // PreCondition:  pointer of type which bit it
  // PostCondition: Does nothing if bit
  //---------------------------------------------------------
  void biteMe(Character *ptr);

  //-------------------------------------------------------
  // Name: morph
  // PreCondition:  Nothing
  // PostCondition: Does not morph, returns NULL
  //---------------------------------------------------------
  Character *morph();

  //-------------------------------------------------------
  // Name: cureMe
  // PreCondition:  nothing
  // PostCondition: Returns nothing, can't be cured
  //---------------------------------------------------------
  void cureMe();

  //-------------------------------------------------------
  // Name: hitMe
  // PreCondition:  Nothing
  // PostCondition: Returns nothing, if bit 3 times, dies
  //---------------------------------------------------------
  void hitMe();

  //-------------------------------------------------------
  // Name: idnetify
  // PreCondition:  Nothing
  // PostCondition: Returns string with Vampire and id number
  //---------------------------------------------------------
  string identify();
 private:
  // counts number of times hit
  int m_hit;
};
#endif
