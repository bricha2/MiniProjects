/******************************                                                
 ** File:     sos.h                                     
 ** Project:  CMSC 202 Proj 2, Fall 2015                            
 ** Author:   Brianna Richardson                                   
 ** Date:     10/12/2015                                              
 ** Section:  0104                                                    
 ** Email:    bricha2@gl.umbc.edu                                
 **                                                   
 **  This file contains the declaration of the main class SoS,  
 ** for Project 2. This program works as a header for the implementation
 ** of the SoS class.
 **                                                                  
 *****************************/

#ifndef _SOS_H_
#define _SOS_H_

#include <string>
#include <vector>
using namespace std ;

class SoS {

   public:

   // Do not change the member function prototypes for
   // any public member function.

   // See documentation in Project 2 description.

   SoS() ;

   void insert(string str) ;
   void print() const ;

   bool isMember(string str) const ;
   bool isSubset(const SoS& B) const ; 
   bool isFinite() const ;

   SoS makeComplement() const ;
   SoS makeUnion(const SoS& B) const ;
   SoS makeIntersection(const SoS& B) const ;
   
   int findIndex(string str) const ;
   


   // The function dump() is used for grading.  Do not modify! 
   //
   vector<string>  dump() const { return m_vos; }


   private:

   // Do not change the types of these private data members

   bool m_cofinite ;
   vector<string> m_vos ;     // vos = vector of strings


   // Declarations for additonal private member functions
   // may be added below. Fully document these.
   

} ;




#endif
