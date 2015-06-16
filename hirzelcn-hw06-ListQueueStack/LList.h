#ifndef LLIST_H
#define LLIST_H 
/**   @file LList.h    
      @author Charles Hirzel
      @date 10-13-2014
      @version 0.01
      
      This LList class implements a templated linked-list container.
      
      Various class members need to be implemented.
      
**/
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <cmath>

using namespace std;

template <class T> 
class LList{
public:
  LList(){
    head = 0;
  }

  ~LList(){
    clear();
  }
  
  LList( const LList<T>& other ){
    this = other;
  }
  
  // Returns a copy of this LList
  LList<T>&  operator=( const LList<T>& other ){
    LList<T> a;
    a.head = new Node<T>;

    Node<T>* this_current = this->head;
    Node<T>* copy_current = a.head;

    while( this_current->next != 0 ){
      copy_current->data = this_current->data;
      copy_current->next = new Node<T>;

      copy_current = copy_current->next;
      this_current = this_current->next;
    }

    return a;
  }

  // Appends rhs to this LList, then returns the result
  LList<T> operator+( const LList<T>& rhs ) const{
    LList<T> a = this;
    LList<T> b = rhs;

    a->getLocation( a.getSize()-1 )->next = b.head;

    return a;
  }
  
  // Checks if equivalent, returns boolean
  bool operator==( const LList<T>& rhs ) const{
    if( rhs.getSize() == this->getSize() ){
      Node<T>* this_current = this.head;
      Node<T>* rhs_current = rhs.head;

      while( this_current.next != 0 ){
        if( this_current.data != rhs_current.data ){
          return false;
        }

        this_current = this_current.next;
        rhs_current = rhs_current.next;
      }
    }else{
      return false;
    }

    return true;
  }
  
  // Checks if not equivalent, returns boolean
  bool operator!=( const LList<T>& rhs ) const{
    if( this == rhs ){
      return false;
    }

    return true;
  }

  // Searching for value, starting at location
  int find( T value, int location ){
    if(( location+1 >= getSize()-1 ) or ( location+1 < 0 )){
      throw logic_error( "Error using find: location out of range" );
    }

    for( int i = location+1; i < getSize(); i++ ){
      if( value == getLocation( i )->data ){
        return i;
      }
    }

    return -1;
  }

  void insert( T value, int location ){
    Node<T>* current = getLocation( location );
    current = new Node<T>( current, value );

    if( location > 0 and location < getSize()+1 ){
      Node<T>* temp;
      temp = getLocation( location-1 );
      temp->next = current;
    }else if( location == 0 ){
      head = current;
    }else{
      delete current;
      throw logic_error( "Error using insert: location out of range" );
    }
  }

  void remove( int location ){
    Node<T>* current = getLocation( location );

    if( current == 0 ){
      throw logic_error( "Error using \"Remove\": Could not get location" );
    }

    if( location > 0 and location < getSize() ){
      Node<T>* temp;
      temp = getLocation( location-1 );
      temp->next = current->next;
    }else if( location == 0 ){
      head = current->next;
    }else{
      throw logic_error( "Error using \"Remove\": Location outside of range" );
    }

    delete current;
  }

  void setAt( T value, int location ){
    Node<T>* current = getLocation( location );
    if( current == 0 ){
      throw logic_error( "Error using setAt(): location out of range" );
    }

    current->data = value;
  }

  void pushFront( T value ){
    insert( value, 0 );
  }

  void pushBack( T value ){
    insert( value, getSize() );
  }

  T getAt( int location ) const{
    Node<T>* current = getLocation( location );

    if( current == 0 ){
      throw logic_error( "Error using getAt(): location out of range" );
    }else{
      return current->data;
    }
  }

  unsigned int getSize() const{
    unsigned int size = 0;
    Node<T>* current = head;

    if( head != 0 ){
      size++;
    }else{
      return size;
    }

    while( current->next != 0 ){
      current = current->next;
      size++;
    }

    return size;
  }

  LList<T> reverse() const{
    LList<T> a; 
    return a;
  }

  void clear(){
    Node<T>* current;
    current = head;

    while( current != 0 ){
      Node<T>* temp = current;
      current = current->next;

      delete temp;
    }
  }

  string print() const{
    stringstream output;
    output << "[";

    for( int i = 0; i < getSize(); i++ ){
      Node<T>* temp;
      temp = getLocation( i );

      output << temp->data;

      if( i != getSize()-1 ){
        output << ", ";
      }
    }

    output << "]";
    return output.str();
  }

private:
  template <class U> 
  class Node{
  public:
    Node<U>* next;
    U data;

    Node(){
      data = 0;
      next = 0;
    }

    Node( Node<U>* next, U data ){
      this->next = next;
      this->data = data;
    }

    ~Node(){
      return;
    }
  };

  Node<T>* getLocation( const int &location ) const{
    if( abs( location ) >= getSize() ){
      return 0;
    }

    int end = location;
    if( end < 0 ){
      end += getSize();
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
};

#endif
