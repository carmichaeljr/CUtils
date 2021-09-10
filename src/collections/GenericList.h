#ifndef GENERICLIST_CLASS
#define GENERICLIST_CLASS

#include <stdlib.h>
#include <stdbool.h>
#include "../objectSystem/Object.h"
#include "../objectSystem/Iterator.h"

//Class: GenericList
//The struct that represents a GenericList.
//
//This class is for storing continuous data in an array. This is perfect for standard
//data types and other small data types.
//
//The memory allocated by the object follows the below rules, in the below order, unless strictAlloc is true.
//
//  Rule 1 - If reserved memory is > newLen*2 and newLen>0 reallocate (shrink to actual size)
//  Rule 2 - If reserved memory is < newLen, reallocate (grow to actual size)
//  Rule 3 - If newLen is 0, free memory
//  Rule 4 - If reserved memory is >= newLen, don't reallocate
//
//General usage is as follows:
//--- Code
//GenericList *list=new(GenericList);
//GenericList_t.<func to call>(list, <params>);
//...
//delete(GenericList,list);
//---
//
//See Also:
//
//  <GenericList_t>
//  <GenericListIterator>
//  <GenericListIterator_t>
typedef struct GenericList {
	//Variable: list
	//
	// - Default: NULL
	void *list;
	//Variable: listSize
	//Holds the actual size of the internal list.
	//
	// - Default: 0
	int listSize;
	//Variable: strictAlloc
	//Determines how memory is allocated.
	//
	// - Default: false
	bool strictAlloc;
	//Variable: numElements
	//Holds how many elements are in the list, may or may not the same as the internal lists actual size.
	//
	// - Default: 0
	int numElements;
	//Variable: elementSize
	//Holds the element size so that pointer arithmetic can be performed with the void pointer.
	//
	// - Default: 0
	size_t elementSize;
        //Variable: elementClass
        //A pointer to the element class so that elements will be created and destroyed properly.
        //
        // - Default: NULL
        //
        //See Also:
        //
        //  <Class>
	const Class *elementClass;
} GenericList;

