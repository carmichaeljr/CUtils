#include <ctype.h>
#include <string.h>
#include "String.h"
#include "../objectSystem/Object.h"
#include "../objectSystem/BasicType.h"
//#include "Print.h"
#include "GenericList.h"

#define strGl (&(self->genericList))

static void constructor(void *obj);
static void* copyConstructor(void *obj, const void * const other, size_t size);
//static void print(const String * const obj);
static int comparator(const void * first, const void * second, size_t size);
static void destructor(void *obj);
static bool setSize(String *self, const int len);
static bool set(String *self, const char * const newStr);
static bool setNonNullString(String *self, const char * const newStr, const int strLen);
static bool concat(String *self, const char * const newStr);
static bool concatChar(String *self, const char newChar);
static bool copyOtherBetween(String *self, const String * const other, int startIndex, int endIndex);
static void toUpper(String *self);
static void toLower(String *self);
static int contains(const String *self, const char * const token);
static int getFirstIndexOf(const String * const self, const char searchChar);
static int getLastIndexOf(const String * const self, const char searchChar);
static int getCharOccurrences(const String * const self, const char * const searchChars);
//static IntList* String_GetIndexesOf(const String *self, const char token);
static bool trimSubstring(String *self, const int startIndex, const int endIndex);
static bool trimWhitespace(String *self);
static bool removeChars(String *self, const char * const unwantedChars);
static bool clear(String *self);
static bool equalsCharArray(const String * const self, const char * const other);

const struct String_t String_t={
	.class=ALLOC_ONLY_DEFAULT_CLASS,
	.setSize=setSize,
	.set=set,
	.setNonNullString=setNonNullString,
	.concat=concat,
	.concatChar=concatChar,
	.copyOtherBetween=copyOtherBetween,
	.toUpper=toUpper,
	.toLower=toLower,
	.contains=contains,
	.getFirstIndexOf=getFirstIndexOf,
	.getLastIndexOf=getLastIndexOf,
	.getCharOccurrences=getCharOccurrences,
	//.getIndexesOf=String_GetIndexesOf,
	.trimSubstring=trimSubstring,
	.trimWhitespace=trimWhitespace,
	.removeChars=removeChars,
	.clear=clear,
	.equalsCharArray=equalsCharArray,
};

// Class Methods================================================================
static void constructor(void *obj){
	String *strObj=(String*)obj;
	new(GenericList,&strObj->genericList);
	GenericList_t.setElementType(&strObj->genericList,&char_t.class,sizeof(char));
	strObj->str=NULL;
	strObj->length=0;
}

static void* copyConstructor(void *obj, const void * const other, size_t size){
	String *newObj=(String*)obj;
	String *copyObj=(String*)other;
	new(GenericList,&(newObj->genericList));
	GenericList_t.setElementType(&newObj->genericList,&char_t.class,sizeof(char));
	String_t.copyOtherBetween(newObj,copyObj,0,copyObj->length);
	return (void*)newObj;
}

//static void print(const String * const obj){
//	Print_t.println("<String Obj[Addr: %p]: '%s'[%d chars]>",obj,obj->str,obj->length);
//}

static int comparator(const void *first, const void *second, size_t size){
	String *self=(String*)first;
	String *other=(String*)second;
	int rv=(self->str==NULL && other->str==NULL)? 0: -1;
	if (rv!=0 && self->str!=NULL && other->str!=NULL){
		return strcmp(self->str,other->str);
	} else if (rv!=0 && self->str!=NULL && other->str==NULL){
		return 1;
	} else if (rv!=0 && self->str==NULL && other->str!=NULL){
		return -1;
	}
	return rv;
}

static void destructor(void *obj){
	String *strObj=(String*)obj;
	GenericList *temp=&strObj->genericList;
	delete(GenericList,temp,false);
}

//Object Methods================================================================
//Public Methods
static bool setSize(String *self, const int len){
	if (len>0 && 
	    GenericList_t.setListSize(strGl,len+1)){
		self->str=(char*)strGl->list;
		self->length=strGl->numElements-((strGl->numElements>0)? 1: 0);
		return true;
	} else if (len==0) {
		return clear(self);
	}
	return false;
}

static bool set(String *self, const char * const newStr){
	return setNonNullString(self,newStr,(newStr!=NULL)? strlen(newStr): 0);
}

static bool setNonNullString(String *self, const char * const newStr, const int strLen){
	if (strLen>0 && newStr!=NULL && GenericList_t.setListSize(strGl,strLen+1)){
		GenericList_t.clearElements(strGl);
		GenericList_t.add(strGl,newStr,strLen);
		GenericList_t.add(strGl,"\0",1);
		self->str=(char*)strGl->list;
		self->length=strGl->numElements-1;
		return true;
	} else if (strLen==0 || newStr==NULL){
		return clear(self);
	}
	return false;
}

