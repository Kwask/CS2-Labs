#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <getopt.h>

#include "BinaryTree.h"

using namespace std;

int main( int argc, char* argv[] ){
  int node_number = 100;
  int value_range = 100;

  int c;
  opterr = 0;
  while(( c = getopt( argc, argv, "n:r:" )) != -1 ){
    switch( c ){
      case 'n':
        node_number = atoi( optarg );
        break;
      case 'r':
        value_range = atoi( optarg );
        break;
      case '?':
        if( c == 'n' or c == 'r' ){
          cout << "Option " << (char)c << " requries an argument." endl;
        }else{
          cout << "Unknown option character \"" << (char)c << "\"." << endl;
        }

        return 1;
      default:
        break;
    }
  }

  BinaryTree<int> Tree;

  srand( time( 0 ));
  for( int i = 0; i < node_number; i++ ){
    int value = rand()%value_range;

    Tree.insert( value );
  }

  delete Tree;
}
