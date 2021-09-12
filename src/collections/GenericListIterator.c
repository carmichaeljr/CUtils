#include <stdlib.h>
#include <string.h>
#include "GenericListIterator.h"

static void constructor(void *obj);
static int comparator(const void *first, const void *second, size_t size);
static void* begin(void *self, void *collectionObj);
static void* increment(void *self, const int num);
static void* dincrement(void *self, const int num);
static void* end(void *self, void *collectionObj);
static void* getVal(const void * const self);

const struct GenericListIterator_t GenericListIterator_t={
	.class={
		.allocator=malloc,
		.constructor=constructor,
		.copyConstructor=memcpy,
		.comparator=comparator,
		.destructor=NULL,
	},
	.iterator=DEFAULT_ITERATOR,
};

//Class Methods================================================================
static void constructor(void *obj){
	GenericListIterator *gliObj=(GenericListIterator*)obj;
	gliObj->index=0;
}

static int comparator(const void *first, const void *second, size_t size){
	GenericListIterator *self=(GenericListIterator*)first;
	GenericListIterator *other=(GenericListIterator*)second;
	if (self->index==other->index){
		return 0;
	} else if (self->index<other->index){
		return -1;
	} else {
		return 1;
	}
}

//Iterator Methods==============================================================
static void* begin(void * self, void *collectionObject){
	((GenericListIterator*)self)->source=(GenericList*)collectionObject;
	((GenericListIterator*)self)->index=0;
	return self;
}

static void* increment(void *self, const int num){
	((GenericListIterator*)self)->index+=num;
	return self;
}

static void* dincrement(void *self, const int num){
	((GenericListIterator*)self)->index-=num;
	return self;
}

static void* end(void *self, void *collectionObj){
	((GenericListIterator*)self)->source=(GenericList*)collectionObj;
	((GenericListIterator*)self)->index=((GenericList*)collectionObj)->numElements;
	return self;
}

static void* getVal(const void * const self){
	const GenericListIterator *iter=(const GenericListIterator*)self;
	return GenericList_t.get(iter->source,iter->index);
}
