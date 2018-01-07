/************************************************                              
 ** File:     redshirt.h                           
 ** Project:  Cmsc 202 Project 4, Fall 2015                                    
 ** Author:   Brianna Richardson                                               
 ** Date:     11/19/2015                                                   
 ** Section:  0104                                                             
 ** Email:    bricha2@gl.umbc.edu                                              
 **                                                         
 ** This is the header file for RedShirt class
 **                                                          
 **                                                       
 **                                                
 ***********************************************/


#ifndef _REDSHIRT_H_
#define _REDSHIRT_H_
#include "character.h"

using namespace std;

class RedShirt : public Character {

 public:
  RedShirt();
  ~RedShirt();

  //-------------------------------------------------------
  // Name: encounter
  // PreCondition:  Character to which it is encountering
  // PostCondition: Returns nothing, interacts with parameter
  //---------------------------------------------------------
  void encounter(Character *ptr); 

  //-------------------------------------------------------
  // Name: morph
  // PreCondition:  Nothing
  // PostCondition: This returns NULL, redshirts can't morph
  //---------------------------------------------------------
  Character *morph(); 

  //-------------------------------------------------------
  // Name: biteMe
  // PreCondition:  Pointer to new character which bit
  // PostCondition: Returns nothing, does nothing also
  //---------------------------------------------------------
  void biteMe(Character *ptr); 

  //-------------------------------------------------------
  // Name: hitMe
  // PreCondition:  Nothing
  // PostCondition: Returns nothing, but Redshirt dies
  //---------------------------------------------------------
  void hitMe(); 

  //-------------------------------------------------------
  // Name: cureMe
  // PreCondition:  Nothing
  // PostCondition: Returns nothing, RedShirt can't be cured
  //---------------------------------------------------------
  void cureMe(); 

  //-------------------------------------------------------
  // Name: identify
  // PreCondition:  Nothing
  // PostCondition: Returns string with Redshirt and ID number
  //---------------------------------------------------------
  string identify();

  //-------------------------------------------------------
  // Name: migrates
  // PreCondition:  Nothing
  // PostCondition: Returns false, RedShirt can't migrate
  //---------------------------------------------------------
  bool migrates();
};
#endif
