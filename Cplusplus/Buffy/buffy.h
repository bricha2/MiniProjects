/************************************************                              
 ** File:     buffy.h                                                          
 ** Project:  Cmsc 202 Project 4, Fall 2015                                    
 ** Author:   Brianna Richardson                                               
 ** Date:     11/19/2015                                                       
 ** Section:  0104                                                             
 ** Email:    bricha2@gl.umbc.edu                                              
 **
 ** This is the header file for the Buffy class
 **                                                                            
 ***********************************************/

#ifndef _BUFFY_H_
#define _BUFFY_H_
#include "character.h"

using namespace std;

class Buffy : public Character {

 public:
  Buffy();
  ~Buffy();
  //-------------------------------------------------------
  // Name: encounter
  // PreCondition:  the character receiving the action
  // PostCondition: Returns NULL
  //---------------------------------------------------------
  void encounter(Character *ptr); 
  
  //-------------------------------------------------------
  // Name: morph
  // PreCondition:  nothing
  // PostCondition: returns NULL
  //---------------------------------------------------------
  Character *morph(); 

  //-------------------------------------------------------
  // Name: biteMe
  // PreCondition:  the character given by the biter
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
  // PostCondition: returns a string with Buffy and ID number
  //---------------------------------------------------------
  string identify();
};
#endif
