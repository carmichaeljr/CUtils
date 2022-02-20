#ifndef OPERATOR_FRAMEWORK
#define OPERATOR_FRAMEWORK

#define GET_OPERATOR(one,two,three,four,NAME,...) NAME
#define GET_NOT_OPERATOR(one,two,three,NAME,...) NAME

//Macro: ADD
//--- Prototype ---
//ADD(type,obj1,obj2,obj3=obj1) 
//-----------------
//Add is a function-macro that, given a type and two preexisting objects, computes the addition
//of those objects. The types of the objects are determined by the implementation of the
//underlying add function in the <ArithLogicOperators> struct. If different types than
//the ones expected by that function are supplied then undefined behavior will occur.
//
//The adder function is supplied by the given object type. This means that in order for
//this macro to work a function with the following signature must be defined
//in the types <ArithLogicOperators> struct.
//--- Code
//void* add(const void * const self, const void * const other, void *result, size_t size);
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <ArithLogicOperators> struct as a member 
//named "operators" in order for this macro expansion to work properly. The 
//<ArithLogicOperators> struct defines how operators operate on objects of <type>.
//An example of this is the <String_t> struct.
//
//Parameters:
//
//  type - The type of the two objects being compared.
//  obj1 - The first object.
//  obj2 - The second object.
//  obj3 - The object to place the result in, defaults to the first object if not supplied.
//
//Returns:
//
//  A void pointer to the object with the result.
#define ADD(...) GET_OPERATOR(__VA_ARGS__,addOther,addSelf)(__VA_ARGS__)
#define addSelf(type,obj1,obj2) type##_t.operators.add((void*)obj1,(void*)obj2,(void*)obj1,sizeof(type))
#define addOther(type,obj1,obj2,obj3) type##_t.operators.add((void*)obj1,(void*)obj2,(void*)obj3,sizeof(type))

//Macro: SUB
//--- Prototype ---
//SUB(type,obj1,obj2,obj3=obj1) 
//-----------------
//Sub is a function-macro that, given a type and two preexisting objects, computes the subtraction
//of those objects. The types of the objects are determined by the implementation of the
//underlying sub function in the <ArithLogicOperators> struct. If different types than
//the ones expected by that function are supplied then undefined behavior will occur.
//
//The subtractor function is supplied by the given object type. This means that in order for
//this macro to work a function with the following signature must be defined
//in the types <ArithLogicOperators> struct.
//--- Code
//void* sub(const void * const self, const void * const other, void *result, size_t size);
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <ArithLogicOperators> struct as a member 
//named "operators" in order for this macro expansion to work properly. The 
//<ArithLogicOperators> struct defines how operators operate on objects of <type>.
//An example of this is the <String_t> struct.
//
//Parameters:
//
//  type - The type of the two objects being compared.
//  obj1 - The first object.
//  obj2 - The second object.
//  obj3 - The object to place the result in, defaults to the first object if not supplied.
//
//Returns:
//
//  A void pointer to the object with the result.
#define SUB(...) GET_OPERATOR(__VA_ARGS__,subOther,subSelf)(__VA_ARGS__)
#define subSelf(type,obj1,obj2) type##_t.operators.sub((void*)obj1,(void*)obj2,(void*)obj1,sizeof(type))
#define subOther(type,obj1,obj2,obj3) type##_t.operators.sub((void*)obj1,(void*)obj2,(void*)obj3,sizeof(type))

//Macro: MUL
//--- Prototype ---
//MUL(type,obj1,obj2,obj3=obj1) 
//-----------------
//Mul is a function-macro that, given a type and two preexisting objects, computes the multiplication
//of those objects. The types of the objects are determined by the implementation of the
//underlying mul function in the <ArithLogicOperators> struct. If different types than
//the ones expected by that function are supplied then undefined behavior will occur.
//
//The nultiplier function is supplied by the given object type. This means that in order for
//this macro to work a function with the following signature must be defined
//in the types <ArithLogicOperators> struct.
//--- Code
//void* mul(const void * const self, const void * const other, void *result, size_t size);
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <ArithLogicOperators> struct as a member 
//named "operators" in order for this macro expansion to work properly. The 
//<ArithLogicOperators> struct defines how operators operate on objects of <type>.
//An example of this is the <String_t> struct.
//
//Parameters:
//
//  type - The type of the two objects being compared.
//  obj1 - The first object.
//  obj2 - The second object.
//  obj3 - The object to place the result in, defaults to the first object if not supplied.
//
//Returns:
//
//  A void pointer to the object with the result.
#define MUL(...) GET_OPERATOR(__VA_ARGS__,mulOther,mulSelf)(__VA_ARGS__)
#define mulSelf(type,obj1,obj2) type##_t.operators.mul((void*)obj1,(void*)obj2,(void*)obj1,sizeof(type))
#define mulOther(type,obj1,obj2,obj3) type##_t.operators.mul((void*)obj1,(void*)obj2,(void*)obj3,sizeof(type))

