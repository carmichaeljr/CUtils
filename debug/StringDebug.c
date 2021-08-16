#include <stdbool.h>
#include <string.h>
#include "Debug.h"
#include "../src/Object.h"
#include "../src/String.h"
#include "../src/Print.h"

#define stringTest(result) test(result,"String",__FUNCTION__,__LINE__)

static void copyConstructor(void);
static void comparator(void);
static void setSize(void);
static void set(void);
static void setNonNullString(void);
static void concat(void);
static void concatChar(void);
static void copyOtherBetween(void);
static void toUpper(void);
static void toLower(void);
static void contains(void);
static void getFirstIndexOf(void);
static void getLastIndexOf(void);
static void getCharOccurrences(void);
static void trimSubstring(void);
static void trimWhitespace(void);
static void removeChars(void);
static void clear(void);
static void equalsCharArray(void);

void stringDebug(void){
	copyConstructor();
	comparator();
	setSize();
	set();
	setNonNullString();
	concat();
	concatChar();
	copyOtherBetween();
	toUpper();
	toLower();
	contains();
	getFirstIndexOf();
	getLastIndexOf();
	getCharOccurrences();
	trimSubstring();
	trimWhitespace();
	removeChars();
	clear();
	equalsCharArray();
}

static void copyConstructor(void){
	String *test1=new(String);
	String_t.set(test1,"hello");
	String *test2=copy(String,test1);
	stringTest(test1!=test2);
	stringTest(test1->length==test2->length);
	stringTest(equals(GenericList,test1->genericList,test2->genericList));
	stringTest(strcmp(test1->str,test2->str)==0);
	delete(String,test1);
	delete(String,test2);
}

static void comparator(void){
	String *test1=new(String);
	String_t.set(test1,"hello");
	String *test2=copy(String,test1);
	stringTest(equals(String,test1,test2)==0);
	test2->str[0]='H';
	stringTest(equals(String,test1,test2)>0);
	test1->str[0]='H';
	test2->str[0]='h';
	stringTest(equals(String,test1,test2)<0);
	String_t.clear(test1);
	stringTest(equals(String,test1,test2)>0);
	String_t.set(test1,"hello");
	String_t.clear(test2);
	stringTest(equals(String,test1,test2)<0);
	String_t.clear(test1);
	stringTest(equals(String,test1,test2)==0);
	delete(String,test1);
	delete(String,test2);
}

static void setSize(void){
	String *test=new(String);
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
	delete(String,test);
}

static void set(void){
	String *test=new(String);
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
	String_t.set(test,"hello");
	stringTest(String_t.set(test,NULL));
	stringTest(test->genericList->numElements>=0);
	stringTest(test->length==0);
	stringTest(test->str==NULL);
	delete(String,test);
}

static void setNonNullString(void){
	char str[5]={ 'h','e','l','l','o' };
	String *test=new(String);
	stringTest(String_t.setNonNullString(test,str,5));
	stringTest(test->genericList->numElements==6);
	stringTest(test->length==5);
	stringTest(strcmp(test->str,"hello")==0);
	stringTest(test->str[test->length]=='\0');
	stringTest(String_t.setNonNullString(test,NULL,0));
	stringTest(test->length==0);
	stringTest(test->str==NULL);
	delete(String,test);
}

static void concat(void){
	String *test=new(String);
	stringTest(String_t.concat(test,"hello"));
	stringTest(test->length==5);
	stringTest(strcmp(test->str,"hello")==0);
	stringTest(test->str[test->length]=='\0');
	stringTest(String_t.concat(test,"bye"));
	stringTest(test->length==8);
	stringTest(strcmp(test->str,"hellobye")==0);
	stringTest(test->str[test->length]=='\0');
	delete(String,test);
}

static void concatChar(void){
	String *test=new(String);
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
	delete(String,test);
}

static void copyOtherBetween(void){
	String *test1=new(String);
	String *test2=new(String);
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
	delete(String,test1);
	delete(String,test2);
}

static void toUpper(void){
	String *test=new(String);
	String_t.set(test,"HELLO");
	String_t.toUpper(test);
	stringTest(strcmp(test->str,"HELLO")==0);
	String_t.set(test,"hello");
	String_t.toUpper(test);
	stringTest(strcmp(test->str,"HELLO")==0);
	delete(String,test);
}

static void toLower(void){
	String *test=new(String);
	String_t.set(test,"hello");
	String_t.toLower(test);
	stringTest(strcmp(test->str,"hello")==0);
	String_t.set(test,"HELLO");
	String_t.toLower(test);
	stringTest(strcmp(test->str,"hello")==0);
	delete(String,test);
}

static void contains(void){
	String *test=new(String);
	stringTest(String_t.contains(test,"h")==-1);
	String_t.set(test,"hello");
	stringTest(String_t.contains(test,"h")==0);
	stringTest(String_t.contains(test,"e")==1);
	stringTest(String_t.contains(test,"l")==2);
	stringTest(String_t.contains(test,"o")==4);
	stringTest(String_t.contains(test,"he")==0);
	stringTest(String_t.contains(test,"el")==1);
	stringTest(String_t.contains(test,"ll")==2);
	stringTest(String_t.contains(test,"lo")==3);
	stringTest(String_t.contains(test,"hel")==0);
	stringTest(String_t.contains(test,"ell")==1);
	stringTest(String_t.contains(test,"llo")==2);
	stringTest(String_t.contains(test,"hell")==0);
	stringTest(String_t.contains(test,"ello")==1);
	stringTest(String_t.contains(test,"hello")==0);
	stringTest(String_t.contains(test,"bye")==-1);
	delete(String,test);
}

