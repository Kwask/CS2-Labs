#ifndef WORDDIST_H
#define WORDDIST_H 
/**   @file WordDist.h    
      @author Charles Hirzel
      @date 10-28-2014
      @version 0.01   
      
      This WordDist class allows the addition of words to an internal
      dictionary, and the retrieval of a set of words which have at
      least a certain 'distance' from it.
      
      See assignment document for 'distance' definition.
**/
#include <set>
#include <string>

using namespace std;

class WordDist{

public:
  WordDist();
  
  ~WordDist();
  
  void addToDictionary(string word);
  
  unsigned int size();
  
  bool isStored(string word);
  
  set<string> getDistanceSet(string word, unsigned int dist);

private:
  set<string> dictionary;

};

#endif
