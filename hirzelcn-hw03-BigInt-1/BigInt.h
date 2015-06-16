#ifndef BIGINT_H
#define BIGINT_H  

/**   @file BigInt.h    
      @author  Charles Hirzel
      @date  9/9/14
      @version 0.01   
      
      This BigInt class implements an infinitely long non-negative integer, 
      with addition possible.
      
      BitInts can be initialized via a long, a string of digits, or by the
      default constructor (value 0).
      
      BigInts can be retrieved as a string of digits or a long.
      
      */

#include <string>
#include <vector>

using namespace std;

class BigInt{

public:
  
  /**
    * Default constructor initializes the BigInt to 0
    */
  BigInt();
  
  /**
    * Creates a new BigInt from an unsigned long integer
    */
  BigInt(unsigned long number);
  
  /**
    * Creates a new BigInt from a string of digits.  Any non-number digit
    * will result in a BigInt value of 0, including the negative sign.
    */
  BigInt(const string& number);
  
  /**
    * Destructor for the class
    */

  BigInt(const BigInt& input );

  virtual ~BigInt();

  /** 
    * Adds two BigInts together, returns result 
    */
  BigInt operator+( const BigInt& rhs );

  /** 
    * Multiplies two BigInts together, returns result 
    */
  BigInt operator*( const BigInt& rhs );

  /** 
    * Multiplies a BigInt and a long together, returns result 
    */
  BigInt operator*( const long multiply );

  /** 
    * Checks if less than, returns bool
    */
  bool operator<( const BigInt& rhs );

  /** 
    * Checks if less than or equal to, returns bool
    */
  bool operator<=( const BigInt& rhs );

  /** 
    * Checks if greater than, returns bool
    */
  bool operator>( const BigInt& rhs );

  /** 
    * Checks if greater than or equal to, returns bool
    */
  bool operator>=( const BigInt& rhs );

  /** 
    * Checks if equivalent, returns bool
    */
  bool operator==( const BigInt& rhs );

  /** 
    * Checks if not equivalent, returns bool
    */
  bool operator!=( const BigInt& rhs );

  /** 
    * Prints to the ostream
    */
  friend ostream& operator<<( ostream& out, BigInt& rhs );
 
  /**
    * Return the Bigint as a string of digits 
    */
  string getAsDigits();

  /**
    * Return the Bigint as an unsigned long.  Returns 0
    * if the BigInt is larger than unsigned long supports.
    */
  unsigned long getAsLong();
  
  /**
    * Adds another Bigint to the current one and returns the sum
    * as another BigInt.
    * Neither this or the other number should change.
    */
  BigInt add(const BigInt& number);
  
  private:
  vector<unsigned short> number_blocks;  // Each block is a single digit

  /**
    * Compares the given BigInt and this BigInt. 
    * Returns -1, 0, or 1 depending on equality.
    */
  int compare( const BigInt& rhs );

};
  
#endif  
