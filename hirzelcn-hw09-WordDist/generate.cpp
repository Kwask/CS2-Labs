/*    @file generate.cpp    
      @author Charles Hirzel
      @date 10-20-2014 

			@description Given a dictionary file (one word per line), and a starter word,
			this prints out all the (simplified) distance 1 words from the given word.
			
			Simplified distance 1 words are all words in the dictionary file that has
			one letter changed from the given word.
			Ex: ape -> aps
			
			./generate wordswithfriends.txt apple
			
			Execution time should be under 1 second.
*/

#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <getopt.h>
#include <stdlib.h>

#include "WordDist.h"

using namespace std;

void printSet( set<string> input ){
  int i = 0;
  for( set<string>::iterator it = input.begin();
       it != input.end(); it++ ){
    cout << i << ":" << *it << endl;
    i++;
  }
}

int main(int argc, char* argv[]){
  string dict_file;
  string word;
  unsigned int distance = 1;

  int c;
  opterr = 0;
  while(( c = getopt( argc, argv, "d:w:n:" )) != -1 ){
    switch (c){
      case 'd':
        dict_file = string( optarg );
        break;
      case 'w':
        word = string( optarg );
        break;
      case 'n':
        distance = atoi( optarg );
        break;
      case '?':
        if( c == 'd' or c == 'w' or c == 'n' ){
          cout << "Option character " << (char)c << " requires an argument!"
               << endl;
        }else{
          cout << "Unrecognized option character \"" << (char)c <<"\"!" << endl;
        }
        return -1;
      default:
        cout << "Requires dictionary filename and word to run!" << endl;
        return -1;
    }
  }

  WordDist dictionary;

  // Loading the dictionary
  ifstream infile;
  infile.open( dict_file.c_str() );

  while( !infile.eof() ){
    string input;
    getline( infile, input );

    dictionary.addToDictionary( input );
  }

  infile.close();

  // Finding words with a distance of "distance"
  set<string> word_dist = dictionary.getDistanceSet( word, distance );
  printSet( word_dist );

  return 0;
}
