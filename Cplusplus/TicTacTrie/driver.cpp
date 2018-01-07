/*****************************************
 ** File:    driver.cpp
 ** Project: CMSC 341 Project 2, Spring 2016
 ** Author:  Brianna Richardson
 ** Date:    3/20/16
 ** Section: 01
 ** E-mail:  bricha2@umbc.edu 
 **
 **   This file contains the main clss for Project 2.
 ** This file accepts a document as a command line argument,
 ** reads in the filenames, and adds them to TicTacTrie. It also
 ** outputs the results of that game and the final board. It
 ** also outputs the final statistics.
 **
 ***********************************************/

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "TicTacTrie.h"
#include "TicTacToe.h"
#include "TicTacNode.h"

int main(int argc, char *argv[]) {
  if (argc != 2)
    cout << "usage: " << argv[0] << " <FILENAME> \n";
  else {
    ifstream infile;
    string filename = argv[1];
    infile.open(filename.c_str()); //, ios_base::in);
    
    // If the file doesn't exist, say so
    if(infile.fail()) {
      cout << "The File was not successfully opened." << endl;
      exit(1);
    }

    TicTacTrie* test = new TicTacTrie();

    while (!infile.eof()) {
      string line;

      infile >> line;

      TicTacToe* thisLine = new TicTacToe();

      thisLine->readGame(line);      
      //  test->addGame(*thisLine);

      cout << "============================" << endl;
      cout << "Reading: " << line << endl;
      cout << "============================" << endl;
      if (thisLine->getResults() == 0) {
	cout << "This Game didn't end!" << endl;
	continue;
      } else if (thisLine->getResults() == 1) {
	cout << "Player X wins!" << endl;
	
      } else if (thisLine->getResults() == 2) {
	cout << "Player O wins! " << endl;

      } else if (thisLine->getResults() == 3) {
	cout << "The game was a draw!" << endl;
      }

      TicTacNode* tail = thisLine->getTail();
      

      cout << "Game Board: " << endl;
      cout << *tail << endl;
      //      cout <<tail->m_board[1]<<tail->m_board[2]<<tail->m_board[3] << endl;
      //      cout <<tail->m_board[4]<<tail->m_board[5]<<tail->m_board[6] << endl;
      //      cout <<tail->m_board[7]<<tail->m_board[8]<<tail->m_board[9] << endl;
      //      cout << endl;

      test->addGame(*thisLine);

    }

    cout << "Final Trie Statistics" << endl;
    cout << "============================" << endl;
    cout << "Player X Wins: " << test->getxWins() << endl;
    cout << "Player O Wins: " << test->getoWins() << endl;
    cout << "Draws: " << test->getDraws() << endl;
    cout << "Trie Size: " << test->getSize() << endl;
    
    
  }
  
  
}
