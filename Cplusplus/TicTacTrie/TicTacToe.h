/*****************************************
 ** File:    TicTacToe.h
 ** Project: CMSC 341 Project 2, Spring 2016
 ** Author:  Brianna Richardson
 ** Date:    3/20/16
 ** Section: 01
 ** E-mail:  bricha2@umbc.edu 
 **
 **   This file contains the definition for the TicTacToe class.
 ** 
 ** 
 ** 
 **
 **
 ***********************************************/
#ifndef TICTACTOE_H_
#define TICTACTOE_H_
#include <iostream>
#include <vector>

using namespace std;

#include "TicTacNode.h"

class TicTacToe {
 public:

  //-------------------------------------------------------
  // Name: constructor, default
  // PreCondition:  none
  // PostCondition: standardizes the member variables
  //---------------------------------------------------------
  TicTacToe();

  //-------------------------------------------------------
  // Name: destructor
  // PreCondition:  none
  // PostCondition: deletes pointers
  //---------------------------------------------------------
  ~TicTacToe();
  
  //-------------------------------------------------------
  // Name: getIsOver
  // PreCondition:  none
  // PostCondition: Returns whether or not the game is over
  //---------------------------------------------------------
  bool getIsOver() const;

  //-------------------------------------------------------
  // Name: getResults
  // PreCondition:  none
  // PostCondition: Returns the winner
  //---------------------------------------------------------
  int getResults() const;

  //-------------------------------------------------------
  // Name: getSize
  // PreCondition:  none
  // PostCondition: Returns the size of the linked list
  //---------------------------------------------------------
  int getSize() const;

  //-------------------------------------------------------
  // Name: getHead
  // PreCondition:  none
  // PostCondition: Returns pointer to top node of linked list
  //---------------------------------------------------------
  TicTacNode* getHead() const;

  //-------------------------------------------------------
  // Name: getTail
  // PreCondition:  none
  // PostCondition: Returns pointer to the last node of linked list
  //---------------------------------------------------------
  TicTacNode* getTail() const;

  //-------------------------------------------------------
  // Name: readGame
  // PreCondition:  valid name of a file
  // PostCondition: makes a TicTacToe from it
  //---------------------------------------------------------
  void readGame(string fileName); 

 private:

  // boolean for whether or not the game in the file reached an end
  bool m_isOver;
 
  // an integer for the outcome of the game
  // 0 for not ended
  // 1 for Player X won
  // 2 for Player O won
  // 3 for draw
  int m_results;

  // pointer to head of the linked list
  TicTacNode* m_head;

  // pointer to the tail of the linked list
  TicTacNode* m_tail;

  // pointer to move down linked list
  TicTacNode* m_cursor;

  // int holds size of linked list
  int m_size;
  
};
  
#endif
