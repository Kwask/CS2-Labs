#ifndef __INHERITANCETEST_H
#define __INHERITANCETEST_H

#include <cxxtest/TestSuite.h>

//
// A simple test suite, which is inherited
//

class BaseTests
{
public:
    void testEquality()
    {
        TS_ASSERT_EQUALS(1, 1);
        TS_ASSERT_EQUALS(1, 2);
        TS_ASSERT_EQUALS('a', 'A');
        TS_ASSERT_EQUALS(1.0, -12345678900000000000000000000000000000000000000000.1234);
    }

    void testAddition()
    {
        TS_ASSERT_EQUALS(1 + 1, 2);
        TS_ASSERT_EQUALS(2 + 2, 5);
    }

    void TestMultiplication()
    {
        TS_ASSERT_EQUALS(2 * 2, 4);
        TS_ASSERT_EQUALS(4 * 4, 44);
        TS_ASSERT_DIFFERS(-2 * -2, 4);
    }

    void testComparison()
    {
        TS_ASSERT_LESS_THAN((int)1, (unsigned long)2);
        TS_ASSERT_LESS_THAN(-1, -2);
    }

    void testTheWorldIsCrazy()
    {
        TS_ASSERT_EQUALS(true, false);
    }

    void test_Failure()
    {
        TS_FAIL("Not implemented");
        TS_FAIL(1569779912);
    }

    void test_TS_WARN_macro()
    {
        TS_WARN("Just a friendly warning");
        TS_WARN("Warnings don't abort the test");
    }
};


class InheritedTests1 : public BaseTests, public CxxTest::TestSuite
{};

class InheritedTests2 : public CxxTest::TestSuite, public BaseTests
{};

#endif // __INHERITANCETEST_H
