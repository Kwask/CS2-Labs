/**   @file Node.cpp  
      @author Charles Hirzel
      @date 9-30-14
      @version 0.01   
      
      This Node class holds the data and next pointer for 
      each entry on the list.
**/
#include "Node.h"

using namespace std;

Node::Node(){
  data = 0;
  next = 0;
}

Node::Node( int data, Node* next ){
  this->data = data;
  this->next = next;
}

Node::Node( int data ){
  this->data = data;
  next = 0;
}

Node::~Node(){
  
}

int Node::getData() const{
  return data;
}

Node* Node::getNext() const{
  return next;
}

void Node::setData( int data ){
  this->data = data;
}

void Node::setNext( Node* next ){
  this->next = next;
}

