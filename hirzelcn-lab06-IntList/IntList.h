#ifndef IntLIST_H
#define IntLIST_H 

/**   @file IntList.h    
      @author Charles Hirzel
      @date 9-30-14
      @version 0.01 
      
      This IntList class represents a singly linked-list storing integers.
      
      Various class members need to be implemented.
      
**/
#include <iostream>

#include "Node.h"

using namespace std;

class IntList{

  public:
  IntList();
  virtual ~IntList();
  
  // Don't worry about copy constructor or assignment operator for LAB.
  
  void pushFront(int value); // Puts value at the beginning of the list.
  void pushBack(int value);  // Puts value at the end of the list
  
  bool setAt(int location, int value);// Returns false if not possible
              // Negative values are from the end. -1 is last
              // location is 0 based.
  
  int getAt(int location);// Returns 0 if location not valid.  negative OK
              // Returns the value at that location if valid.
  
  bool insert(int location, int value); // Puts value BEFORE location in
              // in the linked list.  false if invalid location.  
              // A location of size should put the value at the end of the list,
              // as will location -1.  (Negs are AFTER location)
              
  bool remove(int location); // Removes the element at location, making the
              // linked-list smaller by 1.  Negatives OK
  
  string print(); // Resturns the linked-list to cout in some 
              // understandable way as a string.

  long getSize() const; /* Returns the number of elements in the 
                                  linked-list. */
  
  private:  // You can change anything you'd like below
  Node* first;
  long size;
  
  Node* getLocation( int location );

};

#endif
