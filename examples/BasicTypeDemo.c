#include "../src/objectSystem/Object.h"
#include "../src/objectSystem/Operator.h"
#include "../src/objectSystem/BasicType.h"
#include "../src/IO/Print.h"

int main(int argc, char **argv){
	//All basic types are fully supported in the object system.
	//Below shows two equivalent ways to create an int object on the stack.
	int a=1;
	int b=newS(int,b);
	b=1;
	Print_t.println("a: %d b: %d, equal? %s",a,b,(a==b)? "Yep": "Nope");
	//Basic types can be deleted just like objects, just nothing will happen
	deleteS(int,b);

	//Below shows two equivalent ways to create a char object on the heap.
	char *c=malloc(sizeof(char));
	if (c!=NULL){
		*c='h';
	}
	char *d=new(char);
	*d='h';
	Print_t.println("c: %c d: %c, equal? %s",*c,*d,(*c==*d)? "Yep": "Nope");
	//Don't forget to delete any objects on the heap.
	delete(char,c);	//Note how both ways can interoperate
	delete(char,d);

	//If you already have memory allocated for the object, just pass the pointer
	//to the already alloc'ed memory location to new. Note that the basic type 
	//constructor *does not* initialize the memory location.
	int *alsoOne=new(int,&a);
	Print_t.println("a: %d alsoOne: %d, equal? %s",a,*alsoOne,(a==*alsoOne)? "Yep": "Nope");

#ifdef CUSTOM_PRE_PROC_ENABLED
	//If the custom preprocessor is enabled basic types with spaces in there
	//names are also permitted.
	//Make sure you always check if the CUSTOM_PRE_PROC_ENABLED macro is defined.
	long long *e=new(long long);
	*e=285212672;
	Print_t.println("e: %llu",*e);
#endif
	
	//The operators for basic types are all also fully defined and perform the
	//same operations you would expect them to. Some are shown below as an example.
	int addResult=0, subResult=0, mulResult=0, divResult=0, andResult=0;
	ADD(int,&a,&b,&addResult);
	SUB(int,&a,&b,&subResult);
	MUL(int,&a,&b,&mulResult);
	DIV(int,&a,&b,&divResult);
	AND(int,&a,&b,&andResult);
	Print_t.println("a+b: %d Result: %d",a+b,addResult);
	Print_t.println("a-b: %d Result: %d",a-b,subResult);
	Print_t.println("a*b: %d Result: %d",a*b,mulResult);
	Print_t.println("a/b: %d Result: %d",a/b,divResult);
	Print_t.println("a&b: %d Result: %d",a&b,andResult);

	//To save the result in one of the operators, just omit the result variable.
	//The result will be saved in the first operator.
	int f=5;
	ADD(int,&f,&a);
	Print_t.println("f: %d",f);

	//The comparison operators are all also fully defined. Some are shown below.
	bool eq=false, neq=false, gt=false, lt=false;
	eq=EQ(int,&a,&b);
	neq=NEQ(int,&a,&b);
	gt=GT(int,&a,&b);
	lt=LT(int,&a,&b);
	Print_t.println("a==b: %s Result: %s",(a==b)? "True": "False",(eq)? "True": "False");
	Print_t.println("a!=b: %s Result: %s",(a!=b)? "True": "False",(neq)? "True": "False");
	Print_t.println("a>b: %s Result: %s",(a>b)? "True": "False",(gt)? "True": "False");
	Print_t.println("a<b: %s Result: %s",(a<b)? "True": "False",(lt)? "True": "False");
}
