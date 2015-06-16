/*    @file MadLib.cpp    
      @author <fill me in>
      @date <fill me in>  

			@description This program accepts a grammar instance text file and 
			prints out a random instance from that grammar.
*/

#include <iostream>
#include <cstdlib>
#include <map>

#include "expression.h"

using namespace std;

Exp* parse(map<string, Exp*>* keywords, string input ){
  
}

int main(int argc, char* argv[]){
  // Randomize number generator
  srand(time(0));

  // Open file

  // Create map of keywords to expressions
  map<string, Exp*> m;
  
  // For every line in the file, send the right side to parse
  // and put the resuling Expression pointer into the map.
  m[--keyword--] = parse(m, --right side of line--);
  
  // Get start expression and print out sentence!
  Exp* s1 = m["start"];
  cout << s1->getString() << endl; 

  // Return all memory back to OS.
}
