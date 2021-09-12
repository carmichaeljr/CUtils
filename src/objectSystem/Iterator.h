#ifndef ITERATOR_FRAMEWORK
#define ITERATOR_FRAMEWORK

#define GET_NEXT_MACRO(one,two,three,NAME,...) NAME
#define GET_PREVIOUS_MACRO(one,two,three,NAME,...) NAME
#define GET_END_MACRO(one,two,three,NAME,...) NAME

//Macro: iterBegin
//--- Prototype ---
//iterBegin(type,iterObj,collectionObj)
//-----------------
//
//This is a function-macro that, given a collection type and collection object,
//creates the appropriate iterator that represents the first object in the iteration
//sequence.
//
//The begin method is supplied by the given object type. This means that in order for
//this macro to work a function with the following signature must be defined
//in the types <Iterator> struct.
//--- Code
//void* begin(void *iterator, void * collectionObj);
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <Iterator> struct as a member named "iterator" in order
//for this macro expansion to work properly. The <Iterator> struct defines how methods that determine
//how the collection will be iterated over. An example of this is the <String_t> struct.
//
//Parameters:
//
//  type - The type of collection object to iterate over.
//  iterObj - A pointer to the iterator object to initialize.
//  collectionObj - A pointer to the collection object to iterate over.
//
//Returns:
//
//  A pointer to the iterator object.
#define iterBegin(type,iterObj,collectionObj) type##Iterator_t.iterator.begin(iterObj,collectionObj)

//Macro: iterNext
//--- Prototype ---
//iterNext(type,iterObj,num=1)
//-----------------
//
//This is a function-macro that, given a collection type, collection object, and iterator object,
//advances the given iterator to represent the next element in the iteration sequence.
//This macro is overloaded with a default parameter.
//
//The increment method is supplied by the given object type. This means that in order for
//this macro to work a function with the following signature must be defined
//in the types <Iterator> struct.
//--- Code
//void* increment(void *iterator, const int num);
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <Iterator> struct as a member named "iterator" in order
//for this macro expansion to work properly. The <Iterator> struct defines how methods that determine
//how the collection will be iterated over. An example of this is the <String_t> struct.
//
//Parameters:
//
//  type - The type of collection object to iterate over.
//  iterObj - A pointer to the iterator object to increment.
//  num - The number of elements forward to go.
//
//Returns:
//
//  A pointer to the iterator object.
#define iterNext(...) GET_NEXT_MACRO(\
		__VA_ARGS__,\
		nextVar,\
		nextOne)(__VA_ARGS__)
#define nextOne(type,iterObj)\
	type##Iterator_t.iterator.increment(iterObj,1)
#define nextVar(type,iterObj,num)\
	type##Iterator_t.iterator.increment(iterObj,num)

//Macro: iterPrev
//--- Prototype ---
//iterPrev(type,iterObj,num=1)
//-----------------
//
//This is a function-macro that, given a collection type,collection object, and iterator object,
//regresses the given iterator to represent the previous element in the iteration sequence.
//This macro is overloaded with a default parameter.
//
//The dincrement method is supplied by the given object type. This means that in order for
//this macro to work a function with the following signature must be defined
//in the types <Iterator> struct.
//--- Code
//void* dincrement(void *iterator, const int num);
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <Iterator> struct as a member named "iterator" in order
//for this macro expansion to work properly. The <Iterator> struct defines how methods that determine
//how the collection will be iterated over. An example of this is the <String_t> struct.
//
//Parameters:
//
//  type - The type of collection object to iterate over.
//  iterObj - A pointer to the iterator object to increment.
//  num - The number of elements backward to go.
//
//Returns:
//
//  A pointer to the iterator object.
#define iterPrev(...) GET_PREVIOUS_MACRO(\
		__VA_ARGS__,\
		previousVar,\
		previousOne)(__VA_ARGS__)
#define previousOne(type,iterObj)\
	type##Iterator_t.iterator.dincrement(iterObj,1)
#define previousVar(type,iterObj,num)\
	type##Iterator_t.iterator.dincrement(iterObj,num)

//Macro: iterEnd
//--- Prototype ---
//iterEnd(type,iterObj,collectionObj)
//-----------------
//
//This is a function-macro that, given a collection type and collection object,
//creates the appropriate iterator that represents the last object in the iteration
//sequence.
//
//The end method is supplied by the given object type. This means that in order for
//this macro to work a function with the following signature must be defined
//in the types <Iterator> struct.
//--- Code
//void* end(void *iterator, void *collectionObj);
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <Iterator> struct as a member named "iterator" in order
//for this macro expansion to work properly. The <Iterator> struct defines how methods that determine
//how the collection will be iterated over. An example of this is the <String_t> struct.
//
//Parameters:
//
//  type - The type of collection object to iterate over.
//  iterObj - A pointer to the iterator to initialize.
//  collectionObj - A pointer to the collection object to iterate over.
//
//Returns:
//
//  A pointer to the iterator object.
#define iterEnd(type,iterObj,collectionObj) type##Iterator_t.iterator.end(iterObj,collectionObj)

//Macro: iterVal
//--- Prototype ---
//iterVal(type,iterObj)
//-----------------
//
//This is a function-macro that, given a collection type, collection object, and iterator object,
//returns a void pointer to the element the iterator is currently at in the iteration sequence.
//
//The getVal method is supplied by the given object type. This means that in order for
//this macro to work a function with the following signature must be defined
//in the types <Iterator> struct.
//--- Code
//void* getVal(const void * const iterator);
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the struct of <type>_t must contain a <Iterator> struct as a member named "iterator" in order
//for this macro expansion to work properly. The <Iterator> struct defines how methods that determine
//how the collection will be iterated over. An example of this is the <String_t> struct.
//
//Parameters:
//
//  type - The type of collection object to iterate over.
//  iterObj - A pointer to the iterator object to increment.
//
//Returns:
//
//  A void pointer to the element that the iterator is currently at.
#define iterVal(type,iterObj) type##Iterator_t.iterator.getVal(iterObj)

