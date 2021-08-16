#include <stdlib.h>
#include <string.h>
#include "Object.h"

void* createObject(size_t size, void* (*allocator)(size_t size), void (*constructor)(void *obj)){
	void *obj=allocator(size);
	if (obj!=NULL){
		constructor(obj);
	}
	return obj;
}

void* cloneObject(const void * const other, size_t size,
		  void* (*allocator)(size_t size),
		  void* (*copyConstructor)(void *obj, const void * const other, size_t size)){
	void *cloneObj=allocator(size);
	if (cloneObj!=NULL){
		copyConstructor(cloneObj,other,size);
	}
	return cloneObj;
}

void deleteObject(void **obj, void (*destructor)(void *obj)){
	destructor(*obj);
	free(*obj);
	*obj=NULL;
}