//Macro: DIV
//--- Prototype ---
//DIV(type,obj1,obj2,obj3=obj1) 
//-----------------
//Div is a function-macro that, given a type and two preexisting objects, computes the division
//of those objects. The types of the objects are determined by the implementation of the
//underlying div function in the <ArithLogicOperators> struct. If different types than
//the ones expected by that function are supplied then undefined behavior will occur.
//
//The divider function is supplied by the given object type. This means that in order for
//this macro to work a function with the following signature must be defined
//in the types <ArithLogicOperators> struct.
//--- Code
//void* div(const void * const self, const void * const other, void *result, size_t size);
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <ArithLogicOperators> struct as a member 
//named "operators" in order for this macro expansion to work properly. The 
//<ArithLogicOperators> struct defines how operators operate on objects of <type>.
//An example of this is the <String_t> struct.
//
//Parameters:
//
//  type - The type of the two objects being compared.
//  obj1 - The first object.
//  obj2 - The second object.
//  obj3 - The object to place the result in, defaults to the first object if not supplied.
//
//Returns:
//
//  A void pointer to the object with the result.
#define DIV(...) GET_OPERATOR(__VA_ARGS__,divOther,divSelf)(__VA_ARGS__)
#define divSelf(type,obj1,obj2) type##_t.operators.div((void*)obj1,(void*)obj2,(void*)obj1,sizeof(type))
#define divOther(type,obj1,obj2,obj3) type##_t.operators.div((void*)obj1,(void*)obj2,(void*)obj3,sizeof(type))

//Macro: MOD
//--- Prototype ---
//MOD(type,obj1,obj2,obj3=obj1) 
//-----------------
//Mod is a function-macro that, given a type and two preexisting objects, computes the modulus
//of those objects. The types of the objects are determined by the implementation of the
//underlying mod function in the <ArithLogicOperators> struct. If different types than
//the ones expected by that function are supplied then undefined behavior will occur.
//
//The modulus function is supplied by the given object type. This means that in order for
//this macro to work a function with the following signature must be defined
//in the types <ArithLogicOperators> struct.
//--- Code
//void* mod(const void * const self, const void * const other, void *result, size_t size);
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <ArithLogicOperators> struct as a member 
//named "operators" in order for this macro expansion to work properly. The 
//<ArithLogicOperators> struct defines how operators operate on objects of <type>.
//An example of this is the <String_t> struct.
//
//Parameters:
//
//  type - The type of the two objects being compared.
//  obj1 - The first object.
//  obj2 - The second object.
//  obj3 - The object to place the result in, defaults to the first object if not supplied.
//
//Returns:
//
//  A void pointer to the object with the result.
#define MOD(...) GET_OPERATOR(__VA_ARGS__,modOther,modSelf)(__VA_ARGS__)
#define modSelf(type,obj1,obj2) type##_t.operators.mod((void*)obj1,(void*)obj2,(void*)obj1,sizeof(type))
#define modOther(type,obj1,obj2,obj3) type##_t.operators.mod((void*)obj1,(void*)obj2,(void*)obj3,sizeof(type))

