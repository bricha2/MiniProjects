/*****************************************
 ** File:    TicTacToe.cpp
 ** Project: CMSC 341 Project 2, Spring 2016
 ** Author:  Brianna Richardson
 ** Date:    3/20/16
 ** Section: 01
 ** E-mail:  bricha2@umbc.edu 
 **
 **   This file contains the implementation for the TicTacToe class.
 ** Here is a Linked List that connects the plays in the game.
 ** It utilizes recursion, vectors and maps.
 ** 
 **
 **
 ***********************************************/
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <cstdlib>

using namespace std;

#include "TicTacToe.h"
#include "TicTacNode.h"

// default constructor
// sets everything to Null or 0
TicTacToe::TicTacToe() {
  m_isOver = false;
  m_results = 0;
  m_head = NULL;
  m_tail = NULL;
  m_cursor = NULL;
  m_size = 0;
}

// destructor
TicTacToe::~TicTacToe() {

  // Loop through each node in the linked list
  while (m_head != NULL) {

    // if there is only one node
    // point all nodes to NULL
    if (m_tail == m_head) {
      m_head = NULL;
      m_cursor = m_tail;
      delete m_cursor;
      m_cursor = NULL;
      m_tail = NULL;

      // if there are more than one node
      // only get rid of the first one and set
      // head equal to the second node
    } else {
      m_cursor = m_head;
      m_head = m_head -> next;
      m_cursor->next = NULL;
      delete m_cursor;
      m_cursor = NULL;
    }
  }   

}

// getIsOver, returns the m_isOver variable
bool TicTacToe::getIsOver() const { return m_isOver; }

// getResults, returns the results variable
int TicTacToe::getResults() const { return m_results; }

// getHead, returns pointer to head of TicTacToe
TicTacNode* TicTacToe::getHead() const { return m_head; }

// getTail, returns pointer to tail of TicTacToe 
TicTacNode* TicTacToe::getTail() const { return m_tail; }

//getSize, returns size of the linked list
int TicTacToe::getSize() const { return m_size; }

// readGame
// brings in a file and makes a TicTacToe from it
void TicTacToe::readGame(string filename) {
  ifstream infile;
  infile.open(filename.c_str(), ios_base::in);

  // If the file isn't there, print out problem
  if(infile.fail()) {
    cout << "The file was not successfully opened." << endl;
    exit(1);
  }

  int count = 1;
  map<int, char> board;

  // while you're not at the end of the file
  while(!infile.eof()) {

    char getLetter;

    infile >> getLetter;

    // check to see what character the input is
    if (getLetter == 'X') {
      board[count] = 'X';
      count++;
    } else if (getLetter == 'O') {
      board[count] = 'O';
      count++;
    } else if (getLetter == '-') {
      board[count] = '-';
      count++;
    }
  
    // once you have 9 characters, make a node from them
    if (count == 10) {
      count = 1;
      TicTacNode* newNode = new TicTacNode(board);
      if (m_size == 0) {
	m_head = newNode;
	m_tail = newNode;
      } else {
	m_tail->next = newNode;
	m_tail = newNode;
      }
      
      m_size++;
    }      
  }

  m_isOver = true;
  char winner;

  // Check to see what type of win it is based on the
  // last node's board
  if ((m_tail->m_board[1] == m_tail->m_board[5]) && 
      (m_tail->m_board[1] == m_tail->m_board[9])) {
    winner = m_tail->m_board[1];
  } else if ((m_tail->m_board[3] == m_tail->m_board[5]) && 
	     (m_tail->m_board[3] == m_tail->m_board[7])) {
    winner = m_tail->m_board[3];
  } else if ((m_tail->m_board[1] == m_tail->m_board[2]) && 
	     (m_tail->m_board[1] == m_tail->m_board[3])) {
    winner = m_tail->m_board[1];
  } else if ((m_tail->m_board[4] == m_tail->m_board[5]) &&
	     (m_tail->m_board[4] == m_tail->m_board[6])) {
    winner = m_tail->m_board[4];
  } else if ((m_tail->m_board[7] == m_tail->m_board[8]) && 
	     (m_tail->m_board[7] == m_tail->m_board[9])) {
    winner = m_tail->m_board[7];
  } else if ((m_tail->m_board[1] == m_tail->m_board[4]) && 
	     (m_tail->m_board[1] == m_tail->m_board[7])) {
    winner = m_tail->m_board[1];
  } else if ((m_tail->m_board[2] == m_tail->m_board[5]) && 
	     (m_tail->m_board[2] == m_tail->m_board[8])) {
    winner = m_tail->m_board[2];
  } else if ((m_tail->m_board[3] == m_tail->m_board[6]) &&
	     (m_tail->m_board[3] == m_tail->m_board[9])) {
    winner = m_tail->m_board[3];
  } else if ((m_tail->m_board[1] == '-') or (m_tail->m_board[2] == '-') or
	     (m_tail->m_board[3] == '-') or (m_tail->m_board[4] == '-') or
	     (m_tail->m_board[5] == '-') or (m_tail->m_board[6] == '-') or
	     (m_tail->m_board[7] == '-') or (m_tail->m_board[8] == '-') or
	     (m_tail->m_board[9] == '-')) {
    m_isOver = false;
    return;
    // if none of these, it is a draw
  } else {
    m_results = 3;
  }
  
  // decide the winner based on the characters
  if (winner == 'X')
    m_results = 1;
  else if (winner == 'O')
    m_results = 2;
  
  return;
}
