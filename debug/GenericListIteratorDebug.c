#include <stdbool.h>
#include "Debug.h"
#include "../src/objectSystem/Object.h"
#include "../src/objectSystem/BasicType.h"
#include "../src/collections/GenericList.h"
#include "../src/collections/GenericListIterator.h"
#include "../src/IO/Print.h"

#define glIteratorTest(result) test(result,"GenericListIterator",__FUNCTION__,__LINE__)

static GenericList *list=NULL;
static void empty(void);
static void beginEnd(void);
static void forwardsLoop(void);
static void forwardsLoopSkipping(void);
static void backwardsLoop(void);
static void backwardsLoopSkipping(void);
static void loopMacro(void);

void genericListIteratorDebug(void){
	list=new(GenericList);
	GenericList_t.setElementType(list,&char_t.class,sizeof(char));
	empty();
	GenericList_t.set(list,"hello",5);
	beginEnd();
	forwardsLoop();
	forwardsLoopSkipping();
	backwardsLoop();
	backwardsLoopSkipping();
	loopMacro();
	delete(GenericList,list);
}

static void empty(void){
	GenericListIterator iter=newS(GenericListIterator,iter);
	GenericListIterator end=newS(GenericListIterator,end);
	iterBegin(GenericList,&iter,list);
	iterEnd(GenericList,&iter,list);
	glIteratorTest(equals(GenericListIterator,&iter,&end)==0);
	int i=0;
	for (; equals(GenericListIterator,&iter,&end)!=0; iterNext(GenericList,&iter)){
		i++;
	}
	glIteratorTest(i==0);
	deleteS(GenericListIterator,iter);
	deleteS(GenericListIterator,end);
}

static void beginEnd(void){
	GenericListIterator *begin=iterBegin(GenericList,new(GenericListIterator),list);
	GenericListIterator *end=iterEnd(GenericList,new(GenericListIterator),list);
	GenericListIterator beginS=newS(GenericListIterator,beginS);
	GenericListIterator endS=newS(GenericListIterator,endS);
	iterBegin(GenericList,&beginS,list);
	iterEnd(GenericList,&endS,list);
	glIteratorTest(equals(GenericListIterator,begin,&beginS)==0);
	glIteratorTest(equals(GenericListIterator,end,&endS)==0);
	glIteratorTest(equals(GenericListIterator,begin,end)!=0);
	glIteratorTest(equals(GenericListIterator,begin,&endS)!=0);
	glIteratorTest(equals(GenericListIterator,&beginS,end)!=0);
	glIteratorTest(equals(GenericListIterator,&beginS,&endS)!=0);
	glIteratorTest(*(char*)iterVal(GenericList,begin)=='h');
	glIteratorTest(*(char*)iterVal(GenericList,&beginS)=='h');
	glIteratorTest(*(char*)iterVal(GenericList,iterPrev(GenericList,end))=='o');
	glIteratorTest(*(char*)iterVal(GenericList,iterPrev(GenericList,&endS))=='o');
	delete(GenericListIterator,begin);
	delete(GenericListIterator,end);
	deleteS(GenericListIterator,beginS);
	deleteS(GenericListIterator,endS);
}

static void forwardsLoop(void){
	GenericListIterator iter=newS(GenericListIterator,iter);
	GenericListIterator end=newS(GenericListIterator,end);
	iterBegin(GenericList,&iter,list);
	iterEnd(GenericList,&end,list);
	glIteratorTest(equals(GenericListIterator,&iter,&end)!=0);
	int i=0;
	for (; equals(GenericListIterator,&iter,&end)<0; iterNext(GenericList,&iter)){
		void *iterVal=iterVal(GenericList,&iter);
		glIteratorTest(*(char*)iterVal=="hello"[i]);
		i++;
	}
	glIteratorTest(i==5);
	deleteS(GenericListIterator,iter);
	deleteS(GenericListIterator,end);
}

static void forwardsLoopSkipping(void){
	GenericListIterator iter=newS(GenericListIterator,iter);
	GenericListIterator end=newS(GenericListIterator,end);
	iterBegin(GenericList,&iter,list);
	iterEnd(GenericList,&end,list);
	glIteratorTest(equals(GenericListIterator,&iter,&end)!=0);
	int i=0, j=0;
	for ( ; equals(GenericListIterator,&iter,&end)<0; iterNext(GenericList,&iter,2)){
		void* iterVal=iterVal(GenericList,&iter);
		glIteratorTest(*(char*)iterVal=="hello"[i]);
		i+=2;
		j++;
	}
	glIteratorTest(i==6);
	glIteratorTest(j==3);
	deleteS(GenericListIterator,iter);
	deleteS(GenericListIterator,end);
}

static void backwardsLoop(void){
	GenericListIterator iter=newS(GenericListIterator,iter);
	GenericListIterator begin=newS(GenericListIterator,begin);
	iterBegin(GenericList,&begin,list);
	iterEnd(GenericList,&iter,list);
	glIteratorTest(equals(GenericListIterator,&iter,&begin)!=0);
	int i=4;
	iterPrev(GenericList,&iter);
	for ( ; equals(GenericListIterator,&iter,&begin)>=0; iterPrev(GenericList,&iter)){
		void* iterVal=iterVal(GenericList,&iter);
		glIteratorTest(*(char*)iterVal=="hello"[i]);
		i--;
	}
	glIteratorTest(i==-1);
	deleteS(GenericListIterator,iter);
	deleteS(GenericListIterator,begin);
}

static void backwardsLoopSkipping(void){
	GenericListIterator iter=newS(GenericListIterator,iter);
	GenericListIterator begin=newS(GenericListIterator,begin);
	iterBegin(GenericList,&begin,list);
	iterEnd(GenericList,&iter,list);
	glIteratorTest(equals(GenericListIterator,&iter,&begin)!=0);
	int i=4, j=0;
	iterPrev(GenericList,&iter);
	for ( ; equals(GenericListIterator,&iter,&begin)>=0; iterPrev(GenericList,&iter,2)){
		void* iterVal=iterVal(GenericList,&iter);
		glIteratorTest(*(char*)iterVal=="hello"[i]);
		i-=2;
		j++;
	}
	glIteratorTest(i==-2);
	glIteratorTest(j==3);
	deleteS(GenericListIterator,iter);
	deleteS(GenericListIterator,begin);
}

static void loopMacro(void){
	int i=0;
	forEach(GenericList,char,list,
			glIteratorTest(*(char*)at=="hello"[i]);
			i++;
		);
	glIteratorTest(i==5);
}
