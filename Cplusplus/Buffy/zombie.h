/************************************************                              
 ** File:     zombie.h                                        
 ** Project:  Cmsc 202 Project 4, Fall 2015                                    
 ** Author:   Brianna Richardson                                               
 ** Date:     11/19/2015                                                       
 ** Section:  0104                                                             
 ** Email:    bricha2@gl.umbc.edu                                              
 ** 
 **
 ** Header file for the Zombie class
 **
 **
 ***********************************************/

#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_
#include "character.h"

using namespace std;

class Zombie : public Character {

public:
  Zombie();
  ~Zombie();

  //-------------------------------------------------------
  // Name: enounter
  // PreCondition:  Pointer to object it encounters
  // PostCondition: Returns Nothing, bites the pointer object
  //---------------------------------------------------------
  void encounter(Character *ptr); 

  //-------------------------------------------------------
  // Name: biteMe
  // PreCondition:  Pointer of type with whatever bit it
  // PostCondition: Returns nothing, does nothing
  //---------------------------------------------------------
  void biteMe(Character *ptr); 

  //-------------------------------------------------------
  // Name: morph
  // PreCondition:  Nothing
  // PostCondition: Returns Human if cured and not dead
  //---------------------------------------------------------
  Character *morph();

  //-------------------------------------------------------
  // Name: cureMe
  // PreCondition:  Nothing
  // PostCondition: Returns nothing, turns human if cured
  //---------------------------------------------------------
  void cureMe();

  //-------------------------------------------------------
  // Name: hitMe
  // PreCondition:  nothing
  // PostCondition: Returns nothing, dies if hit 3 times
  //---------------------------------------------------------
  void hitMe();

  //-------------------------------------------------------
  // Name: identify
  // PreCondition:  Nothing
  // PostCondition: Returns string with Zombie and ID number
  //---------------------------------------------------------
  string identify();
 private:
  // counter for number of hits
  int m_hit;
  // pointer for type Zombie will turn into
  Character* newChar;
  // boolean for if Zombie is cured
  bool m_cured;
};
#endif
