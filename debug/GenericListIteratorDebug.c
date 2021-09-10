#include <stdbool.h>
#include "Debug.h"
#include "../src/objectSystem/Object.h"
#include "../src/collections/GenericList.h"
#include "../src/collections/GenericListIterator.h"
#include "../src/IO/Print.h"

#define glIteratorTest(result) test(result,"GenericListIterator",__FUNCTION__,__LINE__)

static GenericList *list=NULL;
static void empty(void);
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
	forwardsLoop();
	forwardsLoopSkipping();
	backwardsLoop();
	backwardsLoopSkipping();
	loopMacro();
	delete(GenericList,list);
}

static void empty(void){
	GenericListIterator *iter=iterBegin(GenericList,list);
	GenericListIterator *end=iterEnd(GenericList,list);
	glIteratorTest(equals(GenericListIterator,iter,end)==0);
	int i=0;
	for (; equals(GenericListIterator,iter,end)!=0; iterNext(GenericList,list,iter)){
		i++;
	}
	glIteratorTest(i==0);
	delete(GenericListIterator,iter);
	delete(GenericListIterator,end);
}

static void forwardsLoop(void){
	GenericListIterator *iter=iterBegin(GenericList,list);
	GenericListIterator *end=iterEnd(GenericList,list);
	glIteratorTest(equals(GenericListIterator,iter,end)!=0);
	int i=0;
	for ( ; equals(GenericListIterator,iter,end)<0; iterNext(GenericList,list,iter)){
		void* iterVal=iterVal(GenericList,list,iter);
		glIteratorTest(*(char*)iterVal=="hello"[i]);
		i++;
	}
	glIteratorTest(i==5);
	delete(GenericListIterator,iter);
	delete(GenericListIterator,end);
}

static void forwardsLoopSkipping(void){
	GenericListIterator *iter=iterBegin(GenericList,list);
	GenericListIterator *end=iterEnd(GenericList,list);
	glIteratorTest(equals(GenericListIterator,iter,end)!=0);
	int i=0, j=0;
	for ( ; equals(GenericListIterator,iter,end)<0; iterNext(GenericList,list,iter,2)){
		void* iterVal=iterVal(GenericList,list,iter);
		glIteratorTest(*(char*)iterVal=="hello"[i]);
		i+=2;
		j++;
	}
	glIteratorTest(i==6);
	glIteratorTest(j==3);
	delete(GenericListIterator,iter);
	delete(GenericListIterator,end);
}

static void backwardsLoop(void){
	GenericListIterator *iter=iterEnd(GenericList,list);
	GenericListIterator *begin=iterBegin(GenericList,list);
	glIteratorTest(equals(GenericListIterator,iter,begin)!=0);
	int i=4;
	iterPrev(GenericList,list,iter);
	for ( ; equals(GenericListIterator,iter,begin)>=0; iterPrev(GenericList,list,iter)){
		void* iterVal=iterVal(GenericList,list,iter);
		glIteratorTest(*(char*)iterVal=="hello"[i]);
		i--;
	}
	glIteratorTest(i==-1);
	delete(GenericListIterator,iter);
	delete(GenericListIterator,begin);
}

static void backwardsLoopSkipping(void){
	GenericListIterator *iter=iterEnd(GenericList,list);
	GenericListIterator *begin=iterBegin(GenericList,list);
	glIteratorTest(equals(GenericListIterator,iter,begin)!=0);
	int i=4, j=0;
	iterPrev(GenericList,list,iter);
	for ( ; equals(GenericListIterator,iter,begin)>=0; iterPrev(GenericList,list,iter,2)){
		void* iterVal=iterVal(GenericList,list,iter);
		glIteratorTest(*(char*)iterVal=="hello"[i]);
		i-=2;
		j++;
	}
	glIteratorTest(i==-2);
	glIteratorTest(j==3);
	delete(GenericListIterator,iter);
	delete(GenericListIterator,begin);
}

static void loopMacro(void){
	int i=0;
	forEach(GenericList,char,list,
			glIteratorTest(*(char*)at=="hello"[i]);
			i++;
		);
	glIteratorTest(i==5);
}
