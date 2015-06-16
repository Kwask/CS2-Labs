/*
  IntList_test.h
  Unit tests for Lab6, linked-list.
  
*/

#include "IntList.h"
#include "Node.h"

#include <stdexcept>
#include <sstream>

#include <cxxtest/TestSuite.h>

class IntListTest : public CxxTest::TestSuite {
public:

  void testDefaultConstructor() {
    IntList a;
    TS_ASSERT_EQUALS( a.getSize(), 0 );
  }

  // Mine
  void testPushFront0() {
    IntList a;
    a.pushFront( 5 );
    TS_ASSERT_EQUALS( a.getSize(), 1 );
  }

  // Mine
  void testPushFront1() {
    IntList a;
    a.pushFront( 5 );
    TS_ASSERT_EQUALS( a.getAt( 0 ), 5 );
  }

  // Mine
  void testPushFront2() {
    IntList a;
    a.pushFront( 8 );
    a.pushFront( 7 );
    a.pushFront( 6 );
    a.pushFront( 5 );
    TS_ASSERT_EQUALS( a.getSize(), 4 );
  }

  // Mine
  void testPushFront3() {
    IntList a;
    a.pushFront( 8 );
    a.pushFront( 7 );
    a.pushFront( 6 );
    a.pushFront( 5 );
    TS_ASSERT_EQUALS( a.getAt( 0 ), 5 );
  }

  // Mine
  void testPushFront4() {
    IntList a;
    a.pushFront( 8 );
    a.pushFront( 7 );
    a.pushFront( 6 );
    a.pushFront( 5 );
    TS_ASSERT_EQUALS( a.getAt( 1 ), 6 );
  }

  // Mine
  void testPushFront5() {
    IntList a;
    a.pushFront( 8 );
    a.pushFront( 7 );
    a.pushFront( 6 );
    a.pushFront( 5 );
    TS_ASSERT_EQUALS( a.getAt( 2 ), 7 );
  }

  // Mine
  void testPushFront6() {
    IntList a;
    a.pushFront( 8 );
    a.pushFront( 7 );
    a.pushFront( 6 );
    a.pushFront( 5 );
    TS_ASSERT_EQUALS( a.getAt( 3 ), 8 );
  }
  
  // Mine
  void testPushBack0() {
    IntList a;
    a.pushBack( 8 );
    TS_ASSERT_EQUALS( a.getSize(), 1 );
  }

  // Mine
  void testPushBack1() {
    IntList a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );
    TS_ASSERT_EQUALS( a.getSize(), 4 );
  }

  // Mine
  void testPushBack2() {
    IntList a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );
    TS_ASSERT_EQUALS( a.getAt( 0 ), 8 );
  }

  // Mine
  void testPushBack3() {
    IntList a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );
    TS_ASSERT_EQUALS( a.getAt( 1 ), 7 );
  }

  // Mine
  void testPushBack4() {
    IntList a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );
    TS_ASSERT_EQUALS( a.getAt( 2 ), 6 );
  }

  // Mine
  void testPushBack5() {
    IntList a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );
    TS_ASSERT_EQUALS( a.getAt( 3 ), 5 );
  }

  // Mine
  void testSetAt0() {
    IntList a;
    a.pushFront( 1 );
    TS_ASSERT_EQUALS( a.setAt( 0, 0 ), true );
  }

  // Mine
  void testSetAt1() {
    IntList a;
    a.pushFront( 1 );
    TS_ASSERT_EQUALS( a.setAt( 1, 0 ), false );
  }

  // Mine
  void testSetAt2() {
    IntList a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );

    a.setAt( 2, 10 );
    TS_ASSERT_EQUALS( a.getAt( 2 ), 10 );
  }

  // Mine
  void testSetAt3() {
    IntList a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );

    a.setAt( 3, 10 );
    TS_ASSERT_EQUALS( a.getAt( 3 ), 10 );
  }

  // Mine
  void testSetAt4() {
    IntList a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );

    TS_ASSERT_EQUALS( a.setAt( 2, 10 ), true );
  }

  // Mine
  void testGetAt0() {
    IntList a;
    a.pushBack( 8 );
    TS_ASSERT_EQUALS( a.getAt( 0 ), 8 );
  }

  // Mine
  void testGetAt1() {
    IntList a;
    a.pushBack( 8 );
    TS_ASSERT_EQUALS( a.getAt( 1 ), 0 );
  }

  // Mine
  void testGetAt2() {
    IntList a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );

    TS_ASSERT_EQUALS( a.getAt( 0 ), 8 );
  }

  // Mine
  void testGetAt3() {
    IntList a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );

    TS_ASSERT_EQUALS( a.getAt( 3 ), 5 );
  }

  // Mine
  void testGetAt4() {
    IntList a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );

    TS_ASSERT_EQUALS( a.getAt( 4 ), 0 );
  }

  // Mine
  void testInsert0() {
    IntList a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );

    a.insert( 2, 10 ); 
    TS_ASSERT_EQUALS( a.getAt( 2 ), 10 );
  }

  // Mine
  void testInsert1() {
    IntList a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );

    a.insert( 2, 10 ); 
    TS_ASSERT_EQUALS( a.getAt( 3 ), 6 );
  }

  // Mine
  void testInsert2() {
    IntList a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );

    a.insert( 2, 10 ); 
    TS_ASSERT_EQUALS( a.getAt( 1 ), 7 );
  }

  // Mine
  void testInsert3() {
    IntList a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );

    a.insert( 2, 10 ); 
    TS_ASSERT_EQUALS( a.getAt( 1 ), 7 );
  }

  // Mine
  void testRemove0() {
    IntList a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );

    a.remove( 1 ); 
    TS_ASSERT_EQUALS( a.getAt( 1 ), 6 );
  }

  // Mine
  void testRemove1() {
    IntList a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );

    a.remove( 1 ); 
    TS_ASSERT_EQUALS( a.getAt( 0 ), 8 );
  }

  // Mine
  void testRemove2() {
    IntList a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );

    a.remove( 1 ); 
    TS_ASSERT_EQUALS( a.getAt( 2 ), 5 );
  }

  // Mine
  void testPrint0() {
    IntList a;
    a.pushBack( 8 );
    a.pushBack( 7 );
    a.pushBack( 6 );
    a.pushBack( 5 );
    TS_ASSERT_EQUALS( a.print(), "[8, 7, 6, 5]" );
  }

  // Mine
  void testPrint1() {
    IntList a;
    a.pushBack( 8 );
    TS_ASSERT_EQUALS( a.print(), "[8]" );
  }
};
