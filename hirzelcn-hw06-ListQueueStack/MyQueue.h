#ifndef MYQUEUE_H
#define MYQUEUE_H 
/**   @file MyQueue.h    
      @author -------     // Change me!
      @date -----        // Change me!
      @version 0.01   
      
      This MyQueue class implements a templated queue
      
      Various class members need to be implemented.
      
**/
#include <iostream>
#include <sstream>
#include "LList.h"  // Hint hint!

using namespace std;

template <class T> class MyQueue{

public:
  MyQueue(){

  }
  
  void enqueue(T value){
    queue.pushBack( value );
  }
  
  T peek(){
    if( isEmpty() ){
      throw logic_error( "Error using peek(): queue was empty" );
    }else{
      return queue.getAt( 0 );
    }
  }
  
  void dequeue(){
    queue.remove( 0 );
  }
  
  unsigned int size() const{
    return queue.getSize();
  }
  
  bool isEmpty() const{
    if( queue.getSize() > 0 ){
      return false;
    }

    return true;
  }

private:
  LList<T> queue;

};

#endif
