/*    @file BigInt.cpp   
      @author Charles Hirzel
      @date 9/9/14

			@description Implements an unlimited-sized unsigned integer.
*/
#include <string>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <climits>
#include <cmath>

#include "BigInt.h"

int base = 10;

BigInt::BigInt(){
  number_blocks.push_back( 0 );
}

BigInt::BigInt(unsigned long my_number){

  bool at_number = false;

  for( int i = base-1; i >= 0; i-- ){
    unsigned short value = floor( (double)my_number/(double)pow( base, i ));
    my_number -= value*pow( base, i );

    if( value > 0 ){
      at_number = true;
    }
    if( at_number ){
      number_blocks.push_back( value );
    }
  }
}

BigInt::BigInt(const string& s_number){
  if( s_number.at( 0 ) == '-' ){
    number_blocks.push_back( 0 );
  }else{

    for( unsigned int i = 0; i < s_number.length(); i++ ){
      unsigned short value = s_number.at( i )-'0';

	    number_blocks.push_back( value );
    }
  }
}

BigInt::BigInt( const BigInt& input ){

  number_blocks = input.number_blocks;

}

BigInt::~BigInt(){

}

BigInt BigInt::operator+( const BigInt& rhs ){
  return add( rhs );
}

BigInt BigInt::operator*( const BigInt& rhs ){
  BigInt output;
  return output;
}

BigInt BigInt::operator*( const long multiply ){
  BigInt output;

  for( long i = 0; i < multiply; i++ ){
    output = output.add( BigInt( getAsDigits() ));
  }

  return output;
}

bool BigInt::operator<( const BigInt& rhs ){
  if( compare( rhs ) == -1 ){
    return true;
  }else{
    return false;
  }
}

bool BigInt::operator<=( const BigInt& rhs ){
  if( compare( rhs ) == -1 or compare( rhs ) == 0 ){
    return true;
  }else{
    return false;
  }
}

bool BigInt::operator>( const BigInt& rhs ){
  if( compare( rhs ) == 1 ){
    return true;
  }else{
    return false;
  }
}

bool BigInt::operator>=( const BigInt& rhs ){
  if( compare( rhs ) == 1 or compare( rhs ) == 0 ){
    return true;
  }else{
    return false;
  }
}

bool BigInt::operator==( const BigInt& rhs ){
  if( compare( rhs ) == 0 ){
    return true;
  }else{
    return false;
  }
}

bool BigInt::operator!=( const BigInt& rhs ){
  if( compare( rhs ) != 0 ){
    return true;
  }else{
    return false;
  }
}

ostream& operator<<( ostream& out, BigInt& rhs ){
  out << rhs.getAsDigits();
  return out;
}

string BigInt::getAsDigits(){
  stringstream ss;

  for( vector<unsigned short>::iterator it = number_blocks.begin();
       it != number_blocks.end(); it++ ){

    ss << *it;

  }

  return ss.str();
}

unsigned long BigInt::getAsLong(){

  unsigned long value = 0;

  for( vector<unsigned short>::iterator it = number_blocks.begin();
       it != number_blocks.end(); it++ ){

    unsigned long i = ( number_blocks.size()-1 )-( it-number_blocks.begin() );
    value += (*it)*pow( base, i );

  }

  return value;
}

BigInt BigInt::add(const BigInt& number_input){

  stringstream sum;
  vector<unsigned short> input_blocks = number_input.number_blocks;
  vector<unsigned short>::iterator it_input = input_blocks.end()-1;
  vector<unsigned short>::iterator it_source = number_blocks.end()-1;

  unsigned short overflow = 0; // To track of radix overflow during summation
  bool complete = false;

  while( !complete ){
    
    unsigned short value = 0;

    // If the three completing conditions are met, loop ends
    bool strike_1 = false;
    bool strike_2 = false;
    bool strike_3 = false;

    if( it_input > input_blocks.begin()-1 ){
      value  += *it_input;
      it_input--;
    }else{
      strike_1 = true;
    }
    
    if( it_source > number_blocks.begin()-1 ){
      value += *it_source;
      it_source--;
    }else{
      strike_2 = true;
    }

    if( overflow > 0 ){
      value += overflow;
      overflow = 0;
    }else{
      strike_3 = true;
    }

    // If value is greater than the radix, then reduce it
    if( value >= base ){
      overflow++; // Since overflow is an order of magnitude larger than value
      value -= 10; // Reducing so that value is smaller than the radix
    }

    if( strike_1 and strike_2 and strike_3 ){
      complete = true;
    }else{
      sum << value;
    }
  }

  string output = sum.str();
  output = string( output.rbegin(), output.rend() ); // Flipping the string

  return BigInt( output );
}

/**
  * -1 = this < number
  * 0 = this == number
  * 1 = this > number
  */
int BigInt::compare( const BigInt& rhs ){
  vector<unsigned short> outside = rhs.number_blocks;

  if( number_blocks.size() > outside.size() ){
    return 1;
  }else if( number_blocks.size() < outside.size() ){
    return -1;
  }else{
    vector<unsigned short>::iterator it_number = outside.begin();

    for( vector<unsigned short>::iterator it_this = number_blocks.begin();
        it_this != number_blocks.end(); it_this++ ){

      if( *it_this > *it_number ){
        return 1;
      }
      
      if( *it_this < *it_number ){
        return -1;
      }

      it_number++;
    }
  }

  return 0;
}

