/*
  AQueue_test.h
  Unit tests for HW07, AQueue.
  
*/

#include "AQueue.h"
#include <stdexcept>
#include <iostream>

#include <cxxtest/TestSuite.h>

class AQueueTest : public CxxTest::TestSuite {
public:

  void testPeek0(){
    AQueue<int> a;
    a.enqueue( 5 );
    TS_ASSERT_EQUALS( a.peek(), 5 );
  }
 
  void testPeek1(){
    AQueue<int> a;
    a.enqueue( 5 );
    a.enqueue( 10 );
    a.enqueue( 15 );
    TS_ASSERT_EQUALS( a.peek(), 5 );
  }

  void testPeek2(){
    AQueue<int> a;
    a.enqueue( 5 );
    a.enqueue( 10 );
    a.enqueue( 15 );
    a.dequeue();
    TS_ASSERT_EQUALS( a.peek(), 10 );
  }

  void testPeek3(){
    AQueue<double> a;
    a.enqueue( 0.05 );
    TS_ASSERT_EQUALS( a.peek(), 0.05 );
  }
 
  void testPeek4(){
    AQueue<double> a;
    a.enqueue( 0.05 );
    a.enqueue( 0.10 );
    a.enqueue( 0.15 );
    TS_ASSERT_EQUALS( a.peek(), 0.05 );
  }

  void testPeek5(){
    AQueue<double> a;
    a.enqueue( 0.05 );
    a.enqueue( 0.10 );
    a.enqueue( 0.15 );
    a.dequeue();
    TS_ASSERT_EQUALS( a.peek(), 0.10 );
  }

  void testSize0(){
    AQueue<int> a;
    TS_ASSERT_EQUALS( a.size(), 0 );
  }

  void testSize1(){
    AQueue<int> a;
    a.enqueue( 5 );
    a.enqueue( 10 );
    a.enqueue( 15 );
    TS_ASSERT_EQUALS( a.size(), 3 );
  }

  void testSize2(){
    AQueue<double> a;
    TS_ASSERT_EQUALS( a.size(), 0 );
  }

  void testSize3(){
    AQueue<double> a;
    a.enqueue( 0.05 );
    a.enqueue( 0.10 );
    a.enqueue( 0.15 );
    TS_ASSERT_EQUALS( a.size(), 3 );
  }

  void testEmpty0(){
    AQueue<int> a;
    TS_ASSERT_EQUALS( a.empty(), true );
  }

  void testEmpty1(){
    AQueue<int> a;
    a.enqueue( 5 );
    TS_ASSERT_EQUALS( a.empty(), false );
  }

  void testEmpty2(){
    AQueue<double> a;
    TS_ASSERT_EQUALS( a.empty(), true );
  }

  void testEmpty3(){
    AQueue<double> a;
    a.enqueue( 0.05 );
    TS_ASSERT_EQUALS( a.empty(), false );
  }

  void testCatchThrow0(){
    AQueue<int> a;
    TS_ASSERT_THROWS_ANYTHING( a.peek() );
  }

  void testCatchThrow1(){
    AQueue<int> a;
    a.enqueue( 5 );
    a.dequeue();
    TS_ASSERT_THROWS_ANYTHING( a.peek() );
  }

  void testCatchThrow2(){
    AQueue<double> a;
    TS_ASSERT_THROWS_ANYTHING( a.peek() );
  }

  void testCatchThrow3(){
    AQueue<double> a;
    a.enqueue( 0.05 );
    a.dequeue();
    TS_ASSERT_THROWS_ANYTHING( a.peek() );
  }



};
