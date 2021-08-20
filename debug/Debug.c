#include "Debug.h"
#include "../src/IO/Print.h"

static int successfulTests=0;
static int testCount=0;

void resetTestResults(void){
	successfulTests=0;
	testCount=0;
}

bool incrementTestCount(bool testResult){
	if (testResult){
		successfulTests++;
	}
	testCount++;
	return testResult;
}

void printTestResults(void){
	Print_t.println("%d out of %d tests were successful",successfulTests,testCount);
}
