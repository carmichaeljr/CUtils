#ifndef STRING_CLASS
#define STRING_CLASS

#include <stdlib.h>
#include <stdbool.h>
#include "GenericList.h"

//Class: String
//The struct that represents a String.
typedef struct StringObj {
	//Variable: genericList
	//The underlying storage and memory management for the string.
	GenericList *genericList;
	//Variable: str
	char *str;
	//Variable: length
	int length;
} String;

//Class: String_t
//The struct that creates and perform operations on objects of type: String
//This class is for storing and manipulating Strings.
//General usage is as follows:
//--- Code
//String *list=String_t.new();
//String_t.<func to call>(list, <params>);
//...
//String_t.delete(&list);
//---
extern const struct String_t {
	//Constructor: new
	//Creates and initializes a String object.
	String* (*new)(void);
	//Destructor: delete
	//Deletes a String object.
	void (*delete)(String **obj);
	//Function: print
	//Prints the contents of a String object.
	void (*print)(const String * const obj);
	//Function: setSize
	//Allocates enough space for a string of length len+1. (for NULL terminator)
	//If len==0 then clear will be called.
	//
	//Memory contents are not initialized besides the terminating '\0'.
	//
	//Useful for reducing reallocations when you know the final size of the string.
	void (*setSize)(String *self, const int len);
	//Function: set
	//Copies the contents of a NULL terminated string.
	//
	//If newStr is empty then clear will be called.
	void (*set)(String *self, const char * const newStr);
	//Function: concat
	//Appends a NULL terminated string to the current string.
	//
	//Only one reallocation is performed.
	void (*concat)(String *self, const char * const newStr);
	//Function: concatChar
	//Appends a character to the current string.
	//
	//If the string is currently empty, the NULL terminating character is added.
	//
	//Only one reallocation is performed.
	void (*concatChar)(String *self, const char newChar);
	//Function: copyOtherBetween
	//Copies another string given the supplied indexes.
	//
	//If startIndex is less than 0 then it is bounded to 0.
	//If endIndex is greater than the number of elements in the string being copied
	//then it is bounded to the length of the string being copied.
	void (*copyOtherBetween)(String *self, const String * const other, const int startIndex, const int endIndex);
	//Function: getFirstIndexOf
	//Finds the first instance of the given char in the string.
	//
	//Searching stops when the first char is found.
	//
	//TODO: see bug noted in debug func. Need to update GenericList to return value based on success of operation.
	int (*getFirstIndexOf)(const String * const self, const char searchChar);
	//Function: getLastIndexOf
	//Finds the last instance of the given char in the string.
	//
	//Searching stops when the last char is found.
	int (*getLastIndexOf)(const String * const self, const char searchChar);
	//Function: getCharOccurrences
	//Counts the number of occurrences of the characters in searchChars in the current string.
	//
	//Duplicate characters in searchChars are ignored, 
	//only the first instance of a char will be used when searching.
	int (*getCharOccurrences)(const String *self, const char *searchChars);
	//Function: clear
	//Clears the contents of the string, sets length to 0.
	void (*clear)(String *self);

	void (*toUpperCase)(String *self);
	void (*toLowerCase)(String *self);
	void (*trimWhitespace)(String *self);
	bool (*equals)(const String *self, const char *other);
	bool (*contains)(const String *self, const char *token);
	//IntList* (*getIndexesOf)(const String *self, const char token);
	void (*removeChars)(String *self, const char *unwantedChars);
	void (*trimSubString)(String *self, const int startIndex, const int endIndex);
} String_t;

#endif
