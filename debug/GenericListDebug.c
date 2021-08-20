#include <string.h>
#include <stdbool.h>
#include "Debug.h"
#include "../src/objectSystem/Object.h"
#include "../src/collections/GenericList.h"
#include "../src/IO/Print.h"

#define genericListTest(result) test(result,"GenericList",__FUNCTION__,__LINE__)

static void copyConstructor(void);
static void comparator(void);
static void setElementSize(void);
static void setListSize(void);
static void set(void);
static void setAt(void);
static void add(void);
static void addAt(void);
static void copyOtherBetween(void);
static void get(void);
static void contains(void);
static void getFirstIndexOf(void);
static void getLastIndexOf(void);
static void _remove(void);
static void removeAll(void);
static void removeAt(void);
static void removeBetween(void);
static void trimToSize(void);
static void clear(void);
static void clearElements(void);
static void isEmpty(void);

void genericListDebug(void){
	copyConstructor();
	comparator();
	setElementSize();
	setListSize();
	set();
	setAt();
	add();
	addAt();
	copyOtherBetween();
	get();
	contains();
	getFirstIndexOf();
	getLastIndexOf();
	_remove();
	removeAll();
	removeAt();
	removeBetween();
	trimToSize();
	clear();
	clearElements();
	isEmpty();
}

static void copyConstructor(void){
	GenericList *test1=new(GenericList);
	GenericList_t.setElementSize(test1,sizeof(char));
	GenericList_t.set(test1,"hello",5);
	GenericList *test2=copy(GenericList,test1);
	genericListTest(test1!=test2);
	genericListTest(test1->numElements==test2->numElements);
	genericListTest(test1->listSize==test2->listSize);
	genericListTest(test1->strictAlloc==test2->strictAlloc);
	genericListTest(test1->elementSize==test2->elementSize);
	genericListTest(test1->list!=test2->list);
	genericListTest(memcmp(test1->list,test2->list,test1->numElements*test1->elementSize)==0);
	delete(GenericList,test1);
	delete(GenericList,test2);
}

static void comparator(void){
	GenericList *test1=new(GenericList);
	GenericList_t.setElementSize(test1,sizeof(char));
	GenericList_t.set(test1,"hello",5);
	GenericList *test2=copy(GenericList,test1);
	genericListTest(equals(GenericList,test1,test2));
	GenericList_t.clear(test2);
	genericListTest(!equals(GenericList,test1,test2));
	delete(GenericList,test1);
	delete(GenericList,test2);
}

static void setElementSize(void){
	GenericList *test=new(GenericList);
	genericListTest(test->elementSize==0);
	genericListTest(GenericList_t.setElementSize(test,sizeof(char)));
	genericListTest(test->elementSize==sizeof(char));
	GenericList_t.add(test,&("hello"[0]),1);
	genericListTest(!GenericList_t.setElementSize(test,sizeof(char)));
	genericListTest(GenericList_t.setElementSize(test,sizeof(float)));
	genericListTest(test->elementSize==sizeof(float));
	genericListTest(test->numElements==0);
	delete(GenericList,test);
}

static void setListSize(void){
	GenericList *test=new(GenericList);
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
	delete(GenericList,test);
}

static void set(void){
	GenericList *test=new(GenericList);
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
	delete(GenericList,test);
}

static void setAt(void){
	GenericList *test=new(GenericList);
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
	delete(GenericList,test);
}

static void add(void){
	GenericList *test=new(GenericList);
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
	delete(GenericList,test);
}

static void addAt(void){
	GenericList *test=new(GenericList);
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
	delete(GenericList,test);
}

static void copyOtherBetween(void){
	GenericList *test1=new(GenericList);
	GenericList *test2=new(GenericList);
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
	delete(GenericList,test1);
	delete(GenericList,test2);
}

static void get(void){
	GenericList *test=new(GenericList);
	GenericList_t.setElementSize(test,sizeof(char));
	GenericList_t.add(test,"hello",5);
	genericListTest(GenericList_t.get(test,-1)==NULL);
	genericListTest(*(char*)GenericList_t.get(test,0)=='h');
	genericListTest(*(char*)GenericList_t.get(test,1)=='e');
	genericListTest(*(char*)GenericList_t.get(test,2)=='l');
	genericListTest(*(char*)GenericList_t.get(test,3)=='l');
	genericListTest(*(char*)GenericList_t.get(test,4)=='o');
	genericListTest(GenericList_t.get(test,5)==NULL);
	delete(GenericList,test);
}

