#ifndef OPERATOR_FRAMEWORK
#define OPERATOR_FRAMEWORK

//All operators have to return a pointer to the object that was manipulated in
//order to allow for chaining of commands
//
//Result *result=new(Result);
//opSqrt(opPowEq(opAddEq(one,two),five),opPowEq(opAddEq(three,four),six),result);
typedef struct ArithLogicOperators {
	void* (*op)(const void * const self, const void * const other, void *result, size_t size);
	void* (*opSelf)(void *self, const void * const other, size_t size);
} ArithLogicOperators;

#define AddOperators ArithLogicOperators
#define SubOperators ArithLogicOperators
#define MulOperators ArithLogicOperators
#define DivOperators ArithLogicOperators
#define ModOperators ArithLogicOperators
#define PowOperators ArithLogicOperators
#define SllOperators ArithLogicOperators
#define SrlOperators ArithLogicOperators
#define AndOperators ArithLogicOperators
#define NotOperators ArithLogicOperators
#define OrOperators ArithLogicOperators

#define GET_OPERATOR(one,two,three,four,NAME,...) NAME

#define opAdd(...) GET_OPERATOR(__VA_ARGS__,addOther,addSelf)(__VA_ARGS__)
#define addSelf(type,obj1,obj2) type##_t.addOperators.opSelf((void*)obj1,(void*)obj2,sizeof(type))
#define addOther(type,obj1,obj2,obj3) type##_t.addOperators.op((void*)obj1,(void*)obj2,(void*)obj3,sizeof(type))

#define opSub(...) GET_OPERATOR(__VA_ARGS__,subOther,subSelf)(__VA_ARGS__)
#define subSelf(type,obj1,obj2) type##_t.subOperators.opSelf((void*)obj1,(void*)obj2,sizeof(type))
#define subOther(type,obj1,obj2,obj3) type##_t.subOperators.op((void*)obj1,(void*)obj2,(void*)obj3,sizeof(type))

//Macro: eq
//--- Prototype ---
//eq(type,obj1,obj2) 
//-----------------
//Equals is a function-macro that, given a type and two preexisting objects, compares the two
//objects.
//
//The comparator is supplied by the given object type. This means that in order for
//this macro to work a comparator function with the following signature must be defined
//in the types <ComparisonOperators> struct.
//--- Code
//bool eqOperator(const void *first, const void *second, size_t size)
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <ComparisonOperators> struct as a member 
//named "comparisonOperators" in order for this macro expansion to work properly. The 
//<ComparisonOperators> struct defines how objects of <type>
//are compared. An example of this is the <String_t> struct.
//
//Parameters:
//
//  type - The type of the two objects being compared.
//  obj1 - The first object to compare.
//  obj2 - The second object to compare.
//
//Returns:
//
//  True if the two objects are considered equal, false otherwise.
#define eq(type,obj1,obj2) type##_t.comparisonOperators.eqOperator((void*)obj1,(void*)obj2,sizeof(type))

//#define eqFromOperator(operators,obj1,obj2) (operators).eqOperator((void*)obj1,(void*)obj2,sizeof(type))

