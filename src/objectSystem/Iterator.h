#ifndef ITERATOR_FRAMEWORK
#define ITERATOR_FRAMEWORK

#define GET_BEGIN_MACRO(one,two,three,NAME,...) NAME
#define GET_NEXT_MACRO(one,two,three,four,NAME,...) NAME
#define GET_PREVIOUS_MACRO(one,two,three,four,NAME,...) NAME
#define GET_END_MACRO(one,two,three,NAME,...) NAME

//Macro: iterBegin
//--- Prototype ---
//iterBegin(type,collectionObj,iterObj=NULL)
//-----------------
//
//This is a function-macro that, given a collection type and collection object,
//creates the appropriate iterator that represents the first object in the iteration
//sequence.
//This macro is overloaded with a default parameter.
//If iterObj is NULL then memory will be allocated for the new object. If obj is not NULL
//then obj is treated as a pointer to memory already allocated for the new object.
//
//The begin method is supplied by the given object type. This means that in order for
//this macro to work a function with the following signature must be defined
//in the types <Iterator> struct.
//--- Code
//void* begin(const void * const obj, void *iterator);
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
//  collectionObj - A pointer to the collection object to iterate over.
//  iterObj - A pointer to already reserved memory to initialize the object with.
//
//Returns:
//
//  A pointer to the iterator object.
#define iterBegin(...) GET_BEGIN_MACRO(\
		__VA_ARGS__,\
		beginNoAlloc,\
		beginAlloc)(__VA_ARGS__)
#define beginAlloc(type,collectionObj) type##_t.iterator.begin(collectionObj,NULL)
#define beginNoAlloc(type,collectionObj,iterObj)\
	type##_t.iterator.begin(collectionObj,iterObj)

//Macro: iterNext
//--- Prototype ---
//iterNext(type,collectionObj,iterObj,num=1)
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
//void increment(const void * const obj, void *iterator, const int num);
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
//  collectionObj - A pointer to the collection object to iterate over.
//  iterObj - A pointer to the iterator object to increment.
//  num - The number of elements forward to go.
//
//Returns:
//
//  Nothing.
#define iterNext(...) GET_NEXT_MACRO(\
		__VA_ARGS__,\
		nextVar,\
		nextOne)(__VA_ARGS__)
#define nextOne(type,collectionObj,iterObj)\
	type##_t.iterator.increment(collectionObj,iterObj,1)
#define nextVar(type,collectionObj,iterObj,num)\
	type##_t.iterator.increment(collectionObj,iterObj,num)

//Macro: iterPrev
//--- Prototype ---
//iterPrev(type,collectionObj,iterObj,num=1)
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
//void dincrement(const void * const obj, void *iterator, const int num);
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
//  collectionObj - A pointer to the collection object to iterate over.
//  iterObj - A pointer to the iterator object to increment.
//  num - The number of elements backward to go.
//
//Returns:
//
//  Nothing
#define iterPrev(...) GET_PREVIOUS_MACRO(\
		__VA_ARGS__,\
		previousVar,\
		previousOne)(__VA_ARGS__)
#define previousOne(type,collectionObj,iterObj)\
	type##_t.iterator.dincrement(collectionObj,iterObj,1)
#define previousVar(type,collectionObj,iterObj,num)\
	type##_t.iterator.dincrement(collectionObj,iterObj,num)


#define iterEnd(...) GET_END_MACRO(\
		__VA_ARGS__,\
		endNoAlloc,\
		endAlloc)(__VA_ARGS__)
#define endAlloc(type,collectionObj) type##_t.iterator.end(collectionObj,NULL)
#define endNoAlloc(type,collectionObj,iterObj)\
	type##_t.iterator.end(collectionObj,iterObj)

//Macro: iterVal
//--- Prototype ---
//iterVal(type,collectionObj,iterObj)
//-----------------
//
//This is a function-macro that, given a collection type, collection object, and iterator object,
//returns a void pointer to the element the iterator is currently at in the iteration sequence.
//
//The getVal method is supplied by the given object type. This means that in order for
//this macro to work a function with the following signature must be defined
//in the types <Iterator> struct.
//--- Code
//void* getVal(const void * const obj, const void * const iterator);
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
//  collectionObj - A pointer to the collection object to iterate over.
//  iterObj - A pointer to the iterator object to increment.
//
//Returns:
//
//  A void pointer to the element that the iterator is currently at.
#define iterVal(type,collectionObj,iterObj) type##_t.iterator.getVal(collectionObj,iterObj)

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
	type##Iterator iter,end;\
	new(type##Iterator,&iter);\
	new(type##Iterator,&end);\
	iterBegin(type,list,&iter);\
	iterEnd(type,list,&end);\
	for ( ; equals(type##Iterator,&iter,&end)<0; iterNext(type,collectionObj,&iter)){\
		subType *at=(subType*)iterVal(type,collectionObj,&iter);\
		loopCode;\
	}\
	delete(type##Iterator,&iter,false);\
	delete(type##Iterator,&end,false)
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
	void* (*begin)(const void * const obj, void *iterator);
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
	void (*increment)(const void * const obj, void *iterator, const int num);
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
	void (*dincrement)(const void * const obj, void *iterator, const int num);
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
	void* (*end)(const void * const obj, void *iterator);
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
	void* (*getVal)(const void * const obj, const void * const iterator);
} Iterator;

#endif
