#ifndef BASIC_TYPE_CLASS
#define BASIC_TYPE_CLASS

#include "Object.h"
#include "Operator.h"

//Class: BasicType_t
//This defines the three classes for the basic data types, listed below.
//
// - SignedBasicType_t
// - UnsignedBasicType_t
// - FloatBasicType_t
//
//An example usage of a basic data type in the object system is shown below.
//
//---Code
//int value=5;
//int *var=new(int);
//int_t.set(var,&value);
//delete(int,var);
//---
//
//Supported basic data types are:
//
//  - char_t: char
//  - short_t: short
//  - int_t: int
//  - unsigned_t: unsigned
//  - long_t: long
//  - float_t: float
//  - double_t: double
//
//With the <customPreProcessor> enabled, the following additional basic data types
//are also supported:
//
//  - signed_char_t: signed char
//  - unsigned_char_t: unsigned char
//  - short_int_t: short int
//  - signed_short_int_t: signed short int
//  - unsigned_short_t: unsigned short
//  - unsigned_short_int_t: unsigned short int
//  - signed_int: signed int
//  - unsigned_int_t: unsigned int
//  - long_int_t: long int
//  - signed_long_t: signed long
//  - signed_long_int_t: signed long int
//  - unsigned_long_t: unsigned long
//  - unsigned_long_int_t: unsigned long int
//  - long_long_t: long long
//  - long_long_int_t: long long int
//  - signed_long_long_t: signed long long
//  - signed_long_long_int_t: signed long long int
//  - unsigned_long_long_t: unsigned long long
//  - unsigned_long_long_int_t: unsigned long long int
//  - long_double_t: long double
//
//Note that each basic type class can represent multiple object types.
//It is for this reason that the three basic type classes is not a supported
//object, the size of the underlying object cannot be determined because the 
//underlying object can be one of multiple types.
//
//The types listed above are just an alias for there respective basic type class,
//but they have a size associated with them making there objects supported.
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
	ComparisonOperators comparisonOperators;
	AddOperators addOperators;
	SubOperators subOperators;
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
} SignedBasicType_t, UnsignedBasicType_t, FloatBasicType_t;
#define char_t SignedBasicType_t
#define short_t SignedBasicType_t
#define int_t SignedBasicType_t
#define unsigned_t UnsignedBasicType_t
#define long_t SignedBasicType_t
#define float_t FloatBasicType_t
#define double_t FloatBasicType_t

#ifdef CUSTOM_PRE_PROC_ENABLED
	#define signed_char_t SignedBasicType_t
	#define unsigned_char_t UnsignedBasicType_t
	#define short_int_t SignedBasicType_t
	#define signed_short_int_t SignedBasicType_t
	#define unsigned_short_t UnsignedBasicType_t
	#define unsigned_short_int_t UnsignedBasicType_t
	#define signed_int_t SignedBasicType_t
	#define unsigned_int_t UnsignedBasicType_t
	#define long_int_t SignedBasicType_t
	#define signed_long_t SignedBasicType_t
	#define signed_long_int_t SignedBasicType_t
	#define unsigned_long_t UnsignedBasicType_t
	#define unsigned_long_int_t UnsignedBasicType_t
	#define long_long_t SignedBasicType_t
	#define long_long_int_t SignedBasicType_t
	#define signed_long_long_t SignedBasicType_t
	#define signed_long_long_int_t SignedBasicType_t
	#define unsigned_long_long_t UnsignedBasicType_t
	#define unsigned_long_long_int_t UnsignedBasicType_t
	#define long_double_t FloatBasicType_t
#endif

#endif
