#include <stdbool.h>
#include "Debug.h"
#include "../src/objectSystem/Object.h"
#include "../src/collections/GenericLinkedList.h"
#include "../src/IO/Print.h"

#define gllTest(result) test(result,"GenericLinkedList",__FUNCTION__,__LINE__)

static void setElementSize(void);

void genericLinkedListDebug(void){
	setElementSize();
}

static void setElementSize(void){
	GenericLinkedList *test=new(GenericLinkedList);
	gllTest(test->elementSize==0);
	gllTest(GenericLinkedList_t.setElementSize(test,sizeof(char)));
	gllTest(test->elementSize==sizeof(char));
	gllTest(!GenericLinkedList_t.setElementSize(test,sizeof(char)));
	//TODO - add elements and then change element size, check for clear
	delete(GenericLinkedList,test);
}
