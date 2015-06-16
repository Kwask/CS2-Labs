#ifndef ASTACK_H
#define ASTACK_H 
/**   @file AStack.h    
      @author Charles Hirzel
      @date 10-14-2014
      @version 0.01   
      
      This AStack class implements a templated stack class using a vector.
      
      Various class members need to be implemented.
      
**/
#include <stdexcept>
#include <vector>

using namespace std;

template <class T> class AStack{

public:
  AStack(){
    
  }
  
  ~AStack(){
    stack.clear();
  }
  
  void push(T value){
    stack.push_back( value );
  }
  
  T peek(){
    if( empty() ){
      throw logic_error( "Error using Stack.peek(): stack empty" );
    }else{
      return stack.back();
    }
  }
  
  void pop(){
    stack.pop_back();
  }
  
  unsigned int size() const{
    return stack.size();
  }
  
  bool empty() const{
    return stack.empty();
  }
  
private:
  vector<T> stack;
};

#endif
