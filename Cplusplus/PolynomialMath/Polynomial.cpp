/*****************************************x
 ** File:    Polynomial.cpp
 ** Project: CMSC 202 Project 3, Fall 2015
 ** Author:  Brianna Richardson
 ** Date:    10/30/15
 ** Section: 0104
 ** E-mail:  bricha2@gl.umbc.edu
 **
 **   This file contains the main implementation file for Project 3.
 ** This program manipulates the Polynomial class through different functions.
 ** Part of this code adds Polynomial classes, one subtracts, one multiplies,
 ** one adds a Node within a Polynomial class, and there are two overload
 ** operators.
 **
 **
 ***********************************************/

#include <iostream>
#include <cstring>

#include "Polynomial.h"
#include "Node.h"
#include <cmath>
#include <stdlib.h>

using namespace std;

// This constructor makes a dummy node.
Polynomial::Polynomial() {
  m_head = new Node(0,0);
}

Polynomial::Polynomial(const Polynomial& p) {
   
  Node* current;
  Node* next;

  // m_head is made to point to a new node
  m_head = new Node(0,0);

  // current pointer points to dummy and
  // next points to value after dummy in p
  current = m_head;
  next = p.m_head -> m_next;

  // while next points to a non null value,
  // identical Nodes from p are placed
  // in the new Polynomial.
  while(next != NULL) {
    current -> m_next = new Node();
    current = current -> m_next;
    current -> m_coefficient = next -> m_coefficient;
    current -> m_degree = next -> m_degree;
    next = next -> m_next;
  }

}

Polynomial::~Polynomial() {

  Node* current = m_head;
  Node* next;

  // while current points to a non null value,
  // next will be set equal to current's next,
  // and current will be removed.
  while (current != NULL) {
    next = current->m_next;
    delete(current);
    current = next;
  }

}

void Polynomial::insertMonomial(long coeff, unsigned int deg) {

  Node* current = m_head;
  
  // If the linked list is empty,
  // just add the new node after dummy.
  if (current->m_next == NULL) {
    Node* newNode = new Node(coeff, deg);
    current->m_next = newNode;
    return;
  }

  Node* next = current->m_next;
  
  // while next points to a non-Null value...
  while (next != NULL) {

    // if the degree from this object == degree 
    // given, print out a warning.
    if (current->m_degree == deg or next->m_degree == deg) {
      cout << "This degree already exists in this Polynomial!" << endl;
      return;
      
      // if the next degree in the list is less than degree given,
      // append this new node here.
    } else if ((next->m_degree) < deg) {
      Node* newNode = new Node(coeff, deg);
      current->m_next = newNode;
      current = current->m_next;
      current -> m_next = next;
      return;

      // if the next degree is greater, move on to 
      // next Node.
    } else {
      current = current->m_next;
      next = next -> m_next;
    }

  }
  
  // if it makes it out the loop, append the Node to the end
  Node* newNode = new Node(coeff, deg);
  current->m_next->m_next = newNode;
  return;
}