static void getFirstIndexOf(void){
	String *test=new(String);
	String_t.set(test,"hello");
	stringTest(String_t.getFirstIndexOf(test,'h')==0);
	stringTest(String_t.getFirstIndexOf(test,'e')==1);
	stringTest(String_t.getFirstIndexOf(test,'l')==2);
	stringTest(String_t.getFirstIndexOf(test,'o')==4);
	stringTest(String_t.getFirstIndexOf(test,'b')==-1);
	delete(String,test);
}

static void getLastIndexOf(void){
	String *test=new(String);
	String_t.set(test,"hello");
	stringTest(String_t.getLastIndexOf(test,'h')==0);
	stringTest(String_t.getLastIndexOf(test,'e')==1);
	stringTest(String_t.getLastIndexOf(test,'l')==3);
	stringTest(String_t.getLastIndexOf(test,'o')==4);
	stringTest(String_t.getLastIndexOf(test,'b')==-1);
	delete(String,test);
}

static void getCharOccurrences(void){
	String *test=new(String);
	String_t.set(test,"hello");
	stringTest(String_t.getCharOccurrences(test,"b")==0);
	stringTest(String_t.getCharOccurrences(test,"h")==1);
	stringTest(String_t.getCharOccurrences(test,"l")==2);
	stringTest(String_t.getCharOccurrences(test,"hl")==3);
	stringTest(String_t.getCharOccurrences(test,"hello")==5);
	delete(String,test);
}

static void trimSubstring(void){
	String *test=new(String);
	stringTest(!String_t.trimSubstring(test,2,3));
	String_t.set(test,"hello");
	stringTest(!String_t.trimSubstring(test,-1,3));
	stringTest(!String_t.trimSubstring(test,1,6));
	stringTest(!String_t.trimSubstring(test,3,2));
	stringTest(String_t.trimSubstring(test,1,2));
	stringTest(test->length==4);
	stringTest(test->str[0]=='h');
	stringTest(test->str[1]=='l');
	stringTest(test->str[3]=='o');
	stringTest(test->str[4]=='\0');
	stringTest(String_t.trimSubstring(test,0,1));
	stringTest(test->length==3);
	stringTest(test->str[0]=='l');
	stringTest(test->str[2]=='o');
	stringTest(test->str[3]=='\0');
	stringTest(String_t.trimSubstring(test,2,3));
	stringTest(test->length==2);
	stringTest(test->str[0]=='l');
	stringTest(test->str[1]=='l');
	stringTest(test->str[2]=='\0');
	stringTest(String_t.trimSubstring(test,0,2));
	stringTest(test->length==0);
	stringTest(test->str==NULL);
	delete(String,test);
}

static void trimWhitespace(void){
	String *test=new(String);
	stringTest(!String_t.trimWhitespace(test));
	String_t.set(test,"   hello   ");
	stringTest(String_t.trimWhitespace(test));
	stringTest(test->length==5);
	stringTest(test->str[0]=='h');
	stringTest(test->str[4]=='o');
	stringTest(test->str[5]=='\0');
	stringTest(String_t.trimWhitespace(test));
	stringTest(test->length==5);
	stringTest(test->str[0]=='h');
	stringTest(test->str[4]=='o');
	stringTest(test->str[5]=='\0');
	delete(String,test);
}

static void removeChars(void){
	String *test=new(String);
	stringTest(!String_t.removeChars(test,"hello"));
	String_t.set(test,"hello");
	stringTest(String_t.removeChars(test,"lo"));
	stringTest(test->length==2);
	stringTest(test->str[0]=='h');
	stringTest(test->str[1]=='e');
	stringTest(test->str[2]=='\0');
	stringTest(String_t.removeChars(test,"he"));
	stringTest(test->length==0);
	stringTest(test->str==NULL);
	delete(String,test);
}

static void clear(void){
	String *test=new(String);
	String_t.set(test,"hello");
	String_t.clear(test);
	stringTest(test->genericList->numElements==0);
	stringTest(test->length==0);
	stringTest(test->str==NULL);
	delete(String,test);
}

static void equalsCharArray(void){
	String *test1=new(String);
	String *test2=new(String);
	stringTest(String_t.equalsCharArray(test1,test2->str));
	stringTest(String_t.equalsCharArray(test2,test1->str));
	String_t.set(test1,"");
	String_t.set(test2,"");
	stringTest(String_t.equalsCharArray(test1,test2->str));
	stringTest(String_t.equalsCharArray(test2,test1->str));
	String_t.set(test1,"hello");
	String_t.set(test2,"hello");
	stringTest(String_t.equalsCharArray(test1,test2->str));
	stringTest(String_t.equalsCharArray(test2,test1->str));
	String_t.set(test2,"bye");
	stringTest(!String_t.equalsCharArray(test1,test2->str));
	stringTest(!String_t.equalsCharArray(test2,test1->str));
	delete(String,test1);
	delete(String,test2);
}
