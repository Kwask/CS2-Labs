#include "BigInt.h"
#include <stdexcept>

#include <cxxtest/TestSuite.h>

class BigIntTest : public CxxTest::TestSuite {
public:
// Constructors

  void testDefaultConstructorString0() {
    BigInt a;
    TS_ASSERT_EQUALS( "0", a.getAsDigits() );
  }

  // Mine
  void testStringConstructorString0() {
    BigInt a( "42" );
    TS_ASSERT_EQUALS( "42", a.getAsDigits() );
  }

  // Mine
  void testStringConstructorString1() {
    BigInt a( "-42" );
    TS_ASSERT_EQUALS( "0", a.getAsDigits() );
  }

  // Mine
  void testStringConstructorLong0() {
    BigInt a( "42" );
    TS_ASSERT_EQUALS( 42, a.getAsLong() );
  }

  // Mine
  void testStringConstructorLong1() {
    BigInt a( "-42" );
    TS_ASSERT_EQUALS( 0, a.getAsLong() );
  }

  void testDefaultConstructorLong0() {
    BigInt a;
    TS_ASSERT_EQUALS( 0, a.getAsLong() );
  }

  // Mine
  void testNumCostructorLong0() {
    BigInt a( 42 );
    TS_ASSERT_EQUALS( 42, a.getAsLong() );
  }

  // Mine
  void testNumCostructorString0() {
    BigInt a( 42 );
    TS_ASSERT_EQUALS( "42", a.getAsDigits() );
  }

  // Mine
  void testBigIntCostructorString0() {
    BigInt a( BigInt( 42 ));
    TS_ASSERT_EQUALS( "42", a.getAsDigits() );
  }

  // Mine
  void testBigIntCostructorLong0() {
    BigInt a( BigInt( 42 ));
    TS_ASSERT_EQUALS( 42, a.getAsLong() );
  }

  // Mine
  void testAddition0() {
    BigInt a( 42 );
    BigInt b( 23 );
    BigInt c( a.add( b ));
    TS_ASSERT_EQUALS( "65", c.getAsDigits() );
  }

  // Mine
  void testAddition1() {
    BigInt a( "42" );
    BigInt b( "23" );
    BigInt c( a.add( b ));
    TS_ASSERT_EQUALS( "65", c.getAsDigits() );
  }

    // Mine
  void testAddition2() {
    BigInt a( "42" );
    BigInt b( "23" );
    BigInt c( a.add( b ));
    TS_ASSERT_EQUALS( 65, c.getAsLong() );
  }

    // Mine
  void testAddition3() {
    BigInt a( 42 );
    BigInt b( 23 );
    BigInt c( a.add( b ));
    TS_ASSERT_EQUALS( 65, c.getAsLong());
  }

  // Mine
  void testAddition4() {
    BigInt a( "10000000000000000000000" );
    BigInt b( "42" );
    BigInt c( a.add( b ));
    TS_ASSERT_EQUALS( "10000000000000000000042", c.getAsDigits() );
  }

  // Mine
  void testAddition5() {
    BigInt a( "5" );
    BigInt b( "5" );
    BigInt c( a.add( b ));
    TS_ASSERT_EQUALS( "10", c.getAsDigits() );
  }

  // Mine
  void testAddition6() {
    BigInt a( "5" );
    BigInt b( a.add( a ));
    TS_ASSERT_EQUALS( "10", b.getAsDigits() );
  }

  // Mine
  void testAddition7() {
    BigInt a( "42" );
    BigInt b( 23 );
    BigInt c( a.add( b ));
    TS_ASSERT_EQUALS( "65", c.getAsDigits() );
  }

  // Mine
  void testAddition8() {
    BigInt a( "42" );
    BigInt b( 23 );
    BigInt c( a.add( b ));
    TS_ASSERT_EQUALS( 65, c.getAsLong() );
  }

  // Mine
  void testAddition9() {
    BigInt a( BigInt( 42 ));
    BigInt b( BigInt( 23 ));
    BigInt c( a.add( b ));
    TS_ASSERT_EQUALS( 65, c.getAsLong() );
  }

  // Mine
  void testAddition10() {
    BigInt a( BigInt( 42 ));
    BigInt b( BigInt( 23 ));
    BigInt c( a.add( b ));
    TS_ASSERT_EQUALS( "65", c.getAsDigits() );
  }

  // Mine
  void testAddition11() {
    BigInt a( BigInt( 42 ));
    BigInt b( 23 );
    BigInt c( a.add( b ));
    TS_ASSERT_EQUALS( "65", c.getAsDigits() );
  }

  // Mine
  void testAddition12() {
    BigInt a( BigInt( 42 ));
    BigInt b( "23" );
    BigInt c( a.add( b ));
    TS_ASSERT_EQUALS( "65", c.getAsDigits() );
  }

  // Mine
  void testAddition13() {
    BigInt a( BigInt( 42 ));
    BigInt b( 23 );
    BigInt c( a.add( b ));
    TS_ASSERT_EQUALS( 65, c.getAsLong() );
  }

