#ifndef MVEC_H
#define MVEC_H 

/**   @file MVec.h    
      @author Charles Hirzel     // Change me!
      @date 9-23-14        // Change me!
      @version 0.01   
      
      This MVec class represents a physics 2-dimensional vector.
      
      Various operators need to be overloaded and implemented:
      
      +  Does vector addition
      *  Extends the vector 'extend' (float) times.
      == Equal if each component differs by less than 0.01
      != Opposite of ==
**/
      
#include <iostream>
#include <string>

using namespace std;

class MVec{
  public:
  MVec();     // Initialize x=0, y=0
  MVec(float x, float y); // Sets x and y
  
  float getMagnitude() const; // Gives the magnitude of the vector
  float getX() const;         // Gets x component
  float getY() const;         // Gets y component

  MVec operator+( const MVec& rhs ); // Adds components
  MVec operator*( float extend ); // Multiplies components by extend
  bool operator==( const MVec& rhs ); // Checks if equal with tolerance of 0.01
  bool operator!=( const MVec& rhs ); // Checks not equal with same tolerance
  friend ostream& operator<<( ostream& out, const MVec& rhs );
  // Prints components in form "x: <x> y: <y>"

  private:
  float x;
  float y;

};

#endif 
