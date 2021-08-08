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
static bool getFirstIndexOf(void);
static bool getLastIndexOf(void);
static bool getCharOccurrences(void);

bool stringDebug(void){
	return (
		setSize() &
		set() &
		concat() &
		concatChar() &
		copyOtherBetween() &
		getFirstIndexOf() &
		getLastIndexOf() &
		getCharOccurrences()
	       );
}

static bool setSize(void){
	bool rv=true;
	String *test=String_t.new();
	String_t.setSize(test,-1);
	(test->length!=0)? rv=false: 0;
	(test->str!=NULL)? rv=false: 0;
	String_t.setSize(test,0);
	(test->length!=0)? rv=false: 0;
	(test->str!=NULL)? rv=false: 0;
	String_t.setSize(test,10);
	(test->genericList->numElements!=11)? rv=false: 0;
	(test->length!=10)? rv=false: 0;
	(test->str[10]!='\0')? rv=false: 0;
	String_t.set(test,"hello");
	String_t.setSize(test,10);
	(test->genericList->numElements!=11)? rv=false: 0;
	(test->length!=10)? rv=false: 0;
	(test->str[0]!='h')? rv=false: 0;
	(test->str[4]!='o')? rv=false: 0;
	(test->str[5]!='\0')? rv=false: 0;
	(test->str[10]!='\0')? rv=false: 0;
	String_t.delete(&test);
	Print_t.objectDebug("String","setSize",rv);
	return rv;
}

static bool set(void){
	bool rv=true;
	String *test=String_t.new();
	String_t.set(test,"hello");
	(test->genericList->numElements!=6)? rv=false: 0;
	(test->length!=5)? rv=false: 0;
	(strcmp(test->str,"hello")!=0)? rv=false: 0;
	(test->str[test->length]!='\0')? rv=false: 0;
	String_t.set(test,"bye");
	(test->genericList->numElements!=4)? rv=false: 0;
	(test->length!=3)? rv=false: 0;
	(strcmp(test->str,"bye")!=0)? rv=false: 0;
	(test->str[test->length]!='\0')? rv=false: 0;
	String_t.set(test,"");
	(test->genericList->numElements!=0)? rv=false: 0;
	(test->length!=0)? rv=false: 0;
	(test->str!=NULL)? rv=false: 0;
	String_t.delete(&test);
	Print_t.objectDebug("String","set",rv);
	return rv;
}

static bool concat(void){
	bool rv=true;
	String *test=String_t.new();
	String_t.concat(test,"hello");
	(test->length!=5)? rv=false: 0;
	(strcmp(test->str,"hello")!=0)? rv=false: 0;
	(test->str[test->length]!='\0')? rv=false: 0;
	String_t.concat(test,"bye");
	(test->length!=8)? rv=false: 0;
	(strcmp(test->str,"hellobye")!=0)? rv=false: 0;
	(test->str[test->length]!='\0')? rv=false: 0;
	String_t.delete(&test);
	Print_t.objectDebug("String","concat",rv);
	return rv;
}

static bool concatChar(void){
	bool rv=true;
	String *test=String_t.new();
	String_t.concatChar(test,'h');
	(test->genericList->numElements!=2)? rv=false: 0;
	(test->length!=1)? rv=false: 0;
	(test->str[0]!='h')? rv=false: 0;
	(test->str[test->length]!='\0')? rv=false: 0;
	String_t.concatChar(test,'e');
	(test->genericList->numElements!=3)? rv=false: 0;
	(test->length!=2)? rv=false: 0;
	(test->str[0]!='h')? rv=false: 0;
	(test->str[1]!='e')? rv=false: 0;
	(test->str[test->length]!='\0')? rv=false: 0;
	String_t.delete(&test);
	Print_t.objectDebug("String","concatChar",rv);
	return rv;
}

