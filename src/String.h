#ifndef STRING_CLASS
#define STRING_CLASS

#include <stdlib.h>
#include <stdbool.h>
#include "GenericList.h"

//Class: String
//The struct that represents a String.
//This class is for storing and manipulating Strings.
//General usage is as follows:
//--- Code
//String *list=String_t.new();
//String_t.<func to call>(list, <params>);
//...
//String_t.delete(&list);
//---
//
//See Also:
//
//  <String_t>
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
//The struct that creates and performs operations on objects of type String.
//
//See Also:
//
//  <String>
extern const struct String_t {
	//Constructor: new
	//Creates and initializes a String object.
	//
	//Parameters:
	//
	//  None
	//
	//Returns:
	//
	//  A pointer to a string object.
	String* (*new)(void);
	//Destructor: delete
	//Deletes a String object and sets its pointer to NULL.
	//
	//Parameters:
	//
	//  obj - The object to delete.
	//
	//Returns:
	//
	//  Nothing
	void (*delete)(String **obj);
	//Function: print
	//Prints the contents of a String object.
	//
	//Parameters:
	//
	//  obj - The string to print.
	//
	//Returns:
	//
	//  Nothing
	void (*print)(const String * const obj);
	//Function: setSize
	//Allocates enough space for a string of length len+1. (for NULL terminator)
	//If len==0 then clear will be called.
	//
	//Memory contents are not initialized besides the terminating '\0'.
	//
	//Useful for reducing reallocations when you know the final size of the string.
	//
	//Parameters:
	//
	//  self - The string object to perform the operation on.
	//  len - The number of characters to allocate space for (excluding the terminating null).
	//
	//Returns:
	//
	//  Returns true if the operation was successful and changes were made to the object.
	//  A return value of false guarantees no changes were made to the object.
	bool (*setSize)(String *self, const int len);
	//Function: set
	//Copies the contents of a NULL terminated string.
	//
	//If newStr is empty then clear will be called.
	//
	//Parameters:
	//
	//  self - The string object to perform the operation on.
	//  newStr - A NULL terminated string to copy.
	//
	//Returns:
	//
	//  Returns true if the operation was successful and changes were made to the object.
	//  A return value of false guarantees no changes were made to the object.
	bool (*set)(String *self, const char * const newStr);
	//Function: concat
	//Appends a NULL terminated string to the current string.
	//
	//Only one reallocation is performed.
	//
	//Parameters:
	//
	//  self - The string object to perform the operation on.
	//  newStr - A NULL terminated string to append to the current string.
	//
	//Returns:
	//
	//  Returns true if the operation was successful and changes were made to the object.
	//  A return value of false guarantees no changes were made to the object.
	bool (*concat)(String *self, const char * const newStr);
	//Function: concatChar
	//Appends a character to the current string.
	//
	//If the string is currently empty, the NULL terminating character is added.
	//
	//Only one reallocation is performed.
	//
	//Parameters:
	//
	//  self - The string to perform the operation on.
	//  newChar - The character to append.
	//
	//Returns:
	//
	//  Returns true if the operation was successful and changes were made to the object.
	//  A return value of false guarantees no changes were made to the object.
	bool (*concatChar)(String *self, const char newChar);
	//Function: copyOtherBetween
	//Copies another string given the supplied indexes.
	//
	//If startIndex is less than 0 then it is bounded to 0.
	//If endIndex is greater than the number of elements in the string being copied
	//then it is bounded to the length of the string being copied.
	//
	//Parameters:
	//
	//  self - The string object to perform the operation on.
	//  other - The string object to copy from.
	//  startIndex - The starting index to copy from in other (inclusive).
	//  endIndex - The last index to copy from in other (exclusive).
	//
	//Returns:
	//
	//  Returns true if the operation was successful and changes were made to the object.
	//  A return value of false DOES NOT guarantee no changes were made to the object.
	bool (*copyOtherBetween)(String *self, const String * const other, const int startIndex, const int endIndex);
	//Function: toUpper
	//Makes a string uppercase.
	//
	//Parameters:
	//
	//  self - The string object to perform the operation on.
	//
	//Returns:
	//
	//  Nothing
	void (*toUpper)(String *self);
	//Function: toLower
	//Makes a string lowercase.
	//
	//Parameters:
	//
	//  self - The string object to perform the operation on.
	//
	//Returns:
	//
	//  Nothing
	void (*toLower)(String *self);
	//Function: getFirstIndexOf
	//Finds the first instance of the given char in the string.
	//
	//Searching stops when the first char is found.
	//
	//Parameters:
	//
	//  self - The string object to perform the operation on.
	//  searchChar - The character to search for in the string.
	//
	//Returns:
	//
	//  The index of the first instance of searchChar in the string, or -1 if it was not found.
	int (*getFirstIndexOf)(const String * const self, const char searchChar);
	//Function: getLastIndexOf
	//Finds the last instance of the given char in the string.
	//
	//Searching stops when the last char is found.
	//
	//Parameters:
	//
	//  self - The string object to perform the operation on.
	//  searchChar - The character to search for in the string.
	//
	//Returns:
	//
	//  The index of the last instance of searchChar in the string, or -1 is it was not found.
	int (*getLastIndexOf)(const String * const self, const char searchChar);
	//Function: getCharOccurrences
	//Counts the number of occurrences of the characters in searchChars in the current string.
	//
	//Duplicate characters in searchChars are ignored, 
	//only the first instance of a char will be used when searching.
	//
	//Parameters:
	//
	//  self - The string object to perform the operation on.
	//  searchChars - The characters to search for in the string.
	//
	//Returns:
	//
	//  The number of characters in the string that are found in searchChars.
	int (*getCharOccurrences)(const String *self, const char *searchChars);
	//Function: clear
	//Clears the contents of the string, sets length to 0.
	//
	//Parameters:
	//
	//  self - The string object to perform the operation on.
	//
	//Returns:
	//
	//  Returns true if the operation was successful and changes were made to the object.
	//  A return value of false guarantees no changes were made to the object.
	bool (*clear)(String *self);

	void (*trimWhitespace)(String *self);
	bool (*equals)(const String *self, const char *other);
	bool (*contains)(const String *self, const char *token);
	//IntList* (*getIndexesOf)(const String *self, const char token);
	void (*removeChars)(String *self, const char *unwantedChars);
	void (*trimSubString)(String *self, const int startIndex, const int endIndex);
} String_t;

#endif