//Macro: SLL
//--- Prototype ---
//SLL(type,obj1,obj2,obj3=obj1) 
//-----------------
//Sll is a function-macro that, given a type and two preexisting objects, computes the 
//logical shift left of those objects. The types of the objects are determined by the 
//implementation of the underlying sll function in the <ArithLogicOperators> struct. 
//If different types than the ones expected by that function are supplied then 
//undefined behavior will occur.
//
//The logical shift left function is supplied by the given object type. This means
//that in order for this macro to work a function with the following signature 
//must be defined in the types <ArithLogicOperators> struct.
//--- Code
//void* sll(const void * const self, const void * const other, void *result, size_t size);
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <ArithLogicOperators> struct as a member 
//named "operators" in order for this macro expansion to work properly. The 
//<ArithLogicOperators> struct defines how operators operate on objects of <type>.
//An example of this is the <String_t> struct.
//
//Parameters:
//
//  type - The type of the two objects being compared.
//  obj1 - The first object.
//  obj2 - The second object.
//  obj3 - The object to place the result in, defaults to the first object if not supplied.
//
//Returns:
//
//  A void pointer to the object with the result.
#define SLL(...) GET_OPERATOR(__VA_ARGS__,sllOther,sllSelf)(__VA_ARGS__)
#define sllSelf(type,obj1,obj2) type##_t.operators.sll((void*)obj1,(void*)obj2,(void*)obj1,sizeof(type))
#define sllOther(type,obj1,obj2,obj3) type##_t.operators.sll((void*)obj1,(void*)obj2,(void*)obj3,sizeof(type))

//Macro: SRL
//--- Prototype ---
//SRL(type,obj1,obj2,obj3=obj1) 
//-----------------
//Srl is a function-macro that, given a type and two preexisting objects, computes the 
//logical shift right of those objects. The types of the objects are determined by the 
//implementation of the underlying srl function in the <ArithLogicOperators> struct. 
//If different types than the ones expected by that function are supplied then 
//undefined behavior will occur.
//
//The logical shift right function is supplied by the given object type. This means
//that in order for this macro to work a function with the following signature 
//must be defined in the types <ArithLogicOperators> struct.
//--- Code
//void* srl(const void * const self, const void * const other, void *result, size_t size);
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <ArithLogicOperators> struct as a member 
//named "operators" in order for this macro expansion to work properly. The 
//<ArithLogicOperators> struct defines how operators operate on objects of <type>.
//An example of this is the <String_t> struct.
//
//Parameters:
//
//  type - The type of the two objects being compared.
//  obj1 - The first object.
//  obj2 - The second object.
//  obj3 - The object to place the result in, defaults to the first object if not supplied.
//
//Returns:
//
//  A void pointer to the object with the result.
#define SRL(...) GET_OPERATOR(__VA_ARGS__,srlOther,srlSelf)(__VA_ARGS__)
#define srlSelf(type,obj1,obj2) type##_t.operators.srl((void*)obj1,(void*)obj2,(void*)obj1,sizeof(type))
#define srlOther(type,obj1,obj2,obj3) type##_t.operators.srl((void*)obj1,(void*)obj2,(void*)obj3,sizeof(type))

//Macro: AND
//--- Prototype ---
//AND(type,obj1,obj2,obj3=obj1) 
//-----------------
//And is a function-macro that, given a type and two preexisting objects, computes the 
//logical and of those objects. The types of the objects are determined by the 
//implementation of the underlying and function in the <ArithLogicOperators> struct. 
//If different types than the ones expected by that function are supplied then 
//undefined behavior will occur.
//
//The logical and function is supplied by the given object type. This means
//that in order for this macro to work a function with the following signature 
//must be defined in the types <ArithLogicOperators> struct.
//--- Code
//void* and(const void * const self, const void * const other, void *result, size_t size);
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <ArithLogicOperators> struct as a member 
//named "operators" in order for this macro expansion to work properly. The 
//<ArithLogicOperators> struct defines how operators operate on objects of <type>.
//An example of this is the <String_t> struct.
//
//Parameters:
//
//  type - The type of the two objects being compared.
//  obj1 - The first object.
//  obj2 - The second object.
//  obj3 - The object to place the result in, defaults to the first object if not supplied.
//
//Returns:
//
//  A void pointer to the object with the result.
#define AND(...) GET_OPERATOR(__VA_ARGS__,andOther,andSelf)(__VA_ARGS__)
#define andSelf(type,obj1,obj2) type##_t.operators.and((void*)obj1,(void*)obj2,(void*)obj1,sizeof(type))
#define andOther(type,obj1,obj2,obj3) type##_t.operators.and((void*)obj1,(void*)obj2,(void*)obj3,sizeof(type))

