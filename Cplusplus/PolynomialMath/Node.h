#ifndef NODE_H
#define NODE_H

using namespace std;

// Do not change any part of this file

// See documentation in Project 3 description.

class Node {

 public:

  Node();
  Node(long coeff, unsigned int deg);
  
  long m_coefficient;
  unsigned int m_degree;
  Node *m_next;
};

#endif