//Macro: forEach
//--- Prototype ---
//forEach(type,subType,collectionObj,loopCode)
//-----------------
//
//forEach is a function-macro that, given a collection type, the type of the items in
//the collection, a collection object, and code to perform on each element, will loop
//through the collection using iterators and run the supplied code on every element.
//
//The current element is stored in a variable of type subType called "at".
//
//Iterators are allocated on the stack and are appropriately deleted.
//
//Calls to forEach *cannot* be nested due to the macro expansion creating duplicate
//variables.
//
//The underlying methods are supplied by the given object type. This means that in order for
//this macro to work functions with the following signature must be defined
//in the types <Iterator> struct.
//--- Code
//void* begin(const void * const obj, void *iterator);
//void increment(const void * const obj, void *iterator, const int num);
//void dincrement(const void * const obj, void *iterator, const int num);
//void* end(const void * const obj, void *iterator);
//void* getVal(const void * const obj, const void * const iterator);
//---
//Note that the naming convention of <type> for objects of class <type>_t must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the class associated with that object
//is a <String_t> struct.
//
//Note that the naming convention of <type>Iterator for objects <type> must be
//followed in order for this macro expansion to work properly. An example of this naming convention
//is a string. The object is a <String> struct and the iterator object associated it is 
//a <StringIterator> struct.
//
//Note that the struct of <type>_t must contain a <Iterator> struct as a member named "iterator" in order
//for this macro expansion to work properly. The <Iterator> struct defines how methods that determine
//how the collection will be iterated over. An example of this is the <String_t> struct.
#define forEach(type,subType,collectionObj,loopCode)\
	type##Iterator iter=newS(type##Iterator,iter)\
	type##Iterator end=newS(type##Iterator,end)\
	iterBegin(type,&iter,collectionObj);\
	iterEnd(type,&end,collectionObj);\
	for ( ; equals(type##Iterator,&iter,&end)<0; iterNext(type,&iter)){\
		subType *at=(subType*)iterVal(type,&iter);\
		loopCode;\
	}\
	deleteS(type##Iterator,iter);\
	deleteS(type##Iterator,end);
//Idea?
//#define forEachTransform(class,func,obj,__VA_ARGS__) class##_t.func##ForEach(obj,__VA_ARGS__)

//Macro: DEFAULT_ITERATOR
//--- Prototype
//DEFAULT_ITERATOR {
//	.begin=begin,
//	.increment=increment,
//	.dincrement=dincrement,
//	.end=end,
//	.getVal=getVal,
//}
//---
//DEFAULT_ITERATOR is a macro that defines class functions to support iteration over
//data structures. 
//
//The functions not supplied need to be defined in the source file that the DEFAULT_ITERATOR
//macro expands in, and are assumed to have the following signatures and names:
//
//--- Code
//void* begin(void);
//void next(void);
//void previous(void);
//void* end(void);
//void* getVal(const void * const iterObj);
//---
#define DEFAULT_ITERATOR {\
	.begin=begin,\
	.increment=increment,\
	.dincrement=dincrement,\
	.end=end,\
	.getVal=getVal,\
}

//Struct: Iterator
//The struct that defines various operations related to iteration over collections.
//Each struct of <type>_t needs to have a Iterator struct named "iterator" for the above macros to work.
typedef struct Iterator {
	//Function: begin
	//Responsible to returning an initialized iterator to the first element of the collection.
	//
	//If iterator is NULL then a new iterator object will be allocated on the heap. If iterator
	//is not null then it is treated as a pointer to memory preallocated for an iterator object.
	//
	//Parameters:
	//
	//  obj - The collection object that is being iterated.
	//  iterator - A pointer to memory preallocated for an iterator, or NULL.
	//
	//Returns:
	//
	//  A pointer to the iterator that is initialized to the first element of the given collection.
	void* (*begin)(void *self, void *collectionObj);
	//Function: increment
	//Responsible for advancing the iterator forward by the given number of elements.
	//
	//Parameters:
	//
	//  obj - The collection object that is being iterated.
	//  iterator - The iterator object to be updated.
	//  num - The number of elements to move forward by.
	//
	//Returns:
	//
	//  Nothing.
	void* (*increment)(void *self, const int num);
	//Function: increment
	//Responsible for advancing the iterator backward by the given number of elements.
	//
	//Parameters:
	//
	//  obj - The collection object that is being iterated.
	//  iterator - The iterator object to be updated.
	//  num - The number of elements to move backward by.
	//
	//Returns:
	//
	//  Nothing.
	void* (*dincrement)(void *self, const int num);
	//Function: end
	//Responsible to returning an initialized iterator to the last element of the collection.
	//
	//If iterator is NULL then a new iterator object will be allocated on the heap. If iterator
	//is not null then it is treated as a pointer to memory preallocated for an iterator object.
	//
	//Parameters:
	//
	//  obj - The collection object that is being iterated.
	//  iterator - A pointer to memory preallocated for an iterator, or NULL.
	//
	//Returns:
	//
	//  A pointer to the iterator that is initialized to the last element of the given collection.
	void* (*end)(void *self, void *collectionObj);
	//Function: getVal
	//Returns a void pointer to the value of the element at the iterators location.
	//
	//Parameters:
	//
	//  obj - The collection object that is being iterated.
	//  iterator - The iterator representing the current value.
	//
	//Returns:
	//
	//  A void pointer to the value of the element at the iterators location.
	void* (*getVal)(const void * const self);
} Iterator;

#endif