Polynomial Polynomial::add(const Polynomial& p) const {

  Polynomial sum;
  Node* sCurrent = sum.m_head;
  Node* current = m_head;
  
  if (current == NULL or current->m_next == NULL) {
   
    Node* pCurrent = p.m_head;
    
    // if the host has no value, copy the nodes from the p polynomial
    while (pCurrent != NULL) {
      Node* newNode = new Node(pCurrent->m_coefficient, pCurrent->m_degree);
      sCurrent->m_next = newNode;
      pCurrent = pCurrent->m_next;
      sCurrent = sCurrent->m_next;
    }

    return sum;

  }

  Node* next = current->m_next;
  Node* pCurrent = p.m_head;
  
  // if p has no values, copy the nodes from the host 
  // polynomial
  if (pCurrent == NULL or pCurrent->m_next == NULL) {
    
    while (current != NULL) {
      Node* newNode = new Node(current->m_coefficient, current->m_degree);
      sCurrent->m_next = newNode;
      current = current->m_next;
      sCurrent = sCurrent->m_next;
    }

    return sum;

  }

  Node* pNext = pCurrent->m_next;

  while (next != NULL and pNext != NULL) {
    
    // if the host's pointer is greater than p's pointer,
    // add a node with host's value into sum polynomial.
    if (current->m_degree > pCurrent->m_degree) {
      Node* newNode = new Node(current->m_coefficient, current->m_degree);
      sCurrent->m_next = newNode;
      sCurrent = sCurrent->m_next;
      current = current->m_next;
      next = next->m_next;

      // if the host's pointer is less than p's pointer,
      // add a node with p's value into sum polynomial
    } else if (current->m_degree < pCurrent->m_degree) {
      Node* newNode= new Node(pCurrent -> m_coefficient, 
				    pCurrent -> m_degree);
      sCurrent->m_next = newNode;
      pCurrent = pCurrent -> m_next;
      pNext = pNext -> m_next;
      sCurrent = sCurrent -> m_next;

      // if the host's pointer equals p's pointer, add coeff
      // and make new Node to append to sum polynomial. 
    } else {
      int sCoeff = current -> m_coefficient + pCurrent -> m_coefficient;

      if (sCoeff != 0) {
	Node* newNode = new Node(sCoeff, current -> m_degree);
	sCurrent->m_next = newNode;
	sCurrent = sCurrent -> m_next;
      }
      
      // move to the next pointer
      pCurrent = pCurrent -> m_next;
      current = current -> m_next;
      next = next -> m_next;
      pNext = pNext -> m_next;

    }

  }

  // if the nodes have the same degree, add their coeff.
  // and make a new node to append to the sum polynomial
  if (current->m_degree == pCurrent->m_degree) {
    
    int sCoeff = current->m_coefficient + pCurrent->m_coefficient;
    
    // as long as the coeff added together are not 0
    if (sCoeff != 0) {
      Node* newNode = new Node(sCoeff, current->m_degree);
      sCurrent->m_next = newNode;
      sCurrent = sCurrent->m_next;
    }

    pCurrent = pCurrent -> m_next;
    current = current -> m_next;

  }


  // as long as there are nodes in the host polynominal
  while (current != NULL) {
    // add a new node to sum polynomial with host pointer's values
    Node* newNode = new Node(current->m_coefficient, current->m_degree);
    sCurrent->m_next = newNode;
    current = current -> m_next;
    sCurrent = sCurrent -> m_next;
  }

  // as long as there are nodes in the p polynomial
  while (pCurrent != NULL) {

    // add a new nodes to sum polynomial with p pointer's values.
    Node* newNode = new Node(pCurrent->m_coefficient, pCurrent->m_degree);
    sCurrent->m_next = newNode;
    pCurrent = pCurrent -> m_next;
    sCurrent = sCurrent-> m_next;
  }

  return sum;

}


Polynomial Polynomial::subtract(const Polynomial& p) const {

  Polynomial subtract;
  Node* current = m_head;
  Node* next = current->m_next;
  Node* pCurrent = p.m_head;

  // if the p Polynomial is empty, return the host
  if (pCurrent == NULL)
    return *this;

  Node* pNext = pCurrent->m_next;
  Node* sCurrent = subtract.m_head;

  // while you haven't reached the end of any list
  while (next != NULL and pNext != NULL) {

    // if the degrees are the same, subtract coefficients
    // if they don't equal zero, add them
    if (current->m_degree == pCurrent->m_degree) {

      int sCoeff = current -> m_coefficient - pCurrent -> m_coefficient;

      if (sCoeff != 0) {
	Node* newNode = new Node(sCoeff, current->m_degree);
	sCurrent->m_next = newNode;
	sCurrent = sCurrent->m_next;
      }

      // move on to the next nodes
      pCurrent = pCurrent->m_next;
      current = current->m_next;
      next = next->m_next;
      pNext = pNext->m_next;

      // if the degree of the host is greater than the degree
      // of p, add the host's node to mult polynomial
    } else if (current->m_degree > pCurrent->m_degree) {
      Node* newNode = new Node(current->m_coefficient, current->m_degree);
      sCurrent->m_next = newNode;
      sCurrent = sCurrent->m_next;
      current = current->m_next;
      next = next->m_next;
      
      // if the degree of the host is less than the degree of
      // p, add a negative coefficient value to mult polynomial
    } else {
      Node* newNode= new Node(-(pCurrent -> m_coefficient), 
			      pCurrent -> m_degree);
      sCurrent->m_next = newNode;
      sCurrent = sCurrent -> m_next;
      pCurrent = pCurrent -> m_next;
      pNext = pNext -> m_next;
    }

  }

  // if the degrees for each of the pointers are the same
  // subtract the host by the p coefficient and add to 
  // mult polynomial.
  if (current->m_degree == pCurrent->m_degree) {

    int sCoeff = current->m_coefficient - pCurrent->m_coefficient;

    if (sCoeff != 0) {
      Node* newNode = new Node(sCoeff, current->m_degree);
      sCurrent->m_next = newNode;
      sCurrent = sCurrent->m_next;
    }

    pCurrent = pCurrent -> m_next;
    current = current -> m_next;  

  }

  // while there are still nodes in the current
  // add the nodes to the mult polynomial.
  while (next != NULL) {
    Node* newNode = new Node(current -> m_coefficient, 
			     current -> m_degree);
    sCurrent->m_next = newNode;
    sCurrent = sCurrent -> m_next;
    current =current-> m_next;
    next = next -> m_next;
  }

  // while there are still nodes in the p polynomial
  // subtract them from the mult polynomial.
  while (pNext != NULL) {
    sCurrent -> m_next = new Node(-(pCurrent -> m_coefficient), 
				  pCurrent -> m_degree);
    sCurrent = sCurrent -> m_next;
    pCurrent = pCurrent -> m_next;
    pNext = pNext -> m_next;
  }
  
  return subtract;

}

