#include <ctype.h>
#include <string.h>
#include "String.h"
#include "Object.h"
#include "Print.h"
#include "GenericList.h"

static String* constructor(void);
static void print(const String * const obj);
//static bool _StringDebug(void);
//static bool _StringDebugAdd(void);
//static bool _StringDebugSet(void);
//static bool _StringDebugRemove(void);
//static bool _StringDebugSearch(void);
//static bool _StringDebugMisc(void);
static void destructor(String **obj);
static void String_ToUpperCase(String *self);
static void String_ToLowerCase(String *self);
static void String_TrimWhitespace(String *self);
static bool String_Equals(const String *self, const char *other);
static bool String_Contains(const String *self, const char *token);
static void String_ConvertFromGenericListToStr(String *self);
//static IntList* String_GetIndexesOf(const String *self, const char token);
static void String_RemoveChars(String *self, const char *unwantedChars);
static void String_TrimSubstring(String *self, const int startIndex, const int endIndex);
//Public
static void setSize(String *self, const int len);
static void set(String *self, const char * const newStr);
static void concat(String *self, const char * const newStr);
static void concatChar(String *self, const char newChar);
static void copyOtherBetween(String *self, const String * const other, int startIndex, int endIndex);
static int getFirstIndexOf(const String * const self, const char searchChar);
static int getLastIndexOf(const String * const self, const char searchChar);
static int getCharOccurrences(const String * const self, const char * const searchChars);
static void clear(String *self);
//Private
static void String_SetLength(String *self);

const struct String_t String_t={
	.new=constructor,
	.delete=destructor,
	.print=print,
	.setSize=setSize,
	.set=set,
	.concat=concat,
	.concatChar=concatChar,
	.copyOtherBetween=copyOtherBetween,
	.getFirstIndexOf=getFirstIndexOf,
	.getLastIndexOf=getLastIndexOf,
	.getCharOccurrences=getCharOccurrences,
	.clear=clear,

	//occurrences 
	.equals=String_Equals,
	.removeChars=String_RemoveChars,
	.trimSubString=String_TrimSubstring,
	.trimWhitespace=String_TrimWhitespace,
	.toUpperCase=String_ToUpperCase,
	.toLowerCase=String_ToLowerCase,
	.contains=String_Contains,
	//.getIndexesOf=String_GetIndexesOf,
};

//Object Methods================================================================
//Public Methods
static void setSize(String *self, const int len){
	GenericList *temp=self->genericList;
	if (len>0){
		GenericList_t.setListSize(self->genericList,len+1);
		GenericList_t.setAt(temp,"\0",1,temp->numElements-1);
		self->str=(char*)temp->list;
		self->length=temp->numElements-1;
	} else if (len==0) {
		clear(self);
	}
}

static void set(String *self, const char * const newStr){
	int lenNewStr=strlen(newStr);
	GenericList *temp=self->genericList;
	if (lenNewStr>0){
		GenericList_t.set(temp,newStr,lenNewStr+1);
		self->str=(char*)temp->list;
		self->length=temp->numElements-1;
	} else if (lenNewStr==0){
		clear(self);
	}
}

static void concat(String *self, const char * const newStr){
	GenericList *temp=self->genericList;
	if (newStr!=NULL){
		GenericList_t.setAt(temp,newStr,1,temp->numElements-1);
		GenericList_t.add(temp,newStr+1,strlen(newStr));
		self->str=(char*)temp->list;
		self->length=temp->numElements-1;
	}
}

static void concatChar(String *self, const char newChar){
	GenericList *temp=self->genericList;
	if (self->length!=0){
		GenericList_t.addAt(temp,&newChar,1,temp->numElements-1);
	} else {
		GenericList_t.setListSize(temp,2);
		GenericList_t.setAt(temp,&newChar,1,0);
		GenericList_t.setAt(temp,"\0",1,1);
	}
	self->str=(char*)temp->list;
	self->length=temp->numElements-1;
}

static void copyOtherBetween(String *self, const String * const other, const int startIndex, const int endIndex){
	GenericList *selfTemp=self->genericList;
	GenericList *otherTemp=other->genericList;
	GenericList_t.copyOtherBetween(selfTemp,otherTemp,startIndex,endIndex);
	if (selfTemp->numElements>0 && *(char*)GenericList_t.get(selfTemp,selfTemp->numElements-1)!='\0'){
		GenericList_t.add(selfTemp,"\0",1);
	}
	self->str=(char*)selfTemp->list;
	self->length=selfTemp->numElements-1;
}

