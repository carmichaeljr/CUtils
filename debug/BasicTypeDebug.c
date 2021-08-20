#include "Debug.h"
#include "../src/objectSystem/Object.h"
#include "../src/IO/Print.h"

#define basicTypeTest(result) test(result,"BasicType",__FUNCTION__,__LINE__)

static void basicTypeChar(void);
static void basicTypeShort(void);
static void basicTypeInt(void);
static void basicTypeUnsigned(void);
static void basicTypeLong(void);
static void basicTypeFloat(void);
static void basicTypeDouble(void);
#ifdef CUSTOM_PRE_PROC_ENABLED
static void basicTypeSignedChar(void);
static void basicTypeUnsignedChar(void);
static void basicTypeShortInt(void);
static void basicTypeSignedShortInt(void);
static void basicTypeUnsignedShort(void);
static void basicTypeUnsignedShortInt(void);
static void basicTypeSignedInt(void);
static void basicTypeUnsignedInt(void);
static void basicTypeLongInt(void);
static void basicTypeSignedLong(void);
static void basicTypeSignedLongInt(void);
static void basicTypeUnsignedLong(void);
static void basicTypeUnsignedLongInt(void);
static void basicTypeLongLong(void);
static void basicTypeLongLongInt(void);
static void basicTypeSignedLongLong(void);
static void basicTypeSignedLongLongInt(void);
static void basicTypeUnsignedLongLong(void);
static void basicTypeUnsignedLongLongInt(void);
static void basicTypeLongDouble(void);
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
	basicTypeSignedChar();
	basicTypeUnsignedChar();
	basicTypeShortInt();
	basicTypeSignedShortInt();
	basicTypeUnsignedShort();
	basicTypeUnsignedShortInt();
	basicTypeSignedInt();
	basicTypeUnsignedInt();
	basicTypeLongInt();
	basicTypeSignedLong();
	basicTypeSignedLongInt();
	basicTypeUnsignedLong();
	basicTypeUnsignedLongInt();
	basicTypeLongLong();
	basicTypeLongLongInt();
	basicTypeSignedLongLong();
	basicTypeSignedLongLongInt();
	basicTypeUnsignedLongLong();
	basicTypeUnsignedLongLongInt();
	basicTypeLongDouble();
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
static void basicTypeSignedChar(void){
	signed char temp='h';
	signed char *test=new(signed char);
	signed_char_t.set(test,&temp,sizeof(signed char));
	basicTypeTest(*test=='h');
	delete(signed char, test);
	basicTypeTest(temp=='h');
}

static void basicTypeUnsignedChar(void){
	unsigned char temp='h';
	unsigned char *test=new(unsigned char);
	unsigned_char_t.set(test,&temp,sizeof(unsigned char));
	basicTypeTest(*test=='h');
	delete(unsigned char,test);
	basicTypeTest(temp=='h');
}

static void basicTypeShortInt(void){
	short int temp=5;
	short int *test=new(short int);
	short_int_t.set(test,&temp,sizeof(short int));
	basicTypeTest(*test==5);
	delete(short int,test);
	basicTypeTest(temp==5);
}

static void basicTypeSignedShortInt(void){
	signed short int temp=5;
	signed short int *test=new(signed short int);
	signed_short_int_t.set(test,&temp,sizeof(signed short int));
	basicTypeTest(*test==5);
	delete(signed short int,test);
	basicTypeTest(temp==5);
}

static void basicTypeUnsignedShort(void){
	unsigned short temp=5;
	unsigned short *test=new(unsigned short);
	unsigned_short_t.set(test,&temp,sizeof(unsigned short));
	basicTypeTest(*test==5);
	delete(unsigned short,test);
	basicTypeTest(temp==5);
}

static void basicTypeUnsignedShortInt(void){
	unsigned short int temp=5;
	unsigned short int *test=new(unsigned short int);
	unsigned_short_int_t.set(test,&temp,sizeof(unsigned short int));
	basicTypeTest(*test==5);
	delete(unsigned short int,test);
	basicTypeTest(temp==5);
}