static bool concat(String *self, const char * const newStr){
	if (newStr!=NULL && 
	    GenericList_t.setAt(strGl,newStr,1,strGl->numElements-1) && 
	    GenericList_t.add(strGl,newStr+1,strlen(newStr))){
		self->str=(char*)strGl->list;
		self->length=strGl->numElements-1;
		return true;
	}
	return false;
}

static bool concatChar(String *self, const char newChar){
	if (self->length>0 && GenericList_t.addAt(strGl,&newChar,1,strGl->numElements-1)){
		self->str=(char*)strGl->list;
		self->length=strGl->numElements-1;
		return true;
	} else if (self->length==0 && GenericList_t.setListSize(strGl,2)){
		GenericList_t.clearElements(strGl);
		GenericList_t.add(strGl,&newChar,1);
		GenericList_t.add(strGl,"\0",1);
		self->str=(char*)strGl->list;
		self->length=strGl->numElements-1;
		return true;
	}
	return false;
}

static bool copyOtherBetween(String *self, const String * const other, const int startIndex, const int endIndex){
	const GenericList *otherTemp=&other->genericList;
	if (startIndex>=0 && startIndex<endIndex && endIndex<=other->length &&
	    GenericList_t.setListSize(strGl,endIndex-startIndex+1)){
		GenericList_t.copyOtherBetween(strGl,otherTemp,startIndex,endIndex);
		GenericList_t.add(strGl,"\0",1);
		self->str=(char*)strGl->list;
		self->length=strGl->numElements-1;
		return true;
	}
	return false;
}

static void toUpper(String *self){
	if (self->str!=NULL){
		for(int i=0; i<self->length; i++){
			self->str[i]=toupper(self->str[i]);
		}
	}
}

static void toLower(String *self){
	if (self->str!=NULL){
		for(int i=0; i<self->length; i++){
			self->str[i]=tolower(self->str[i]);
		}
	}
}

static int contains(const String *self, const char * const token){
	if (self->str!=NULL){
		const char * const index=strstr(self->str,token);
		if (index==NULL){
			return -1;
		} else {
			return index-self->str;
		}
	}
	return -1;
}

static int getFirstIndexOf(const String * const self, const char searchChar){
	return GenericList_t.getFirstIndexOf(strGl,&searchChar);
}

static int getLastIndexOf(const String * const self, const char searchChar){
	return GenericList_t.getLastIndexOf(strGl,&searchChar);
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

//static IntList* String_GetIndexesOf(const String *self, const char token){
//	IntList *rv=IntListClass.new();
//	for (int i=0; i<self->length; i++){
//		if (self->str[i]==token){
//			rv->methods->add(rv,i);
//		}
//	}
//	return rv;
//}

static bool trimSubstring(String *self, const int startIndex, const int endIndex){
	if (startIndex>=0 && startIndex<endIndex && endIndex<=self->length){
		if (startIndex==0 && endIndex==self->length){
			return String_t.clear(self);
		} else if (GenericList_t.removeBetween(strGl,startIndex,endIndex)){
			self->str=(char*)strGl->list;
			self->length=strGl->numElements-1;
			return true;
		}
	}
	return false;
}

static bool trimWhitespace(String *self){
	bool exit=false;
	if (self->str!=NULL){
		for (int i=0; i<self->length && !exit; i++){
			if (self->str[i]!=' ' && self->str[i]!='\t'){
				String_t.trimSubstring(self,0,i);
				exit=true;
			}
		}
		exit=false;
		for (int i=self->length-1; i>0 && !exit; i--){
			if (self->str[i]!=' ' && self->str[i]!='\t'){
				String_t.trimSubstring(self,i+1,self->length);
				exit=true;
			}
		}
		return true;
	}
	return false;
}

static bool removeChars(String *self, const char * const unwantedChars){
	if (GenericList_t.removeAll(strGl,unwantedChars,strlen(unwantedChars))){
		if (strGl->numElements==1 && *(char*)GenericList_t.get(strGl,0)=='\0'){
			return clear(self);
		} else {
			self->str=(char*)strGl->list;
			self->length=strGl->numElements-((strGl->numElements>0)? 1: 0);
			return true;
		}
	}
	return false;
}

//TODO - clear without realloc???
static bool clear(String *self){
	if (GenericList_t.clear(&self->genericList)){
		self->str=(char*)self->genericList.list;
		self->length=self->genericList.numElements;
		return true;
	}
	return false;
}

static bool equalsCharArray(const String * const self, const char * const other){
	bool rv=(self->str==NULL && other==NULL)? true: false;
	if (!rv && self->str!=NULL && other!=NULL && strcmp(self->str,other)==0){
		rv=true;
	}
	return rv;
}

#undef strGl
