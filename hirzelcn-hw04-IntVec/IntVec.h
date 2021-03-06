#ifndef INTVEC_H
#define INTVEC_H  

/**   @file IntVec.h    
      @author Charles Hirzel     // Change me!
      @date 09-16-2014        // Change me!
      @version 0.01   
      
      This IntVec class implements a vector-like class that stores integers.
      It also can return statistics about the data and return new IntVec's 
      based on arithmetic operations on them.
      
      This class may not use vector!
      */

#include <string>


using namespace std;

/**
  * Storage class able to dynamically store integers
*/
class IntVec{

public:
  
  /**
    * Default constructor initializes to an empty array
    */
  IntVec();
  
  /**
    * Constructor which takes a string in list form:
    * [ v1, v2, ... vn ]
    * Where each v can be a negative or positive value within the
    * range of an int.
    * Any amount of spaces around numbers is allowed.
    */
  IntVec(const string& values);
  
  /**
    * Copy constructor
    */
  IntVec(const IntVec& other);  
 
  /**
    * Class destructor
    */
  ~IntVec(); 
  
  /**
    * Push the value on the end of the array.
    */
  void pushBack(int value);
  
  /**
    * Returns the value at position loc in the array, or 0 if
    * loc is not valid.
    */
  int getAt(unsigned long loc);
  
  /**
    * Put val in loc position.  Returns true if successful, false otherwise.
    * 0 based.
    */
  bool setAt(int val, unsigned long loc);

  /**
    * Return the number of elements stored in IntVec
    */
  unsigned long getSize();
  
  /**
    * Return the current capacity of the IntVec
    */
  unsigned long getCapacity();
  
  /**
    * Removes all values in the current IntVec
    */
  void clear();
  
  /**
    * Return the sum or the values in the IntVec
    */
  long sum();
  
  /**
    * Return the average value in IntVec
    */
  float average();
  
  /**
    * Return the standard deviation of the values in the IntVec
    */
  float standardDev();
  
  /**
    * Adds another IntVec to the current one, element by element.
    * Neither this or the other IntVec should change.
    * If the sizes do not match, return an empty IntVec.
    */
  IntVec add(const IntVec& rhs);
  
  /**
    * Adds number to every element of the IntVec and returns the result.
    * This IntVec should not change.
    */
  IntVec add(int number); 
  
  /**
    * Returns a string of this IntVec with the format:
    * [1, 2, 3, .. 4]  The last value should not have a trailing comma.
    * This output should be the same format as the constructor which takes
    * a string.
    */
  string getAsString();
  
  /**
    * Returns true if both IntVec(s) contain the same values, false otherwise.
    */
  bool equals(const IntVec& rhs);
  
  /**
    * Appends the given IntVec to the right hand side of the current
    * one and returns the result.
    * IntVec("[1, 2, 3]").append(IntVec("[4, 5, 6]")).getAsString() ==
    * [1, 2, 3, 4, 5, 6]
    */
  IntVec append(const IntVec& rhs);
  
  private:
  unsigned long size;
  unsigned long capacity;

  int* address_book;

  /**
    * Resizes the address_book size to be += change
    */
  void resize( int change );

  /**
    * Copies the data from one array into a new one
    * Dynamic
    */
  int* copy( unsigned long array_size, const int* array );
  
};
  
#endif  
