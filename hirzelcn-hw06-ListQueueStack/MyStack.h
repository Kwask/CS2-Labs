#ifndef MYSTACK_H
#define MYSTACK_H 
/**   @file MyStack.h    
      @author -------     // Change me!
      @date -----        // Change me!
      @version 0.01   
      
      This MyStack class implements a templated stack
      
      Various class members need to be implemented.
      
**/
#include <iostream>
#include <sstream>
#include "LList.h"

using namespace std;

template <class T> class MyStack{

public:
  MyStack(){
    
  }
  
  void push(T value){
    stack.pushFront( value );
  }
  
  T peek(){
    if( isEmpty() ){
      throw logic_error( "Error using peek(): stack was empty" );
    }else{
      return stack.getAt( 0 );
    }
  }
  
  void pop(){
    stack.remove( 0 );
  }
  
  unsigned int size() const{
    return stack.getSize();
  }
  
  bool isEmpty() const{
    if( stack.getSize() > 0 ){
      return false;
    }

    return true;
  }

private:
  LList<T> stack;
};

#endif
