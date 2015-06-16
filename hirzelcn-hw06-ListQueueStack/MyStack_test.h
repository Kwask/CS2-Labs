/*
  MyStack_test.h
  Unit tests for HW06, MyStack.
  
*/

#include "MyStack.h"
#include <stdexcept>

#include <cxxtest/TestSuite.h>

class MyStackTest : public CxxTest::TestSuite {
public:

  void testSize() {
    MyStack<int> a;
    TS_ASSERT_EQUALS(a.size(), 0);
  }

  // Mine
  void testSize0() {
    MyStack<int> a;
    a.push( 5 );
    TS_ASSERT_EQUALS( a.size(), 1 );
  }

  // Mine
  void testSize1() {
    MyStack<int> a;
    a.push( 5 );
    a.push( 10 );
    a.push( 15 );
    TS_ASSERT_EQUALS( a.size(), 3 );
  }
  
  // Mine
  void testDequeue0() {
    MyStack<int> a;
    a.push( 5 );
    a.pop();
    TS_ASSERT_EQUALS( a.size(), 0 );
  }

  // Mine
  void testDequeue1() {
    MyStack<int> a;
    a.push( 5 );
    a.push( 10 );
    a.pop();
    TS_ASSERT_EQUALS( a.size(), 1 );
  }

  // Mine
  void testDequeue2() {
    MyStack<int> a;
    a.push( 5 );
    a.push( 10 );
    a.pop();
    a.pop();
    TS_ASSERT_EQUALS( a.size(), 0 );
  }

  // Mine
  void testPeek0() {
    MyStack<int> a;
    a.push( 5 );
    a.push( 10 );
    TS_ASSERT_EQUALS( a.peek(), 10 );
  }

  // Mine
  void testPeek1() {
    MyStack<int> a;
    a.push( 5 );
    a.push( 10 );
    a.pop();
    TS_ASSERT_EQUALS( a.peek(), 5 );
  }

  // Mine
  void testIsEmpty0() {
    MyStack<int> a;
    TS_ASSERT_EQUALS( a.isEmpty(), true );
  }

  // Mine
  void testIsEmpty1() {
    MyStack<int> a;
    a.push( 5 );
    TS_ASSERT_EQUALS( a.isEmpty(), false );
  }

  // Mine
  void testIsEmpty2() {
    MyStack<int> a;
    a.push( 5 );
    a.pop();
    TS_ASSERT_EQUALS( a.isEmpty(), true );
  }
  
  // Mine
  void testThrow0() {
    MyStack<int> a;
    try{
      a.peek();
    }catch( exception &e ){
      return;
    }
    TS_ASSERT( 0 );
  }

  // Mine
  void testThrow1() {
    MyStack<int> a;
    a.push( 5 );
    a.pop();

    try{
      a.peek();
    }catch( exception &e ){
      return;
    }
    TS_ASSERT( 0 );
  }

  // Mine
  void testThrow2() {
    MyStack<int> a;
    a.push( 5 );
    a.pop();

    try{
      a.pop();
    }catch( exception &e ){
      return;
    }
    TS_ASSERT( 0 );
  }
};
