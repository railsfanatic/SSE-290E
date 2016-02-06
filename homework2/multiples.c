#include "../Unity/src/unity.h"
#include <stdio.h>
#include <setjmp.h>

extern void testWillAlwaysPass(void);
extern void testWillAlwaysFail(void);

void runTest(UnityTestFunction test)
{
	if (TEST_PROTECT())
	{
		test();
	}
}

int main()
{
	UnityBegin(__FILE__);
	RUN_TEST(testWillAlwaysPass, __LINE__);
	RUN_TEST(testWillAlwaysFail, __LINE__);
	UnityEnd();
	return 0;
}