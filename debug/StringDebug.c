#include <stdbool.h>
#include <string.h>
#include "Debug.h"
#include "../src/String.h"
#include "../src/Print.h"

#define stringTest(result) test(result,"String",__FUNCTION__,__LINE__)

static void setSize(void);
static void set(void);
static void concat(void);
static void concatChar(void);
static void copyOtherBetween(void);
static void toUpper(void);
static void toLower(void);
static void getFirstIndexOf(void);
static void getLastIndexOf(void);
static void getCharOccurrences(void);
static void trimSubstring(void);
static void clear(void);

void stringDebug(void){
	setSize();
	set();
	concat();
	concatChar();
	copyOtherBetween();
	toUpper();
	toLower();
	getFirstIndexOf();
	getLastIndexOf();
	getCharOccurrences();
	trimSubstring();
	clear();
}

static void setSize(void){
	String *test=String_t.new();
	stringTest(!String_t.setSize(test,-1));
	stringTest(test->length==0);
	stringTest(test->str==NULL);
	stringTest(!String_t.setSize(test,0));
	stringTest(test->length==0);
	stringTest(test->str==NULL);
	stringTest(String_t.setSize(test,10));
	stringTest(test->genericList->listSize==11);
	stringTest(test->length==0);
	String_t.set(test,"hello");
	stringTest(String_t.setSize(test,20));
	stringTest(test->genericList->listSize==21);
	stringTest(test->length==5);
	stringTest(test->str[0]=='h');
	stringTest(test->str[4]=='o');
	stringTest(test->str[5]=='\0');
	String_t.delete(&test);
}

static void set(void){
	String *test=String_t.new();
	stringTest(String_t.set(test,"hello"));
	stringTest(test->genericList->numElements>=6);
	stringTest(test->length==5);
	stringTest(strcmp(test->str,"hello")==0);
	stringTest(test->str[test->length]=='\0');
	stringTest(String_t.set(test,"bye"));
	stringTest(test->genericList->numElements>=4);
	stringTest(test->length==3);
	stringTest(strcmp(test->str,"bye")==0);
	stringTest(test->str[test->length]=='\0');
	stringTest(String_t.set(test,""));
	stringTest(test->genericList->numElements>=0);
	stringTest(test->length==0);
	stringTest(test->str==NULL);
	String_t.delete(&test);
}

static void concat(void){
	String *test=String_t.new();
	stringTest(String_t.concat(test,"hello"));
	stringTest(test->length==5);
	stringTest(strcmp(test->str,"hello")==0);
	stringTest(test->str[test->length]=='\0');
	stringTest(String_t.concat(test,"bye"));
	stringTest(test->length==8);
	stringTest(strcmp(test->str,"hellobye")==0);
	stringTest(test->str[test->length]=='\0');
	String_t.delete(&test);
}

static void concatChar(void){
	String *test=String_t.new();
	stringTest(String_t.concatChar(test,'h'));
	stringTest(test->genericList->numElements==2);
	stringTest(test->length==1);
	stringTest(test->str[0]=='h');
	stringTest(test->str[test->length]=='\0');
	stringTest(String_t.concatChar(test,'e'));
	stringTest(test->genericList->numElements==3);
	stringTest(test->length==2);
	stringTest(test->str[0]=='h');
	stringTest(test->str[1]=='e');
	stringTest(test->str[test->length]=='\0');
	String_t.delete(&test);
}

static void copyOtherBetween(void){
	String *test1=String_t.new();
	String *test2=String_t.new();
	String_t.set(test2,"hello");
	stringTest(!String_t.copyOtherBetween(test1,test2,1,0));
	stringTest(test1->genericList->numElements==0);
	stringTest(test1->length==0);
	stringTest(test1->str==NULL);
	stringTest(!String_t.copyOtherBetween(test1,test2,-1,3));
	stringTest(test1->genericList->numElements==0);
	stringTest(test1->length==0);
	stringTest(!String_t.copyOtherBetween(test1,test2,2,6));
	stringTest(test1->genericList->numElements==0);
	stringTest(test1->length==0);
	stringTest(!String_t.copyOtherBetween(test1,test2,6,2));
	stringTest(test1->genericList->numElements==0);
	stringTest(test1->length==0);
	stringTest(String_t.copyOtherBetween(test1,test2,0,1));
	stringTest(test1->genericList->numElements==2);
	stringTest(test1->str[test1->length]=='\0');
	stringTest(test1->length==1);
	stringTest(strcmp(test1->str,"h")==0);
	stringTest(String_t.copyOtherBetween(test1,test2,4,5));
	stringTest(test1->genericList->numElements==2);
	stringTest(test1->str[test1->length]=='\0');
	stringTest(test1->length==1);
	stringTest(strcmp(test1->str,"o")==0);
	stringTest(String_t.copyOtherBetween(test1,test2,1,3));
	stringTest(test1->genericList->numElements==3);
	stringTest(test1->str[test1->length]=='\0');
	stringTest(test1->length==2);
	stringTest(strcmp(test1->str,"el")==0);
	String_t.delete(&test1);
	String_t.delete(&test2);
}

static void toUpper(void){
	String *test=String_t.new();
	String_t.set(test,"HELLO");
	String_t.toUpper(test);
	stringTest(strcmp(test->str,"HELLO")==0);
	String_t.set(test,"hello");
	String_t.toUpper(test);
	stringTest(strcmp(test->str,"HELLO")==0);
	String_t.delete(&test);
}

static void toLower(void){
	String *test=String_t.new();
	String_t.set(test,"hello");
	String_t.toLower(test);
	stringTest(strcmp(test->str,"hello")==0);
	String_t.set(test,"HELLO");
	String_t.toLower(test);
	stringTest(strcmp(test->str,"hello")==0);
	String_t.delete(&test);
}

static void getFirstIndexOf(void){
	String *test=String_t.new();
	String_t.set(test,"hello");
	stringTest(String_t.getFirstIndexOf(test,'h')==0);
	stringTest(String_t.getFirstIndexOf(test,'e')==1);
	stringTest(String_t.getFirstIndexOf(test,'l')==2);
	stringTest(String_t.getFirstIndexOf(test,'o')==4);
	stringTest(String_t.getFirstIndexOf(test,'b')==-1);
	String_t.delete(&test);
}

static void getLastIndexOf(void){
	String *test=String_t.new();
	String_t.set(test,"hello");
	stringTest(String_t.getLastIndexOf(test,'h')==0);
	stringTest(String_t.getLastIndexOf(test,'e')==1);
	stringTest(String_t.getLastIndexOf(test,'l')==3);
	stringTest(String_t.getLastIndexOf(test,'o')==4);
	stringTest(String_t.getLastIndexOf(test,'b')==-1);
	String_t.delete(&test);
}

static void getCharOccurrences(void){
	String *test=String_t.new();
	String_t.set(test,"hello");
	stringTest(String_t.getCharOccurrences(test,"b")==0);
	stringTest(String_t.getCharOccurrences(test,"h")==1);
	stringTest(String_t.getCharOccurrences(test,"l")==2);
	stringTest(String_t.getCharOccurrences(test,"hl")==3);
	stringTest(String_t.getCharOccurrences(test,"hello")==5);
	String_t.delete(&test);
}

static void trimSubstring(void){
	String *test=String_t.new();
	//if (String_t.trimSubstring(test,
}

static void clear(void){
	String *test=String_t.new();
	String_t.set(test,"hello");
	String_t.clear(test);
	stringTest(test->genericList->numElements==0);
	stringTest(test->length==0);
	stringTest(test->str==NULL);
	String_t.delete(&test);
}
