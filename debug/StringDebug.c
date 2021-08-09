#include <stdbool.h>
#include <string.h>
#include "Debug.h"
#include "../src/String.h"
#include "../src/Print.h"

static bool setSize(void);
static bool set(void);
static bool concat(void);
static bool concatChar(void);
static bool copyOtherBetween(void);
static bool toUpper(void);
static bool toLower(void);
static bool getFirstIndexOf(void);
static bool getLastIndexOf(void);
static bool getCharOccurrences(void);
static bool clear(void);

bool stringDebug(void){
	return (
		setSize() &
		set() &
		concat() &
		concatChar() &
		copyOtherBetween() &
		toUpper() &
		toLower() &
		getFirstIndexOf() &
		getLastIndexOf() &
		getCharOccurrences() &
		clear()
	       );
}

static bool setSize(void){
	bool rv=true;
	String *test=String_t.new();
	if (String_t.setSize(test,-1)) rv=false;
	if (test->length!=0) rv=false;
	if (test->str!=NULL) rv=false;
	if (String_t.setSize(test,0)) rv=false;
	if (test->length!=0) rv=false;
	if (test->str!=NULL) rv=false;
	if (!String_t.setSize(test,10)) rv=false;
	if (test->genericList->numElements!=11) rv=false;
	if (test->length!=10) rv=false;
	if (test->str[10]!='\0') rv=false;
	String_t.set(test,"hello");
	if (!String_t.setSize(test,10)) rv=false;
	if (test->genericList->numElements!=11) rv=false;
	if (test->length!=10) rv=false;
	if (test->str[0]!='h') rv=false;
	if (test->str[4]!='o') rv=false;
	if (test->str[5]!='\0') rv=false;
	if (test->str[10]!='\0') rv=false;
	String_t.delete(&test);
	Print_t.objectDebug("String","setSize",rv);
	return rv;
}

static bool set(void){
	bool rv=true;
	String *test=String_t.new();
	if (!String_t.set(test,"hello")) rv=false;
	if (test->genericList->numElements!=6) rv=false;
	if (test->length!=5) rv=false;
	if (strcmp(test->str,"hello")!=0) rv=false;
	if (test->str[test->length]!='\0') rv=false;
	if (!String_t.set(test,"bye")) rv=false;
	if (test->genericList->numElements!=4) rv=false;
	if (test->length!=3) rv=false;
	if (strcmp(test->str,"bye")!=0) rv=false;
	if (test->str[test->length]!='\0') rv=false;
	if (!String_t.set(test,"")) rv=false;
	if (test->genericList->numElements!=0) rv=false;
	if (test->length!=0) rv=false;
	if (test->str!=NULL) rv=false;
	String_t.delete(&test);
	Print_t.objectDebug("String","set",rv);
	return rv;
}

static bool concat(void){
	bool rv=true;
	String *test=String_t.new();
	if (!String_t.concat(test,"hello")) rv=false;
	if (test->length!=5) rv=false;
	if (strcmp(test->str,"hello")!=0) rv=false;
	if (test->str[test->length]!='\0') rv=false;
	if (!String_t.concat(test,"bye")) rv=false;
	if (test->length!=8) rv=false;
	if (strcmp(test->str,"hellobye")!=0) rv=false;
	if (test->str[test->length]!='\0') rv=false;
	String_t.delete(&test);
	Print_t.objectDebug("String","concat",rv);
	return rv;
}

static bool concatChar(void){
	bool rv=true;
	String *test=String_t.new();
	if (!String_t.concatChar(test,'h')) rv=false;
	if (test->genericList->numElements!=2) rv=false;
	if (test->length!=1) rv=false;
	if (test->str[0]!='h') rv=false;
	if (test->str[test->length]!='\0') rv=false;
	if (!String_t.concatChar(test,'e')) rv=false;
	if (test->genericList->numElements!=3) rv=false;
	if (test->length!=2) rv=false;
	if (test->str[0]!='h') rv=false;
	if (test->str[1]!='e') rv=false;
	if (test->str[test->length]!='\0') rv=false;
	String_t.delete(&test);
	Print_t.objectDebug("String","concatChar",rv);
	return rv;
}

