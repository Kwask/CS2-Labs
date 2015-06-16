/**   @file MVec.cpp    
      @author Charles Hirzel     // Change me!
      @date 9-23-14        // Change me!
      @version 0.01   
      
      This MVec class represents a physics 2-dimensional vector.
      
      Various operators need to be implemented or overloaded.
      See MVec.cpp for details.
      
**/
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <math.h>
#include <sstream>
#include <string>

#include "MVec.h"

using namespace std;

MVec::MVec(){
  x = 0;
  y = 0;
}

MVec::MVec( float x, float y ){
  this->x = x;
  this->y = y;
}

float MVec::getMagnitude() const{
  return sqrt( pow( x, 2 )+pow( y, 2 ));
}

float MVec::getX() const{
  return x;
}

float MVec::getY() const{
  return y;
}

MVec MVec::operator+( const MVec& rhs ){
  MVec output( x, y );

  output.x = output.x+rhs.x;
  output.y = output.y+rhs.y;

  return output;
}

MVec MVec::operator*( float extend ){
  MVec output( x, y );

  output.x = output.x*extend;
  output.y = output.y*extend;

  return output;
}

bool MVec::operator==( const MVec& rhs ){
  if( 0.01f < fabs( x-rhs.x )){
    return false;
  }
  
  if( 0.01f < fabs( y-rhs.y )){
    return false;
  }

  return true;
}

bool MVec::operator!=( const MVec& rhs ){
  if( 0.01f < fabs( x-rhs.x )){
    return true;
  }
  
  if( 0.01f < fabs( y-rhs.y )){
    return true;
  }

  return false;
}

ostream& operator<<( ostream& out, const MVec& rhs ){
  out << "x: " << rhs.x << " y: " << rhs.y;
  return out;
}

