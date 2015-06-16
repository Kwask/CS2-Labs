/*    @file WordDist.cpp   
      @author Charles Hirzel
      @date 10-28-2014

			@description Implements the WordDist class
*/
#include <set>
#include <string>
#include <cmath>
#include <iostream>

#include "WordDist.h"

using namespace std;

WordDist::WordDist(){

}

WordDist::~WordDist(){

}

void WordDist::addToDictionary( string word ){
  dictionary.insert( word );
}

unsigned int WordDist::size(){
  return dictionary.size();
}

bool WordDist::isStored( string word ){
  for( set<string>::iterator it = dictionary.begin();
       it != dictionary.end(); it++ ){
    if( *it == word ){
      return true;
    }
  }

  return false;
}

set<string> WordDist::getDistanceSet( string word, unsigned int dist ){
  set<string> output;

  // Loops through each word in the dictionary
  for( set<string>::iterator it = dictionary.begin();
       it != dictionary.end(); it++ ){

    // Starts off with distance being the possible maximum
    unsigned int distance;
    if( it->length() > word.length() ){
      distance = it->length();
    }else{
      distance = word.length();
    }

    // Works through the two words seperately. Every iteration moves a letter
    // forward in the comparative word, and each time a letter matches, it
    // moves forward a letter in the given word and distance is decreased by 1.
    unsigned int original_i = 0;
    for( unsigned int compare_i = 0;
        compare_i < it->length() and original_i < word.length();
        compare_i++ ){
      if( it->at( compare_i ) == word.at( original_i )){
        distance--;
        original_i++;
      }
    }

     // If the distance is sufficient, add it to the output set
    if( distance == dist ){
      output.insert( *it );
    }
  }

  return output;
}
