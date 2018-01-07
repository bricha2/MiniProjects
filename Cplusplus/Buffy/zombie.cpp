/************************************************   
 ** File:     zombie.cpp                     
 ** Project:  Cmsc 202 Project 4, Fall 2015                                    
 ** Author:   Brianna Richardson                                               
 ** Date:     11/19/2015                                                       
 ** Section:  0104                                                             
 ** Email:    bricha2@gl.umbc.edu                                              
 **                                                                            
 **  Implementation file for the Zombie class.
 **                                                                           
 **
 ******************************************/
 

#include <iostream>
#include <sstream>
using namespace std;

#include "zombie.h"
#include "human.h"

// Constructor sets private variables
Zombie::Zombie(){ 
  m_hit = 0;
  m_cured = false;
}
//destructor
Zombie::~Zombie(){ 
  //does nothing
}

//encounter
//Zombies will bite what they encounter
void Zombie::encounter(Character *ptr) { 
  // create a new Zombie pointer to give to 
  // the biteMe function of whatever was bit
  Zombie* newZ = new Zombie();
  ptr->biteMe(newZ);
  cout << identify() << " bites " << ptr->identify() << endl;
}
// biteMe
// if bitten, nothing happens
void Zombie::biteMe(Character *ptr){ 
  delete ptr;
}

//morph
//can turn into human if cured.
Character *Zombie::morph(){ 
  // if it has been cured and it's not dead
  // return the private pointer
  if (m_cured and !m_isDead) {
    cout << identify() << " turns into " << newChar->identify() << endl;
    return newChar;    
    
    // or return nothing
  }  else
    return NULL;
}

//cureMe
// can be cured by Doctor
void Zombie::cureMe(){ 
  // if it's not dead and it's not yet been cured
  if (!m_isDead and !m_cured) {
    // Cure it and reassign private pointer
    newChar = new Human();
    m_cured = true;
  }
}

// hitMe
// will die if hit 3 times
void Zombie::hitMe(){ 
  // increase number of hits
  m_hit += 1;
  
  // if hit three times, die
  if (m_hit == 3)
    m_isDead = true;
}

//identify()
//returns string with Zombie and ID number
string Zombie::identify(){
  ostringstream out;
  out <<  "Zombie #" << getId();
  return out.str();
}

