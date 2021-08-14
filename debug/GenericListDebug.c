#include <stdbool.h>
#include "Debug.h"
#include "../src/GenericList.h"
#include "../src/Print.h"

#define genericListTest(result) test(result,"GenericList",__FUNCTION__,__LINE__)

static void setElementSize(void);
static void setListSize(void);
static void set(void);
static void setAt(void);
static void add(void);
static void addAt(void);
static void copyOtherBetween(void);
static bool get(void);
static bool contains(void);
static bool getFirstIndexOf(void);
static bool getLastIndexOf(void);
static bool _remove(void);
static bool removeAt(void);
static bool removeBetween(void);
static bool trimToSize(void);
static bool clear(void);
static bool isEmpty(void);
static bool equals(void);

bool genericListDebug(void){
	setElementSize();
	setListSize();
	set();
	setAt();
	add();
	addAt();
	copyOtherBetween();
	return (
		get() &
		contains() &
		getFirstIndexOf() &
		getLastIndexOf() &
		_remove() &
		removeAt() &
		removeBetween() &
		trimToSize() &
		clear() &
		isEmpty() &
		equals()
	       );
}

static void setElementSize(void){
	GenericList *test=GenericList_t.new();
	genericListTest(test->elementSize==0);
	GenericList_t.setElementSize(test,sizeof(char));
	genericListTest(test->elementSize==sizeof(char));
	GenericList_t.add(test,&("hello"[0]),1);
	GenericList_t.setElementSize(test,sizeof(float));
	genericListTest(test->elementSize==sizeof(float));
	genericListTest(test->numElements==0);
	GenericList_t.delete(&test);
}

static void setListSize(void){
	GenericList *test=GenericList_t.new();
	genericListTest(!GenericList_t.setListSize(test,10));
	genericListTest(test->listSize==0);
	genericListTest(test->numElements==0);
	GenericList_t.setElementSize(test,sizeof(char));
	genericListTest(!GenericList_t.setListSize(test,-1));
	genericListTest(test->listSize==0);
	genericListTest(test->numElements==0);
	genericListTest(GenericList_t.setListSize(test,10));
	genericListTest(test->listSize==10);
	genericListTest(test->numElements==0);
	GenericList_t.delete(&test);
}

static void set(void){
	GenericList *test=GenericList_t.new();
	genericListTest(!GenericList_t.set(test,"hello",5));
	genericListTest(test->numElements==0);
	GenericList_t.setElementSize(test,sizeof(char));
	genericListTest(GenericList_t.set(test,"hello",5));
	genericListTest(test->numElements==5);
	genericListTest(*((char*)test->list+sizeof(char)*0)=='h');
	genericListTest(*((char*)test->list+sizeof(char)*1)=='e');
	genericListTest(*((char*)test->list+sizeof(char)*2)=='l');
	genericListTest(*((char*)test->list+sizeof(char)*3)=='l');
	genericListTest(*((char*)test->list+sizeof(char)*4)=='o');
	genericListTest(GenericList_t.set(test,"hi",2));
	genericListTest(test->numElements==2);
	genericListTest(*((char*)test->list+sizeof(char)*0)=='h');
	genericListTest(*((char*)test->list+sizeof(char)*1)=='i');
	GenericList_t.delete(&test);
}