Polynomial Polynomial::multiply(const Polynomial& p) const {

  Polynomial mult;
  Node* current = m_head->m_next;
  int count = 0;
  
  // while there are still nodes in the host
  while (current != NULL) {

    Node* pCurrent = p.m_head->m_next;

    // multiply each Node in the host by a node in the p
    while (pCurrent != NULL) {

      int deg = current->m_degree + pCurrent->m_degree;
      long coeff = current->m_coefficient * pCurrent->m_coefficient;
      Node* newNode = new Node(coeff, deg);

      if (count == 0) {
	mult.insertMonomial(coeff, deg);
	count += 1;
	
	// if product is a positive number, make a 
	// Polynomial out of it and add it to mult Poly.
      } else {
	Polynomial product;
	Node* prCurrent = product.m_head;
	prCurrent->m_next = newNode;
	mult = mult.add(product);
      }

      //traverse through p's Nodes

      pCurrent = pCurrent->m_next;

    }
    //traverse through te host's Nodes
    current = current->m_next;

  }

  return mult;
}

unsigned int Polynomial::degree() const {

  // point current to the dummy and move past it,
  // one, to get the highest degree
  Node* current = m_head;
  current = current -> m_next;
  return current -> m_degree;

}

long Polynomial::evaluate(long x) const {
  
  // current moves down the Linked List,
  // while next stays one Node ahead,
  // and final keeps track of value
  Node* current = m_head -> m_next;
  Node* next = current -> m_next;
  long final = 0;
  
  // while next points to a non-Null value,
  // insert x and add up to final
  while (next != NULL) {
    unsigned int deg = current -> m_degree;
    long coeff = current -> m_coefficient;
    final += coeff * (pow (x, deg));
    current = current -> m_next;
    next = next -> m_next;
  }
  
  // for the last value, also add it to final.
  if (current != NULL) {
    unsigned int deg = current -> m_degree;
    long coeff = current -> m_coefficient;
    final += coeff * pow(x, deg);
  }
  
  return final; 

}

Polynomial& Polynomial::operator=(const Polynomial& p) {

  Node* current = m_head;
  Node* pCurrent = p.m_head;
  
  // while the p polynomial has values in it
  while (pCurrent != NULL) {

    // Add each node in p into the new polynomial
    long coeff = pCurrent->m_coefficient;
    int degree = pCurrent->m_degree;
    Node* newNode = new Node(coeff, degree);
    current->m_next = newNode;
    pCurrent = pCurrent->m_next;
    current = current->m_next;

  }

  return *this;

}
 
ostream& operator<<(ostream& sout, const Polynomial& p) {
  
  // Move through the p linked list.
  Node* current = p.m_head;
  // keep count of number of values printed.
  int count = 0;

  // while current points to a non-NULL value...
  while (current != NULL) {
    // find the coeff and deg of the selected Node
    long coeff = current -> m_coefficient;
    int deg = current -> m_degree;
    
    // if values have been printed, print appropriate sign.
    if (count > 0) {
      if (coeff < 0)
	sout << " - ";
      else 
	sout << " + ";
    }

    // find the absolute value of coeff
    long absCoeff = labs(coeff);

    // if coeff is zero, print nothing
    if (coeff == 0)
      sout << "";
    
    // if degree is zero, print only coeff
    else if (deg == 0)
      sout << absCoeff;
    
    // if its the first element in the Polynomial,
    // print the original value
    else if (count == 0) {
      sout << coeff << "x^" << deg << " ";
      count += 1;
    
      // print the value.
    } else {
      count += 1;
      sout << absCoeff << "x^" << deg << " "; 
    }
    
    //move on to the next Node.
    current = current -> m_next;

  }

  return sout;

}