static bool copyOtherBetween(void){
	bool rv=true;
	String *test1=String_t.new();
	String *test2=String_t.new();
	String_t.set(test2,"hello");
	if (String_t.copyOtherBetween(test1,test2,1,0)) rv=false;
	if (test1->genericList->numElements!=0) rv=false;
	if (test1->length!=0) rv=false;
	if (test1->str!=NULL) rv=false;
	if (!String_t.copyOtherBetween(test1,test2,-1,6)) rv=false;
	if (test1->genericList->numElements!=6) rv=false;
	if (test1->str[test1->length]!='\0') rv=false;
	if (test1->length!=5) rv=false;
	if (strcmp(test1->str,"hello")!=0) rv=false;
	if (!String_t.copyOtherBetween(test1,test2,0,1)) rv=false;
	if (test1->genericList->numElements!=2) rv=false;
	if (test1->str[test1->length]!='\0') rv=false;
	if (test1->length!=1) rv=false;
	if (strcmp(test1->str,"h")!=0) rv=false;
	if (!String_t.copyOtherBetween(test1,test2,4,5)) rv=false;
	if (test1->genericList->numElements!=2) rv=false;
	if (test1->str[test1->length]!='\0') rv=false;
	if (test1->length!=1) rv=false;
	if (strcmp(test1->str,"o")!=0) rv=false;
	if (!String_t.copyOtherBetween(test1,test2,1,3)) rv=false;
	if (test1->genericList->numElements!=3) rv=false;
	if (test1->str[test1->length]!='\0') rv=false;
	if (test1->length!=2) rv=false;
	if (strcmp(test1->str,"el")!=0) rv=false;
	String_t.delete(&test1);
	String_t.delete(&test2);
	Print_t.objectDebug("String","copyOtherBetween",rv);
	return rv;
}

static bool toUpper(void){
	bool rv=true;
	String *test=String_t.new();
	String_t.set(test,"HELLO");
	String_t.toUpper(test);
	if (strcmp(test->str,"HELLO")!=0) rv=false;
	String_t.set(test,"hello");
	String_t.toUpper(test);
	if (strcmp(test->str,"HELLO")!=0) rv=false;
	String_t.delete(&test);
	Print_t.objectDebug("String","toUpper",rv);
	return rv;
}

static bool toLower(void){
	bool rv=true;
	String *test=String_t.new();
	String_t.set(test,"hello");
	String_t.toLower(test);
	if (strcmp(test->str,"hello")!=0) rv=false;
	String_t.set(test,"HELLO");
	String_t.toLower(test);
	if (strcmp(test->str,"hello")!=0) rv=false;
	String_t.delete(&test);
	Print_t.objectDebug("String","toLower",rv);
	return rv;
}

static bool getFirstIndexOf(void){
	bool rv=true;
	String *test=String_t.new();
	String_t.set(test,"hello");
	if (String_t.getFirstIndexOf(test,'h')!=0) rv=false;
	if (String_t.getFirstIndexOf(test,'e')!=1) rv=false;
	if (String_t.getFirstIndexOf(test,'l')!=2) rv=false;
	if (String_t.getFirstIndexOf(test,'o')!=4) rv=false;
	if (String_t.getFirstIndexOf(test,'b')!=-1) rv=false;
	String_t.delete(&test);
	Print_t.objectDebug("String","getFirstIndexOf",rv);
	return rv;
}

static bool getLastIndexOf(void){
	bool rv=true;
	String *test=String_t.new();
	String_t.set(test,"hello");
	if (String_t.getLastIndexOf(test,'h')!=0) rv=false;
	if (String_t.getLastIndexOf(test,'e')!=1) rv=false;
	if (String_t.getLastIndexOf(test,'l')!=3) rv=false;
	if (String_t.getLastIndexOf(test,'o')!=4) rv=false;
	if (String_t.getLastIndexOf(test,'b')!=-1) rv=false;
	String_t.delete(&test);
	Print_t.objectDebug("String","getLastIndexOf",rv);
	return rv;
}

static bool getCharOccurrences(void){
	bool rv=true;
	String *test=String_t.new();
	String_t.set(test,"hello");
	if (String_t.getCharOccurrences(test,"b")!=0) rv=false;
	if (String_t.getCharOccurrences(test,"h")!=1) rv=false;
	if (String_t.getCharOccurrences(test,"l")!=2) rv=false;
	if (String_t.getCharOccurrences(test,"hl")!=3) rv=false;
	if (String_t.getCharOccurrences(test,"hello")!=5) rv=false;
	String_t.delete(&test);
	Print_t.objectDebug("String","getCharOccurrences",rv);
	return rv;
}

static bool clear(void){
	bool rv=true;
	String *test=String_t.new();
	String_t.set(test,"hello");
	String_t.clear(test);
	if (test->genericList->numElements!=0) rv=false;
	if (test->length!=0) rv=false;
	if (test->str!=NULL) rv=false;
	String_t.delete(&test);
	Print_t.objectDebug("String","clear",rv);
	return rv;
}
