#include <string.h>
#include "Object.h"

void* createObject(void *obj, size_t size, 
		   void* (*allocator)(size_t size),
		   void (*constructor)(void *obj)){
	void *newObj=(obj==NULL)? allocator(size): obj;
	if (newObj!=NULL){
		constructor(newObj);
	}
	return newObj;
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

void deleteObject(void **obj, void (*destructor)(void *obj), bool freeObj){
	destructor(*obj);
	if (freeObj){
		free(*obj);
		*obj=NULL;
	}
}
