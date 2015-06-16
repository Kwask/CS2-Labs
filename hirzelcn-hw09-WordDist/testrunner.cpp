/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_WordDistTest_init = false;
#include "WordDist_test.h"

static WordDistTest suite_WordDistTest;

static CxxTest::List Tests_WordDistTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_WordDistTest( "WordDist_test.h", 12, "WordDistTest", suite_WordDistTest, Tests_WordDistTest );

static class TestDescription_suite_WordDistTest_testDefaultConstruct : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WordDistTest_testDefaultConstruct() : CxxTest::RealTestDescription( Tests_WordDistTest, suiteDescription_WordDistTest, 15, "testDefaultConstruct" ) {}
 void runTest() { suite_WordDistTest.testDefaultConstruct(); }
} testDescription_suite_WordDistTest_testDefaultConstruct;

static class TestDescription_suite_WordDistTest_testAddWord0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WordDistTest_testAddWord0() : CxxTest::RealTestDescription( Tests_WordDistTest, suiteDescription_WordDistTest, 21, "testAddWord0" ) {}
 void runTest() { suite_WordDistTest.testAddWord0(); }
} testDescription_suite_WordDistTest_testAddWord0;

static class TestDescription_suite_WordDistTest_testAddWord1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WordDistTest_testAddWord1() : CxxTest::RealTestDescription( Tests_WordDistTest, suiteDescription_WordDistTest, 28, "testAddWord1" ) {}
 void runTest() { suite_WordDistTest.testAddWord1(); }
} testDescription_suite_WordDistTest_testAddWord1;

static class TestDescription_suite_WordDistTest_testAddWord2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WordDistTest_testAddWord2() : CxxTest::RealTestDescription( Tests_WordDistTest, suiteDescription_WordDistTest, 38, "testAddWord2" ) {}
 void runTest() { suite_WordDistTest.testAddWord2(); }
} testDescription_suite_WordDistTest_testAddWord2;

static class TestDescription_suite_WordDistTest_testIsStored0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WordDistTest_testIsStored0() : CxxTest::RealTestDescription( Tests_WordDistTest, suiteDescription_WordDistTest, 46, "testIsStored0" ) {}
 void runTest() { suite_WordDistTest.testIsStored0(); }
} testDescription_suite_WordDistTest_testIsStored0;

static class TestDescription_suite_WordDistTest_testIsStored1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WordDistTest_testIsStored1() : CxxTest::RealTestDescription( Tests_WordDistTest, suiteDescription_WordDistTest, 56, "testIsStored1" ) {}
 void runTest() { suite_WordDistTest.testIsStored1(); }
} testDescription_suite_WordDistTest_testIsStored1;

static class TestDescription_suite_WordDistTest_testIsStored2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WordDistTest_testIsStored2() : CxxTest::RealTestDescription( Tests_WordDistTest, suiteDescription_WordDistTest, 66, "testIsStored2" ) {}
 void runTest() { suite_WordDistTest.testIsStored2(); }
} testDescription_suite_WordDistTest_testIsStored2;

static class TestDescription_suite_WordDistTest_testIsStored3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WordDistTest_testIsStored3() : CxxTest::RealTestDescription( Tests_WordDistTest, suiteDescription_WordDistTest, 76, "testIsStored3" ) {}
 void runTest() { suite_WordDistTest.testIsStored3(); }
} testDescription_suite_WordDistTest_testIsStored3;

static class TestDescription_suite_WordDistTest_testGetDistanceSet0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WordDistTest_testGetDistanceSet0() : CxxTest::RealTestDescription( Tests_WordDistTest, suiteDescription_WordDistTest, 86, "testGetDistanceSet0" ) {}
 void runTest() { suite_WordDistTest.testGetDistanceSet0(); }
} testDescription_suite_WordDistTest_testGetDistanceSet0;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
