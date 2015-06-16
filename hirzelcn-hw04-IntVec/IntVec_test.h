#include "IntVec.h"
#include <stdexcept>

#include <cxxtest/TestSuite.h>

class IntVecTest : public CxxTest::TestSuite {
public:
// Constructors
  void testDefaultConstructorSize(){
    IntVec a;
    TS_ASSERT_EQUALS( 0, a.getSize() );
  }

  void testStringConstructorSize0(){
    IntVec a( "[0, 1]" );
    TS_ASSERT_EQUALS( 2, a.getSize() );
  }

  // Mine
  void testStringConstructorSize1(){
    IntVec a( "[0, 1, 2, 3, 4, 5]" );
    TS_ASSERT_EQUALS( 6, a.getSize() );
  }

  // Mine
  void testStringConstructorSize2(){
    IntVec a( "[0, -1, -2, -3, -4, -5]" );
    TS_ASSERT_EQUALS( 6, a.getSize() );
  }

  // Mine
  void testIntVecConstructorSize2(){
    IntVec a( IntVec( "[0, -1, -2, -3, -4, -5]" ));
    TS_ASSERT_EQUALS( 6, a.getSize() );
  }

  // Mine
  void testStringConstructorString0(){
    IntVec a( "[0, 1, 2, 3, 4, 5]" );
    TS_ASSERT_EQUALS( "[0, 1, 2, 3, 4, 5]", a.getAsString() );
  }

  // Mine
  void testStringConstructorString1(){
    IntVec a( "[0, -1, -2, -3, -4, -5]" );
    TS_ASSERT_EQUALS( "[0, -1, -2, -3, -4, -5]", a.getAsString() );
  }

  // Mine
  void testStringConstructorString2(){
    IntVec a( "[-0, -1, -2, -3, -4, -5]" );
    TS_ASSERT_EQUALS( "[0, -1, -2, -3, -4, -5]", a.getAsString() );
  }

  // Mine
  void testStringConstructorString3(){
    IntVec a( "[0, -1, -2, 3, -4, 5]" );
    TS_ASSERT_EQUALS( "[0, -1, -2, 3, -4, 5]", a.getAsString() );
  }

  // Mine
  void testStringConstructorString4(){
    IntVec a( "[0, 1,  2,   3,    4,     5]" );
    TS_ASSERT_EQUALS( "[0, 1, 2, 3, 4, 5]", a.getAsString() );
  }

  // Mine
  void testPushBackSize0(){
    IntVec a;
    a.pushBack( 0 );
    TS_ASSERT_EQUALS( 1, a.getSize() );
  }

  // Mine
  void testPushBackSize1(){
    IntVec a;
    a.pushBack( 0 );
    a.pushBack( 1 );
    a.pushBack( 2 );
    TS_ASSERT_EQUALS( 3, a.getSize() );
  }

  // Mine
  void testPushBackString0(){
    IntVec a;
    a.pushBack( 0 );
    a.pushBack( 1 );
    a.pushBack( 2 );
    TS_ASSERT_EQUALS( "[0, 1, 2]", a.getAsString() );
  }

  // Mine
  void testGetAt0(){
    IntVec a( "[0, 1, 2, 3, 4]" );
    TS_ASSERT_EQUALS( 2, a.getAt( 2 ) );
  }

  // Mine
  void testGetAt1(){
    IntVec a( "[0, 1, 2, 3, 4]" );
    TS_ASSERT_EQUALS( 4, a.getAt( 4 ) );
  }

  // Mine
  void testGetAt2(){
    IntVec a( "[0, 1, 2, 3, 4]" );
    TS_ASSERT_EQUALS( 0, a.getAt( 0 ) );
  }

  // Mine
  void testGetAt3(){
    IntVec a( "[0, 1, 2, 3, 4]" );
    TS_ASSERT_EQUALS( 0, a.getAt( 5 ) );
  }

  // Mine
  void testGetAt4(){
    IntVec a( "[0, 1, 2, 3, 4]" );
    a.clear();
    TS_ASSERT_EQUALS( 0, a.getAt( 0 ) );
  }

  // Mine
  void testSetAt0(){
    IntVec a( "[0, 1, 2, 3, 4]" );
    TS_ASSERT_EQUALS( true, a.setAt( 3, 2 ));
  }

  // Mine
  void testSetAt1(){
    IntVec a( "[0, 1, 2, 3, 4]" );
    TS_ASSERT_EQUALS( false, a.setAt( 3, 5 ));
  }

  // Mine
  void testSetAt2(){
    IntVec a( "[0, 1, 2, 3, 4]" );
    a.setAt( 3, 2 );
    TS_ASSERT_EQUALS( 3, a.getAt( 2 ));
  }

  // Mine
  void testSetAt3(){
    IntVec a( "[0, 1, 2, 3, 4]" );
    a.setAt( 1, 0 );
    TS_ASSERT_EQUALS( 1, a.getAt( 0 ));
  }

  // Mine
  void testSetAt4(){
    IntVec a( "[0, 1, 2, 3, 4]" );
    a.setAt( 1, 4 );
    TS_ASSERT_EQUALS( 1, a.getAt( 4 ));
  }

