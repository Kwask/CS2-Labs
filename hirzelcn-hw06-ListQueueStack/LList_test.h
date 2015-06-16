/*
  LList_test.h
  Unit tests for HW06, linked-list.
  
*/

#include "LList.h"
#include <stdexcept>
#include <string>

#include <cxxtest/TestSuite.h>

class LListTest : public CxxTest::TestSuite {
public:

  void testSize1() {
    LList<int> a;
    TS_ASSERT_EQUALS(a.getSize(), 0);
  }

  
  // Mine
  void testPushFront0() {
    LList<int> a;
    a.pushFront( 5 );
    TS_ASSERT_EQUALS( a.getSize(), 1 );
  }

  // Mine
  void testPushFront1() {
    LList<int> a;
    a.pushFront( 5 );
    TS_ASSERT_EQUALS( a.getAt( 0 ), 5 );
  }

  // Mine
  void testPushFront2() {
    LList<int> a;
    a.pushFront( 8 );
    a.pushFront( 7 );
    a.pushFront( 6 );
    a.pushFront( 5 );
    TS_ASSERT_EQUALS( a.getSize(), 4 );
  }

  // Mine
  void testPushFront3() {
    LList<int> a;
    a.pushFront( 8 );
    a.pushFront( 7 );
    a.pushFront( 6 );
    a.pushFront( 5 );
    TS_ASSERT_EQUALS( a.getAt( 0 ), 5 );
  }

  // Mine
  void testPushFront4() {
    LList<int> a;
    a.pushFront( 8 );
    a.pushFront( 7 );
    a.pushFront( 6 );
    a.pushFront( 5 );
    TS_ASSERT_EQUALS( a.getAt( 1 ), 6 );
  }

  // Mine
  void testPushFront5() {
    LList<int> a;
    a.pushFront( 8 );
    a.pushFront( 7 );
    a.pushFront( 6 );
    a.pushFront( 5 );
    TS_ASSERT_EQUALS( a.getAt( 2 ), 7 );
  }

  // Mine
  void testPushFront6() {
    LList<int> a;
    a.pushFront( 8 );
    a.pushFront( 7 );
    a.pushFront( 6 );
    a.pushFront( 5 );
    TS_ASSERT_EQUALS( a.getAt( 3 ), 8 );
  }
  
  // Mine
  void testPushBack0() {
    LList<int> a;
    a.pushBack( 8 );
    TS_ASSERT_EQUALS( a.getSize(), 1 );
  }

  // Mine
  void testPushBack1() {
    LList<int> a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );
    TS_ASSERT_EQUALS( a.getSize(), 4 );
  }

  // Mine
  void testPushBack2() {
    LList<int> a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );
    TS_ASSERT_EQUALS( a.getAt( 0 ), 8 );
  }

  // Mine
  void testPushBack3() {
    LList<int> a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );
    TS_ASSERT_EQUALS( a.getAt( 1 ), 7 );
  }

  // Mine
  void testPushBack4() {
    LList<int> a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );
    TS_ASSERT_EQUALS( a.getAt( 2 ), 6 );
  }

  // Mine
  void testPushBack5() {
    LList<int> a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );
    TS_ASSERT_EQUALS( a.getAt( 3 ), 5 );
  }

  // Mine
  void testSetAt0() {
    LList<int> a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );

    a.setAt( 10, 2 );
    TS_ASSERT_EQUALS( a.getAt( 2 ), 10 );
  }

  // Mine
  void testSetAt1() {
    LList<int> a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );

    a.setAt( 10, 3 );
    TS_ASSERT_EQUALS( a.getAt( 3 ), 10 );
  }

  // Mine
  void testGetAt0() {
    LList<int> a;
    a.pushBack( 8 );
    TS_ASSERT_EQUALS( a.getAt( 0 ), 8 );
  }

  // Mine
  void testGetAt2() {
    LList<int> a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );

    TS_ASSERT_EQUALS( a.getAt( 0 ), 8 );
  }

  // Mine
  void testGetAt3() {
    LList<int> a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );

    TS_ASSERT_EQUALS( a.getAt( 3 ), 5 );
  }

  // Mine
  void testInsert0() {
    LList<int> a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );

    a.insert( 10, 2 ); 
    TS_ASSERT_EQUALS( a.getAt( 2 ), 10 );
  }

  // Mine
  void testInsert1() {
    LList<int> a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );

    a.insert( 10, 2 ); 
    TS_ASSERT_EQUALS( a.getAt( 3 ), 6 );
  }

  // Mine
  void testInsert2() {
    LList<int> a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );

    a.insert( 10, 2 ); 
    TS_ASSERT_EQUALS( a.getAt( 1 ), 7 );
  }

  // Mine
  void testInsert3() {
    LList<int> a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );

    a.insert( 10, 2 ); 
    TS_ASSERT_EQUALS( a.getAt( 1 ), 7 );
  }

  // Mine
  void testRemove0() {
    LList<int> a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );

    a.remove( 1 ); 
    TS_ASSERT_EQUALS( a.getAt( 1 ), 6 );
  }

  // Mine
  void testRemove1() {
    LList<int> a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );

    a.remove( 1 ); 
    TS_ASSERT_EQUALS( a.getAt( 0 ), 8 );
  }

  // Mine
  void testRemove2() {
    LList<int> a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );

    a.remove( 1 ); 
    TS_ASSERT_EQUALS( a.getAt( 2 ), 5 );
  }

  // Mine
  void testPrint0() {
    LList<int> a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );
    TS_ASSERT_EQUALS( a.print(), "[8, 7, 6, 5]" );
  }

  // Mine
  void testPrint1() {
    LList<int> a;
    a.pushBack( 8 );
    TS_ASSERT_EQUALS( a.print(), "[8]" );
  }

  // Mine
  void testFind0() {
    LList<int> a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );
    TS_ASSERT_EQUALS( a.find( 6, -1 ), 2 );
  }

  // Mine
  void testFind1() {
    LList<int> a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );
    TS_ASSERT_EQUALS( a.find( 9, -1 ), -1 );
  }

  // Mine
  void testFind2() {
    LList<int> a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );
    TS_ASSERT_EQUALS( a.find( 8, 1 ), -1 );
  }

  // Mine
  void testThrow0() {
    LList<int> a;
    try{
      a.getAt( 1 );
    }catch( exception &e ){
      return;
    }
    TS_ASSERT( 0 );
  }

  // Mine
  void testThrow1() {
    LList<int> a;
    try{
      a.setAt( 1, 1 );
    }catch( exception &e ){
      return;
    }
    TS_ASSERT( 0 );
  }


  // Mine
  void testThrow2() {
    LList<int> a;
    a.pushBack( 10 );
    a.pushBack( 15 );

    try{
      a.find( 20, 3 );
    }catch( exception &e ){
      return;
    }
    TS_ASSERT( 0 );
  }

};