  // Mine
  void testAddition14() {
    BigInt a( BigInt( 42 ));
    BigInt b( "23" );
    BigInt c( a.add( b ));
    TS_ASSERT_EQUALS( 65, c.getAsLong() );
  }

  // Mine
  void testOverloadedAdd0() {
    BigInt a( "42" );
    BigInt b( "23" );
    BigInt c = a + b;
    TS_ASSERT_EQUALS( 65, c.getAsLong() );
  }

  // Mine
  void testOverloadedAdd1() {
    BigInt a( "5000");
    BigInt b( "23" );
    BigInt c = a + b;
    TS_ASSERT_EQUALS( 5023, c.getAsLong() );
  }

  // Mine
  void testOverloadedLessThan0() {
    BigInt a( "42" );
    BigInt b( "23" );
    TS_ASSERT_EQUALS( true, b < a );
  }

  // Mine
  void testOverloadedLessThan1() {
    BigInt a( "42" );
    BigInt b( "23" );
    TS_ASSERT_EQUALS( false, a < b );
  }

  // Mine
  void testOverloadedLessThan2() {
    BigInt a( "640" );
    BigInt b( "23" );
    TS_ASSERT_EQUALS( false, a < b );
  }

  // Mine
  void testOverloadedGreaterThan0() {
    BigInt a( "42" );
    BigInt b( "23" );
    TS_ASSERT_EQUALS( true, a > b );
  }

  // Mine
  void testOverloadedGreaterThan1() {
    BigInt a( "42" );
    BigInt b( "23" );
    TS_ASSERT_EQUALS( false, b > a );
  }

  // Mine
  void testOverloadedGreaterThan2() {
    BigInt a( "640" );
    BigInt b( "23" );
    TS_ASSERT_EQUALS( true, a > b );
  }

  // Mine
  void testOverloadedEqual0() {
    BigInt a( "42" );
    BigInt b( "42" );
    TS_ASSERT_EQUALS( true, a == b );
  }

  // Mine
  void testOverloadedEqual1() {
    BigInt a( "42" );
    BigInt b( "0" );
    TS_ASSERT_EQUALS( false, a == b );
  }

  // Mine
  void testOverloadedEqual2() {
    BigInt a( "42" );
    BigInt b( "43" );
    TS_ASSERT_EQUALS( false, a == b );
  }

  // Mine
  void testOverloadedEqual3() {
    BigInt a( "4200" );
    BigInt b( "43" );
    TS_ASSERT_EQUALS( false, a == b );
  }

  // Mine
  void testOverloadedNotEqual0() {
    BigInt a( "42" );
    BigInt b( "23" );
    TS_ASSERT_EQUALS( true, a != b );
  }

  // Mine
  void testOverloadedNotEqual1() {
    BigInt a( "42" );
    BigInt b( "0" );
    TS_ASSERT_EQUALS( true, a != b );
  }

  // Mine
  void testOverloadedNotEqual2() {
    BigInt a( "42" );
    BigInt b( "43" );
    TS_ASSERT_EQUALS( true, a != b );
  }

  // Mine
  void testOverloadedNotEqual3() {
    BigInt a( "42" );
    BigInt b( "42" );
    TS_ASSERT_EQUALS( false, a != b );
  }

  // Mine
  void testOverloadedNotEqual4() {
    BigInt a( "42000000000" );
    BigInt b( "42000000000" );
    TS_ASSERT_EQUALS( false, a != b );
  }

  // Mine
  void testOverloadedLessThanOrEqual0() {
    BigInt a( "42" );
    BigInt b( "42" );
    TS_ASSERT_EQUALS( true, a <= b );
  }

  // Mine
  void testOverloadedLessThanOrEqual1() {
    BigInt a( "23" );
    BigInt b( "42" );
    TS_ASSERT_EQUALS( true, a <= b );
  }

  // Mine
  void testOverloadedLessThanOrEqual2() {
    BigInt a( "23" );
    BigInt b( "42" );
    TS_ASSERT_EQUALS( false, b <= a );
  }

  // Mine
  void testOverloadedGreaterThanOrEqual0() {
    BigInt a( "42" );
    BigInt b( "42" );
    TS_ASSERT_EQUALS( true, a >= b );
  }

  // Mine
  void testOverloadedGreaterThanOrEqual1() {
    BigInt a( "64" );
    BigInt b( "42" );
    TS_ASSERT_EQUALS( true, a >= b );
  }

  // Mine
  void testOverloadedGreaterThanOrEqual2() {
    BigInt a( "64" );
    BigInt b( "42" );
    TS_ASSERT_EQUALS( false, b >= a );
  }

  // Mine
  void testOverloadedGreaterThanOrEqual3() {
    BigInt a( "640" );
    BigInt b( "42" );
    TS_ASSERT_EQUALS( true, a >= b );
  }

  // Mine
  void testOverloadedGreaterThanOrEqual4() {
    BigInt a( "1" );
    BigInt b( "0" );
    TS_ASSERT_EQUALS( true, a >= b );
  }

};
