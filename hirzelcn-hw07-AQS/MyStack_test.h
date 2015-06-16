/*
  MyStack_test.h
  Unit tests for HW07, MyStack.
  
*/

#include "MyStack.h"
#include <stdexcept>

#include <cxxtest/TestSuite.h>

class MyStackTest : public CxxTest::TestSuite {
public:

  void testPeek0(){
    MyStack<int> a;
    a.push( 5 );
    TS_ASSERT_EQUALS( a.peek(), 5 );
  }
 
  void testPeek1(){
    MyStack<int> a;
    a.push( 5 );
    a.push( 10 );
    a.push( 15 );
    TS_ASSERT_EQUALS( a.peek(), 15 );
  }

  void testPeek2(){
    MyStack<int> a;
    a.push( 5 );
    a.push( 10 );
    a.push( 15 );
    a.pop();
    TS_ASSERT_EQUALS( a.peek(), 10 );
  }

  void testPeek3(){
    MyStack<double> a;
    a.push( 0.05 );
    TS_ASSERT_EQUALS( a.peek(), 0.05 );
  }
 
  void testPeek4(){
    MyStack<double> a;
    a.push( 0.05 );
    a.push( 0.10 );
    a.push( 0.15 );
    TS_ASSERT_EQUALS( a.peek(), 0.15 );
  }

  void testPeek5(){
    MyStack<double> a;
    a.push( 0.05 );
    a.push( 0.10 );
    a.push( 0.15 );
    a.pop();
    TS_ASSERT_EQUALS( a.peek(), 0.10 );
  }

  void testSize0(){
    MyStack<int> a;
    TS_ASSERT_EQUALS( a.size(), 0 );
  }

  void testSize1(){
    MyStack<int> a;
    a.push( 5 );
    a.push( 10 );
    a.push( 15 );
    TS_ASSERT_EQUALS( a.size(), 3 );
  }

  void testSize2(){
    MyStack<double> a;
    TS_ASSERT_EQUALS( a.size(), 0 );
  }

  void testSize3(){
    MyStack<double> a;
    a.push( 0.05 );
    a.push( 0.10 );
    a.push( 0.15 );
    TS_ASSERT_EQUALS( a.size(), 3 );
  }

  void testEmpty0(){
    MyStack<int> a;
    TS_ASSERT_EQUALS( a.empty(), true );
  }

  void testEmpty1(){
    MyStack<int> a;
    a.push( 5 );
    TS_ASSERT_EQUALS( a.empty(), false );
  }

  void testEmpty2(){
    MyStack<double> a;
    TS_ASSERT_EQUALS( a.empty(), true );
  }

  void testEmpty3(){
    MyStack<double> a;
    a.push( 0.05 );
    TS_ASSERT_EQUALS( a.empty(), false );
  }

  void testCatchThrow0(){
    MyStack<int> a;
    TS_ASSERT_THROWS_ANYTHING( a.peek() );
  }

  void testCatchThrow1(){
    MyStack<int> a;
    a.push( 5 );
    a.pop();
    TS_ASSERT_THROWS_ANYTHING( a.peek() );
  }

  void testCatchThrow2(){
    MyStack<double> a;
    TS_ASSERT_THROWS_ANYTHING( a.peek() );
  }

  void testCatchThrow3(){
    MyStack<double> a;
    a.push( 0.05 );
    a.pop();
    TS_ASSERT_THROWS_ANYTHING( a.peek() );
  }

};