static void setAt(void){
	GenericList *test=GenericList_t.new();
	genericListTest(!GenericList_t.setAt(test,"hello",5,0));
	genericListTest(test->numElements==0);
	GenericList_t.setElementSize(test,sizeof(char));
	genericListTest(GenericList_t.setAt(test,"hello",5,1));
	genericListTest(test->numElements==5);
	genericListTest(*((char*)test->list+sizeof(char)*0)=='h');
	genericListTest(*((char*)test->list+sizeof(char)*1)=='e');
	genericListTest(*((char*)test->list+sizeof(char)*2)=='l');
	genericListTest(*((char*)test->list+sizeof(char)*3)=='l');
	genericListTest(*((char*)test->list+sizeof(char)*4)=='o');
	genericListTest(GenericList_t.setAt(test,"bye",3,2));
	genericListTest(test->numElements==5);
	genericListTest(*((char*)test->list+sizeof(char)*0)=='h');
	genericListTest(*((char*)test->list+sizeof(char)*1)=='e');
	genericListTest(*((char*)test->list+sizeof(char)*2)=='b');
	genericListTest(*((char*)test->list+sizeof(char)*3)=='y');
	genericListTest(*((char*)test->list+sizeof(char)*4)=='e');
	genericListTest(GenericList_t.setAt(test,"bye",3,3));
	genericListTest(test->numElements==5);
	genericListTest(*((char*)test->list+sizeof(char)*0)=='h');
	genericListTest(*((char*)test->list+sizeof(char)*1)=='e');
	genericListTest(*((char*)test->list+sizeof(char)*2)=='b');
	genericListTest(*((char*)test->list+sizeof(char)*3)=='b');
	genericListTest(*((char*)test->list+sizeof(char)*4)=='y');
	genericListTest(!GenericList_t.setAt(test,"bye",3,6));
	genericListTest(test->numElements==5);
	genericListTest(*((char*)test->list+sizeof(char)*0)=='h');
	genericListTest(*((char*)test->list+sizeof(char)*1)=='e');
	genericListTest(*((char*)test->list+sizeof(char)*2)=='b');
	genericListTest(*((char*)test->list+sizeof(char)*3)=='b');
	genericListTest(*((char*)test->list+sizeof(char)*4)=='y');
	GenericList_t.delete(&test);
}

static void add(void){
	GenericList *test=GenericList_t.new();
	genericListTest(!GenericList_t.add(test,"hello",5));
	genericListTest(test->numElements==0);
	GenericList_t.setElementSize(test,sizeof(char));
	genericListTest(GenericList_t.add(test,"hello",5));
	genericListTest(test->numElements==5);
	genericListTest(*((char*)test->list+sizeof(char)*0)=='h');
	genericListTest(*((char*)test->list+sizeof(char)*1)=='e');
	genericListTest(*((char*)test->list+sizeof(char)*2)=='l');
	genericListTest(*((char*)test->list+sizeof(char)*3)=='l');
	genericListTest(*((char*)test->list+sizeof(char)*4)=='o');
	genericListTest(GenericList_t.add(test,"bye",3));
	genericListTest(test->numElements==8);
	genericListTest(*((char*)test->list+sizeof(char)*0)=='h');
	genericListTest(*((char*)test->list+sizeof(char)*1)=='e');
	genericListTest(*((char*)test->list+sizeof(char)*2)=='l');
	genericListTest(*((char*)test->list+sizeof(char)*3)=='l');
	genericListTest(*((char*)test->list+sizeof(char)*4)=='o');
	genericListTest(*((char*)test->list+sizeof(char)*5)=='b');
	genericListTest(*((char*)test->list+sizeof(char)*6)=='y');
	genericListTest(*((char*)test->list+sizeof(char)*7)=='e');
	GenericList_t.delete(&test);
}

static void addAt(void){
	GenericList *test=GenericList_t.new();
	genericListTest(!GenericList_t.addAt(test,"hello",5,0));
	genericListTest(test->numElements==0);
	GenericList_t.setElementSize(test,sizeof(char));
	genericListTest(GenericList_t.addAt(test,"hello",5,1));
	genericListTest(test->numElements==5);
	genericListTest(*((char*)test->list+sizeof(char)*0)=='h');
	genericListTest(*((char*)test->list+sizeof(char)*1)=='e');
	genericListTest(*((char*)test->list+sizeof(char)*2)=='l');
	genericListTest(*((char*)test->list+sizeof(char)*3)=='l');
	genericListTest(*((char*)test->list+sizeof(char)*4)=='o');
	genericListTest(GenericList_t.addAt(test,"1",1,0));
	genericListTest(GenericList_t.addAt(test,"1",1,3));
	genericListTest(GenericList_t.addAt(test,"1",1,7));
	genericListTest(test->numElements==8);
	genericListTest(*((char*)test->list+sizeof(char)*0)=='1');
	genericListTest(*((char*)test->list+sizeof(char)*1)=='h');
	genericListTest(*((char*)test->list+sizeof(char)*2)=='e');
	genericListTest(*((char*)test->list+sizeof(char)*3)=='1');
	genericListTest(*((char*)test->list+sizeof(char)*4)=='l');
	genericListTest(*((char*)test->list+sizeof(char)*5)=='l');
	genericListTest(*((char*)test->list+sizeof(char)*6)=='o');
	genericListTest(*((char*)test->list+sizeof(char)*7)=='1');
	GenericList_t.delete(&test);
}

