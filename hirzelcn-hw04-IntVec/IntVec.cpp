/*    @file IntVec.cpp   
      @author Charles Hirzel
      @date 9-16-2014 

			@description Implements vector-like container for integers.
*/

#include <string>
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <cmath>

#include "IntVec.h"

IntVec::IntVec(){

  size = 0;
  capacity = 0;
  address_book = 0;

}

IntVec::IntVec(const string& values){
  size = 0;
  capacity = 0;
  address_book = 0;

  for( unsigned int i = 0; i < values.length(); i++ ){
    if(( values.at( i ) >= 48 and values.at( i ) < 58 ) 
        or values.at( i ) == '-' ){

      stringstream temp;
      while(( values.at( i ) >= 48 and values.at( i ) < 58 
          and i < values.length() ) or values.at( i ) == '-' ){

        temp << values.at( i );
        i++;

      }

      size++;
      if( size >= capacity ){
        resize( 10 ); // Reallocating new space on the end
      }

      address_book[ size-1 ] = atoi( string( temp.str() ).c_str() );
    }
  }
}

IntVec::IntVec( const IntVec& other ){
  size = other.size;
  capacity = other.capacity;
  address_book = copy( other.size, other.address_book );
}

IntVec::~IntVec(){
  delete[] address_book;
}

void IntVec::pushBack( int value ){
  size++;

  if( size >= capacity ){
    resize( 10 ); // Reallocate with new space at the end
  }

  address_book[ size-1 ] = value; // Adding the value to the new spot
}

int IntVec::getAt( unsigned long loc ){
  if( loc < size ){
    return address_book[ loc ];
  }

  return 0;
}

bool IntVec::setAt( int value, unsigned long loc ){
  if( loc < size ){
    address_book[ loc ] = value;
    return true;
  }

  return false;
}

unsigned long IntVec::getSize(){
  return size;
}

unsigned long IntVec::getCapacity(){
  return capacity;
}

void IntVec::clear(){
  delete[] address_book;
  address_book = 0;
  size = 0;
  capacity = 0;
}

long IntVec::sum(){
  long sum = 0;

  for( unsigned long i = 0; i < size; i++ ){
    sum += address_book[ i ];
  }
  
  return sum;
}

float IntVec::average(){
  if( size == 0 ){
    return 0;
  }else{
    return (float)sum()/size;
  }
}

float IntVec::standardDev(){
  float avg = average();
  float standard_dev = 0;
  float point_diff[ size ];

  if( size > 0 ){
    for( unsigned long i = 0; i < size; i++ ){
      point_diff[ i ] = avg-address_book[ i ];
    }

    for( unsigned long i = 0; i < size; i++ ){
      standard_dev += pow( point_diff[ i ], 2.0f );
    }
  }

  standard_dev = standard_dev/(float)size;
  return sqrt( standard_dev );
}

IntVec IntVec::add( const IntVec& rhs ){
  IntVec output;

  if( size == rhs.size ){
    for( unsigned long i = 0; i < size; i++ ){
      output.pushBack( address_book[ i ]+rhs.address_book[ i ] );
    }
  }

  return output;
}

IntVec IntVec::add( int number ){
  IntVec output;

  for( unsigned long i = 0; i < size; i++ ){
    output.pushBack( address_book[ i ]+number );
  }

  return output;
}

string IntVec::getAsString(){
  stringstream output;
  output << "[";

  for( unsigned long i = 0; i < size; i++ ){
    output << address_book[ i ];

    if( i != size-1 ){
      output << ", ";
    }
  }

  output << "]";
  return output.str();
}

bool IntVec::equals( const IntVec& rhs ){
  if( size == rhs.size ){  
    for( unsigned long i = 0; i < size; i++ ){
      if( address_book[ i ] != rhs.address_book[ i ] ){
        return false;
      }
    }
  }else{
    return false;
  }

  return true;
}

IntVec IntVec::append( const IntVec& rhs ){
  IntVec output( getAsString() );

  for( unsigned long i = 0; i < rhs.size; i++ ){
    output.pushBack( rhs.address_book[ i ] );
  }

  return output;
}

void IntVec::resize( int change ){
  int* temp = address_book;
  unsigned long old_capacity = capacity;

  capacity += change;
  address_book = new int[ capacity ];

  for( unsigned long i = 0; i < capacity; i++ ){
    if( i >= old_capacity ){
      break;
    }

    address_book[ i ] = temp[ i ];
  }

  if( old_capacity > 0 ){
    delete[] temp;
  }else{
    delete temp;
  }
}

int* IntVec::copy( unsigned long array_size, const int* array ){
  int* output = new int[ array_size ];

  for( unsigned long i = 0; i < array_size; i++ ){
    output[ i ] = array[ i ];
  }

  return output;
}

