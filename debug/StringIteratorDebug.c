#include <stdbool.h>
#include "Debug.h"
#include "../src/objectSystem/Object.h"
#include "../src/collections/String.h"
#include "../src/collections/StringIterator.h"
#include "../src/IO/Print.h"

#define strIteratorTest(result) test(result,"StringIterator",__FUNCTION__,__LINE__)

static String *str=NULL;
static void empty(void);
//static void forwardsLoop(void);
//static void forwardsLoopSkipping(void);
//static void backwardsLoop(void);
//static void backwardsLoopSkipping(void);
//static void loopMacro(void);

void stringIteratorDebug(void){
	str=new(String);
	String_t.set(str,"Hello");
	empty();
	delete(String,str);
}

static void empty(void){
	//StringIterator *iter=iterBegin(String,str);
	//StringIterator *end=iterEnd(String,str);
	//strIteratorTest(equals(StringIterator,iter,end)==0);
	//int i=0;
	//for(; equals(StringIterator,iter,end)!=0; iterNext(String,str,iter)){
	//	i++;
	//}
	//strIteratorTest(i==0);
	//delete(StringIterator,iter);
	//delete(StringIterator,end);
}
