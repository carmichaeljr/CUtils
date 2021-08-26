#ifndef %CLASS_NAME%_CLASS
#define %CLASS_NAME%_CLASS

//TODO - verify that the include path is correct
#include "../objectSystem/Object.h"

//Class: %CLASS_NAME%
// TODO - Add description here
//
//General usage is as follows:
//--- Code
//%CLASS_NAME% *obj=new(%CLASS_NAME%);
//%CLASS_NAME%_t.<func to call>(obj, <params>);
//...
//delete(%CLASS_NAME%,obj);
//---
//
//See Also:
//
//  <%CLASS_NAME%_t>
typedef struct %CLASS_NAME% {
	//TODO - add attributes here
} %CLASS_NAME%;

//Class: %CLASS_NAME%_t
//The struct that creates and performs operations on objects of type %CLASS_NAME%.
//
//See Also:
//
//  <%CLASS_NAME%>
extern const struct %CLASS_NAME%_t {
	Class class;
	//TODO - add methods here
} %CLASS_NAME%_t;

#endif
