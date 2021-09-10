#include <unistd.h>
#include <sys/stat.h>
#include "File.h"

#include "../IO/Print.h"

static void constructor(void *obj);
static void* copyConstructor(void *obj, const void * const other, size_t size);
static int comparator(const void *self, const void *other, size_t size);
static void destructor(void *obj);
static bool exists(const String * const path);
static bool isDir(const String * const path);
static bool isFile(const String * const path);
static bool isPipe(const String * const path);
static String* getExtension(const String * const path, String *buff);

const struct File_t File_t ={
	.pathSeparator=
#if OS==WINDOWS
		'\\',
#else
		'/',
#endif
	.class=ALLOC_ONLY_DEFAULT_CLASS,
	.exists=exists,
	.isDir=isDir,
	.isFile=isFile,
	.isPipe=isPipe,
	.getExtension=getExtension,
};

//Class Methods=================================================================
static void constructor(void *obj){
	//File *_obj=(File*)obj;
}

static void* copyConstructor(void *obj, const void * const other, size_t size){
	//File *newObj=(File*)obj;
	//File *copyObj=(File*)other;
	return NULL;
}

static int comparator(const void *first, const void *second, size_t size){
	//File *self=(File*)first;
	//File *other=(File*)second;
	return -1;
}

static void destructor(void *obj){
	//File *_obj=(File*)obj;
}

static bool exists(const String * const path){
	if (access(path->str,F_OK)!=-1){
		return true;
	}
	return false;
}

static bool isDir(const String * const path){
	struct stat statBuf;
	return (
		stat(path->str,&statBuf)==0 &&
		S_ISDIR(statBuf.st_mode)!=0 &&
		S_ISREG(statBuf.st_mode)==0
		);
}

static bool isFile(const String * const path){
	struct stat statBuf;
	return (
		stat(path->str,&statBuf)==0 &&
		S_ISREG(statBuf.st_mode)!=0 &&
		S_ISDIR(statBuf.st_mode)==0
		);
}

static bool isPipe(const String * const path){
	struct stat statBuf;
	return (
		stat(path->str,&statBuf)==0 &&
		S_ISFIFO(statBuf.st_mode)==0
		);
}

//String *path=new(String);
//String *chars=new(String);
//GenericList *indexes=new(GenericList);
//forEach(String,chars,GenericList_t.add(indexes,String_t.getLastIndexOf(path,val));
static String* getExtension(const String * const path, String *buff){
	String *rv=(buff==NULL)? new(String): buff;
	int lastIndexDot=String_t.getLastIndexOf(path,'.')+1;
	//int lastIndexPathSep=
	//if (lastIndex>0 && lastIndex<path->length && path->str[lastIndex-1]!='.' &&
	//		path->str[lastIndex+1]!='/' && path->str[lastIndex+1]!='\\'){

	//}
	String_t.copyOtherBetween(rv,path,String_t.getLastIndexOf(path,'.')+1,path->length);
	return rv;
}

//Object Methods================================================================
//Public methods

//Private methods