//Macro: neq
//--- Prototype ---
//neq(type,obj1,obj2) 
//-----------------
//A function-macro that, given a type and two preexisting objects, compares the two
//objects.
//
//The comparator is supplied by the given object type. This means that in order for
//this macro to work a comparator function with the following signature must be defined
//in the types <ComparisonOperators> struct.
//--- Code
//bool neqOperator(const void *first, const void *second, size_t size)
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <ComparisonOperators> struct as a member 
//named "comparisonOperators" in order for this macro expansion to work properly. The 
//<ComparisonOperators> struct defines how objects of <type>
//are compared. An example of this is the <String_t> struct.
//
//Parameters:
//
//  type - The type of the two objects being compared.
//  obj1 - The first object to compare.
//  obj2 - The second object to compare.
//
//Returns:
//
//  True if the two objects are considered not equal, false otherwise.
#define neq(type,obj1,obj2) type##_t.comparisonOperators.neqOperator((void*)obj1,(void*)obj2,sizeof(type))
//Macro: gt
//--- Prototype ---
//gt(type,obj1,obj2) 
//-----------------
//A function-macro that, given a type and two preexisting objects, compares the two
//objects.
//
//The comparator is supplied by the given object type. This means that in order for
//this macro to work a comparator function with the following signature must be defined
//in the types <ComparisonOperators> struct.
//--- Code
//bool gtOperator(const void *first, const void *second, size_t size)
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <ComparisonOperators> struct as a member 
//named "comparisonOperators" in order for this macro expansion to work properly. The 
//<ComparisonOperators> struct defines how objects of <type>
//are compared. An example of this is the <String_t> struct.
//
//Parameters:
//
//  type - The type of the two objects being compared.
//  obj1 - The first object to compare.
//  obj2 - The second object to compare.
//
//Returns:
//
//  True if the first object is considered to be greater than the second object.
#define gt(type,obj1,obj2) type##_t.comparisonOperators.gtOperator((void*)obj1,(void*)obj2,sizeof(type))
//Macro: lt
//--- Prototype ---
//lt(type,obj1,obj2) 
//-----------------
//A function-macro that, given a type and two preexisting objects, compares the two
//objects.
//
//The comparator is supplied by the given object type. This means that in order for
//this macro to work a comparator function with the following signature must be defined
//in the types <ComparisonOperators> struct.
//--- Code
//bool ltOperator(const void *first, const void *second, size_t size)
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <ComparisonOperators> struct as a member 
//named "comparisonOperators" in order for this macro expansion to work properly. The 
//<ComparisonOperators> struct defines how objects of <type>
//are compared. An example of this is the <String_t> struct.
//
//Parameters:
//
//  type - The type of the two objects being compared.
//  obj1 - The first object to compare.
//  obj2 - The second object to compare.
//
//Returns:
//
//  True if the first object is considered to be less than the second object.
#define lt(type,obj1,obj2) type##_t.comparisonOperators.ltOperator((void*)obj1,(void*)obj2,sizeof(type))
//Macro: gte
//--- Prototype ---
//gte(type,obj1,obj2) 
//-----------------
//A function-macro that, given a type and two preexisting objects, compares the two
//objects.
//
//The comparator is supplied by the given object type. This means that in order for
//this macro to work a comparator function with the following signature must be defined
//in the types <ComparisonOperators> struct.
//--- Code
//bool gteOperator(const void *first, const void *second, size_t size)
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <ComparisonOperators> struct as a member 
//named "comparisonOperators" in order for this macro expansion to work properly. The 
//<ComparisonOperators> struct defines how objects of <type>
//are compared. An example of this is the <String_t> struct.
//
//Parameters:
//
//  type - The type of the two objects being compared.
//  obj1 - The first object to compare.
//  obj2 - The second object to compare.
//
//Returns:
//
//  True if the first object is considered to be greater than or equal to the second object.
#define gte(type,obj1,obj2) type##_t.comparisonOperators.gteOperator((void*)obj1,(void*)obj2,sizeof(type))
//Macro: lte
//--- Prototype ---
//lte(type,obj1,obj2) 
//-----------------
//A function-macro that, given a type and two preexisting objects, compares the two
//objects.
//
//The comparator is supplied by the given object type. This means that in order for
//this macro to work a comparator function with the following signature must be defined
//in the types <ComparisonOperators> struct.
//--- Code
//bool lteOperator(const void *first, const void *second, size_t size)
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <ComparisonOperators> struct as a member 
//named "comparisonOperators" in order for this macro expansion to work properly. The 
//<ComparisonOperators> struct defines how objects of <type>
//are compared. An example of this is the <String_t> struct.
//
//Parameters:
//
//  type - The type of the two objects being compared.
//  obj1 - The first object to compare.
//  obj2 - The second object to compare.
//
//Returns:
//
//  True if the first object is considered to be less than or equal to the second object.
#define lte(type,obj1,obj2) type##_t.comparisonOperators.lteOperator((void*)obj1,(void*)obj2,sizeof(type))

