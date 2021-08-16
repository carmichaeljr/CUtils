#ifndef STRING_CLASS
#define STRING_CLASS

#include <stdlib.h>
#include <stdbool.h>
#include "../src/Object.h"
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
	//The length of the string excluding the NULL terminator.
	int length;
} String;

//Class: String_t
//The struct that creates and performs operations on objects of type String.
//
//See Also:
//
//  <String>
extern const struct String_t {
	Class class;
	//Function: setSize
	//Allocates enough space for a string of length len+1. (for NULL terminator)
	//Contents of the string will not be changed unless the new size is less than the current size.
	//No terminating NULL character is added, this is purely just to set the size of the underlying array.
	//If len==0 then <String_t.clear> will be called.
	//
	//Memory contents are not initialized.
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
	//If newStr is empty or NULL then <String_t.clear> will be called.
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
	//Function: setNonNullString
	//Copies the contents of a non-NULL terminated string.
	//
	//If newStr is empty or NULL then <String_t.clear> will be called.
	//
	//Parameters:
	//
	//  self - The string object to perform the operation on.
	//  newStr - The string to copy.
	//  strLen - The length of the string being copied.
	//
	//Returns:
	//
	//  Returns true if the operation was successful and changes were made to the object.
	//  A return value of false guarantees no changes were made to the object.
	bool (*setNonNullString)(String *self, const char * const newStr, const int strLen);
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
	//If startIndex is less than 0, endIndex is greater than the length of the string being copied,
	//or startIndex>endIndex, no operation occurs.
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
	//  A return value of false guarantees no changes were made to the object.
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
	//Function: contains
	//Returns the index of where the substring starts in the current string, or -1 if not present.
	//
	//Parameters:
	//
	//  self - The string object to perform the operaion on.
	//  token - The substring to look for in the string.
	//
	//Returns:
	//
	//  True or fa
	int (*contains)(const String *self, const char * const token);
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
	//IntList* (*getIndexesOf)(const String *self, const char token);
	//Function: trimSubstring
	//Removes the substring defined by the given indexes.
	//
	//If the indexes specify the whole string then <String_t.clear> will be called.
	//
	//Parameters:
	//
	//  self - The string object to perform the operation on.
	//  startIndex - The start index of the substring to remove (inclusive).
	//  endIndex - The end index of the substring to remove (exclusive).
	//
	//Returns:
	//
	//  Returns true if the operation was successful and changes were made to the object.
	//  A return value of false guarantees no changes were made to the object, 
	//  unless strictAlloc is true for the underlying GenericList data structure (defaults to false).
	//
	//See Also:
	//
	//  - <GenericList.strictAlloc>
	bool (*trimSubstring)(String *self, const int startIndex, const int endIndex);
	//Function: trimWhitespace
	//Removes whitespace characters (' ','\t') from the beginning and end of the string.
	//
	//Parameters:
	//
	//  self - The string object to perform the operation on.
	//
	//Returns:
	//
	//  Returns true if the operation was successful and changes were made to the object.
	//  A return value of false guarantees no changes were made to the object, 
	//  unless strictAlloc is true for the underlying GenericList data structure (defaults to false).
	bool (*trimWhitespace)(String *self);
	//Function: removeChars
	//Removes the supplied chars from the string.
	//If all of the characters are removed from the string then the string is cleared.
	//
	//Parameters:
	//
	//  self - The string object to perform the operation on.
	//  unwantedChars - A NULL terminated string containing the chars to remove.
	//
	//Returns:
	//
	//  Returns true if the operation was successful and changes were made to the object.
	//  A return value of false guarantees no changes were made to the object, 
	//  unless strictAlloc is true for the underlying GenericList data structure (defaults to false).
	//
	//See Also:
	//
	//  - <GenericList.strictAlloc>
	bool (*removeChars)(String *self, const char * const unwantedChars);
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
	//Function: equalsCharArray
	//Returns true/false depending if the strings are equal or not.
	//Two NULL strings are considered equal. Two empty strings are considered equal.
	//
	//Parameters:
	//
	//  self - The string object to perform the operation on.
	//  other - The string to compare to.
	//
	//Returns:
	//
	//  True if the strings are equal, false if they aren't.
	bool (*equalsCharArray)(const String * const self, const char * const other);
} String_t;

#endif