static void copyOtherBetween(void){
	GenericList *test1=GenericList_t.new();
	GenericList *test2=GenericList_t.new();
	GenericList_t.setElementSize(test1,sizeof(float));
	GenericList_t.setElementSize(test2,sizeof(char));
	GenericList_t.add(test2,"hello",5);
	genericListTest(!GenericList_t.copyOtherBetween(test1,test2,1,3));
	genericListTest(test1->numElements==0);
	GenericList_t.setElementSize(test1,sizeof(char));
	genericListTest(!GenericList_t.copyOtherBetween(test1,test2,-1,3));
	genericListTest(!GenericList_t.copyOtherBetween(test1,test2,3,6));
	genericListTest(!GenericList_t.copyOtherBetween(test1,test2,3,2));
	genericListTest(GenericList_t.copyOtherBetween(test1,test2,1,3));
	genericListTest(test1->numElements==2);
	genericListTest(*((char*)test1->list+sizeof(char)*0)=='e');
	genericListTest(*((char*)test1->list+sizeof(char)*1)=='l');
	genericListTest(GenericList_t.copyOtherBetween(test1,test2,0,3));
	genericListTest(test1->numElements==3);
	genericListTest(*((char*)test1->list+sizeof(char)*0)=='h');
	genericListTest(*((char*)test1->list+sizeof(char)*1)=='e');
	genericListTest(*((char*)test1->list+sizeof(char)*2)=='l');
	genericListTest(GenericList_t.copyOtherBetween(test1,test2,3,5));
	genericListTest(test1->numElements==2);
	genericListTest(*((char*)test1->list+sizeof(char)*0)=='l');
	genericListTest(*((char*)test1->list+sizeof(char)*1)=='o');
	GenericList_t.delete(&test1);
	GenericList_t.delete(&test2);
}

static bool get(void){
	bool rv=true;
	GenericList *test=GenericList_t.new();
	GenericList_t.setElementSize(test,sizeof(char));
	GenericList_t.add(test,"hello",5);
	if (GenericList_t.get(test,-1)!=NULL) rv=false;
	if (*(char*)GenericList_t.get(test,0)!='h') rv=false;
	if (*(char*)GenericList_t.get(test,1)!='e') rv=false;
	if (*(char*)GenericList_t.get(test,2)!='l') rv=false;
	if (*(char*)GenericList_t.get(test,3)!='l') rv=false;
	if (*(char*)GenericList_t.get(test,4)!='o') rv=false;
	if (GenericList_t.get(test,5)!=NULL) rv=false;
	GenericList_t.delete(&test);
	return rv;
}

static bool contains(void){
	bool rv=true;
	GenericList *test=GenericList_t.new();
	GenericList_t.setElementSize(test,sizeof(char));
	GenericList_t.add(test,"hello",5);
	if (!GenericList_t.contains(test,&("hello"[0]))) rv=false;
	if (!GenericList_t.contains(test,&("hello"[1]))) rv=false;
	if (!GenericList_t.contains(test,&("hello"[2]))) rv=false;
	if (!GenericList_t.contains(test,&("hello"[3]))) rv=false;
	if (!GenericList_t.contains(test,&("hello"[4]))) rv=false;
	if (GenericList_t.contains(test,&("bye"[0]))) rv=false;
	if (GenericList_t.contains(test,&("bye"[1]))) rv=false;
	GenericList_t.delete(&test);
	Print_t.objectDebug("GenericList","contains",rv);
	return rv;
}