static void basicTypeSignedInt(void){
	signed int temp=5;
	signed int *test=new(signed int);
	unsigned_short_int_t.set(test,&temp,sizeof(signed int));
	basicTypeTest(*test==5);
	delete(signed int,test);
	basicTypeTest(temp==5);
}

static void basicTypeUnsignedInt(void){
	unsigned int temp=5;
	unsigned int *test=new(unsigned int);
	unsigned_int_t.set(test,&temp,sizeof(unsigned int));
	basicTypeTest(*test==5);
	delete(unsigned int,test);
	basicTypeTest(temp==5);
}

static void basicTypeLongInt(void){
	long int temp=5;
	long int *test=new(long int);
	long_int_t.set(test,&temp,sizeof(long int));
	basicTypeTest(*test==5);
	delete(long int,test);
	basicTypeTest(temp==5);
}

static void basicTypeSignedLong(void){
	signed long temp=5;
	signed long *test=new(signed long);
	signed_long_t.set(test,&temp,sizeof(signed long));
	basicTypeTest(*test==5);
	delete(signed long,test);
	basicTypeTest(temp==5);
}

static void basicTypeSignedLongInt(void){
	signed long int temp=5;
	signed long int *test=new(signed long int);
	signed_long_int_t.set(test,&temp,sizeof(signed long int));
	basicTypeTest(*test==5);
	delete(signed long int,test);
	basicTypeTest(temp==5);
}

static void basicTypeUnsignedLong(void){
	unsigned long temp=5;
	unsigned long *test=new(unsigned long);
	unsigned_long_t.set(test,&temp,sizeof(unsigned long));
	basicTypeTest(*test==5);
	delete(unsigned long,test);
	basicTypeTest(temp==5);
}

static void basicTypeUnsignedLongInt(void){
	unsigned long int temp=5;
	unsigned long int *test=new(unsigned long int);
	unsigned_long_int_t.set(test,&temp,sizeof(unsigned long int));
	basicTypeTest(*test==5);
	delete(unsigned long int,test);
	basicTypeTest(temp==5);
}

static void basicTypeLongLong(void){
	long long temp=5;
	long long *test=new(long long);
	long_long_t.set(test,&temp,sizeof(long long));
	basicTypeTest(*test==5);
	delete(long long,test);
	basicTypeTest(temp==5);
}

static void basicTypeLongLongInt(void){
	long long int temp=5;
	long long int *test=new(long long int);
	long_long_int_t.set(test,&temp,sizeof(long long int));
	basicTypeTest(*test==5);
	delete(long long int,test);
	basicTypeTest(temp==5);
}

static void basicTypeSignedLongLong(void){
	signed long long temp=5;
	signed long long *test=new(signed long long);
	signed_long_long_t.set(test,&temp,sizeof(signed long long));
	basicTypeTest(*test==5);
	delete(signed long long,test);
	basicTypeTest(temp==5);
}

static void basicTypeSignedLongLongInt(void){
	signed long long int temp=5;
	signed long long int *test=new(signed long long int);
	signed_long_long_int_t.set(test,&temp,sizeof(signed long long int));
	basicTypeTest(*test==5);
	delete(signed long long int,test);
	basicTypeTest(temp==5);
}

static void basicTypeUnsignedLongLong(void){
	unsigned long long temp=5;
	unsigned long long *test=new(unsigned long long);
	unsigned_long_long_t.set(test,&temp,sizeof(unsigned long long));
	basicTypeTest(*test==5);
	delete(unsigned long long,test);
	basicTypeTest(temp==5);
}

static void basicTypeUnsignedLongLongInt(void){
	unsigned long long int temp=5;
	unsigned long long int *test=new(unsigned long long int);
	unsigned_long_long_int_t.set(test,&temp,sizeof(unsigned long long int));
	basicTypeTest(*test==5);
	delete(unsigned long long int,test);
	basicTypeTest(temp==5);
}

static void basicTypeLongDouble(void){
	long double temp=5;
	long double *test=new(long double);
	long_double_t.set(test,&temp,sizeof(long double));
	basicTypeTest(*test==5);
	delete(long double,test);
	basicTypeTest(temp==5);
}
#endif
