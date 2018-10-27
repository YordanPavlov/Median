#include <cmath>

#include "cppunit/TestFixture.h"
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestResult.h>
#include "cppunit/extensions/HelperMacros.h"

#include "medianstructure.h"
#include "utest.h"



CPPUNIT_TEST_SUITE_REGISTRATION( MedianStoreTest );

  void MedianStoreTest::setUp()
  {
  }

  void MedianStoreTest::tearDown()
  {
  }

  void MedianStoreTest::test1()
  {
    MedianStore<int> store;
    store.add(1);

    CPPUNIT_ASSERT(1 == store.getMedian());
  }

  void MedianStoreTest::test2()
  {
    MedianStore<int> store;
    store.add(1);
    store.add(2);

    CPPUNIT_ASSERT(1.5 == store.getMedian());
  }

  void MedianStoreTest::test3()
  {
    MedianStore<int> store;
    store.add(1);
    store.add(2);
    store.add(100);

    CPPUNIT_ASSERT(2 == store.getMedian());
  }

  void MedianStoreTest::test4()
  {
    MedianStore<int> store;
    store.add(1);
    store.add(2);
    store.add(100);
    store.add(-1);

    CPPUNIT_ASSERT(1.5 == store.getMedian());
  }

  void MedianStoreTest::test5()
  { // -1 0 1 2 100
    MedianStore<int> store;
    store.add(1);
    store.add(2);
    store.add(100);
    store.add(-1);
    store.add(0);

    CPPUNIT_ASSERT(1 == store.getMedian());
  }

  void MedianStoreTest::test6()
  { // -1 0 1 1 1 3
    MedianStore<int> store;
    store.add(-1);
    store.add(0);
    store.add(1);
    store.add(1);
    store.add(1);
    store.add(3);

    CPPUNIT_ASSERT(1 == store.getMedian());
  }

  void MedianStoreTest::test7()
  {
    MedianStore<int> store;

    store.add(3);
    CPPUNIT_ASSERT(3 == store.getMedian());

    store.add(2);
    CPPUNIT_ASSERT(2.5 == store.getMedian());

    store.add(1);
    CPPUNIT_ASSERT(2 == store.getMedian());

    store.add(0);
    CPPUNIT_ASSERT(1.5 == store.getMedian());

    store.add(0);
    CPPUNIT_ASSERT(1 == store.getMedian());

    store.add(0);
    CPPUNIT_ASSERT(0.5 == store.getMedian());

    store.add(0);
    CPPUNIT_ASSERT(0 == store.getMedian());

    store.add(0);
    CPPUNIT_ASSERT(0 == store.getMedian());
  }

  void MedianStoreTest::testFail()
  {
    MedianStore<int> store;

    try
    {
        store.getMedian();
        CPPUNIT_FAIL("Expected exception not thrown. Median of empty store.");
    }
    catch(std::exception& ex)
    {
        // Expected
    }
  }

int main( int argc, char **argv)
{
  // Get the top level suite from the registry
  CPPUNIT_NS::Test *suite = CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest();

  // Adds the test to the list of test to run
  CPPUNIT_NS::TextUi::TestRunner runner;
  runner.addTest( suite );

  // Run the test.
  bool wasSucessful = runner.run();

  // Return error code 1 if the one of test failed.
  return wasSucessful ? 0 : 1;

}
