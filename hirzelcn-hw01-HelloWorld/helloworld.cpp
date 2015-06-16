/*    @file helloworld.cpp    
      @author Charles Hirzel
      @date August 26, 2014  */

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

/*  Prints "[<print_count>] Hello <name>!" printe_count number of times.
    @param print_count the number of times to print the message
    @param name the word to be inserted as the name, default is "World" */

void repeatPrint( int print_count, char* name ){
    for( int i = 1; i <= print_count; i++ ){
      
      cout << "[" << i << "] Hello " << name << "!" << endl;
    
    }
}

int main(int argc, char* argv[]){

  char* name;
  char default_name[] = "World";
  name = default_name;
  
  int character;
  int print_count;

  bool repeat = false;
  while(( character = getopt( argc, argv, "n:t:" )) != -1 ){
    switch( character ){
      case 'n':
        name = optarg;
	      break;
      case 't':
        print_count = atoi( optarg );
        repeat = true;
	      break;
      case '?':
        cout << "Unknown option" << endl;
	      break;
      default:
        abort();
    }
  }

  if( repeat ){

    repeatPrint( print_count, name );

  }else{

    cout << "Hello " << name << "!" << endl;	
  
  }

  return 0;

}
