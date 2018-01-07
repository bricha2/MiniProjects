/************************************************
 ** File:     human.h
 ** Project:  Cmsc 202 Project 4, Fall 2015
 ** Author:   Brianna Richardson
 ** Date:     11/19/2015
 ** Section:  0104
 ** Email:    bricha2@gl.umbc.edu 
 ** 
 ** This is the header file for the Human class.
 **
 **
 **
 ***********************************************/


#ifndef _HUMAN_H_
#define _HUMAN_H_
#include "character.h"

using namespace std;

class Human : public Character {

 public:

  Human();
  ~Human();

  //-------------------------------------------------------
  // Name: encounter
  // PreCondition:  pointer to the object it's interacting with
  // PostCondition: returns nothing
  //---------------------------------------------------------
  void encounter(Character *ptr); 

  //-------------------------------------------------------
  // Name: morph
  // PreCondition:  nothing
  // PostCondition: returns a new instance of the character which bit it
  //---------------------------------------------------------
  Character *morph(); 

  //-------------------------------------------------------
  // Name: biteMe
  // PreCondition:  the radius is greater than zero
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
  // PreCondition:  returns nothing
  // PostCondition: stops human from morphing if it was
  //---------------------------------------------------------
  void cureMe(); 

  //-------------------------------------------------------
  // Name: identify
  // PreCondition:  nothing
  // PostCondition: Returns a string with Human and id number
  //---------------------------------------------------------
  string identify();

 private:
  // a pointer whatever bit it
  Character* newChar;
  // boolean for if the person was bit
  bool m_turning;
  // how long since human was bit
  int m_stepsTillTurn;
};
#endif
