/*
  AStack_test.h
  Unit tests for HW07, AStack.
  
*/

#include "AStack.h"
#include <stdexcept>

#include <cxxtest/TestSuite.h>

class AStackTest : public CxxTest::TestSuite {
public:

  void testPeek0(){
    AStack<int> a;
    a.push( 5 );
    TS_ASSERT_EQUALS( a.peek(), 5 );
  }
 
  void testPeek1(){
    AStack<int> a;
    a.push( 5 );
    a.push( 10 );
    a.push( 15 );
    TS_ASSERT_EQUALS( a.peek(), 15 );
  }

  void testPeek2(){
    AStack<int> a;
    a.push( 5 );
    a.push( 10 );
    a.push( 15 );
    a.pop();
    TS_ASSERT_EQUALS( a.peek(), 10 );
  }

  void testPeek3(){
    AStack<double> a;
    a.push( 0.05 );
    TS_ASSERT_EQUALS( a.peek(), 0.05 );
  }
 
  void testPeek4(){
    AStack<double> a;
    a.push( 0.05 );
    a.push( 0.10 );
    a.push( 0.15 );
    TS_ASSERT_EQUALS( a.peek(), 0.15 );
  }

  void testPeek5(){
    AStack<double> a;
    a.push( 0.05 );
    a.push( 0.10 );
    a.push( 0.15 );
    a.pop();
    TS_ASSERT_EQUALS( a.peek(), 0.10 );
  }

  void testSize0(){
    AStack<int> a;
    TS_ASSERT_EQUALS( a.size(), 0 );
  }

  void testSize1(){
    AStack<int> a;
    a.push( 5 );
    a.push( 10 );
    a.push( 15 );
    TS_ASSERT_EQUALS( a.size(), 3 );
  }

  void testSize2(){
    AStack<double> a;
    TS_ASSERT_EQUALS( a.size(), 0 );
  }

  void testSize3(){
    AStack<double> a;
    a.push( 0.05 );
    a.push( 0.10 );
    a.push( 0.15 );
    TS_ASSERT_EQUALS( a.size(), 3 );
  }

  void testEmpty0(){
    AStack<int> a;
    TS_ASSERT_EQUALS( a.empty(), true );
  }

  void testEmpty1(){
    AStack<int> a;
    a.push( 5 );
    TS_ASSERT_EQUALS( a.empty(), false );
  }

  void testEmpty2(){
    AStack<double> a;
    TS_ASSERT_EQUALS( a.empty(), true );
  }

  void testEmpty3(){
    AStack<double> a;
    a.push( 0.05 );
    TS_ASSERT_EQUALS( a.empty(), false );
  }

  void testCatchThrow0(){
    AStack<int> a;
    TS_ASSERT_THROWS_ANYTHING( a.peek() );
  }

  void testCatchThrow1(){
    AStack<int> a;
    a.push( 5 );
    a.pop();
    TS_ASSERT_THROWS_ANYTHING( a.peek() );
  }

  void testCatchThrow2(){
    AStack<double> a;
    TS_ASSERT_THROWS_ANYTHING( a.peek() );
  }

  void testCatchThrow3(){
    AStack<double> a;
    a.push( 0.05 );
    a.pop();
    TS_ASSERT_THROWS_ANYTHING( a.peek() );
  }
 
};
