/**   @file IntList.h    
      @author Charles Hirzel
      @date 9-30-14
      @version 0.01 
      
      This IntList class represents a singly linked-list storing integers.
      
      Various class members need to be implemented.
      
**/
#include <iostream>
#include <sstream>
#include <cmath>

#include "IntList.h"
#include "Node.h"

using namespace std;

IntList::IntList(){
  first = 0;
  size = 0;
}

IntList::~IntList(){
  Node* current;
  current = first;

  while( current != 0 ){
    Node* temp = current;
    current = current->getNext();

    delete temp;
    size--;
  }
}

void IntList::pushFront( int value ){
  insert( 0, value );
}

void IntList::pushBack( int value ){
  insert( size, value );
}

bool IntList::setAt( int location, int value ){
  Node* current;
  current = getLocation( location );

  if( current == 0 ){
    return false;
  }

  current->setData( value );
  
  return true;
}

int IntList::getAt( int location ){
  Node* current;
  current = getLocation( location );

  if( current == 0 ){
    return 0;
  }

  return current->getData();
}

bool IntList::insert( int location, int value ){
  Node* current;
  current = getLocation( location );

  current = new Node( value, current );
  size++;

  if( location > 0 and location < size ){
    Node* temp;
    temp = getLocation( location-1 );
    temp->setNext( current );
  }else if( location == 0 ){
    first = current;
  }else{
    return false;
  }

  return true;
}

bool IntList::remove( int location ){
  Node* current;
  current = getLocation( location );

  if( current == 0 ){
    return false;
  }

  Node* temp;
  if( location > 0 and location < size ){
    temp = getLocation( location-1 );
    temp->setNext( current->getNext() );
  }else if( location == 0 ){
    first = current->getNext();
  }else{
    return false;
  }

  delete current;
  size--;

  return true;
}

string IntList::print() {
  stringstream output;
  output << "[";

  for( int i = 0; i < size; i++ ){
    Node* temp;
    temp = getLocation( i );

    output << temp->getData();

    if( i != size-1 ){
      output << ", ";
    }
  }

  output << "]";
  return output.str();
}

long IntList::getSize() const{
  return size;
}

Node* IntList::getLocation( int location ){
  if( abs( location ) >= size ){
    return 0;
  }

  int end = location;
  if( end < 0 ){
    end += size;
  }

  Node* current = first;
  for( int i = 0; i < end; i++ ){
    if( current->getNext() != 0 ){
      current = current->getNext();
    }
  }

  return current;
}
