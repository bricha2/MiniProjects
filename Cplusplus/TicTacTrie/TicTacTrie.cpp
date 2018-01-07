/*****************************************
 ** File:    TicTacTrie.cpp
 ** Project: CMSC 341 Project 2, Spring 2016
 ** Author:  Brianna Richardson
 ** Date:    3/20/16
 ** Section: 01
 ** E-mail:  bricha2@umbc.edu 
 **
 **   This file contains the implementation for the TicTacTrie class.
 ** This file utilizes recursion to add TicTacToes to a specified TicTacTrie.
 ** 
 ** 
 **
 **
   ***********************************************/
#include <iostream>
#include <vector>

using namespace std;

#include "TicTacTrie.h"
#include "TicTacNode.h"
#include "TicTacToe.h"

// default constructor
// sets everything to NULL or 0
TicTacTrie::TicTacTrie() {
  m_xWins = 0;
  m_oWins = 0;
  m_draws = 0;
  m_size = 0;
  root = NULL;
  trieCursor = NULL;
  childrenLookedAt = 0;
}

// Destructor, calls bootstrap
TicTacTrie::~TicTacTrie() {
  makeEmpty();
}

// Bootstrap makeEmpty, calls MakeEmpty
void TicTacTrie::makeEmpty() {
  makeEmpty(root);
}

// makeEMpty, accepts a node
// delets all nodes
void TicTacTrie::makeEmpty(TicTacNode *& t) {
  if (t != NULL) {
    for (unsigned int i = 0; i < t->m_children.size(); i++) {
      makeEmpty(t->m_children.at(i));
      delete t;
    }
  }
  t = NULL;
}

// retuns xWins
int TicTacTrie::getxWins() const { return m_xWins; }

// returns oWins
int TicTacTrie::getoWins() const { return m_oWins; }

// returns draws
int TicTacTrie::getDraws() const { return m_draws; }

//returns size
int TicTacTrie::getSize() const { return m_size; }

// adds a TicTacToe to the trie through recursion
// works as a bootstrap
void TicTacTrie::addGame(TicTacToe t) {

  // first gets the result of that TicTacToe
  int results = t.getResults();
  if (results == 1) {
    m_xWins++;
  } else if (results == 2) {
    m_oWins++;
  } else if (results == 3) {
    m_draws++;
  }

  // Then gets the head of the linked list 
  // and calls the recursive function
  TicTacNode* m_head = t.getHead();
  TicTacNode* prevNode = new TicTacNode();
  prevNode = NULL;

  addNode(root, m_head, prevNode);
  return;
}

//addNode
// recursive function
void TicTacTrie::addNode(TicTacNode * & trieNode, TicTacNode * & toeNode, 
			 TicTacNode * & prevNode) {

  if (toeNode == NULL)
    return;

  // If the Trie is empty, add the head node of the linked list
  // and then recurse through the linked list
  if (trieNode == NULL) {
    TicTacNode* newNode = new TicTacNode(toeNode->m_board);
    root = newNode;
    TicTacNode* toeCursor = toeNode->next;
    trieCursor = root;  
    m_size = 2;

    // while the toeCursor is not at the end of
    // the linked list, add nodes from the linked list
    while (toeCursor->next != NULL) {
      TicTacNode* newNode = new TicTacNode(toeCursor->m_board);
      trieCursor->m_children.push_back(newNode);
      toeCursor = toeCursor->next;
      trieCursor = trieCursor->m_children[0];
      m_size++;
    }

    return;
    
  // If the board in the trie's node is the same as the board
  // in the toe's node
  }  else if (*trieNode == *toeNode) {

    // if the trieNode has children look through the children and
    // compare them
    if (trieNode->getNumOfChildren() > 0) {

      if (toeNode->next != NULL) {
	
	bool called = false;
	for (int i = 0; i < trieNode->getNumOfChildren(); i++) {
	  
	  if (*trieNode->m_children[i] == *toeNode->next) {
	    childrenLookedAt = i+1;
	    called = true;
	    addNode(trieNode->m_children[i], toeNode->next, trieNode);
	    break;
	  }
	}
	
	// if none of the children matched, add in the node
	// to the parent that called it
	if (!called) {
	  TicTacNode* newNode = new TicTacNode(toeNode->next->m_board);
	  m_size++;
	  trieNode->m_children.push_back(newNode);

	  // as long as there are nodes in the linked list
	  // add all the nodes
	  if (toeNode->next->next != NULL) {
	    TicTacNode* toeCursor = toeNode->next->next;
	    trieCursor = newNode;
	    
	    while (toeCursor != NULL) {
	      TicTacNode* newNode = new TicTacNode(toeCursor->m_board);
	      trieCursor->m_children.push_back(newNode);
	      toeCursor = toeCursor->next;
	      trieCursor = trieCursor->m_children[0];
	      m_size++;
	    }
	  }
	}
      }

      // if the trieNode has no children and it's the same
      // as the linked list, traverse through the rest
      // of the linked list and add it
    } else if (toeNode->next != NULL) {
      TicTacNode* newNode = new TicTacNode(toeNode->next->m_board);
      m_size++;
      trieNode->m_children.push_back(newNode);
      if (toeNode->next->next!= NULL) {
	TicTacNode* toeCursor = toeNode->next->next;
	trieCursor = newNode;
	
	while (toeCursor != NULL) {
	  TicTacNode* newNode = new TicTacNode(toeCursor->m_board);
	  trieCursor->m_children.push_back(newNode);
	  toeCursor = toeCursor->next;
	  trieCursor = trieCursor->m_children[0];
	  m_size++;
	}
      } 
      return;
    }
  } else {
    return;
  }
}   