  // Mine
  void testGetCapacity0(){
    IntVec a( "[0, 1, 2, 3, 4]" );
    TS_ASSERT_EQUALS( 10, a.getCapacity() );
  }

  // Mine
  void testGetCapacity1(){
    IntVec a( "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]" );
    TS_ASSERT_EQUALS( 20, a.getCapacity() );
  }

  // Mine
  void testClear0(){
    IntVec a( "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]" );
    a.clear();
    TS_ASSERT_EQUALS( 0, a.getCapacity() );
  }

  // Mine
  void testClear1(){
    IntVec a( "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]" );
    a.clear();
    TS_ASSERT_EQUALS( 0, a.getSize() );
  }

  // Mine
  void testClear2(){
    IntVec a( "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]" );
    a.clear();
    TS_ASSERT_EQUALS( 0, a.getAt( 1 ));
  }

  // Mine
  void testSum0(){
    IntVec a( "[1, 1, 1, 1, 1, 1, 1, 1, 1, 1]" );
    TS_ASSERT_EQUALS( 10, a.sum() );
  }

  // Mine
  void testSum1(){
    IntVec a( "[1, 1, 1, 1, 1, 1, 1, 1, 1, 1]" );
    a.pushBack( 1 );
    TS_ASSERT_EQUALS( 11, a.sum() );
  }

  // Mine
  void testSum2(){
    IntVec a( "[1, 1, 1, 1, 1, 1, 1, 1, 1, 1]" );
    a.clear();
    TS_ASSERT_EQUALS( 0, a.sum() );
  }

  // Mine
  void testSum3(){
    IntVec a( "[1, 1, 1, 1, 1, 1, 1, 1, 1, 1]" );
    a.clear();
    TS_ASSERT_EQUALS( 0, a.sum() );
  }

  // Mine
  void testAverage0(){
    IntVec a( "[1, 1, 1, 1, 1, 1, 1, 1, 1, 1]" );
    TS_ASSERT_EQUALS( 1, a.average() );
  }

  // Mine
  void testAverage1(){
    IntVec a( "[0, 10, 0, 10, 0, 10, 0, 10, 0, 10]" );
    TS_ASSERT_EQUALS( 5, a.average() );
  }

  // Mine
  void testAverage2(){
    IntVec a( "[0, 3]" );
    TS_ASSERT_EQUALS( 1.5f, a.average() );
  }

  // Mine
  void testAverage3(){
    IntVec a;
    TS_ASSERT_EQUALS( 0, a.average() );
  }

  // Mine
  void testAverage4(){
    IntVec a( "[0, 3]" );
    a.clear();
    TS_ASSERT_EQUALS( 0, a.average() );
  }

  // Mine
  void testStandDev0(){
    IntVec a( "[0, 5]" );
    TS_ASSERT_EQUALS( 2.5, a.standardDev() );
  }

  // Mine
  void testStandDev1(){
    IntVec a( "[0, 1]" );
    TS_ASSERT_EQUALS( 0.5, a.standardDev() );
  }

  // Mine
  void testAddVec0(){
    IntVec a( "[0, 1]" );
    TS_ASSERT_EQUALS( "[2, 4]", a.add( IntVec( "[2, 3]" )).getAsString() );
  }

  // Mine
  void testAddVec1(){
    IntVec a( "[0, 1]" );
    TS_ASSERT_EQUALS( "[]", a.add( IntVec( "[2, 3. 4]" )).getAsString() );
  }

  // Mine
  void testAddVec2(){
    IntVec a( "[0, 1]" );
    a.add( IntVec( "[1, 2]" ));
    TS_ASSERT_EQUALS( "[0, 1]", a.getAsString() );
  }

  // Mine
  void testAddNum0(){
    IntVec a( "[0, 1]" );
    TS_ASSERT_EQUALS( "[1, 2]", a.add( 1 ).getAsString() );
  }

  // Mine
  void testAddNum1(){
    IntVec a( "[0, 1]" );
    a.add( 1 );
    TS_ASSERT_EQUALS( "[0, 1]", a.getAsString() );
  }

  // Mine
  void testEquals0(){
    IntVec a( "[0, 1]" );
    TS_ASSERT_EQUALS( true, a.equals( IntVec( "[0, 1]" )));
  }

  // Mine
  void testEquals1(){
    IntVec a( "[0, 1]" );
    TS_ASSERT_EQUALS( false, a.equals( IntVec( "[0, 1, 2]" )));
  }

  // Mine
  void testEquals2(){
    IntVec a;
    TS_ASSERT_EQUALS( false, a.equals( IntVec( "[0, 1, 2]" )));
  }

  // Mine
  void testAppend0(){
    IntVec a;
    TS_ASSERT_EQUALS( "[0, 1, 2]", 
        a.append( IntVec( "[0, 1, 2]" )).getAsString());
  }

  // Mine
  void testAppend1(){
    IntVec a( "[0, 1, 2]" );
    TS_ASSERT_EQUALS( "[0, 1, 2, 3, 4, 5]", 
        a.append( IntVec("[3, 4, 5]" )).getAsString());
  }

  // Mine
  void testAppend2(){
    IntVec a( "[0, 1, 2]" );
    TS_ASSERT_EQUALS( "[0, 1, 2]", 
        a.append( IntVec() ).getAsString());
  }

};
