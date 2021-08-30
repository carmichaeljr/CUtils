#include "File.h"

static void constructor(void *obj);
static void* copyConstructor(void *obj, const void * const other, size_t size);
static int comparator(const void *self, const void *other, size_t size);
static void destructor(void *obj);

const struct File_t File_t ={
	.class=ALLOC_ONLY_DEFAULT_CLASS,
	//TODO - set method function pointers here
};

//Class Methods=================================================================
static void constructor(void *obj){
	//TODO - complete method
	File *_obj=(File*)obj;
}

static void* copyConstructor(void *obj, const void * const other, size_t size){
	//TODO - complete method
	File *newObj=(File*)obj;
	File *copyObj=(File*)other;
	return NULL;
}

static int comparator(const void *first, const void *second, size_t size){
	//TODO - complete method
	File *self=(File*)first;
	File *other=(File*)second;
	return -1;
}

static void destructor(void *obj){
	File *_obj=(File*)obj;
	//TODO - complete method
}

//static void exists(const String * const path){
//
//}

//Object Methods================================================================
//Public methods

//Private methods