static bool copyOtherBetween(void){
	bool rv=true;
	String *test1=String_t.new();
	String *test2=String_t.new();
	String_t.set(test2,"hello");
	String_t.copyOtherBetween(test1,test2,1,0);
	Print_t.println("%s",test1->str);
	//numElements is being set to -1
	(test1->genericList->numElements!=0)? rv=false: 0;
	(test1->length!=0)? rv=false: 0;
	(test1->str!=NULL)? rv=false: 0;
	String_t.copyOtherBetween(test1,test2,-1,6);
	Print_t.println("%s",test1->str);
	(test1->genericList->numElements!=6)? rv=false: 0;
	(test1->str[test1->length]!='\0')? rv=false: 0;
	(test1->length!=5)? rv=false: 0;
	(strcmp(test1->str,"hello")!=0)? rv=false: 0;
	String_t.copyOtherBetween(test1,test2,0,1);
	Print_t.println("%s",test1->str);
	(test1->genericList->numElements!=2)? rv=false: 0;
	(test1->str[test1->length]!='\0')? rv=false: 0;
	(test1->length!=1)? rv=false: 0;
	(strcmp(test1->str,"h")!=0)? rv=false: 0;
	String_t.copyOtherBetween(test1,test2,4,5);
	Print_t.println("%s",test1->str);
	(test1->genericList->numElements!=2)? rv=false: 0;
	(test1->str[test1->length]!='\0')? rv=false: 0;
	(test1->length!=1)? rv=false: 0;
	(strcmp(test1->str,"o")!=0)? rv=false: 0;
	String_t.copyOtherBetween(test1,test2,1,3);
	Print_t.println("%s",test1->str);
	(test1->genericList->numElements!=3)? rv=false: 0;
	(test1->str[test1->length]!='\0')? rv=false: 0;
	(test1->length!=2)? rv=false: 0;
	(strcmp(test1->str,"el")!=0)? rv=false: 0;
	String_t.delete(&test1);
	String_t.delete(&test2);
	Print_t.objectDebug("String","copyOtherBetween",rv);
	return rv;
}

static bool getFirstIndexOf(void){
	bool rv=true;
	String *test=String_t.new();
	String_t.set(test,"hello");
	(String_t.getFirstIndexOf(test,'h')!=0)? rv=false: 0;
	(String_t.getFirstIndexOf(test,'e')!=1)? rv=false: 0;
	(String_t.getFirstIndexOf(test,'l')!=2)? rv=false: 0;
	(String_t.getFirstIndexOf(test,'o')!=4)? rv=false: 0;
	(String_t.getFirstIndexOf(test,'b')!=-1)? rv=false: 0;
	String_t.delete(&test);
	Print_t.objectDebug("String","getFirstIndexOf",rv);
	return rv;
}

static bool getLastIndexOf(void){
	bool rv=true;
	String *test=String_t.new();
	String_t.set(test,"hello");
	(String_t.getLastIndexOf(test,'h')!=0)? rv=false: 0;
	(String_t.getLastIndexOf(test,'e')!=1)? rv=false: 0;
	(String_t.getLastIndexOf(test,'l')!=3)? rv=false: 0;
	(String_t.getLastIndexOf(test,'o')!=4)? rv=false: 0;
	(String_t.getLastIndexOf(test,'b')!=-1)? rv=false: 0;
	String_t.delete(&test);
	Print_t.objectDebug("String","getLastIndexOf",rv);
	return rv;
}

static bool getCharOccurrences(void){
	bool rv=true;
	String *test=String_t.new();
	String_t.set(test,"hello");
	(String_t.getCharOccurrences(test,"b")!=0)? rv=false: 0;
	(String_t.getCharOccurrences(test,"h")!=1)? rv=false: 0;
	(String_t.getCharOccurrences(test,"l")!=2)? rv=false: 0;
	(String_t.getCharOccurrences(test,"hl")!=3)? rv=false: 0;
	(String_t.getCharOccurrences(test,"hello")!=5)? rv=false: 0;
	String_t.delete(&test);
	Print_t.objectDebug("String","getCharOccurrences",rv);
	return rv;
}

