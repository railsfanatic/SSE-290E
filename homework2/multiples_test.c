#include "../Unity/src/unity.h"

void setUp()
{
}

void tearDown()
{
}

void testWillAlwaysPass(void)
{
	TEST_ASSERT_EQUAL_INT(42, 42);
}

void testWillAlwaysFail(void)
{
	TEST_ASSERT_EQUAL_INT(42, 41);
}