//Macro: DEFAULT_COMPARISON_OPERATORS
//--- Prototype
//DEFAULT_COMPARISON_OPERATORS {
//	.eqOperator=eqOperator,
//	.neqOperator=neqOperator,
//	.gtOperator=gtOperator,
//	.ltOperator=ltOperator,
//	.gteOperator=gteOperator,
//	.lteOperator=lteOperator,
//}
//---
//DEFAULT_COMPARISON_OPERATORS is a macro that defines default comparison functions for a class.
//
//All of the functions listed above need to be supplied, no defaults are set. These 
//functions need to be defined in the source file that the DEFAULT_COMPARISON_OPERATORS macro 
//expands in, and are assumed to have the following signatures and names:
//
//--- Code
//	bool eqOperator(const void * const first, const void * const second, size_t size);
//	bool neqOperator(const void * const first, const void * const second, size_t size);
//	bool gtOperator(const void * const first, const void * const second, size_t size);
//	bool ltOperator(const void * const first, const void * const second, size_t size);
//	bool gteOperator(const void * const first, const void * const second, size_t size);
//	bool lteOperator(const void * const first, const void * const second, size_t size);
//---
#define DEFAULT_COMPARISON_OPERATORS {\
	.eqOperator=eqOperator,\
	.neqOperator=neqOperator,\
	.gtOperator=gtOperator,\
	.ltOperator=ltOperator,\
	.gteOperator=gteOperator,\
	.lteOperator=lteOperator,\
}

//Struct: ComparisonOperators
//The struct that defines various equality related operations related to objects.
//Each struct of <type>_t needs to have a ComparisonOperator struct named "comparisonOperators" for the above macros to work.
typedef struct ComparisonOperators {
	//Function: eqOperator
	//Defines if two objects of the same type are considered equal or not
	//
	//Parameters:
	//
	//  first - the first object to compare
	//  second - the second object to compare
	//  size - the size of the objects being compared
	//
	//Returns:
	//
	//  True if the two objects are equal, false otherwise
	bool (*eqOperator)(const void * const first, const void * const second, size_t size);
	//Function: neqOperator
	//Defines if two objects of the same type are considered not equal
	//
	//Parameters:
	//
	//  first - the first object to compare
	//  second - the second object to compare
	//  size - the size of the objects being compared
	//
	//Returns:
	//
	//  True if the two objects are not equal, false otherwise
	bool (*neqOperator)(const void * const first, const void * const second, size_t size);
	//Function: gtOperator
	//Defines if one object is greater than another object of the same type
	//
	//Parameters:
	//
	//  first - the first object to compare
	//  second - the second object to compare
	//  size - the size of the objects being compared
	//
	//Returns:
	//
	//  True if the first object is greater than the second object
	bool (*gtOperator)(const void * const first, const void * const second, size_t size);
	//Function: ltOperator
	//Defines if one object is less than another object of the same type
	//
	//Parameters:
	//
	//  first - the first object to compare
	//  second - the second object to compare
	//  size - the size of the objects being compared
	//
	//Returns:
	//
	//  True if the first object is less than the second object
	bool (*ltOperator)(const void * const first, const void * const second, size_t size);
	//Function: gteOperator
	//Defines if one object is greater than or equal to another object of the same type
	//
	//Parameters:
	//
	//  first - the first object to compare
	//  second - the second object to compare
	//  size - the size of the objects being compared
	//
	//Returns:
	//
	//  True if the first object is greater than or equal to the second object
	bool (*gteOperator)(const void * const first, const void * const second, size_t size);
	//Function: lteOperator
	//Defines if one object is less than or equal to another object of the same type
	//
	//Parameters:
	//
	//  first - the first object to compare
	//  second - the second object to compare
	//  size - the size of the objects being compared
	//
	//Returns:
	//
	//  True if the first object is less than or equal to the second object
	bool (*lteOperator)(const void * const first, const void * const second, size_t size);
} ComparisonOperators;

typedef struct AccessOperators {
	void* (*brackOperator)(const void * const self, const int num);
} AccessOperators;


#endif
