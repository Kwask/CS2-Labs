/*
  WordDist_test.h
  Unit tests for HW09, WordDist.
  
*/

#include "WordDist.h"
#include <stdexcept>

#include <cxxtest/TestSuite.h>

class WordDistTest : public CxxTest::TestSuite {
public:

void testDefaultConstruct(){
  WordDist dictionary;

  TS_ASSERT_EQUALS( dictionary.size(), 0 );
}

void testAddWord0(){
  WordDist dictionary;
  dictionary.addToDictionary( "hello" );

  TS_ASSERT_EQUALS( dictionary.size(), 1 );
}

void testAddWord1(){
  WordDist dictionary;
  dictionary.addToDictionary( "hello" );
  dictionary.addToDictionary( "to" );
  dictionary.addToDictionary( "the" );
  dictionary.addToDictionary( "world" );

  TS_ASSERT_EQUALS( dictionary.size(), 4 );
}

void testAddWord2(){
  WordDist dictionary;
  dictionary.addToDictionary( "hello" );
  dictionary.addToDictionary( "hello" );

  TS_ASSERT_EQUALS( dictionary.size(), 1 );
}

void testIsStored0(){
  WordDist dictionary;
  dictionary.addToDictionary( "hello" );
  dictionary.addToDictionary( "to" );
  dictionary.addToDictionary( "the" );
  dictionary.addToDictionary( "world" );

  TS_ASSERT_EQUALS( dictionary.isStored( "hello" ), true );
}

void testIsStored1(){
  WordDist dictionary;
  dictionary.addToDictionary( "hello" );
  dictionary.addToDictionary( "to" );
  dictionary.addToDictionary( "the" );
  dictionary.addToDictionary( "world" );

  TS_ASSERT_EQUALS( dictionary.isStored( "to" ), true );
}

void testIsStored2(){
  WordDist dictionary;
  dictionary.addToDictionary( "hello" );
  dictionary.addToDictionary( "to" );
  dictionary.addToDictionary( "the" );
  dictionary.addToDictionary( "world" );

  TS_ASSERT_EQUALS( dictionary.isStored( "the" ), true );
}

void testIsStored3(){
  WordDist dictionary;
  dictionary.addToDictionary( "hello" );
  dictionary.addToDictionary( "to" );
  dictionary.addToDictionary( "the" );
  dictionary.addToDictionary( "world" );

  TS_ASSERT_EQUALS( dictionary.isStored( "world" ), true );
}

void testGetDistanceSet0(){
  WordDist dictionary;
  dictionary.addToDictionary( "hello" );
  dictionary.addToDictionary( "to" );
  dictionary.addToDictionary( "the" );
  dictionary.addToDictionary( "world" );

  set<string> result_set;
  result_set.insert( "world" );

  TS_ASSERT_EQUALS( dictionary.getDistanceSet( "would", 1 ), result_set );
}
  
};
