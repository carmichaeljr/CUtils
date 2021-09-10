#include <string.h>
#include <stdarg.h>
#include "Object.h"

const struct BasicType_t BasicType_t={
	.class={
		.allocator=malloc,
		.constructor=NULL,
		.copyConstructor=memcpy,
		.comparator=memcmp,
		.destructor=NULL,
	},
	.set=memcpy,
};

void* createObject(void *obj, size_t size, 
		   void* (*allocator)(size_t size),
		   void (*constructor)(void *obj)){
	void *newObj=(obj==NULL)? ((allocator==NULL)? NULL: allocator(size)): obj;
	if (newObj!=NULL && constructor!=NULL){
		constructor(newObj);
	}
	return newObj;
}

void* cloneObject(void *obj, const void * const other, size_t size,
		  void* (*allocator)(size_t size),
		  void* (*copyConstructor)(void *obj, const void * const other, size_t size)){
	void *cloneObj=(obj==NULL)? ((allocator==NULL)? NULL: allocator(size)): obj;
	if (cloneObj!=NULL && copyConstructor!=NULL){
		copyConstructor(cloneObj,other,size);
	}
	return cloneObj;
}

void deleteObject(void *obj, void (*destructor)(void *obj), bool freeObj){
	if (destructor!=NULL){
		destructor(obj);
	}
	if (freeObj){
		free(obj);
	}
}