//Macro: OR
//--- Prototype ---
//OR(type,obj1,obj2,obj3=obj1) 
//-----------------
//Or is a function-macro that, given a type and two preexisting objects, computes the 
//logical or of those objects. The types of the objects are determined by the 
//implementation of the underlying or function in the <ArithLogicOperators> struct. 
//If different types than the ones expected by that function are supplied then 
//undefined behavior will occur.
//
//The logical and function is supplied by the given object type. This means
//that in order for this macro to work a function with the following signature 
//must be defined in the types <ArithLogicOperators> struct.
//--- Code
//void* or(const void * const self, const void * const other, void *result, size_t size);
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <ArithLogicOperators> struct as a member 
//named "operators" in order for this macro expansion to work properly. The 
//<ArithLogicOperators> struct defines how operators operate on objects of <type>.
//An example of this is the <String_t> struct.
//
//Parameters:
//
//  type - The type of the two objects being compared.
//  obj1 - The first object.
//  obj2 - The second object.
//  obj3 - The object to place the result in, defaults to the first object if not supplied.
//
//Returns:
//
//  A void pointer to the object with the result.
#define OR(...) GET_OPERATOR(__VA_ARGS__,orOther,orSelf)(__VA_ARGS__)
#define orSelf(type,obj1,obj2) type##_t.operators.or((void*)obj1,(void*)obj2,(void*)obj1,sizeof(type))
#define orOther(type,obj1,obj2,obj3) type##_t.operators.or((void*)obj1,(void*)obj2,(void*)obj3,sizeof(type))

//Macro: NOT
//--- Prototype ---
//NOT(type,obj1,obj2=obj1) 
//-----------------
//Not is a function-macro that, given a type and two preexisting objects, computes the 
//logical not of those objects. The types of the objects are determined by the 
//implementation of the underlying not function in the <ArithLogicOperators> struct. 
//If different types than the ones expected by that function are supplied then 
//undefined behavior will occur.
//
//The logical and function is supplied by the given object type. This means
//that in order for this macro to work a function with the following signature 
//must be defined in the types <ArithLogicOperators> struct. The <NOT> macro will
//always set the other pointer to NULL.
//--- Code
//void* not(const void * const self, const void * const other, void *result, size_t size);
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <ArithLogicOperators> struct as a member 
//named "operators" in order for this macro expansion to work properly. The 
//<ArithLogicOperators> struct defines how operators operate on objects of <type>.
//An example of this is the <String_t> struct.
//
//Parameters:
//
//  type - The type of the two objects being compared.
//  obj1 - The object to take the not of.
//  obj2 - The object to place the result in, defaults to the first object if not supplied.
//
//Returns:
//
//  A void pointer to the object with the result.
#define NOT(...) GET_NOT_OPERATOR(__VA_ARGS__,notOther,notSelf)(__VA_ARGS__)
#define notSelf(type,obj) type##_t.operators.not((void*)obj,NULL,(void*)obj,sizeof(type));
#define notOther(type,obj1,obj2) type##_t.operators.not((void*)obj1,NULL,(void*)obj2,sizeof(type));

