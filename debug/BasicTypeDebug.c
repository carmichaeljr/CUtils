#include "Debug.h"
#include "../src/Object.h"
#include "../src/Print.h"

#define basicTypeTest(result) test(result,"BasicType",__FUNCTION__,__LINE__)

static void basicTypeChar(void);
static void basicTypeShort(void);
static void basicTypeInt(void);
static void basicTypeUnsigned(void);
static void basicTypeLong(void);
static void basicTypeFloat(void);
static void basicTypeDouble(void);
#ifdef CUSTOM_PRE_PROC_ENABLED
static void basicTypeUnsignedInt(void);
#endif

void basicTypesDebug(void){
	basicTypeChar();
	basicTypeShort();
	basicTypeInt();
	basicTypeUnsigned();
	basicTypeLong();
	basicTypeFloat();
	basicTypeDouble();
#if CUSTOM_PRE_PROC_ENABLED
	basicTypeUnsignedInt();
#endif
}

static void basicTypeChar(void){
	char temp='h';
	char *test=new(char);
	int_t.set(test,&temp,sizeof(char));
	basicTypeTest(*test=='h');
	delete(char,test);
	basicTypeTest(temp=='h');
}

static void basicTypeShort(void){
	short temp=5;
	short *test=new(short);
	int_t.set(test,&temp,sizeof(short));
	basicTypeTest(*test==5);
	delete(short,test);
	basicTypeTest(temp==5);
}

static void basicTypeInt(void){
	int temp=5;
	int *test=new(int);
	int_t.set(test,&temp,sizeof(int));
	basicTypeTest(*test==5);
	delete(int,test);
	basicTypeTest(temp==5);
}

static void basicTypeUnsigned(void){
	unsigned temp=5;
	unsigned *test=new(unsigned);
	int_t.set(test,&temp,sizeof(unsigned));
	basicTypeTest(*test==5);
	delete(unsigned,test);
	basicTypeTest(temp==5);
}

static void basicTypeLong(void){
	long temp=5;
	long *test=new(long);
	int_t.set(test,&temp,sizeof(long));
	basicTypeTest(*test==5);
	delete(long,test);
	basicTypeTest(temp==5);

}

static void basicTypeFloat(void){
	float temp=5;
	float *test=new(float);
	int_t.set(test,&temp,sizeof(float));
	basicTypeTest(*test==5);
	delete(float,test);
	basicTypeTest(temp==5);
}

static void basicTypeDouble(void){
	double temp=5;
	double *test=new(double);
	int_t.set(test,&temp,sizeof(double));
	basicTypeTest(*test==5);
	delete(double,test);
	basicTypeTest(temp==5);
}

#ifdef CUSTOM_PRE_PROC_ENABLED
static void basicTypeUnsignedInt(void){
	unsigned int temp='h';
	unsigned int *test=new(unsigned int);
	unsigned_int_t.set(test,&temp,sizeof(unsigned int));
	basicTypeTest(*test=='h');
	delete(unsigned int,test);
	basicTypeTest(temp=='h');
}
#endif