//Class: GenericList_t
//The struct that creates and performs operations on objects of type GenericList.
//
//See Also:
//
//  <GenericList>
//  <GenericListIterator>
//  <GenericListIterator_t>
extern const struct GenericList_t {
	Class class;
	Iterator iterator;
	//Function: setElementType
	//Sets the size and type of the elements stored in the list.
	//
	//If element size is 0 or element class is NULL then the generic list object 
        //will be considered uninitialized, and no other functions will perform any action.
	//
	//When setting the element size, if the new element size is different from the current element size
	//then <GenericList_t.clear> will be called.
	//
	//Parameters:
	//
	//  self - The generic list to perform the operation on.
	//  newSize - The size each element will be in the list.
	//
	//Returns:
	//
	//  Returns true if the operation was successful.
	//  A return value of false indicates no operation occurred, or an error occurred during the operation.
	bool (*setElementType)(GenericList *self, const Class * const newClass, const size_t newSize);
	//Function: setListSize
	//Useful for reducing the number of memory reallocations if you know the final size of the list.
	//Contents of the list will not be changed unless the new size is less than the current size.
	//numElements will not be updated, and future calls should assume that the list is 'empty' or
	//contains what was previously held in the array.
        //The elements constructors will not be called to initialize each object,
	//this is purely just to set the size of the underlying array.
	//
	//Parameters:
	//
	//  self - The generic list to perform the operation on.
	//  numElements - The number of elements to allocate space for, using elementSize to calculate the total size.
	//
	//Returns:
	//
	//  Returns true if the operation was successful and changes were made to the object.
        //
	//  Returns true if the operation was successful.
	//  A return value of false indicates no operation occurred, or an error occurred during the operation.
	bool (*setListSize)(GenericList *self, const int numElements);
        //Function: setNumElements
        //Sets the size of the list and calls the elements constructors defined by <GenericList.elementClass>
        //to initialize each object that is created (if any).
        //If the given number of elements is less than the current number of elements,
        //<GenericList_t.removeBetween> will be called to remove the appropriate number of
        //elements from the end of the list.
        //
        //Paremeters:
        //
        //  self - The generic list to perform the operation on.
        //  numElements - The number of elements to have in the list.
        //
        //Returns:
        //
	//  Returns true if the operation was successful.
	//  A return value of false indicates no operation occurred, or an error occurred during the operation.
        bool (*setNumElements)(GenericList *self, const int numElements);
	//Function: set
	//Sets the list with the given data, clearing any data that was previously held in the list.
	//
	//Parameters:
	//
	//  self - The generic list to perform the operation on.
	//  newElements - The elements to copy to the generic list.
	//  numElements - The number of elements in the newElements list to copy.
	//
	//Returns:
	//
	//  Returns true if the operation was successful.
	//  A return value of false indicates no operation occurred, or an error occurred during the operation.
	bool (*set)(GenericList *self, const void * const newElements, const int numElements);
	//Function: setAt
	//Sets the selected elements in the list, up to the end of the list.
	//
	//No reallocation is performed, with the one exception of when this list is empty.
	//If the list is empty then set is called.
	//
	//Parameters:
	//
	//  self - The generic list to perform the operation on.
	//  newElements - The elements to copy to the generic list.
	//  numElements - The number of elements in the newElements list to copy.
	//  index - The index to start setting the elements at.
	//
	//Returns:
	//
	//  Returns true if the operation was successful.
	//  A return value of false indicates no operation occurred, or an error occurred during the operation.
	bool (*setAt)(GenericList *self, const void * const newElements, const int numElements, const int index);
	//Function: add
	//Appends the given elements to the list
	//
	//Parameters:
	//
	//  self - The generic list to perform the operation on.
	//  newElements - The elements to add to the generic list.
	//  numElements - The number of elements in the newElements list to copy.
	//
	//Returns:
	//
	//  Returns true if the operation was successful.
	//  A return value of false indicates no operation occurred, or an error occurred during the operation.
	bool (*add)(GenericList *self, const void * const newElements, const int numElements);
	//Function: addAt
	//Inserts the given elements into the list
	//
	//If the list is empty or index is equal to the length of the list, then add is called.
	//
	//Parameters:
	//
	//  self - The generic list to perform the operation on.
	//  newElements - The elements to add to the generic list.
	//  numElements - The number of elements in the newElements list to copy.
	//  index - The index to insert the new elements at.
	//
	//Returns:
	//
	//  Returns true if the operation was successful.
	//  A return value of false indicates no operation occurred, or an error occurred during the operation.
	bool (*addAt)(GenericList *self, const void * const newElement, const int numElements, const int index);
	//Function: copyOtherBetween
	//Copies the selected data from another GenericList. If elements are already in the
        //list then <GenericList_t.clear> is called.
	//
	//If startIndex is less than 0, endIndex is greater than the number of elements in the list being copied,
	//or startIndex>endIndex, no operation occurs.
	//
	//Parameters:
	//
	//  self - The generic list to perform the operation on.
	//  other - The generic list to copy elements from.
	//  startIndex - The index to start copying elements from other at (inclusive).
	//  endIndex - The index to end copying elements from other at (exclusive).
	//
	//Returns:
	//
	//  Returns true if the operation was successful.
	//  A return value of false indicates no operation occurred, or an error occurred during the operation.
	bool (*copyOtherBetween)(GenericList *self, const GenericList * const other, const int startIndex, const int endIndex);
	//Function: get
	//Gets the selected element from the list.
	//
	//Parameters:
	//
	//  self - The generic list to perform the operation on.
	//  index - The index to retrieve the element at.
	//
	//Returns:
	//
	//  If uninitialized, empty, or the index is out of bounds, then get will return NULL,
	//  otherwise will return a pointer to the element in the list.
	void* (*get)(const GenericList * const self, const int index);
	//Function: contains
	//Returns true/false depending on if the given token is in the list. Searching will stop
	//once the first instance is found.
	//
	//Parameters:
	//
	//  self - The generic list to perform the operation on.
	//  token - The token to search the list for.
	//
	//Returns:
	//
	//  True if token is found in the list, otherwise false.
	bool (*contains)(const GenericList * const self, const void * const token);
	//Function: getFirstIndexOf
	//Returns the first index of where token is in the list. If not present in the list, it returns -1.
	//
	//Searching starts at index 0 and stops when the first instance is found.
	//
	//Parameters:
	//
	//  self - The generic list to perform the operation on.
	//  token - The token to search the list for.
	//
	//Returns:
	//
	//  The first index where token is found in the list, or -1 if it is not found.
	int (*getFirstIndexOf)(const GenericList * const self, const void * const token);
	//Function: getLastIndexOf
	//Returns the last index of where token is in the list. If not present in the list, it returns -1.
	//
	//Searching starts at the end of the list and stops when the last instance is found.
	//
	//Parameters:
	//
	//  self - The generic list to perform the operation on.
	//  token - The token to search the list for.
	//
	//Returns:
	//
	//  The last index where token is found in the list, or -1 if it is not found.
	int (*getLastIndexOf)(const GenericList * const self, const void * const token);
	//Function: remove
	//Removes all instances of the supplied token from the list. The destructor in the
        //<GenericList.elementClass> struct will be called for each element that is deleted.
	//
	//Only one memory reallocation is performed.
	//
	//Parameters:
	//
	//  self - The generic list to perform the operation on.
	//  token - The token to remove from the list.
	//
	//Returns:
	//
	//  Returns true if the operation was successful.
	//  A return value of false indicates no operation occurred, or an error occurred during the operation.
	bool (*remove)(GenericList *self, const void * const token);
	//Function: removeAll
	//Removes all instances of the supplied tokens from the list. The destructor in the
        //<GenericList.elementClass> struct will be called for each element that is deleted.
	//
	//Only one memory reallocation is performed.
	//
	//Parameters:
	//
	//  self - The generic list to perform the operation on.
	//  tokens - The tokens to remove from the list.
	//  numTokens - The number of tokens in the tokens list.
	//
	//Returns:
	//
	//  Returns true if the operation was successful.
	//  A return value of false indicates no operation occurred, or an error occurred during the operation.
	bool (*removeAll)(GenericList *self, const void *const tokens, const int numTokens);
	//Function: removeAt
	//Removes the item at the supplied index from the list. The destructor in the
        //<GenericList.elementClass> struct will be called for each element that is deleted.
	//
	//Parameters:
	//
	//  self - The generic list to perform the operation on.
	//  index - The index to remove.
	//
	//Returns:
	//
	//  Returns true if the operation was successful.
	//  A return value of false indicates no operation occurred, or an error occurred during the operation.
	bool (*removeAt)(GenericList *self, const int index);
	//Function: removeBetween
	//Removes the items between the supplied indexes. The destructor in the
        //<GenericList.elementClass> struct will be called for each element that is deleted.
	//
	//No action will occur if start index is less than 0,
	//the start index is greater than the end index,
	//or the end index is greater than the end of the list.
	//
	//Only one memory reallocation is performed.
	//
	//Parameters:
	//
	//  self - The generic list to perform the operation on.
	//  startIndex - The index to start removing elements at (inclusive).
	//  endIndex - The index to stop removing elements at (exclusive).
	//
	//Returns:
	//
	//  Returns true if the operation was successful.
	//  A return value of false indicates no operation occurred, or an error occurred during the operation.
	bool (*removeBetween)(GenericList *self, const int startIndex, const int endIndex);
	//Function: trimToSize
	//Reallocates the internal memory so that numElements==listSize.
	//
	//Parameters:
	//
	//  self - The generic list to perform the operation on.
	//
	//Returns:
	//
	//  Returns true if the operation was successful.
	//  A return value of false indicates no operation occurred, or an error occurred during the operation.
	bool (*trimToSize)(GenericList *self);
	//Function: clear
	//Removes all elements from the list and frees the underlying memory. The destructor in the
        //<GenericList.elementClass> struct will be called for each element that is deleted.
	//
	//Parameters:
	//
	//  self - The generic list to perform the operation on.
	//
	//Returns:
	//
	//  Returns true if the operation was successful.
	//  A return value of false indicates no operation occurred, or an error occurred during the operation.
	bool (*clear)(GenericList *self);
	//Function: clearElements
	//Removes all elements from the list but does not free the underlying memory.
        //The destructor in the <GenericList.elementClass> struct will be called for
        //each element that is deleted.
	//This does not create a memory leak because the actual list size is
	//tracked by <GenericList.listSize>.
	//
	//This is useful for avoiding the memory reallocation associated with <GenericList_t.clear>.
	//
	//Parameters:
	//
	//  self - The generic list to perform the operation on.
	//
	//Returns:
	//
	//  Returns true if the operation was successful.
	//  A return value of false indicates no operation occurred, or an error occurred during the operation.
	bool (*clearElements)(GenericList *self);
	//Function: isEmpty
	//Returns true or false depending on weather the list is empty or not.
	//
	//Parameters:
	//
	//  self - The generic list to perform the operation on.
	//
	// Returns:
	//
	//   true if the list is empty, false if not.
	bool (*isEmpty)(const GenericList * const self);
} GenericList_t;

#endif
