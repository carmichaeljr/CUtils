#include <stdbool.h>
#include "Debug.h"
#include "../src/objectSystem/Object.h"
#include "../src/IO/File.h"
#include "../src/collections/String.h"
#include "../src/IO/Print.h"

#define fileTest(result) test(result,"File",__FUNCTION__,__LINE__)

static String *permFile=NULL;
static String *permDir=NULL;
static void exists(void);
static void isDir(void);
static void isFile(void);
static void isPipe(void);
static void getExtension(void);

void fileDebug(void){
	permFile=new(String);
	permDir=new(String);
	String_t.set(permFile,"./debug/FileDebugData/permFile.txt");
	String_t.set(permDir,"./debug/FileDebugData");
	exists();
	isDir();
	isFile();
	isPipe();
	getExtension();
	delete(String,permFile);
	delete(String,permDir);
}

static void exists(void){
	fileTest(File_t.exists(permFile));
	fileTest(File_t.exists(permDir));
}

static void isDir(void){
	fileTest(File_t.isDir(permDir));
	fileTest(!File_t.isDir(permFile));
}

static void isFile(void){
	fileTest(File_t.isFile(permFile));
	fileTest(!File_t.isFile(permDir));
}

static void isPipe(void){
	String *temp=new(String);
#if OS==WINDOWS
	String_t.set(temp,"con:");
#else
	String_t.set(temp,"/dev/stdout");
#endif
	fileTest(File_t.isPipe(temp));
	delete(String,temp);
}

static void getExtension(void){
	String *ext=File_t.getExtension(permFile,NULL);
	Print_t.println("%s",ext->str);
	fileTest(String_t.equalsCharArray(ext,"txt"));
	delete(String,ext);
	ext=File_t.getExtension(permDir,NULL);
	Print_t.println("%s",ext->str);
	fileTest(String_t.equalsCharArray(ext,""));
	fileTest(ext->length==0);
	delete(String,ext);
}
