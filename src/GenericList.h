#ifndef GENERICLIST_CLASS
#define GENERICLIST_CLASS

#include <stdlib.h>
#include <stdbool.h>

//Class: GenericList
//The struct that represents a GenericList.
typedef struct GenericListObj {
	//Variable: list
	void *list;
	//Variable: numElements
	int numElements;
	//Variable: elementSize
	//Holds the element size so that pointer arithmetic can be performed with the void pointer.
	size_t elementSize;
} GenericList;

//Class: GenericList_t
//The struct that creates and perform operations on objects of type GenericList.
//This class is for storing continuous data in an array. This is perfect for standard
//data types and other small data types.
//General usage is as follows:
//--- Code
//GenericList *list=GenericList_t.new();
//GenericList_t.<func to call>(list, <params>);
//...
//GenericList_t.delete(&list);
//---
extern const struct GenericList_t {
	//Constructor: new
	//Creates and initializes a GenericList object.
	GenericList* (*new)(void);
	//Destructor: delete
	//Deletes a GenericList object.
	void (*delete)(GenericList **obj);
	//Function: print
	//Prints the contents of a GenericList object.
	void (*print)(const GenericList * const obj);
	//Function: setElementSize
	//Sets the size of the elements stored in the list.
	//
	//If element size is 0 then the generic list object will be considered uninitialized, and no other
	//functions will perform any action.
	//
	//When setting the element size, if the new element size is different from the current element size
	//then the list will be cleared.
	void (*setElementSize)(GenericList *self, const size_t newSize);
	//Function: setListSize
	//Useful for reducing the number of memory reallocations if you know the final size of the list.
	void (*setListSize)(GenericList *self, const int numElements);
	//Function: set
	//Sets the list with the given data, clearing any data that was previously held in the list.
	void (*set)(GenericList *self, const void * const newElements, const int numElements);
	//Function: setAt
	//Sets the selected elements in the list, up to the end of the list.
	//
	//No reallocation is performed, with the one exception of when this list is empty.
	//If the list is empty then set is called.
	void (*setAt)(GenericList *self, const void * const newElements, const int numElements, const int index);
	//Function: add
	//Appends the given elements to the list
	void (*add)(GenericList *self, const void * const newElement, const int numElements);
	//Function: addAt
	//Inserts the given elements into the list
	//
	//If the list is empty or index is equal to the length of the list, then add is called.
	void (*addAt)(GenericList *self, const void * const newElement, const int numElements, const int index);
	//Function: copyOtherBetween
	//Copies the selected data from another GenericList.
	//
	//If startIndex is less than 0 then it is bounded to 0.
	//If endIndex is greater than the number of elements in the list being copied
	//then it is bounded to the length of the list being copied.
	void (*copyOtherBetween)(GenericList *self, const GenericList * const other, const int startIndex, const int endIndex);
	//Function: get
	//Gets the selected element from the list
	//
	//If uninitialized, empty, or the index is out of bounds, then get will return NULL.
	void* (*get)(const GenericList * const self, const int index);
	//Function: contains
	//Returns true/false depending on if the given token is in the list. Searching will stop
	//once the first instance is found.
	bool (*contains)(const GenericList * const self, const void * const token);
	//Function: getFirstIndexOf
	//Returns the first index of where token is in the list. If not present in the list, it returns -1.
	//
	//Searching starts at index 0 and stops when the first instance is found.
	int (*getFirstIndexOf)(const GenericList * const self, const void * const token);
	//Function: getLastIndexOf
	//Returns the last index of where token is in the list. If not present in the list, it returns -1.
	//
	//Searching starts at the end of the list and stops when the first instance is found.
	int (*getLastIndexOf)(const GenericList * const self, const void * const token);
	//Function: remove
	//Removes all instances of the supplied token from the list.
	//
	//Only one memory reallocation is performed.
	void (*remove)(GenericList *self, const void * const token);
	//Function: removeAt
	//Removes the item at the supplied index from the list.
	void (*removeAt)(GenericList *self, const int index);
	//Function: removeBetween
	//Removes the items between the supplied indexes.
	//
	//No action will occur if start index is less than 0,
	//the start index is greater than the end index,
	//or the end index is greater than the end of the list.
	//
	//Only one memory reallocation is performed.
	void (*removeBetween)(GenericList *self, const int startIndex, const int endIndex);
	//Function: trimToSize
	//Removes elements from the end of the list until the list size equals numElements.
	//
	//If numElements is greater than the lists size then no action occurs.
	//
	//If numElements is 0 the list is cleared.
	void (*trimToSize)(GenericList *self, const int numElements);
	//Function: clear
	//Removes all elements from the list.
	void (*clear)(GenericList *self);
	//Function: isEmpty
	//Returns true or false depending on weather the list is empty or not.
	bool (*isEmpty)(const GenericList * const self);
	//Function: equals
	//Returns true/false depending if the two lists are equal.
	//
	//Equality is determined by comparing length, and the memory contents of each list.
	bool (*equals)(const GenericList * const self, const GenericList * const other);
} GenericList_t;

#endif
