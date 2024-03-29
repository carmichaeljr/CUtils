#ifndef GENERIC_LIST_ITERATOR_CLASS
#define GENERIC_LIST_ITERATOR_CLASS

#include "../objectSystem/Object.h"
#include "../objectSystem/Iterator.h"
#include "GenericList.h"

//Class: GenericListIterator
//A struct that represents an iterator for a generic list.
//
//General usage is as follows:
//--- Code
//GenericList *list=new(GenericList);
//...
//GenericListIterator *iter=new(GenericListIterator);
//GenericListIterator *end=new(GenericListIterator);
//iterEnd(GenericList,end,list);
//for (iterBegin(GenericList,iter,list); equals(GenericListIterator,iter,end)>0; iterNext(GenericList,iter)){
//	void* iterVal=iterVal(GenericList,iter);
//	...
//}
//delete(GenericListIterator,iter);
//delete(GenericListIterator,end);
//...
//delete(GenericList,list);
//---
//
//See Also:
//
//  <GenericList>
//  <GenericList_t>
//  <GenericListIterator_t>
typedef struct GenericListIterator {
	//Variable: index
	//
	// - Default: 0
	int index;
	GenericList *source;
} GenericListIterator;

//Class: GenericListIterator_t
//The struct that creates and performs operations on objects of type GenericListIterator.
//
//See Also:
//
//  <GenericList>
//  <GenericListIterator>
extern const struct GenericListIterator_t {
	Class class;
	Iterator iterator;
} GenericListIterator_t;

#endif
