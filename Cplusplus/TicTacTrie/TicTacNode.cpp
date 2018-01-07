/*****************************************
 ** File:    TicTacNode.cpp
 ** Project: CMSC 341 Project 2, Spring 2016
 ** Author:  Brianna Richardson
 ** Date:    3/20/16
 ** Section: 01
 ** E-mail:  bricha2@umbc.edu 
 **
 **   This file contains the implementation for the TicTacNode class.
 ** 
 ** 
 ** 
 **
 **
 ***********************************************/
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

#include "TicTacNode.h"

// default constructor, sets everything to NULL, if need be
TicTacNode::TicTacNode() {
  next = NULL;
  int count = 1;
  while (count < 10) {
    m_board[count] = '-';
    count = count + 1;
  }
}

// TicTacNode destructor
TicTacNode::~TicTacNode() {
  for (unsigned int i = 0; i < m_children.size(); i++) {
    delete m_children[i];
    m_children[i] = NULL;
  }

  m_children.clear();
  next = NULL;
}

// nondefault constructor, accepts a board
// sets everything to NULL and copies the board
TicTacNode::TicTacNode(map<int, char> board) {
  m_board = board;
  next = NULL;
}


//overloaded comparison ==
bool TicTacNode::operator==(const TicTacNode& theNode) {
  
  bool isEqual = true;

  for (int i = 1; i < 10; i ++) {
    if (!(m_board.at(i) == theNode.m_board.at(i)))
      isEqual = false;
  }

  return isEqual;

}

//overload assignment =
const TicTacNode& TicTacNode::operator= (const TicTacNode& theNode) {

  if (!(this == &theNode)) {
    m_board = theNode.m_board;
    next = NULL;
    return *this;
  }
  return *this;
}

// getNumOfChildren
// returns the number of children
int TicTacNode::getNumOfChildren() const { return m_children.size(); }

// << overloard Operator
ostream& operator<<(ostream& sout, const TicTacNode& theNode) {
  sout << theNode.m_board.at(1) << theNode.m_board.at(2) << theNode.m_board.at(3) << endl;
  sout << theNode.m_board.at(4) << theNode.m_board.at(5) << theNode.m_board.at(6) << endl;  
  sout << theNode.m_board.at(7) << theNode.m_board.at(8) << theNode.m_board.at(9) << endl;
  return sout;
}

