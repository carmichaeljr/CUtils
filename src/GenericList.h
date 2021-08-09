#ifndef GENERICLIST_CLASS
#define GENERICLIST_CLASS

#include <stdlib.h>
#include <stdbool.h>

//Class: GenericList
//The struct that represents a GenericList.
//
//This class is for storing continuous data in an array. This is perfect for standard
//data types and other small data types.
//General usage is as follows:
//--- Code
//GenericList *list=GenericList_t.new();
//GenericList_t.<func to call>(list, <params>);
//...
//GenericList_t.delete(&list);
//---
//
//See Also:
//
//  <GenericList_t>
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
//The struct that creates and performs operations on objects of type GenericList.
//
//See Also:
//
//  <GenericList>
extern const struct GenericList_t {
	//Constructor: new
	//Creates and initializes a GenericList object.
	//
	//Parameters:
	//
	//  None
	//
	//Returns:
	//
	//  A pointer to a generic list object.
	GenericList* (*new)(void);
	//Destructor: delete
	//Deletes a GenericList object and sets its pointer to NULL.
	//
	//Parameters:
	//
	//  obj - The object to delete.
	//
	//Returns:
	//
	//  Nothing
	void (*delete)(GenericList **obj);
	//Function: print
	//Prints the contents of a GenericList object.
	//
	//Parameters:
	//
	//  obj - The generic list to print.
	//
	//Returns:
	//
	//  Nothing
	void (*print)(const GenericList * const obj);
	//Function: setElementSize
	//Sets the size of the elements stored in the list.
	//
	//If element size is 0 then the generic list object will be considered uninitialized, and no other
	//functions will perform any action.
	//
	//When setting the element size, if the new element size is different from the current element size
	//then the list will be cleared.
	//
	//Parameters:
	//
	//  self - The generic list to perform the operation on.
	//  newSize - The size each element will be in the list.
	//
	//Returns:
	//
	//Nothing
	void (*setElementSize)(GenericList *self, const size_t newSize);
	//Function: setListSize
	//Useful for reducing the number of memory reallocations if you know the final size of the list.
	//
	//Parameters:
	//
	//  self - The generic list to perform the operation on.
	//  numElements - The number of elements to allocate space for, using elementSize to calculate the total size.
	//
	//Returns:
	//
	//  Returns true if the operation was successful and changes were made to the object.
	//  A return value of false guarantees no changes were made to the object.
	bool (*setListSize)(GenericList *self, const int numElements);
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
	//  Returns true if the operation was successful and changes were made to the object.
	//  A return value of false guarantees no changes were made to the object.
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
	//  Returns true if the operation was successful and changes were made to the object.
	//  A return value of false guarantees no changes were made to the object.
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
	//  Returns true if the operation was successful and changes were made to the object.
	//  A return value of false guarantees no changes were made to the object.
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
	//  Returns true if the operation was successful and changes were made to the object.
	//  A return value of false guarantees no changes were made to the object.
	bool (*addAt)(GenericList *self, const void * const newElement, const int numElements, const int index);
	//Function: copyOtherBetween
	//Copies the selected data from another GenericList.
	//
	//If startIndex is less than 0 then it is bounded to 0.
	//If endIndex is greater than the number of elements in the list being copied
	//then it is bounded to the length of the list being copied.
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
	//  Returns true if the operation was successful and changes were made to the object.
	//  A return value of false guarantees no changes were made to the object.
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
	//  true if token is found in the list, otherwise false.
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
	//Removes all instances of the supplied token from the list.
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
	//  Returns true if the operation was successful and changes were made to the object.
	//  A return value of false DOES NOT guarantee no changes were made to the object.
	bool (*remove)(GenericList *self, const void * const token);
	//Function: removeAt
	//Removes the item at the supplied index from the list.
	//
	//Parameters:
	//
	//  self - The generic list to perform the operation on.
	//  index - The index to remove.
	//
	//Returns:
	//
	//  Returns true if the operation was successful and changes were made to the object.
	//  A return value of false DOES NOT guarantee no changes were made to the object.
	bool (*removeAt)(GenericList *self, const int index);
	//Function: removeBetween
	//Removes the items between the supplied indexes.
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
	//  Returns true if the operation was successful and changes were made to the object.
	//  A return value of false DOES NOT guarantee no changes were made to the object.
	bool (*removeBetween)(GenericList *self, const int startIndex, const int endIndex);
	//Function: trimToSize
	//Removes elements from the end of the list until the list size equals numElements.
	//
	//If numElements is greater than the lists size then no action occurs.
	//
	//If numElements is 0 clear will be called.
	//
	//Parameters:
	//
	//  self - The generic list to perform the operation on.
	//  numElements - The number of elements to keep in the list.
	//
	//Returns:
	//
	//  Returns true if the operation was successful and changes were made to the object.
	//  A return value of false guarantees no changes were made to the object.
	bool (*trimToSize)(GenericList *self, const int numElements);
	//Function: clear
	//Removes all elements from the list.
	//
	//Parameters:
	//
	//  self - The generic list to perform the operation on.
	//
	//Returns:
	//
	//  Returns true if the operation was successful and changes were made to the object.
	//  A return value of false guarantees no changes were made to the object.
	bool (*clear)(GenericList *self);
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
	//Function: equals
	//Returns true/false depending if the two lists are equal.
	//
	//Equality is determined by comparing length, and the memory contents of each list.
	//
	//Parameters:
	//
	//  self - The first generic list to compare.
	//  other - The second generic list to compare.
	//
	//Returns:
	//
	//  true if the lists are equal, otherwise false.
	bool (*equals)(const GenericList * const self, const GenericList * const other);
} GenericList_t;

#endif
