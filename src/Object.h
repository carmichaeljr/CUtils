#ifndef OBJECT_FRAMEWORK
#define OBJECT_FRAMEWORK

#include <stdlib.h>

//Macro: new
//--- Prototype ---
//new(type) 
//-----------------
//
//New is a function-macro that, given a type, creates a new object of that type.
//
//The constructor is supplied by the given object type. This means that in order for
//this macro to work a constructor function with the following signature must be defined
//in the types <Class> struct.
//--- Code
//void constructor(void *obj)
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <Class> struct as a member named "class" in order
//for this macro expansion to work properly. The <Class> struct defines how objects of <type>
//are created, destroyed, copied, and compared. An example of this is the <String_t> struct.
#define new(type) createObject(sizeof(type),type##_t.class.allocator,type##_t.class.constructor)
//Macro: copy
//--- Prototype ---
//copy(type,obj) 
//-----------------
//
//Copy is a function-macro that, given a type and a preexisting object, creates a copy of
//the object.
//
//The copyConstructor is supplied by the given object type. This means that in order for
//this macro to work a copyConstructor function with the following signature must be defined
//in the types <Class> struct.
//--- Code
//void* copyConstructor(void *obj, const void * const other, size_t size)
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <Class> struct as a member named "class" in order
//for this macro expansion to work properly. The <Class> struct defines how objects of <type>
//are created, destroyed, copied, and compared. An example of this is the <String_t> struct.
#define copy(type,obj) cloneObject((void*)obj,sizeof(type),type##_t.class.allocator,type##_t.class.copyConstructor)
//Macro: delete
//--- Prototype ---
//delete(type,obj) 
//-----------------
//
//Delete is a function-macro that, given a type and a preexisting object, deletes the object.
//
//The destructor is supplied by the given object type. This means that in order for
//this macro to work a destructor function with the following signature must be defined
//in the types <Class> struct.
//--- Code
//void destructor(void *obj)
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <Class> struct as a member named "class" in order
//for this macro expansion to work properly. The <Class> struct defines how objects of <type>
//are created, destroyed, copied, and compared. An example of this is the <String_t> struct.
#define delete(type,obj) deleteObject((void**)(&obj),type##_t.class.destructor)
//Macro: equals
//--- Prototype ---
//equals(type,obj1,obj2) 
//-----------------
//
//Equals is a function-macro that, given a type and a preexisting object, compares the two
//objects. The return value is defined by the implementation of the comparator in the <type>_t struct.
//
//The comparator is supplied by the given object type. This means that in order for
//this macro to work a comparator function with the following signature must be defined
//in the types <Class> struct.
//--- Code
//int comparator(const void *first, const void *second, size_t size)
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <Class> struct as a member named "class" in order
//for this macro expansion to work properly. The <Class> struct defines how objects of <type>
//are created, destroyed, copied, and compared. An example of this is the <String_t> struct.
#define equals(type,obj1,obj2) type##_t.class.comparator(obj1,obj2,sizeof(type))
//Macro: DEFAULT_CLASS
//--- Prototype
//DEFAULT_CLASS {
//	.allocator=malloc,
//	.constructor=constructor,
//	.copyConstructor=memcpy,
//	.comparator=memcmp,
//	.destructor=destructor,
//}
//---
//DEFAULT_CLASS is a macro that defines default allocator, copyConstructor, and comparator functions.
//Use this macro when the only functions you wish to change from default in the <Class> struct are the
//constructor and destructor.
//
//The default allocator is malloc, the default copyConstructor is memcpy, and the default comparator
//is memcmp. All of these can be overridden manually.
//
//A default constructor and destructor are NOT supplied. These functions need to be defined
//in the source file that the DEFAULT_CLASS macro expands in, and are assumed to have the
//following signatures and names:
//
//--- Code
//void constructor(void *obj);
//void destructor(void *obj);
//---
#define DEFAULT_CLASS { \
		.allocator=malloc,\
		.constructor=constructor,\
		.copyConstructor=memcpy,\
		.comparator=memcmp\
		.destructor=destructor,\
	}

//Struct: Class
//The struct that defines various memory related operations related to objects.
//Each struct of <type>_t needs to have a Class struct named "class" for the above macros to work.
typedef struct Class {
	//Function: allocator
	//Responsible for allocating space for the object.
	//
	//Parameters:
	//
	//  size - The size in bytes to allocate for the object.
	//
	//Returns:
	//
	//  A void pointer to the memory block allocated.
	void* (*allocator)(size_t size);
	//Function: constructor
	//Responsible for initializing an already allocated object.
	//
	//Parameters:
	//
	//  obj - A pointer to the memory block allocated for the object.
	//
	//Returns:
	//
	//  Nothing
	void (*constructor)(void *obj);
	//Function: copyConstructor
	//Responsible for creating a clone of another object.
	//
	//Parameters:
	//
	//  obj - A pointer to the memory block allocated for the new object.
	//  other - The object to copy.
	//  size - The size of the object being copied.
	//
	//Returns:
	//
	//  A void pointer to the initialized new object.
	void* (*copyConstructor)(void *obj, const void * const other, size_t size);
	//Function: comparator
	//Responsible for comparing two objects of the same type.
	//
	//Parameters:
	//
	//  first - The first object to compare.
	//  second - The second object to compare.
	//  size - The size of the objects being compared.
	//
	//Returns:
	//
	//  The return value is defined by the implementation of the comparator in the <type>_t struct.
	int (*comparator)(const void *first, const void *second, size_t size);
	//Function: destructor
	//Responsible for deleting and freeing memory allocated for the given object.
	//
	//Parameters:
	//
	//  obj - A pointer to the object.
	//
	//Returns:
	//
	//  Nothing
	void (*destructor)(void *obj);
} Class;

void* createObject(size_t size, void* (*allocator)(size_t size), void (*constructor)(void *obj));
void* cloneObject(const void * const other, size_t size,
		  void* (*allocator)(size_t size),
		  void* (*copyConstructor)(void *obj, const void * const other, size_t size));
void deleteObject(void **obj, void (*destructor)(void *obj));

#endif
