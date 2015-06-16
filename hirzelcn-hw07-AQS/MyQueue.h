#ifndef MYQUEUE_H
#define MYQUEUE_H 
/**   @file MyQueue.h    
      @author Charles Hirzel
      @date 10-14-2014
      @version 0.01   
      
      This MyQueue class implements a templated queue
      
      Various class members need to be implemented.
      
**/
#include <stdexcept>
#include <iostream>
#include <cmath>

using namespace std;

template <class T> class MyQueue{

template <class G> class Node{
  public:
  Node(){
    value = 0;
    next = 0;
  }

  Node( G value, Node<G>* next ){
    this->value = value;
    this->next = next;
  }

  G value;
  Node<G>* next;
};

private:
  Node<T>* getAt( int location ){
    if( abs( location ) >= size() ){
      return 0;
    }

    int end = location;
    if( end < 0 ){
      end += size();
    }

    Node<T>* current = head;
    for( int i = 0; i < end; i++ ){
      if( current->next != 0 ){
        current = current->next;
      }
    }

    return current;
  }

private:
  Node<T>* head;

public:
  MyQueue(){
    head = 0;
  }
  
  ~MyQueue(){
    while( head != 0 ){
      dequeue();
    }
  }
  
  void enqueue(T value){
    if( empty() ){
      head = new Node<T>( value, 0 );
    }else{
      Node<T>* current = head;

      while( current->next != 0 ){
        current = current->next;
      }
      
      current->next = new Node<T>( value, 0 );
    }
  }
  
  T peek(){
    if( empty() ){
      throw logic_error( "Error using MyQueue.peek(): queue is empty" );
    }else{
//      cout << "accessing head value at " << head << endl;
      return head->value;
    }
  }
  
  void dequeue(){
    Node<T>* temp = head;
    head = head->next;
    delete temp;
  }
  
  unsigned int size() const{
//    cout << "count() beginning..." << endl;    

    unsigned int count = 0;

    Node<T>* current = head;
    while( current != 0 ){
      current = current->next;
//      cout << "- count: " << count << endl;

      count++;
    }

//    cout << "returning " << count << " as count()" << endl;
    return count;
  }
  
  bool empty() const{
    if( size() <= 0 ){
//      cout << "empty() returning true" << endl;
      return true;
    }else{
//      cout << "empty() returning false" << endl;
      return false;
    }
  }
};

#endif
