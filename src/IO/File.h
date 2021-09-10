#ifndef File_CLASS
#define File_CLASS

#include <stdbool.h>
#include "../collections/String.h"
#include "../objectSystem/Object.h"

#define WINDOWS 0
#define UNIX 1
#define LINUX 2
#define MAC 3
#define OS_UK -1

#if defined(_WIN32) || defined(WIN63)
	#define OS WINDOWS
#elif defined(unix) || defined(__unix) || defined(__unix__)
	#define OS UNIX
#elif defined (__APPLE__) || defined(__MACH__)
	#define OS MAC
#elif defined(__linux__) || defined(linux) || defined(__linux)
	#define OS LINUX
#else
	#define OS OS_UK
#endif

//Class: File
// TODO - Add description here
//
//General usage is as follows:
//--- Code
//File *obj=new(File);
//File_t.<func to call>(obj, <params>);
//...
//delete(File,obj);
//---
//
//See Also:
//
//  <File_t>
typedef struct File {
	//TODO - add attributes here
} File;

//Class: File_t
//The struct that creates and performs operations on objects of type File.
//
//See Also:
//
//  <File>
extern const struct File_t {
	//Variable: pathSeparator
	//A char containing the default path separator defined by the OS.
	//The File_t object will work with all file separator types regardless
	//of the current OS.
	const char pathSeparator;
	Class class;
	//Function: exists
	//Determines if the given path exists as either a file or a directory.
	//
	//Parameters:
	//
	//  path - A string object containing the path to the folder or directory
	//  in question
	//
	//Returns:
	//
	//  True if the given path exists as a file or directory. 
	//  False if it does not exist.
	bool (*exists)(const String * const path);
	//Function: isDir
	//Determines if the given path exists as a directory.
	//
	//Parameters:
	//
	//  path - A string object containing the path to the folder in question
	//
	//Returns:
	//
	//  True if the given path exists as a directory, false otherwise.
	bool (*isDir)(const String * const path);
	//Function: isFile
	//Determines if the given path exists as a file.
	//
	//Parameters:
	//
	//  path - A string object containing the path to the file in question.
	//
	//Returns:
	//
	//  True if the given path exists as a file, false otherwise.
	bool (*isFile)(const String * const path);
	//Function: isPipe
	//Determines if the given path exists as a pipe.
	//
	//Parameters:
	//
	//  path - A string object containing the path to the pipe in question.
	//
	//Returns:
	//
	//  True if the given path exists as a pipe, false otherwise.
	bool (*isPipe)(const String * const path);
	String* (*getExtension)(const String * const path, String *buff);
} File_t;

#endif
