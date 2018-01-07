/*****************************************
 ** File:    proj4.cpp
 ** Project: CMSC 202 Project 4, Fall 2015
 ** Author:  Brianna Richardson
 ** Date:    11/19/15
 ** Section: 0104
 ** E-mail:  bricha2@gl.umbc.edu 
 **
 **   This is the main file to prove all functions work.
 ** All functions were tested and work!
 **
 ***********************************************/

#include <iostream>
using namespace std ;

#include "character.h"
#include "ghost.h"
#include "human.h"
#include "zombie.h"
#include "doctor.h"
#include "buffy.h"
#include "redshirt.h"
#include "vampire.h"

#include "game.h"

int main() {  

   bool map[] = { 
         // Room  0  1  2  3  4  5  6  7  8
                  0, 1, 0, 1, 0, 0, 0, 0, 0,   // Room 0
                  1, 0, 1, 0, 1, 0, 0, 0, 0,   // Room 1
                  0, 1, 0, 0, 0, 1, 0, 0, 0,   // Room 2
                  1, 0, 0, 0, 1, 0, 1, 0, 0,   // Room 3
                  0, 1, 0, 1, 0, 1, 0, 1, 0,   // Room 4
                  0, 0, 1, 0, 1, 0, 0, 0, 1,   // Room 5
                  0, 0, 0, 1, 0, 0, 0, 1, 0,   // Room 6
                  0, 0, 0, 0, 1, 0, 1, 0, 1,   // Room 7
                  0, 0, 0, 0, 0, 1, 0, 1, 0    // Room 8
                } ;

   /*

   Room connections in ASCII art:

                0 ---- 1 --- 2
                |      |     |
                3 ---- 4 --- 5
                |      |     |
                6 ---- 7 --- 8

   */




   Game G(9, map, 1234) ;

   // Add humans
   G.addToRoom(1, new Human());
   G.addToRoom(2, new Human());
   G.addToRoom(2, new Human());
   G.addToRoom(2, new Human());
   G.addToRoom(4, new Human());
   G.addToRoom(4, new Human());
   G.addToRoom(4, new Human());
   G.addToRoom(4, new Human());
   G.addToRoom(8, new Human());

   // Add zombies
   G.addToRoom(1,new Zombie()) ;
   G.addToRoom(1,new Zombie()) ;
   G.addToRoom(7,new Zombie()) ;
   G.addToRoom(8,new Zombie()) ;

   // Add Doctors
   G.addToRoom(3, new Doctor());
   G.addToRoom(3, new Doctor());
   G.addToRoom(3, new Doctor());
   G.addToRoom(7, new Doctor());
   G.addToRoom(7, new Doctor());
   G.addToRoom(7, new Doctor());
   G.addToRoom(8, new Doctor());

   // Add Buffy
   G.addToRoom(5,new Buffy()) ;
   G.addToRoom(5,new Buffy()) ;
   G.addToRoom(5,new Buffy()) ;
   G.addToRoom(8,new Buffy()) ;

   // Add Vampire
   G.addToRoom(4,new Vampire()) ;
   G.addToRoom(4,new Vampire()) ;
   G.addToRoom(7,new Vampire()) ;
   G.addToRoom(8,new Vampire()) ;
   
   // Add RedShirt
   G.addToRoom(2, new RedShirt()) ;
   G.addToRoom(4, new RedShirt()) ;
   G.addToRoom(5, new RedShirt()) ;
   G.addToRoom(5, new RedShirt()) ;
   G.addToRoom(6, new RedShirt()) ;
   G.addToRoom(7, new RedShirt()) ;
   G.addToRoom(8, new RedShirt()) ;

   // Add Ghosts
   G.addToRoom(6, new Ghost());
   G.addToRoom(6, new Ghost());
   G.addToRoom(6, new Ghost());
   G.addToRoom(6, new Ghost());
   G.addToRoom(8, new Ghost());

   G.display() ;
   // Check Rooms:
   //   Room 0: Empty
   //   Room 1: 2 zombies, 1 human
   //   Room 2: 3 Humans, 1 redShirt
   //   Room 3: 3 doctors
   //   Room 4: 4 Humans, 1 RedShirt, 2 vampires
   //   Room 5: 2 Redshirts, 3 Buffys
   //   Room 6: 4 Ghosts, 1 RedShirt
   //   Room 7: 3 Doctors, Zombie, Vampire, RedShirt
   //   Room 8: RedShirt, Vampire, Ghost, Zombie, Human, Doctor, Buffy
   // CORRECT

   // Cycle through 20 rounds of the game
   for (int i=0 ; i < 20 ; i++) {

      cout << "***********************************\n" ;
      cout << "Begin Round #" << i << ":\n" ;
      cout << "***********************************\n" ;

      G.playOneTurn() ;

      cout << "----------------------------------\n" ;
      cout << "Characters in each room:\n" ;
      cout << "----------------------------------\n" ;
      G.display() ;
      cout << "----------------------------------\n" ;
   }
   // WORKS CORRECTLY

   cout << "Goodbye!\n" ;
   
   return 0;
}

// Valgrind works with any number of rounds in the game,
// Therefore, the destructors are working.
