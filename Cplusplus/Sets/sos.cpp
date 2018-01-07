/******************************
** File:     sos.cpp
** Project:  CMSC 202 Proj 2, Fall 2015
** Author:   Brianna Richardson
** Date:     10/12/2015
** Section:  0104
** Email:    bricha2@gl.umbc.edu
**
**  This file containts the implementation of the main class SoS,
** for Project 2. This program has separate functions that handle
** vectors of string in cofinite and finite sets. 
**
*****************************/

#include <algorithm>
#include <iostream>
#include "sos.h"

using namespace std;


SoS::SoS() {
  m_cofinite = false;
}

void SoS::insert(string str) {

  unsigned int strLocation = m_vos.size();
  // Find the location of str in m_vos (if it is present) 
  for (unsigned int i = 0; i < m_vos.size(); i++) {
    if (m_vos[i] == str)
      strLocation = i;
  }

  // If the object is cofinite ...
  if (m_cofinite) {
    // And it is in the complement vector, remove it.
    if (strLocation != m_vos.size()) {
      vector <string> newVec;
      for (unsigned int i = 0; i < m_vos.size(); i++) {
	if (i != strLocation)
	  newVec.push_back(m_vos[i]);
      }
      m_vos = newVec;
    }

  // If it is a finite object ...
  } else {
    // And not in the vector, add it.
    if (strLocation == m_vos.size())
      m_vos.push_back(str);    
  }
}

void SoS::print() const {
  // If it is cofinite, print out.
  if (m_cofinite)
    cout << "COMPLEMENT OF:" << endl;

  // Loop through vector and print on separate lines.
  for(unsigned int i = 0; i < m_vos.size(); i++)
    cout << m_vos[i] << endl;
}

bool SoS::isMember(string str) const {
  // Find the location of str in m_vos (if present)
  unsigned int strLocation = m_vos.size();
  for (unsigned int i = 0; i < m_vos.size(); i ++){
    if (m_vos[i] == str)
      strLocation = i;
  }

  // If the object is cofinite ...
  if (m_cofinite) {
    // And str is in complement, return false
    // Otherwise, return true
    if (strLocation != m_vos.size())
      return false;
    return true;
  
  // If the object is finite ...
  } else {
    // And the str is in the vector, return true.
    // Otherwise, return false
    if(strLocation == m_vos.size())
      return false;
    return true;
  }
}

bool SoS::isSubset(const SoS& B) const {
  // If the host is cofinite, and B is finite, return false
  if (B.isFinite() and m_cofinite)
    return false;
  
  // If both are finite, check to see that all strings in host
  // are also in B. return true if so.
  if (B.isFinite() and !(m_cofinite)) { 
    bool isASubset = true;
    unsigned int i = 0;
    while (isASubset and i < m_vos.size()) {
      isASubset = B.isMember(m_vos[i]);
      i += 1;
    }
    return isASubset;
  
  // If both are cofinite, check to see that all strings in
  // B's complement are in host's complement. return true if so.
  } else if (!B.isFinite() and m_cofinite) {
    bool isASubset = true;
    unsigned int i = 0;
    while (isASubset and i < B.m_vos.size()) {
      isASubset = !isMember(B.m_vos[i]);
      i += 1;
    }
    return isASubset;
  
  // If host is finite and B is cofinite, check to see that all
  // strings in host are not in B's complement. return true if so.
  } else {
    bool isASubset = true;
    unsigned int i = 0;
    while (isASubset and i < B.m_vos.size()) {
      isASubset = !isMember(B.m_vos[i]);
      i += 1;
    }
    return isASubset;
  }
}

bool SoS::isFinite() const { 
  // If cofinite, return false. Otherwise, true.
  if (m_cofinite)
    return false;
  return true;
}

SoS SoS::makeComplement() const { 
  // Create a new SoS object with opposite cofinite status
  SoS theComplement;
  theComplement.m_cofinite = !m_cofinite;

  // Copy every object in the m_vos to Complement's m_vos
  for (unsigned int i = 0; i < m_vos.size(); i++ )
    theComplement.m_vos.push_back(m_vos[i]);
   return theComplement;
}

SoS SoS::makeUnion(const SoS& B) const {
  // If both are finite make a new union SoS
  if (B.isFinite() and !(m_cofinite)) {
    SoS unionSos;
    unionSos.m_cofinite = false;
    // Insert all the elements of each m_vos to the union
    for (unsigned int i = 0; i < m_vos.size(); i ++)
      unionSos.m_vos.push_back(m_vos[i]); 
    for (unsigned int i = 0; i < B.m_vos.size(); i++) {
      if (!unionSos.isMember(B.m_vos[i]))
	unionSos.m_vos.push_back(B.m_vos[i]);
    }
    return unionSos;
  
  // If both are cofinite, make a new union SoS
  } else if (!(B.isFinite()) and m_cofinite){
    SoS unionSos;
    unionSos.m_cofinite = true;
    // Loop through the host's complement
    // If not in complement, insert into union.
    for (unsigned int i = 0; i <m_vos.size(); i++) {
      if (!B.isMember(m_vos[i]))
	unionSos.m_vos.push_back(m_vos[i]);
    }
    // Loop through the B's complement. If not 
    // in the complement or already in union, insert.
    for (unsigned int i = 0; i < B.m_vos.size(); i ++) {
      if (!isMember(B.m_vos[i]) and unionSos.isMember(B.m_vos[i]))
	unionSos.m_vos.push_back(B.m_vos[i]);
    }
    return unionSos;
 
  // If one of the objects are cofinite, make a unionSos
  } else {
    SoS unionSos;
    unionSos.m_cofinite = true;
    
    // If the host is cofinite, insert all objects in B
    // and in the host's complement into union's complement
    if (m_cofinite) {
      for (unsigned int i = 0; i < B.m_vos.size(); i ++) {
	if (!(isMember(B.m_vos[i])))
	  unionSos.m_vos.push_back(B.m_vos[i]);
      }
    
    // If B is cofinite, insert all objects in the host
    // and in B's complement into union's complement
    } else {
      for (unsigned int i = 0; i < m_vos.size(); i ++) {
	if(!B.isMember(m_vos[i]))
	  unionSos.m_vos.push_back(m_vos[i]);
      }
    }
    return unionSos;
  }
}

SoS SoS::makeIntersection(const SoS& B) const {
  // Make the complement of both sets
  SoS hostComplement = makeComplement();
  SoS BComplement =  B.makeComplement();
  // Intersection is the union of the complements
  SoS intersectSos = hostComplement.makeUnion(BComplement);
  return intersectSos;
}
