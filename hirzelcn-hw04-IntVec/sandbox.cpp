/*    @file sandbox.cpp    
      @author <fill me in>
      @date <fill me in>  

			@description Sandbox for IntVec
*/

#include <iostream>


#include "IntVec.h"

using namespace std;

int main(int argc, char* argv[]){
  // Use this program to test your IntVec implementation!
  cout << "IntVec sandbox!\n";
  IntVec test( "[0, 1, 2, 3, 4, 5]" );

  cout << "Original String: " << test.getAsString() << endl;
  cout << "Added +1: " << test.add( 1 ).getAsString() << endl;
  cout << "Appended 6: " << test.append( IntVec( "[6]" )).getAsString() << endl;
  cout << "Sum: " << test.sum() << endl;
  cout << "Average: " << test.average() << endl;
  cout << "Standard Dev: " << test.standardDev() << endl;

  test.clear();

  cout << "Cleared String: " << test.getAsString() << endl;
	
	return 0;
}
