#include "Debug.h"
#include "../src/objectSystem/Object.h"
#include "../src/objectSystem/BasicType.h"
#include "../src/IO/Print.h"

#define basicTypeTest(result) test(result,"BasicType",__FUNCTION__,__LINE__)
#define basicTypeTypeTest(type,typeName,val1,val2)\
	static void basicType_##typeName(void){\
		type temp1=val1;\
		type temp2=val2;\
		type *test1=new(type);\
		type test2=newS(type,test2);\
		typeName.set(test1,&temp1,sizeof(type));\
		typeName.set(&test2,&temp1,sizeof(type));\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val1);\
		basicTypeTest(eq(type,test1,&test2));\
		basicTypeTest(gte(type,test1,&test2));\
		basicTypeTest(lte(type,test1,&test2));\
		typeName.set(&test2,&temp2,sizeof(type));\
		basicTypeTest(neq(type,test1,&test2));\
		basicTypeTest(gt(type,&test2,test1));\
		basicTypeTest(gte(type,&test2,test1));\
		basicTypeTest(lt(type,test1,&test2));\
		basicTypeTest(lte(type,test1,&test2));\
		delete(type,test1);\
		deleteS(type,test2);\
		basicTypeTest(temp1==val1);\
		basicTypeTest(temp2==val2);\
	}

basicTypeTypeTest(char,char_t,'h','i')
basicTypeTypeTest(short,short_t,5,6)
basicTypeTypeTest(int,int_t,5,6)
basicTypeTypeTest(unsigned,unsigned_t,5,6)
basicTypeTypeTest(long,long_t,5,6)
basicTypeTypeTest(float,float_t,5.5,6.5)
basicTypeTypeTest(double,double_t,5.5,6.5)
#ifdef CUSTOM_PRE_PROC_ENABLED
basicTypeTypeTest(signed char,signed_char_t,'h','i')
basicTypeTypeTest(unsigned char,unsigned_char_t,'h','i')
basicTypeTypeTest(short int,short_int_t,5,6)
basicTypeTypeTest(signed short int,signed_short_int_t,5,6)
basicTypeTypeTest(unsigned short,unsigned_short_t,5,6)
basicTypeTypeTest(unsigned short int,unsigned_short_int_t,5,6)
basicTypeTypeTest(signed int,signed_int_t,5,6)
basicTypeTypeTest(unsigned int,unsigned_int_t,5,6)
basicTypeTypeTest(long int,long_int_t,5,6)
basicTypeTypeTest(signed long,signed_long_t,5,6)
basicTypeTypeTest(signed long int,signed_long_int_t,5,6)
basicTypeTypeTest(unsigned long,unsigned_long_t,5,6)
basicTypeTypeTest(unsigned long int,unsigned_long_int_t,5,6)
basicTypeTypeTest(long long,long_long_t,5,6)
basicTypeTypeTest(long long int,long_long_int_t,5,6)
basicTypeTypeTest(signed long long,signed_long_long_t,5,6)
basicTypeTypeTest(signed long long int,signed_long_long_int_t,5,6)
basicTypeTypeTest(unsigned long long,unsigned_long_long_t,5,6)
basicTypeTypeTest(unsigned long long int,unsigned_long_long_int_t,5,6)
basicTypeTypeTest(long double,long_double_t,5,6)
#endif

void basicTypesDebug(void){
	basicType_char_t();
	basicType_short_t();
	basicType_int_t();
	basicType_unsigned_t();
	basicType_long_t();
	basicType_float_t();
	basicType_double_t();
#if CUSTOM_PRE_PROC_ENABLED
	basicType_signed_char_t();
	basicType_unsigned_char_t();
	basicType_short_int_t();
	basicType_signed_short_int_t();
	basicType_unsigned_short_t();
	basicType_unsigned_short_int_t();
	basicType_signed_int_t();
	basicType_unsigned_int_t();
	basicType_long_int_t();
	basicType_signed_long_t();
	basicType_signed_long_int_t();
	basicType_unsigned_long_t();
	basicType_unsigned_long_int_t();
	basicType_long_long_t();
	basicType_long_long_int_t();
	basicType_signed_long_long_t();
	basicType_signed_long_long_int_t();
	basicType_unsigned_long_long_t();
	basicType_unsigned_long_long_int_t();
	basicType_long_double_t();
#endif
}
