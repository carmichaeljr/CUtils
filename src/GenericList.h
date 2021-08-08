#ifndef GENERICLIST_CLASS
#define GENERICLIST_CLASS

#include <stdlib.h>
#include <stdbool.h>

typedef struct GenericListObj GenericList;

struct GenericListClass {
	GenericList* (*new)(void);
	void (*delete)(GenericList **obj);
	void (*print)(const GenericList * const obj);
	void (*setElementSize)(GenericList *self, const size_t newSize);
	void (*setListSize)(GenericList *self, const int numElements);
	void (*set)(GenericList *self, const void * const newElements, const int numElements);
	void (*setAt)(GenericList *self, const void * const newElements, const int numElements, const int index);
	void (*add)(GenericList *self, const void * const newElement, const int numElements);
	void (*addAt)(GenericList *self, const void * const newElement, const int numElements, const int index);
	void (*copyOtherBetween)(GenericList *self, const GenericList * const other, const int startIndex, const int endIndex);
	void* (*get)(const GenericList * const self, const int index);
	bool (*contains)(const GenericList * const self, const void * const token);
	int (*getFirstIndexOf)(const GenericList * const self, const void * const token);
	int (*getLastIndexOf)(const GenericList * const self, const void * const token);
	void (*remove)(GenericList *self, const void * const token);
	void (*removeAt)(GenericList *self, const int index);
	void (*removeBetween)(GenericList *self, const int startIndex, const int endIndex);
	void (*trimToSize)(GenericList *self, const int numElements);
	void (*clear)(GenericList *self);
	bool (*isEmpty)(const GenericList * const self);
	bool (*equals)(const GenericList * const self, const GenericList * const other);
};

struct GenericListObj {
	void *list;
	int numElements;
	size_t elementSize;
};

extern const struct GenericListClass GenericList_t;

#endif
