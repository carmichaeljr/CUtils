#include <stdbool.h>
#include "Debug.h"
#include "../src/Object.h"
#include "../src/GenericLinkedList.h"
#include "../src/Print.h"

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