//Struct: ArithLogicOperators
//The struct that defines various operator operations related to objects.
//Each struct of <type>_t needs to have a ArithLogicOperators struct named "operators" for the above macros to work.
typedef struct ArithLogicOperators {
	//Function: add
	//Adds two objects.
	//
	//Parameters:
	//
	//  self - the first object to add
	//  other - the second object to add
	//  result - the object to store the result in
	//  size - the size of the objects being operated on
	//
	//Returns:
	//
	//  A void pointer to the result object
	void* (*add)(const void * const self, const void * const other, void *result, size_t size);
	//Function: sub
	//Subtracts two objects.
	//
	//Parameters:
	//
	//  self - the first object to subtract
	//  other - the second object to subtract
	//  result - the object to store the result in
	//  size - the size of the objects being operated on
	//
	//Returns:
	//
	//  A void pointer to the result object
	void* (*sub)(const void * const self, const void * const other, void *result, size_t size);
	//Function: mul
	//Multiplies two objects.
	//
	//Parameters:
	//
	//  self - the first object to multiply
	//  other - the second object to multiply
	//  result - the object to store the result in
	//  size - the size of the objects being operated on
	//
	//Returns:
	//
	//  A void pointer to the result object
	void* (*mul)(const void * const self, const void * const other, void *result, size_t size);
	//Function: div
	//Divides two objects.
	//
	//Parameters:
	//
	//  self - the first object to divide
	//  other - the second object to divide
	//  result - the object to store the result in
	//  size - the size of the objects being operated on
	//
	//Returns:
	//
	//  A void pointer to the result object
	void* (*div)(const void * const self, const void * const other, void *result, size_t size);
	//Function: mod
	//Computes the modulus two objects.
	//
	//Parameters:
	//
	//  self - the first object to take the modulus of
	//  other - the second object to take the modulus of
	//  result - the object to store the result in
	//  size - the size of the objects being operated on
	//
	//Returns:
	//
	//  A void pointer to the result object
	void* (*mod)(const void * const self, const void * const other, void *result, size_t size);
	//Function: sll
	//Computes the logical shift left of two objects.
	//
	//Parameters:
	//
	//  self - the first object to take the logical shift left of
	//  other - the second object to take the logical shift left of
	//  result - the object to store the result in
	//  size - the size of the objects being operated on
	//
	//Returns:
	//
	//  A void pointer to the result object
	void* (*sll)(const void * const self, const void * const other, void *result, size_t size);
	//Function: srl
	//Computes the logical shift right of two objects.
	//
	//Parameters:
	//
	//  self - the first object to take the logical shift right of
	//  other - the second object to take the logical shift right of
	//  result - the object to store the result in
	//  size - the size of the objects being operated on
	//
	//Returns:
	//
	//  A void pointer to the result object
	void* (*srl)(const void * const self, const void * const other, void *result, size_t size);
	//Function: and
	//Computes the logical and of two objects.
	//
	//Parameters:
	//
	//  self - the first object to take the logical and of
	//  other - the second object to take the logical and of
	//  result - the object to store the result in
	//  size - the size of the objects being operated on
	//
	//Returns:
	//
	//  A void pointer to the result object
	void* (*and)(const void * const self, const void * const other, void *result, size_t size);
	//Function: or
	//Computes the logical or of two objects.
	//
	//Parameters:
	//
	//  self - the first object to take the logical or of
	//  other - the second object to take the logical or of
	//  result - the object to store the result in
	//  size - the size of the objects being operated on
	//
	//Returns:
	//
	//  A void pointer to the result object
	void* (*or)(const void * const self, const void * const other, void *result, size_t size);
	//Function: not
	//Computes the logical not of an object.
	//
	//Parameters:
	//
	//  self - the first object to take the logical not of
	//  other - the second object to take the logical or of, NULL most of the time
	//  result - the object to store the result in
	//  size - the size of the objects being operated on
	//
	//Returns:
	//
	//  A void pointer to the result object
	void* (*not)(const void * const self, const void * const other, void *result, size_t size);
} ArithLogicOperators;

//Macro: EQ
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
#define EQ(type,obj1,obj2) type##_t.comparisonOperators.eqOperator((void*)obj1,(void*)obj2,sizeof(type))

//#define eqFromOperator(operators,obj1,obj2) (operators).eqOperator((void*)obj1,(void*)obj2,sizeof(type))

//Macro: NEQ
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
#define NEQ(type,obj1,obj2) type##_t.comparisonOperators.neqOperator((void*)obj1,(void*)obj2,sizeof(type))

//Macro: GT
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
#define GT(type,obj1,obj2) type##_t.comparisonOperators.gtOperator((void*)obj1,(void*)obj2,sizeof(type))

//Macro: LT
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
#define LT(type,obj1,obj2) type##_t.comparisonOperators.ltOperator((void*)obj1,(void*)obj2,sizeof(type))

//Macro: GTE
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
#define GTE(type,obj1,obj2) type##_t.comparisonOperators.gteOperator((void*)obj1,(void*)obj2,sizeof(type))

//Macro: LTE
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
#define LTE(type,obj1,obj2) type##_t.comparisonOperators.lteOperator((void*)obj1,(void*)obj2,sizeof(type))

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
