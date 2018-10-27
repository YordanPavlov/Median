#include "cppunit/TestFixture.h"
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include "cppunit/extensions/HelperMacros.h"

#include "medianstructure.h"

class MedianStoreTest : public CppUnit::TestFixture  {

    CPPUNIT_TEST_SUITE( MedianStoreTest );

    CPPUNIT_TEST( test1 );
    CPPUNIT_TEST( test2 );
    CPPUNIT_TEST( test3 );
    CPPUNIT_TEST( test4 );
    CPPUNIT_TEST( test5 );
    CPPUNIT_TEST( test6 );
    CPPUNIT_TEST( test7 );

    CPPUNIT_TEST( testFail );

  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();

  void tearDown();

  void test1();
  void test2();
  void test3();
  void test4();
  void test5();
  void test6();
  void test7();

  void testFail();
};

