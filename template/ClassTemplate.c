#include "%CLASS_NAME%.h"

static void constructor(void *obj);
static void* copyConstructor(void *obj, const void * const other, size_t size);
static int comparator(const void *self, const void *other, size_t size);
static void destructor(void *obj);

const struct %CLASS_NAME%_t %CLASS_NAME%_t ={
	//TODO - change class type if necessary
	.class=ALLOC_ONLY_DEFAULT_CLASS,
	//TODO - set method function pointers here
};

//Class Methods=================================================================
static void constructor(void *obj){
	//TODO - complete method
	%CLASS_NAME% *_obj=(%CLASS_NAME%*)obj;
}

static void* copyConstructor(void *obj, const void * const other, size_t size){
	//TODO - complete method
	%CLASS_NAME% *newObj=(%CLASS_NAME%*)obj;
	%CLASS_NAME% *copyObj=(%CLASS_NAME%*)other;
	return NULL;
}

static int comparator(const void *first, const void *second, size_t size){
	//TODO - complete method
	%CLASS_NAME% *self=(%CLASS_NAME%*)first;
	%CLASS_NAME% *other=(%CLASS_NAME%*)second;
	return -1;
}

static void destructor(void *obj){
	%CLASS_NAME% *_obj=(%CLASS_NAME%*)obj;
	//TODO - complete method
}

//Object Methods================================================================
//Public methods

//Private methods
