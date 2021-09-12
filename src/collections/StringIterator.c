#include <stdlib.h>
#include <string.h>
#include "StringIterator.h"

static void constructor(void *obj);
static int comparator(const void *first, const void *second, size_t size);

const struct StringIterator_t StringIterator_t={
	.class={
		.allocator=malloc,
		.constructor=constructor,
		.copyConstructor=memcpy,
		.comparator=comparator,
		.destructor=NULL,
	},
};

//Class Methods================================================================
static void constructor(void *obj){
	StringIterator *strIterObj=(StringIterator*)obj;
	strIterObj->index=0;
}

static int comparator(const void *first, const void *second, size_t size){
	StringIterator *self=(StringIterator*)first;
	StringIterator *other=(StringIterator*)second;
	if (self->index==other->index){
		return 0;
	} else if (self->index<other->index){
		return -1;
	} else {
		return 1;
	}
}
