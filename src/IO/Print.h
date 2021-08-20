#ifndef PRINT_CLASS
#define PRINT_CLASS

#include <stdbool.h>

//Class: Print_t
//The struct that performs operations related to printing to the console.
//Changes made to Print_t by calling the functions associated with Print_t are global.
//As a result Print_t is not thread safe.
//
//General usage is as follows:
//--- Code
//Print_t.<func to call>(<params>);
//---
extern const struct Print_t {
	//Function: incrementIndentLevel
	//Adds the given value to the indentLevel.
	//Use positive numbers to increase the indent and negative numbers to decrease the indent.
	//
	//If incrementLevel will end up being a negative value, then no changes are made.
	//
	//Parameters:
	//
	//  increment - The number to add to the current indent level.
	//
	//Returns:
	//
	//Nothing
	void (*incrementIndentLevel)(const int increment);
	//Function: setSpacesPerIndent
	//Sets the number of spaces that represent an indent when printing them to the console.
	//
	//If numSpaces<=0, no changes will be made.
	//
	//Parameters:
	//
	//  numSpaces - The number of spaces to set an indent to.
	//
	//Returns:
	//
	//Nothing
	void (*setSpacesPerIndent)(const int numSpaces);
	//Function: setLineLength
	//Sets the number of spaces that will be printed at the end of a line as spacing.
	//This is so lines that end in '\r' will clear the next line fully.
	//
	//If newLineLength<=0, no changes will be made.
	//
	//Parameters:
	//
	//  newLineLength - The length of a line in every print call.
	//
	//Returns:
	//
	//Nothing
	void (*setLineLength)(const int newLineLength);
	//Function: print
	//Prints the given string with the given format specifiers with an indent.
	//
	//Parameters:
	//
	//  format - The string dictating the format of what to print.
	//  ... - The list of parameters that are used to format the string.
	//
	//Returns:
	//
	//Nothing
	void (*print)(const char *format, ...);
	//Function: println
	//Prints the given string with the given format specifiers with an indent. 
	//A newline ('\n') is printed at the end of the formatted string.
	//
	//Parameters:
	//
	//  format - The string dictating the format of what to print.
	//  ... - The list of parameters that are used to format the string.
	//
	//Returns:
	//
	//Nothing
	void (*println)(const char *format, ...);
	//Function: printWithoutIndent
	//Prints the given string with the given format specifiers. 
	//No newline of indent are added.
	//
	//Parameters:
	//
	//  format - The string dictating the format of what to print.
	//  ... - The list of parameters that are used to format the string.
	//
	//Returns:
	//
	//Nothing
	void (*printWithoutIndent)(const char *format, ...);
	//Function: objectDebug
	//Prints debug information for the given parameters.
	//If success is true, the line is ended with a '\r' to allow successful tests to be overwritten.
	//If success if false, the line is ended with a '\n' so non-successful tests will not be overwritten.
	//
	//Parameters:
	//
	//  structName - The name of the struct that is being debugged.
	//  funcName - The function that is being debugged.
	//  line - The line number in the src file where the test if being performed.
	//  success - Weather or not the test was successful.
	//
	//Returns:
	//
	//Nothing
	void (*objectDebug)(const char * const structName, const char * const methodName, const int line, const bool success);
} Print_t;

#endif
