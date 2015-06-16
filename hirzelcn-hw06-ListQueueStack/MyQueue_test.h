/*
  MyQueue_test.h
  Unit tests for HW06, MyQueue.
  
*/

#include "MyQueue.h"
#include <stdexcept>

#include <cxxtest/TestSuite.h>

class MyQueueTest : public CxxTest::TestSuite {
public:

  void testEnqueuePeek() {
    MyQueue<int> a;
    a.enqueue(5);
    TS_ASSERT_EQUALS( a.peek(), 5 );
  }

  // Mine
  void testSize0() {
    MyQueue<int> a;
    a.enqueue( 5 );
    TS_ASSERT_EQUALS( a.size(), 1 );
  }

  // Mine
  void testSize1() {
    MyQueue<int> a;
    a.enqueue( 5 );
    a.enqueue( 10 );
    a.enqueue( 15 );
    TS_ASSERT_EQUALS( a.size(), 3 );
  }
  
  // Mine
  void testDequeue0() {
    MyQueue<int> a;
    a.enqueue( 5 );
    a.dequeue();
    TS_ASSERT_EQUALS( a.size(), 0 );
  }

  // Mine
  void testDequeue1() {
    MyQueue<int> a;
    a.enqueue( 5 );
    a.enqueue( 10 );
    a.dequeue();
    TS_ASSERT_EQUALS( a.size(), 1 );
  }

  // Mine
  void testDequeue2() {
    MyQueue<int> a;
    a.enqueue( 5 );
    a.enqueue( 10 );
    a.dequeue();
    a.dequeue();
    TS_ASSERT_EQUALS( a.size(), 0 );
  }

  // Mine
  void testPeek0() {
    MyQueue<int> a;
    a.enqueue( 5 );
    a.enqueue( 10 );
    TS_ASSERT_EQUALS( a.peek(), 5 );
  }

  // Mine
  void testPeek1() {
    MyQueue<int> a;
    a.enqueue( 5 );
    a.enqueue( 10 );
    a.dequeue();
    TS_ASSERT_EQUALS( a.peek(), 10 );
  }

  // Mine
  void testIsEmpty0() {
    MyQueue<int> a;
    TS_ASSERT_EQUALS( a.isEmpty(), true );
  }

  // Mine
  void testIsEmpty1() {
    MyQueue<int> a;
    a.enqueue( 5 );
    TS_ASSERT_EQUALS( a.isEmpty(), false );
  }

  // Mine
  void testIsEmpty2() {
    MyQueue<int> a;
    a.enqueue( 5 );
    a.dequeue();
    TS_ASSERT_EQUALS( a.isEmpty(), true );
  }

  // Mine
  void testThrow0() {
    MyQueue<int> a;
    try{
      a.peek();
    }catch( exception &e ){
      return;
    }
    TS_ASSERT( 0 );
  }

  // Mine
  void testThrow1() {
    MyQueue<int> a;
    a.enqueue( 5 );
    a.dequeue();

    try{
      a.peek();
    }catch( exception &e ){
      return;
    }
    TS_ASSERT( 0 );
  }

  // Mine
  void testThrow2() {
    MyQueue<int> a;
    a.enqueue( 5 );
    a.dequeue();

    try{
      a.dequeue();
    }catch( exception &e ){
      return;
    }
    TS_ASSERT( 0 );
  }
};
