/*****************************************
 ** File:    TicTacTrie.h
 ** Project: CMSC 341 Project 2, Spring 2016
 ** Author:  Brianna Richardson
 ** Date:    3/20/16
 ** Section: 01
 ** E-mail:  bricha2@umbc.edu 
 **
 **   This file contains the definition for the TicTacTrie class.
 ** 
 ** 
 ** 
 **
 **
 ***********************************************/
#ifndef TICTACTRIE_H_
#define TICTACTRIE_H_
#include <iostream>
#include <vector>

using namespace std;

#include "TicTacToe.h"
#include "TicTacNode.h"

class TicTacTrie {
 public:
  //-------------------------------------------------------
  // Name: constructor, default
  // PreCondition:  none
  // PostCondition: standardizes the member variables
  //---------------------------------------------------------
  TicTacTrie();

  //-------------------------------------------------------
  // Name: destructor
  // PreCondition:  none
  // PostCondition: deletes the linked list
  //---------------------------------------------------------
  ~TicTacTrie();

  //-------------------------------------------------------
  // Name: makeEmpty
  // PreCondition:  none
  // PostCondition: recursive function to remove nodes
  //---------------------------------------------------------
  void makeEmpty();

  //-------------------------------------------------------
  // Name: getxWins
  // PreCondition:  none
  // PostCondition: Returns how many games X won
  //---------------------------------------------------------
  int getxWins() const;

  //-------------------------------------------------------
  // Name: getoWins
  // PreCondition:  none
  // PostCondition: Returns how many games O won
  //---------------------------------------------------------
  int getoWins() const;

  //-------------------------------------------------------
  // Name: getDraws
  // PreCondition: none
  // PostCondition: Returns the number of draws
  //---------------------------------------------------------
  int getDraws() const;

  //-------------------------------------------------------
  // Name: getSize
  // PreCondition:  none
  // PostCondition: Returns the size of the trie
  //---------------------------------------------------------
  int getSize() const;

  // bootstrap
  void addGame(TicTacToe t);

  // recursive function
  void addNode(TicTacNode * & trieNode, TicTacNode * & toeNode,
	       TicTacNode * & prevNode);


 private:
  // number of times Player X has won
  int m_xWins;

  // number of times Player O has won
  int m_oWins;

  // number of times the game resulted in a draw
  int m_draws;

  // current number of nodes in the tree
  int m_size;

  // Pointer to the root of the trie
  TicTacNode* root;

  // Pointer for the cursor
  TicTacNode* trieCursor;

  // Used for emptying the tree
  void makeEmpty(TicTacNode *& t);

  // counter for adding Nodes
  int childrenLookedAt;

};

#endif
