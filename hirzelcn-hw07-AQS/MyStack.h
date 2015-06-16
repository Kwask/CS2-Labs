#ifndef MYSTACK_H
#define MYSTACK_H 
/**   @file MyStack.h    
      @author Charles Hirzel
      @date 10-14-2014
      @version 0.01   
      
      This MyStack class implements a templated stack
      
      Various class members need to be implemented.
      
**/
#include <stdexcept>

using namespace std;

template <class T> class MyStack{

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

public:
  MyStack(){
    head = 0;
  }
  
  ~MyStack(){
    while( head != 0 ){
      pop();
    }
  }
  
  void push(T value){
    head = new Node<T>( value, head );
  }
  
  T peek(){
    if( empty() ){
      throw logic_error( "Error using MyStack.peek(): stack is empty" );
    }else{
      return head->value;
    }
  }
  
  void pop(){
    Node<T>* temp = head;
    head = head->next;
    delete temp;
  }
  
  unsigned int size() const{
    unsigned int size_output = 0;
    
    Node<T>* current = head;
    while( current != 0 ){
      current = current->next;
      size_output++;
    }

    return size_output;
  }
  
  bool empty() const{
    if( size() <= 0 ){
      return true;
    }else{
      return false;
    }
  }

private:
  Node<T>* head;

};

#endif
