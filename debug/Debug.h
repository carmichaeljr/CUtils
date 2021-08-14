#ifndef DEBUG
#define DEBUG

#define test(result,object,func,line) Print_t.objectDebugWithLine(object,func,line,incrementTestCount(result))

#include <stdbool.h>

//Defined in Debug.c
void resetTestResults(void);
bool incrementTestCount(bool testResult);
void printTestResults(void);

//Defined in various debug files
bool genericListDebug(void);
void stringDebug(void);

#endif