static void contains(void){
	GenericList *test=new(GenericList);
	GenericList_t.setElementSize(test,sizeof(char));
	GenericList_t.add(test,"hello",5);
	genericListTest(GenericList_t.contains(test,&("hello"[0])));
	genericListTest(GenericList_t.contains(test,&("hello"[1])));
	genericListTest(GenericList_t.contains(test,&("hello"[2])));
	genericListTest(GenericList_t.contains(test,&("hello"[3])));
	genericListTest(GenericList_t.contains(test,&("hello"[4])));
	genericListTest(!GenericList_t.contains(test,&("bye"[0])));
	genericListTest(!GenericList_t.contains(test,&("bye"[1])));
	delete(GenericList,test);
}

static void getFirstIndexOf(void){
	GenericList *test=new(GenericList);
	GenericList_t.setElementSize(test,sizeof(char));
	GenericList_t.add(test,"hello",5);
	genericListTest(GenericList_t.getFirstIndexOf(test,&("hello"[0]))==0);
	genericListTest(GenericList_t.getFirstIndexOf(test,&("hello"[1]))==1);
	genericListTest(GenericList_t.getFirstIndexOf(test,&("hello"[2]))==2);
	genericListTest(GenericList_t.getFirstIndexOf(test,&("hello"[3]))==2);
	genericListTest(GenericList_t.getFirstIndexOf(test,&("hello"[4]))==4);
	genericListTest(GenericList_t.getFirstIndexOf(test,&("bye"[0]))==-1);
	genericListTest(GenericList_t.getFirstIndexOf(test,&("bye"[1]))==-1);
	delete(GenericList,test);
}

static void getLastIndexOf(void){
	GenericList *test=new(GenericList);
	GenericList_t.setElementSize(test,sizeof(char));
	GenericList_t.add(test,"hello",5);
	genericListTest(GenericList_t.getLastIndexOf(test,&("hello"[0]))==0);
	genericListTest(GenericList_t.getLastIndexOf(test,&("hello"[1]))==1);
	genericListTest(GenericList_t.getLastIndexOf(test,&("hello"[2]))==3);
	genericListTest(GenericList_t.getLastIndexOf(test,&("hello"[3]))==3);
	genericListTest(GenericList_t.getLastIndexOf(test,&("hello"[4]))==4);
	genericListTest(GenericList_t.getLastIndexOf(test,&("bye"[0]))==-1);
	genericListTest(GenericList_t.getLastIndexOf(test,&("bye"[1]))==-1);
	delete(GenericList,test);
}

static void _remove(void){
	GenericList *test=new(GenericList);
	GenericList_t.setElementSize(test,sizeof(char));
	GenericList_t.add(test,"hello",5);
	genericListTest(GenericList_t.remove(test,&("bye"[0])));
	genericListTest(GenericList_t.remove(test,&("hello"[0])));
	genericListTest(GenericList_t.remove(test,&("hello"[4])));
	genericListTest(GenericList_t.remove(test,&("hello"[2])));
	genericListTest(test->numElements==1);
	genericListTest(*((char*)test->list+sizeof(char)*0)=='e');
	genericListTest(GenericList_t.remove(test,&("hello"[1])));
	genericListTest(test->numElements==0);
	genericListTest(test->list==NULL);
	delete(GenericList,test);
}

static void removeAll(void){
	GenericList *test=new(GenericList);
	GenericList_t.setElementSize(test,sizeof(char));
	genericListTest(!GenericList_t.removeAll(test,"hello",5));
	GenericList_t.add(test,"hello",5);
	genericListTest(GenericList_t.removeAll(test,"bye",3));
	genericListTest(test->numElements==4);
	genericListTest(*((char*)test->list+sizeof(char)*0)=='h');
	genericListTest(*((char*)test->list+sizeof(char)*1)=='l');
	genericListTest(*((char*)test->list+sizeof(char)*2)=='l');
	genericListTest(*((char*)test->list+sizeof(char)*3)=='o');
	genericListTest(GenericList_t.removeAll(test,"hl",2));
	genericListTest(test->numElements==1);
	genericListTest(*((char*)test->list+sizeof(char)*0)=='o');
	genericListTest(GenericList_t.removeAll(test,"o",1));
	genericListTest(test->numElements==0);
	genericListTest(test->list==NULL);
	delete(GenericList,test);
}

