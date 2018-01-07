/*****************************************                                                                                                                                           
 ** File:    Node.cpp 
 ** Project: CMSC 202 Project 3, Fall 2015
 ** Author:  Brianna Richardson
 ** Date:    10/30/15
 ** Section: 0104
 ** E-mail:  bricha2@gl.umbc.edu
 **
 **   This file contains the implementation for the Node class in Project 3.
 ** This program consists of two constructors, one of which takes in two 
 ** parameters. Both constructors set m_next value to NULL.
 **                                                                                                                                                                                  
 **                                                                                                                                                                                  
 ***********************************************/



#include <cstring>
using namespace std;
#include "Node.h"

Node::Node() {
  m_next = NULL;
}

Node::Node(long coeff, unsigned int deg) {
  m_coefficient = coeff;
  m_degree = deg;
  m_next = NULL;
}