static int getFirstIndexOf(const String * const self, const char searchChar){
	GenericList *temp=self->genericList;
	return GenericList_t.getFirstIndexOf(temp,&searchChar);
}

static int getLastIndexOf(const String * const self, const char searchChar){
	GenericList *temp=self->genericList;
	return GenericList_t.getLastIndexOf(temp,&searchChar);
}

static int getCharOccurrences(const String * const self, const char * const searchChars){
	int rv=0;
	for (int i=0; i<self->length; i++){
		if (strchr(searchChars,self->str[i])!=NULL){
			rv++;
		}
	}
	return rv;
}

static void clear(String *self){
	GenericList_t.clear(self->genericList);
	self->str=(char*)self->genericList->list;
	self->length=self->genericList->numElements;
}

static void String_RemoveChars(String *self, const char *unwantedChars){
	GenericList *temp=self->genericList;
	for (int i=0; i<strlen(unwantedChars); i++){
		GenericList_t.remove(temp,&unwantedChars[i]);
	}
	String_ConvertFromGenericListToStr(self);
}

static void String_TrimSubstring(String *self, const int startIndex, const int endIndex){
	GenericList *temp=self->genericList;
	GenericList_t.removeBetween(temp,startIndex,endIndex);
	String_ConvertFromGenericListToStr(self);
}

static void String_TrimWhitespace(String *self){
	bool exit=false;
	if (self->str!=NULL){
		for (int i=0; i<self->length && !exit; i++){
			if (self->str[i]!=' ' && self->str[i]!='\t'){
				String_t.trimSubString(self,0,i);
				exit=true;
			}
		}
		exit=false;
		for (int i=self->length-1; i>0 && !exit; i--){
			if (self->str[i]!=' ' && self->str[i]!='\t'){
				String_t.trimSubString(self,i+1,self->length);
				exit=true;
			}
		}
	}
}

static void String_ToUpperCase(String *self){
	if (self->str!=NULL){
		for(int i=0; i<self->length; i++){
			self->str[i]=toupper(self->str[i]);
		}
	}
}

static void String_ToLowerCase(String *self){
	if (self->str!=NULL){
		for(int i=0; i<self->length; i++){
			self->str[i]=tolower(self->str[i]);
		}
	}
}

//static IntList* String_GetIndexesOf(const String *self, const char token){
//	IntList *rv=IntListClass.new();
//	for (int i=0; i<self->length; i++){
//		if (self->str[i]==token){
//			rv->methods->add(rv,i);
//		}
//	}
//	return rv;
//}

static bool String_Contains(const String *self, const char *token){
	return (strstr(self->str,token)!=NULL)? true: false;
}

static bool String_Equals(const String *self, const char *other){
	bool rv=(self->str==NULL && other==NULL)? true: false;
	if (!rv && self->str!=NULL && other!=NULL && strcmp(self->str,other)==0){
		rv=true;
	}
	return rv;
}

//Private Methods
static void String_ConvertFromGenericListToStr(String *self){
	char *nullTerminator="\0";
	GenericList *temp=self->genericList;
	bool strExists=(temp->numElements>0)? true: false;
	bool hasNullTerm=(GenericList_t.getLastIndexOf(temp,nullTerminator)==temp->numElements-1)? true: false;
	if (strExists){
		if (!hasNullTerm){
			GenericList_t.add(temp,nullTerminator,1);
		}
		self->str=(char*)temp->list;
		String_SetLength(self);
	} else {
		self->str=NULL;
		self->length=0;
	}
}

static void String_SetLength(String *self){
	self->length=strlen(self->str);
}

// Class Methods================================================================
static String* constructor(void){
	String *rv=(String*)createObject(sizeof(String));
	rv->genericList=GenericList_t.new();
	GenericList_t.setElementSize(rv->genericList,sizeof(char));
	rv->str=NULL;
	rv->length=0;
	return rv;
}

static void print(const String * const obj){
	Print_t.println("<String Obj[Addr: %p]: '%s'[%d chars]>",obj,obj->str,obj->length);
}

static void destructor(String **obj){
	GenericList_t.delete(&(*obj)->genericList);
	deleteObject((void**)obj);
}