static void removeAt(void){
	GenericList *test=new(GenericList);
	GenericList_t.setElementSize(test,sizeof(char));
	GenericList_t.add(test,"hello",5);
	genericListTest(!GenericList_t.removeAt(test,-1));
	genericListTest(!GenericList_t.removeAt(test,6));
	genericListTest(test->numElements==5);
	genericListTest(GenericList_t.removeAt(test,0));
	genericListTest(GenericList_t.removeAt(test,3));
	genericListTest(GenericList_t.removeAt(test,1));
	genericListTest(test->numElements==2);
	genericListTest(*((char*)test->list+sizeof(char)*0)=='e');
	genericListTest(*((char*)test->list+sizeof(char)));
	genericListTest(GenericList_t.removeAt(test,0));
	genericListTest(GenericList_t.removeAt(test,0));
	genericListTest(test->numElements==0);
	genericListTest(test->list==NULL);
	delete(GenericList,test);
}

static void removeBetween(void){
	GenericList *test=new(GenericList);
	GenericList_t.setElementSize(test,sizeof(char));
	GenericList_t.add(test,"hello",5);
	genericListTest(!GenericList_t.removeBetween(test,-1,3));
	genericListTest(!GenericList_t.removeBetween(test,0,6));
	genericListTest(!GenericList_t.removeBetween(test,3,2));
	genericListTest(test->numElements==5);
	genericListTest(GenericList_t.removeBetween(test,0,1));
	genericListTest(GenericList_t.removeBetween(test,3,4));
	genericListTest(GenericList_t.removeBetween(test,1,2));
	genericListTest(test->numElements==2);
	genericListTest(*((char*)test->list+sizeof(char)*0)=='e');
	genericListTest(*((char*)test->list+sizeof(char)*1)=='l');
	genericListTest(GenericList_t.removeBetween(test,0,2));
	genericListTest(test->numElements==0);
	genericListTest(test->list==NULL);
	delete(GenericList,test);
}

static void trimToSize(void){
	GenericList *test=new(GenericList);
	GenericList_t.setElementSize(test,sizeof(char));
	GenericList_t.add(test,"hello",5);
	genericListTest(!GenericList_t.trimToSize(test));
	genericListTest(test->numElements==5);
	genericListTest(test->listSize==5);
	genericListTest(*((char*)test->list+sizeof(char)*0)=='h');
	genericListTest(*((char*)test->list+sizeof(char)*4)=='o');
	GenericList_t.set(test,"bye",3);
	genericListTest(test->numElements==3);
	genericListTest(test->listSize==5);
	genericListTest(GenericList_t.trimToSize(test));
	genericListTest(test->numElements==3);
	genericListTest(test->listSize==3);
	genericListTest(*((char*)test->list+sizeof(char)*0)=='b');
	genericListTest(*((char*)test->list+sizeof(char)*2)=='e');

	test->strictAlloc=true;
	GenericList_t.set(test,"hello",5);
	genericListTest(!GenericList_t.trimToSize(test));
	genericListTest(test->numElements==5);
	genericListTest(test->listSize==5);
	genericListTest(*((char*)test->list+sizeof(char)*0)=='h');
	genericListTest(*((char*)test->list+sizeof(char)*4)=='o');
	GenericList_t.set(test,"bye",3);
	genericListTest(test->numElements==3);
	genericListTest(test->listSize==3);
	genericListTest(!GenericList_t.trimToSize(test));
	genericListTest(test->numElements==3);
	genericListTest(test->listSize==3);
	genericListTest(*((char*)test->list+sizeof(char)*0)=='b');
	genericListTest(*((char*)test->list+sizeof(char)*2)=='e');

	delete(GenericList,test);
}

static void clear(void){
	GenericList *test=new(GenericList);
	GenericList_t.setElementSize(test,sizeof(char));
	GenericList_t.add(test,"hello",5);
	genericListTest(GenericList_t.clear(test));
	genericListTest(test->numElements==0);
	genericListTest(test->list==NULL);
	delete(GenericList,test);
}

static void clearElements(void){
	GenericList *test=new(GenericList);
	GenericList_t.setElementSize(test,sizeof(char));
	GenericList_t.set(test,"hello",5);
	genericListTest(GenericList_t.clearElements(test));
	genericListTest(test->numElements==0);
	genericListTest(test->listSize==5);
	genericListTest(*((char*)test->list+sizeof(char)*0)=='h');
	genericListTest(*((char*)test->list+sizeof(char)*4)=='o');
	delete(GenericList,test);
}

static void isEmpty(void){
	GenericList *test=new(GenericList);
	genericListTest(GenericList_t.isEmpty(test));
	delete(GenericList,test);
}