static bool getFirstIndexOf(void){
	bool rv=true;
	GenericList *test=GenericList_t.new();
	GenericList_t.setElementSize(test,sizeof(char));
	GenericList_t.add(test,"hello",5);
	if (GenericList_t.getFirstIndexOf(test,&("hello"[0]))!=0) rv=false;
	if (GenericList_t.getFirstIndexOf(test,&("hello"[1]))!=1) rv=false;
	if (GenericList_t.getFirstIndexOf(test,&("hello"[2]))!=2) rv=false;
	if (GenericList_t.getFirstIndexOf(test,&("hello"[3]))!=2) rv=false;
	if (GenericList_t.getFirstIndexOf(test,&("hello"[4]))!=4) rv=false;
	if (GenericList_t.getFirstIndexOf(test,&("bye"[0]))!=-1) rv=false;
	if (GenericList_t.getFirstIndexOf(test,&("bye"[1]))!=-1) rv=false;
	GenericList_t.delete(&test);
	Print_t.objectDebug("GenericList","getFirstIndexOf",rv);
	return rv;
}

static bool getLastIndexOf(void){
	bool rv=true;
	GenericList *test=GenericList_t.new();
	GenericList_t.setElementSize(test,sizeof(char));
	GenericList_t.add(test,"hello",5);
	if (GenericList_t.getLastIndexOf(test,&("hello"[0]))!=0) rv=false;
	if (GenericList_t.getLastIndexOf(test,&("hello"[1]))!=1) rv=false;
	if (GenericList_t.getLastIndexOf(test,&("hello"[2]))!=3) rv=false;
	if (GenericList_t.getLastIndexOf(test,&("hello"[3]))!=3) rv=false;
	if (GenericList_t.getLastIndexOf(test,&("hello"[4]))!=4) rv=false;
	if (GenericList_t.getLastIndexOf(test,&("bye"[0]))!=-1) rv=false;
	if (GenericList_t.getLastIndexOf(test,&("bye"[1]))!=-1) rv=false;
	GenericList_t.delete(&test);
	Print_t.objectDebug("GenericList","getLastIndexOf",rv);
	return rv;
}

static bool _remove(void){
	bool rv=true;
	GenericList *test=GenericList_t.new();
	GenericList_t.setElementSize(test,sizeof(char));
	GenericList_t.add(test,"hello",5);
	if (!GenericList_t.remove(test,&("hello"[0]))) rv=false;
	if (!GenericList_t.remove(test,&("hello"[4]))) rv=false;
	if (!GenericList_t.remove(test,&("hello"[2]))) rv=false;
	if (test->numElements!=1) rv=false;
	if (*((char*)test->list+sizeof(char)*0)!='e') rv=false;
	if (!GenericList_t.remove(test,&("hello"[1]))) rv=false;
	if (test->numElements!=0) rv=false;
	if (test->list!=NULL) rv=false;
	GenericList_t.delete(&test);
	Print_t.objectDebug("GenericList","remove",rv);
	return rv;
}

static bool removeAt(void){
	bool rv=true;
	GenericList *test=GenericList_t.new();
	GenericList_t.setElementSize(test,sizeof(char));
	GenericList_t.add(test,"hello",5);
	if (GenericList_t.removeAt(test,-1)) rv=false;
	if (GenericList_t.removeAt(test,6)) rv=false;
	if (test->numElements!=5) rv=false;
	if (!GenericList_t.removeAt(test,0)) rv=false;
	if (!GenericList_t.removeAt(test,3)) rv=false;
	if (!GenericList_t.removeAt(test,1)) rv=false;
	if (test->numElements!=2) rv=false;
	if (*((char*)test->list+sizeof(char)*0)!='e') rv=false;
	if (*((char*)test->list+sizeof(char)*1)!='l') rv=false;
	if (!GenericList_t.removeAt(test,0)) rv=false;
	if (!GenericList_t.removeAt(test,0)) rv=false;
	if (test->numElements!=0) rv=false;
	if (test->list!=NULL) rv=false;
	GenericList_t.delete(&test);
	Print_t.objectDebug("GenericList","removeAt",rv);
	return rv;
}

