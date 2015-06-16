#ifndef NODE_H
#define NODE_H

/**   @file Node.h    
      @author Charles Hirzel
      @date 9-30-14
      @version 0.01   
      
      This Node class holds the data and next pointer for 
      each entry on the list.
**/

class Node{
  public:
  Node();
  Node( int data, Node* next );
  Node( int data );
  virtual ~Node();

  int getData() const;
  Node* getNext() const;

  void setData( int data );
  void setNext( Node* next ); 

  private:
  int data; // Node data
  Node* next; // Location of next node
};

#endif
