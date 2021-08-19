#ifndef OBJECT_FRAMEWORK
#define OBJECT_FRAMEWORK

#include <stdlib.h>
#include <stdbool.h>

#define GET_NEW_MACRO(one,two,NAME,...) NAME
#define GET_COPY_MACRO(one,two,three,NAME,...) NAME
#define GET_DELETE_MACRO(one,two,three,NAME,...) NAME
#define MERGE_(a,b)  a##b
#define LABEL_(a) MERGE_(unique_name_, a)
#define UNIQUE_NAME LABEL_(__LINE__)

//Macro: new
//--- Prototype ---
//new(type,obj=NULL)
//-----------------
//
//New is a function-macro that, given a type, creates a new object of that type.
//This macro is overloaded with a default parameter.
//If obj is NULL then memory will be allocated for the new object. If obj is not NULL
//then obj is treated as a pointer to heap memory already allocated for the new object.
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
//
//Parameters:
//
//  type - The type of object to create.
//  obj - A pointer to already reserved heap memory to initialize the object with.
#define new(...) GET_NEW_MACRO(__VA_ARGS__,newWithoutAlloc,newWithAlloc)(__VA_ARGS__)
#define newWithAlloc(type) createObject(NULL,sizeof(type),type##_t.class.allocator,type##_t.class.constructor)
#define newWithoutAlloc(type,obj) createObject((void*)obj,sizeof(type),type##_t.class.allocator,type##_t.class.constructor)
//Macro: copy
//--- Prototype ---
//copy(type,obj=NULL,other) 
//-----------------
//
//Copy is a function-macro that, given a type and a preexisting object, creates a copy of
//the object.
//This macro is overloaded with a default parameter.
//If obj is NULL then memory will be allocated for the new object. If obj is not NULL
//then obj is treated as a pointer to heap memory already allocated for the new object.
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
//
//Parameters: 
//
//  type - The type of object being cloned.
//  obj - A pointer to already reserved heap memory to initialize the object with.
//  other - The object to clone.
#define copy(...) GET_COPY_MACRO(__VA_ARGS__,copyWithoutAlloc,copyWithAlloc)(__VA_ARGS__)
#define copyWithAlloc(type,other)\
	cloneObject(NULL,(void*)other,sizeof(type),type##_t.class.allocator,type##_t.class.copyConstructor)
#define copyWithoutAlloc(type,obj,other)\
	cloneObject((void*)obj,(void*)other,sizeof(type),type##_t.class.allocator,type##_t.class.copyConstructor)
//Macro: delete
//--- Prototype ---
//delete(type,obj,freeObj=true) 
//-----------------
//
//Delete is a function-macro that, given a type and a preexisting object, deletes the object.
//This macro is overloaded through defining a default parameter.
//If freeObj is true then the memory allocated to the object will be freed. If obj is false
//then the memory allocated for the object will not be freed.
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
//
//Parameters:
//
//  type - The type of the object being deleted.
//  obj - A pointer to the object to be deleted.
//  freeObj - Determines if the memory is freed or not.
#define delete(...) GET_DELETE_MACRO(__VA_ARGS__,deleteFreeOption,deleteWithFree)(__VA_ARGS__)
#define deleteWithFree(type,obj) deleteObject((void**)(&obj),type##_t.class.destructor,true)
#define deleteFreeOption(type,obj,freeObj) deleteObject((void**)(&obj),type##_t.class.destructor,freeObj)

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
//
//Parameters:
//
//  type - The type of the two objects being compared.
//  obj1 - The first object to compare.
//  obj2 - The second object to compare.
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
		.comparator=memcmp,\
		.destructor=destructor,\
	}
//Macro: ALLOC_ONLY_DEFAULT_CLASS
//--- Prototype
//ALLOC_ONLY_DEFAULT_CLASS {
//	.allocator=malloc,
//	.constructor=constructor,
//	.copyConstructor=copyConstructor,
//	.comparator=comparator,
//	.destructor=destructor,
//}
//---
//ALLOC_ONLY_DEFAULT_CLASS is a macro that defines only a default allocator function.
//Use this macro when the only functions you wish to change from default in the <Class> struct are the
//constructor, copyConstructor, comparator, and destructor.
//
//The default allocator is malloc, which can be overridden manually.
//
//The functions not supplied need to be defined in the source file that the ALLOC_ONLY_DEFAULT_CLASS 
//macro expands in, and are assumed to have the following signatures and names:
//
//--- Code
//void constructor(void *obj);
//void* copyConstructor(void *obj, const void * const other, size_t size);
//int comparator(const void *first, const void *second, size_t size);
//void destructor(void *obj);
//---
#define ALLOC_ONLY_DEFAULT_CLASS { \
		.allocator=malloc,\
		.constructor=constructor,\
		.copyConstructor=copyConstructor,\
		.comparator=comparator,\
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
	//Responsible for creating a clone of another object, given already allocated memory.
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

//Class: BasicType_t
//This defines the class for the basic data types. Supported basic data types are:
//
//  - char_t: char
//  - short_t: short
//  - int_t: int
//  - unsigned_t: unsigned
//  - long_t: long
//  - float_t: float
//  - double_t: double
//
//With the custom pre-processor enabled, the following additional basic data types are supported:
//
//  - unsigned_int_t: unsigned int
//
//Note that BasicType_t is a class that can represent multiple object types.
//It is for this reason that BasicType is not a supported object, the size of the
//underlying object cannot be determined because the underlying object can be one
//of multiple types.
//
//The types listed above are just an alias for BasicType_t, but they have a size
//associated with them making there objects supported.
//
//The class declaration is as follows for all basic data types:
//--- Code
//.allocator=malloc,
//.constructor=NULL,
//.copyConstructor=memcpy,
//.comparator=memcmp,
//.destructor=NULL,
//---
//
//Creating the class in this manner allows objects of basic data types to be supported.
//It allows for basic data types to interact with the rest of the objects in the object
//system and be treated as regular objects.
const struct BasicType_t {
	Class class;
	//Function: set
	//Sets the objects value. The default operation is memcpy.
	//
	//Parameters:
	//
	//  self - The object to perform the operation on.
	//  other - The object to copy from. In this case most likely a variable to
	//  	    a corresponding data type.
	//  size - The size of the object.
	//
	//Returns:
	//	A void pointer to the newly set object.
	void* (*set)(void *self, const void * const other, size_t size);
} BasicType_t;
#define char_t BasicType_t
#define short_t BasicType_t
#define int_t BasicType_t
#define unsigned_t BasicType_t
#define long_t BasicType_t
#define float_t BasicType_t
#define double_t BasicType_t

#ifdef CUSTOM_PRE_PROC_ENABLED
	#define unsigned_int_t BasicType_t
#endif

void* createObject(void *obj, size_t size, 
		   void* (*allocator)(size_t size),
		   void (*constructor)(void *obj));
void* cloneObject(void *obj, const void * const other, size_t size,
		  void* (*allocator)(size_t size),
		  void* (*copyConstructor)(void *obj, const void * const other, size_t size));
void deleteObject(void **obj, void (*destructor)(void *obj), bool freeObj);

#endif
