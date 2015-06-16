#ifndef AQUEUE_H
#define AQUEUE_H 
/**   @file AQueue.h    
      @author Charles Hirzel
      @date 10-14-2014
      @version 0.01   
      
      This AQueue class implements a templated queue class using a vector.
      
      Various class members need to be implemented.
      
**/
#include <stdexcept>
#include <vector>

using namespace std;

template <class T> class AQueue{

public:
  AQueue(){  
  
  }
  
  ~AQueue(){
    queue.clear();
  }
  
  void enqueue(T value){
    queue.push_back( value );
  }
  
  T peek(){
    if( empty() ){
      throw logic_error( "Error using AQueue.peek(): queue empty" );
    }else{
      return queue.front();
    }
  }
  
  void dequeue(){
    queue.erase( queue.begin() );
  }
  
  unsigned int size() const{
    return queue.size();
  }
  
  bool empty() const{
    return queue.empty();
  }

private:
  vector<T> queue;
};

#endif
