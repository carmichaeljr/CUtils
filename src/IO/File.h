#ifndef File_CLASS
#define File_CLASS

//TODO - verify that the include path is correct
#include "../objectSystem/Object.h"

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
	Class class;
	//TODO - add methods here
} File_t;

#endif
