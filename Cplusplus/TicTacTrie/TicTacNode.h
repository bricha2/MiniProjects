/*****************************************
 ** File:    TicTacNode.h
 ** Project: CMSC 341 Project 2, Spring 2016
 ** Author:  Brianna Richardson
 ** Date:    3/20/16
 ** Section: 01
 ** E-mail:  bricha2@umbc.edu 
 **
 **   This file contains the definition for the TicTacNode class.
 ** 
 ** 
 ** 
 **
 **
 ***********************************************/
#ifndef TICTACNODE_H_
#define TICTACNODE_H_
#include <iostream>
#include <vector>
#include <map>
using namespace std;


class TicTacNode {
 public:

  //-------------------------------------------------------
  // Name: constructor, default
  // PreCondition:  none
  // PostCondition: standardized member variables
  //---------------------------------------------------------
  TicTacNode();

  //-------------------------------------------------------
  // Name: deconstructor
  // PreCondition:  none
  // PostCondition: deletes the pointers
  //---------------------------------------------------------
  ~TicTacNode();

  //-------------------------------------------------------
  // Name: constructor, non-default
  // PreCondition:  accepts a map of the board
  // PostCondition: creates an object
  //---------------------------------------------------------
  TicTacNode(map<int, char> board);

  //-------------------------------------------------------
  // Name: overlod == operator
  // PreCondition:  reference to a TicTacNode
  // PostCondition: Returns whether or not the nodes have same board
  //---------------------------------------------------------
  bool operator==(const TicTacNode& theNode);

  //-------------------------------------------------------
  // Name: overload = operator
  // PreCondition:  reference to a TicTacNode
  // PostCondition: Returns TicTacNode with same board
  //---------------------------------------------------------
  const TicTacNode& operator= (const TicTacNode& theNode);

  //-------------------------------------------------------
  // Name: getNumOfChildren
  // PreCondition:  none
  // PostCondition: Returns the number of children
  //---------------------------------------------------------
  int getNumOfChildren() const;

  //-------------------------------------------------------
  // Name: overload << operator
  // PreCondition:  the TicTacNode has a board
  // PostCondition: Returns ostream to be printed out
  //---------------------------------------------------------
  friend ostream& operator<<(ostream& sout, const TicTacNode& theNode);

  // vector to hold the pointers to the children of the node
  vector<TicTacNode*> m_children;
  // a map containing game board
  map<int, char> m_board;
  // next pointer for linked list
  TicTacNode* next;

};
  
#endif