static bool removeBetween(void){
	bool rv=true;
	GenericList *test=GenericList_t.new();
	GenericList_t.setElementSize(test,sizeof(char));
	GenericList_t.add(test,"hello",5);
	if (GenericList_t.removeBetween(test,-1,3)) rv=false;
	if (GenericList_t.removeBetween(test,0,6)) rv=false;
	if (GenericList_t.removeBetween(test,3,2)) rv=false;
	if (test->numElements!=5) rv=false;
	if (!GenericList_t.removeBetween(test,0,1)) rv=false;
	if (!GenericList_t.removeBetween(test,3,4)) rv=false;
	if (!GenericList_t.removeBetween(test,1,2)) rv=false;
	if (test->numElements!=2) rv=false;
	if (*((char*)test->list+sizeof(char)*0)!='e') rv=false;
	if (*((char*)test->list+sizeof(char)*1)!='l') rv=false;
	if (!GenericList_t.removeBetween(test,0,2)) rv=false;
	if (test->numElements!=0) rv=false;
	if (test->list!=NULL) rv=false;
	GenericList_t.delete(&test);
	Print_t.objectDebug("GenericList","removeBetween",rv);
	return rv;
}

static bool trimToSize(void){
	bool rv=true;
	GenericList *test=GenericList_t.new();
	GenericList_t.setElementSize(test,sizeof(char));
	GenericList_t.add(test,"hello",5);
	if (GenericList_t.trimToSize(test)) rv=false;
	if (test->numElements!=5) rv=false;
	if (test->listSize!=5) rv=false;
	if (*((char*)test->list+sizeof(char)*0)!='h') rv=false;
	if (*((char*)test->list+sizeof(char)*4)!='o') rv=false;
	GenericList_t.set(test,"bye",3);
	if (test->numElements!=3) rv=false;
	if (test->listSize!=5) rv=false;
	if (!GenericList_t.trimToSize(test)) rv=false;
	if (test->numElements!=3) rv=false;
	if (test->listSize!=3) rv=false;
	if (*((char*)test->list+sizeof(char)*0)!='b') rv=false;
	if (*((char*)test->list+sizeof(char)*2)!='e') rv=false;

	test->strictAlloc=true;
	GenericList_t.set(test,"hello",5);
	if (GenericList_t.trimToSize(test)) rv=false;
	if (test->numElements!=5) rv=false;
	if (test->listSize!=5) rv=false;
	if (*((char*)test->list+sizeof(char)*0)!='h') rv=false;
	if (*((char*)test->list+sizeof(char)*4)!='o') rv=false;
	GenericList_t.set(test,"bye",3);
	if (test->numElements!=3) rv=false;
	if (test->listSize!=3) rv=false;
	if (GenericList_t.trimToSize(test)) rv=false;
	if (test->numElements!=3) rv=false;
	if (test->listSize!=3) rv=false;
	if (*((char*)test->list+sizeof(char)*0)!='b') rv=false;
	if (*((char*)test->list+sizeof(char)*2)!='e') rv=false;

	GenericList_t.delete(&test);
	Print_t.objectDebug("GenericList","trimToSize",rv);
	return rv;
}

static bool clear(void){
	bool rv=true;
	GenericList *test=GenericList_t.new();
	GenericList_t.setElementSize(test,sizeof(char));
	GenericList_t.add(test,"hello",5);
	if (!GenericList_t.clear(test)) rv=false;
	if (test->numElements!=0) rv=false;
	if (test->list!=NULL) rv=false;
	GenericList_t.delete(&test);
	Print_t.objectDebug("GenericList","clear",rv);
	return rv;
}

static bool isEmpty(void){
	bool rv=true;
	GenericList *test=GenericList_t.new();
	if (!GenericList_t.isEmpty(test)) rv=false;
	GenericList_t.delete(&test);
	Print_t.objectDebug("GenericList","isEmpty",rv);
	return rv;
}

static bool equals(void){
	bool rv=true;
	GenericList *test1=GenericList_t.new();
	GenericList *test2=GenericList_t.new();
	GenericList_t.setElementSize(test1,sizeof(char));
	GenericList_t.setElementSize(test2,sizeof(char));
	GenericList_t.add(test1,"hello",5);
	GenericList_t.add(test2,"bye",3);
	if (GenericList_t.equals(test1,test2)) rv=false;
	GenericList_t.clear(test2);
	GenericList_t.add(test2,"hello",5);
	if (!GenericList_t.equals(test1,test2)) rv=false;
	GenericList_t.delete(&test1);
	GenericList_t.delete(&test2);
	Print_t.objectDebug("GenericList","equals",rv);
	return rv;
}
