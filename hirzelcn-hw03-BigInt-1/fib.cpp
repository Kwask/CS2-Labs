/*    @file fib.cpp    
      @author  Charles Hirzel
      @date  9/9/14

			@description Returns the fibonochi value of the n
*/

#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>

#include "BigInt.h"

using namespace std;

/*  Calculates the <max>'th number in the fibonacci sequence "instantly".
    @param input1  argument used for recursion, use 0 when calling func
    @param input2  argument used for recursion, use 0 when calling func
    @param max  the value that the func will find the fibonacci number of
    @param iterator  argument used for recursion, use 0 when calling func
    @return  the value of the <max>'th number in the fibonacci sequence  */
BigInt fibonacci( BigInt input1, BigInt input2, unsigned long max, 
    unsigned long iteration ){

  if( iteration == 0 ){
    input1 = BigInt( 0 );
    input2 = BigInt( 0 );
  }else if( iteration == 1 ){
    input1 = BigInt( 1 );
    input2 = BigInt( 0 );
  }else{
    BigInt temp( input1 );
    input1 = input1.add( input2 );
    input2 = temp;
  }

  if( iteration >= max ){
    return input1;
  }else{
    iteration++;
    return fibonacci( input1, input2, max, iteration );
  }
}

int main(int argc, char* argv[]){
  int input = 47;
  int c;

  bool given_number = false;

  // Parsing command-line arguments
  while(( c = getopt( argc, argv, "n:" )) != -1 ){
    switch( c ){
      case 'n':
        input = atoi( optarg );
        given_number = true;
        break;
      case '?':
        if( optopt == 'n' ){
          cout << "Option n requires an argument." << endl;
        }else{
          cout << "Unrecognized option." << endl;
        }
        break;
    }
  }

  BigInt fib_value( fibonacci( 0, 0, input, 0 ));

  if( given_number ){
    cout << "f(" << input << ") = "
         << fib_value.getAsDigits() << endl;
  }else{
    cout << "This program calculates the nth value in the fibonacci sequence." 
         << endl 
         << "To use it, use the -n option along with a number as the n value."
         << endl;
  }

	return 0;
}

