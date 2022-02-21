#include "Debug.h"
#include "../src/objectSystem/Object.h"
#include "../src/objectSystem/BasicType.h"
#include "../src/objectSystem/Operator.h"
#include "../src/IO/Print.h"

#define basicTypeTest(result) test(result,"BasicType",__FUNCTION__,__LINE__)

#define basicTypeTypeTest(type,typeName)\
	static void basicType_##typeName(type val1, type val2){\
		type temp1=val1;\
		type temp2=val2;\
		type *test1=new(type);\
		type test2=newS(type,test2);\
		type test3=newS(type,test3);\
		\
		typeName.set(test1,&temp1,sizeof(type));\
		typeName.set(&test2,&temp1,sizeof(type));\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val1);\
		bool eq1=EQ(type,test1,&test2), eq2=(*test1==test2);\
		bool neq1=NEQ(type,test1,&test2), neq2=(*test1!=test2);\
		bool gt1=GT(type,test1,&test2), gt2=(*test1>test2);\
		bool lt1=LT(type,test1,&test2), lt2=(*test1<test2);\
		bool gte1=GTE(type,test1,&test2), gte2=(*test1>=test2);\
		bool lte1=LTE(type,test1,&test2), lte2=(*test1<=test2);\
		basicTypeTest(eq1==eq2);\
		basicTypeTest(neq1==neq2);\
		basicTypeTest(gt1==gt2);\
		basicTypeTest(lt1==lt2);\
		basicTypeTest(gte1==gte2);\
		basicTypeTest(lte1==lte2);\
		\
		typeName.set(&test2,&temp2,sizeof(type));\
		eq1=EQ(type,test1,&test2); eq2=(*test1==test2);\
		neq1=NEQ(type,test1,&test2); neq2=(*test1!=test2);\
		gt1=GT(type,test1,&test2); gt2=(*test1>test2);\
		lt1=LT(type,test1,&test2); lt2=(*test1<test2);\
		gte1=GTE(type,test1,&test2); gte2=(*test1>=test2);\
		lte1=LTE(type,test1,&test2); lte2=(*test1<=test2);\
		basicTypeTest(eq1==eq2);\
		basicTypeTest(neq1==neq2);\
		basicTypeTest(gt1==gt2);\
		basicTypeTest(lt1==lt2);\
		basicTypeTest(gte1==gte2);\
		basicTypeTest(lte1==lte2);\
		\
		*test1=val1;\
		test2=val2;\
		ADD(type,test1,&test2,&test3);\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val2);\
		basicTypeTest(test3==(type)((type)val1+(type)val2));\
		ADD(type,test1,&test2);\
		basicTypeTest(*test1==(type)((type)val1+(type)val2));\
		basicTypeTest(test2==val2);\
		\
		*test1=val1;\
		test2=val2;\
		SUB(type,test1,&test2,&test3);\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val2);\
		basicTypeTest(test3==(type)((type)val1-(type)val2));\
		SUB(type,test1,&test2);\
		basicTypeTest(*test1==(type)((type)val1-(type)val2));\
		basicTypeTest(test2==val2);\
		\
		*test1=val1;\
		test2=val2;\
		MUL(type,test1,&test2,&test3);\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val2);\
		basicTypeTest(test3==(type)((type)val1*(type)val2));\
		MUL(type,test1,&test2);\
		basicTypeTest(*test1==(type)((type)val1*(type)val2));\
		basicTypeTest(test2==val2);\
		\
		*test1=val1;\
		test2=val2;\
		MOD(type,test1,&test2,&test3);\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val2);\
		basicTypeTest(test3==(type)((type)val1%(type)val2));\
		MOD(type,test1,&test2);\
		basicTypeTest(*test1==(type)((type)val1%(type)val2));\
		basicTypeTest(test2==val2);\
		\
		*test1=val1;\
		test2=val2;\
		DIV(type,test1,&test2,&test3);\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val2);\
		basicTypeTest(test3==(type)((type)val1/(type)val2));\
		DIV(type,test1,&test2);\
		basicTypeTest(*test1==(type)((type)val1/(type)val2));\
		basicTypeTest(test2==val2);\
		\
		*test1=val1;\
		test2=val2;\
		SLL(type,test1,&test2,&test3);\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val2);\
		basicTypeTest(test3==(type)val1<<(type)val2);\
		SLL(type,test1,&test2);\
		basicTypeTest(*test1==(type)val1<<(type)val2);\
		basicTypeTest(test2==val2);\
		\
		*test1=val1;\
		test2=val2;\
		SRL(type,test1,&test2,&test3);\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val2);\
		basicTypeTest(test3==(type)val1>>(type)val2);\
		SRL(type,test1,&test2);\
		basicTypeTest(*test1==(type)val1>>(type)val2);\
		basicTypeTest(test2==val2);\
		\
		*test1=val1;\
		test2=val2;\
		AND(type,test1,&test2,&test3);\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val2);\
		basicTypeTest(test3==((type)val1 & (type)val2));\
		AND(type,test1,&test2);\
		basicTypeTest(*test1==((type)val1 & (type)val2));\
		basicTypeTest(test2==val2);\
		\
		*test1=val1;\
		test2=val2;\
		OR(type,test1,&test2,&test3);\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val2);\
		basicTypeTest(test3==((type)val1 | (type)val2));\
		OR(type,test1,&test2);\
		basicTypeTest(*test1==((type)val1 | (type)val2));\
		basicTypeTest(test2==val2);\
		\
		*test1=val1;\
		test2=val2;\
		NOT(type,test1,&test3);\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val2);\
		basicTypeTest(test3==((type)~val1));\
		NOT(type,test1);\
		basicTypeTest(*test1==((type)~val1));\
		basicTypeTest(test2==val2);\
		\
		delete(type,test1);\
		deleteS(type,test2);\
		deleteS(type,test3);\
		basicTypeTest(temp1==val1);\
		basicTypeTest(temp2==val2);\
	}

#define basicTypeFloatTypeTest(type,typeName)\
	static void basicType_##typeName(type val1, type val2){\
		type temp1=val1;\
		type temp2=val2;\
		type *test1=new(type);\
		type test2=newS(type,test2);\
		type test3=newS(type,test3);\
		\
		typeName.set(test1,&temp1,sizeof(type));\
		typeName.set(&test2,&temp1,sizeof(type));\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val1);\
		bool eq1=EQ(type,test1,&test2), eq2=(*test1==test2);\
		bool neq1=NEQ(type,test1,&test2), neq2=(*test1!=test2);\
		bool gt1=GT(type,test1,&test2), gt2=(*test1>test2);\
		bool lt1=LT(type,test1,&test2), lt2=(*test1<test2);\
		bool gte1=GTE(type,test1,&test2), gte2=(*test1>=test2);\
		bool lte1=LTE(type,test1,&test2), lte2=(*test1<=test2);\
		basicTypeTest(eq1==eq2);\
		basicTypeTest(neq1==neq2);\
		basicTypeTest(gt1==gt2);\
		basicTypeTest(lt1==lt2);\
		basicTypeTest(gte1==gte2);\
		basicTypeTest(lte1==lte2);\
		\
		typeName.set(&test2,&temp2,sizeof(type));\
		eq1=EQ(type,test1,&test2); eq2=(*test1==test2);\
		neq1=NEQ(type,test1,&test2); neq2=(*test1!=test2);\
		gt1=GT(type,test1,&test2); gt2=(*test1>test2);\
		lt1=LT(type,test1,&test2); lt2=(*test1<test2);\
		gte1=GTE(type,test1,&test2); gte2=(*test1>=test2);\
		lte1=LTE(type,test1,&test2); lte2=(*test1<=test2);\
		basicTypeTest(eq1==eq2);\
		basicTypeTest(neq1==neq2);\
		basicTypeTest(gt1==gt2);\
		basicTypeTest(lt1==lt2);\
		basicTypeTest(gte1==gte2);\
		basicTypeTest(lte1==lte2);\
		\
		*test1=val1;\
		test2=val2;\
		type expected=val1+val2;\
		ADD(type,test1,&test2,&test3);\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val2);\
		basicTypeTest(test3==expected);\
		ADD(type,test1,&test2);\
		basicTypeTest(*test1==expected);\
		basicTypeTest(test2==val2);\
		\
		*test1=val1;\
		test2=val2;\
		expected=val1-val2;\
		SUB(type,test1,&test2,&test3);\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val2);\
		basicTypeTest(test3==expected);\
		SUB(type,test1,&test2);\
		basicTypeTest(*test1==expected);\
		basicTypeTest(test2==val2);\
		\
		*test1=val1;\
		test2=val2;\
		expected=val1*val2;\
		MUL(type,test1,&test2,&test3);\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val2);\
		basicTypeTest(test3==expected);\
		MUL(type,test1,&test2);\
		basicTypeTest(*test1==expected);\
		basicTypeTest(test2==val2);\
		\
		*test1=val1;\
		test2=val2;\
		expected=val1/val2;\
		DIV(type,test1,&test2,&test3);\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val2);\
		basicTypeTest(test3==expected);\
		DIV(type,test1,&test2);\
		basicTypeTest(*test1==expected);\
		basicTypeTest(test2==val2);\
		\
		delete(type,test1);\
		deleteS(type,test2);\
		deleteS(type,test3);\
		basicTypeTest(temp1==val1);\
		basicTypeTest(temp2==val2);\
	}

#define basicTypeCharTypeTest(type,typeName)\
	static void basicType_##typeName(type val1, type val2){\
		type temp1=val1;\
		type temp2=val2;\
		type *test1=new(type);\
		type test2=newS(type,test2);\
		type test3=newS(type,test3);\
		\
		typeName.set(test1,&temp1,sizeof(type));\
		typeName.set(&test2,&temp1,sizeof(type));\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val1);\
		bool eq1=EQ(type,test1,&test2), eq2=(*test1==test2);\
		bool neq1=NEQ(type,test1,&test2), neq2=(*test1!=test2);\
		bool gt1=GT(type,test1,&test2), gt2=(*test1>test2);\
		bool lt1=LT(type,test1,&test2), lt2=(*test1<test2);\
		bool gte1=GTE(type,test1,&test2), gte2=(*test1>=test2);\
		bool lte1=LTE(type,test1,&test2), lte2=(*test1<=test2);\
		basicTypeTest(eq1==eq2);\
		basicTypeTest(neq1==neq2);\
		basicTypeTest(gt1==gt2);\
		basicTypeTest(lt1==lt2);\
		basicTypeTest(gte1==gte2);\
		basicTypeTest(lte1==lte2);\
		\
		typeName.set(&test2,&temp2,sizeof(type));\
		eq1=EQ(type,test1,&test2); eq2=(*test1==test2);\
		neq1=NEQ(type,test1,&test2); neq2=(*test1!=test2);\
		gt1=GT(type,test1,&test2); gt2=(*test1>test2);\
		lt1=LT(type,test1,&test2); lt2=(*test1<test2);\
		gte1=GTE(type,test1,&test2); gte2=(*test1>=test2);\
		lte1=LTE(type,test1,&test2); lte2=(*test1<=test2);\
		basicTypeTest(eq1==eq2);\
		basicTypeTest(neq1==neq2);\
		basicTypeTest(gt1==gt2);\
		basicTypeTest(lt1==lt2);\
		basicTypeTest(gte1==gte2);\
		basicTypeTest(lte1==lte2);\
		\
		*test1=val1;\
		test2=val2;\
		ADD(type,test1,&test2,&test3);\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val2);\
		basicTypeTest(test3==0);\
		ADD(type,test1,&test2);\
		basicTypeTest(*test1==0);\
		basicTypeTest(test2==val2);\
		\
		*test1=val1;\
		test2=val2;\
		SUB(type,test1,&test2,&test3);\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val2);\
		basicTypeTest(test3==0);\
		SUB(type,test1,&test2);\
		basicTypeTest(*test1==0);\
		basicTypeTest(test2==val2);\
		\
		*test1=val1;\
		test2=val2;\
		MUL(type,test1,&test2,&test3);\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val2);\
		basicTypeTest(test3==0);\
		MUL(type,test1,&test2);\
		basicTypeTest(*test1==0);\
		basicTypeTest(test2==val2);\
		\
		*test1=val1;\
		test2=val2;\
		DIV(type,test1,&test2,&test3);\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val2);\
		basicTypeTest(test3==0);\
		DIV(type,test1,&test2);\
		basicTypeTest(*test1==0);\
		basicTypeTest(test2==val2);\
		\
		*test1=val1;\
		test2=val2;\
		MOD(type,test1,&test2,&test3);\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val2);\
		basicTypeTest(test3==0);\
		MOD(type,test1,&test2);\
		basicTypeTest(*test1==0);\
		basicTypeTest(test2==val2);\
		\
		*test1=val1;\
		test2=val2;\
		SLL(type,test1,&test2,&test3);\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val2);\
		basicTypeTest(test3==0);\
		SLL(type,test1,&test2);\
		basicTypeTest(*test1==0);\
		basicTypeTest(test2==val2);\
		\
		*test1=val1;\
		test2=val2;\
		SRL(type,test1,&test2,&test3);\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val2);\
		basicTypeTest(test3==0);\
		SRL(type,test1,&test2);\
		basicTypeTest(*test1==0);\
		basicTypeTest(test2==val2);\
		\
		*test1=val1;\
		test2=val2;\
		AND(type,test1,&test2,&test3);\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val2);\
		basicTypeTest(test3==0);\
		AND(type,test1,&test2);\
		basicTypeTest(*test1==0);\
		basicTypeTest(test2==val2);\
		\
		*test1=val1;\
		test2=val2;\
		OR(type,test1,&test2,&test3);\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val2);\
		basicTypeTest(test3==0);\
		OR(type,test1,&test2);\
		basicTypeTest(*test1==0);\
		basicTypeTest(test2==val2);\
		\
		*test1=val1;\
		test2=val2;\
		NOT(type,test1,&test3);\
		basicTypeTest(*test1==val1);\
		basicTypeTest(test2==val2);\
		basicTypeTest(test3==0);\
		NOT(type,test1);\
		basicTypeTest(*test1==0);\
		basicTypeTest(test2==val2);\
		\
		delete(type,test1);\
		deleteS(type,test2);\
		deleteS(type,test3);\
		basicTypeTest(temp1==val1);\
		basicTypeTest(temp2==val2);\
	}

basicTypeCharTypeTest(char,char_t)
basicTypeTypeTest(short,short_t)
basicTypeTypeTest(int,int_t)
basicTypeTypeTest(unsigned,unsigned_t)
basicTypeTypeTest(long,long_t)
basicTypeFloatTypeTest(float,float_t)
basicTypeFloatTypeTest(double,double_t)
#ifdef CUSTOM_PRE_PROC_ENABLED
basicTypeCharTypeTest(signed char,signed_char_t)
basicTypeCharTypeTest(unsigned char,unsigned_char_t)
basicTypeTypeTest(short int,short_int_t)
basicTypeTypeTest(signed short int,signed_short_int_t)
basicTypeTypeTest(unsigned short,unsigned_short_t)
basicTypeTypeTest(unsigned short int,unsigned_short_int_t)
basicTypeTypeTest(signed int,signed_int_t)
basicTypeTypeTest(unsigned int,unsigned_int_t)
basicTypeTypeTest(long int,long_int_t)
basicTypeTypeTest(signed long,signed_long_t)
basicTypeTypeTest(signed long int,signed_long_int_t)
basicTypeTypeTest(unsigned long,unsigned_long_t)
basicTypeTypeTest(unsigned long int,unsigned_long_int_t)
basicTypeTypeTest(long long,long_long_t)
basicTypeTypeTest(long long int,long_long_int_t)
basicTypeTypeTest(signed long long,signed_long_long_t)
basicTypeTypeTest(signed long long int,signed_long_long_int_t)
basicTypeTypeTest(unsigned long long,unsigned_long_long_t)
basicTypeTypeTest(unsigned long long int,unsigned_long_long_int_t)
basicTypeFloatTypeTest(long double,long_double_t)
#endif

#define basicTypeTests(typeName,val1,val2)\
	basicType_##typeName##_t(val1,val2);\
	basicType_##typeName##_t(val2,val1);\
	basicType_##typeName##_t(val1,val1);

void basicTypesDebug(void){
	basicTypeTests(char,'h','i');
	basicTypeTests(short,5,6);
	basicTypeTests(int,5,6);
	basicTypeTests(unsigned,5,6);
	basicTypeTests(long,5,6);
	basicTypeTests(float,5,6);
	basicTypeTests(double,5,6);
#if CUSTOM_PRE_PROC_ENABLED
	basicTypeTests(signed_char,'h','i');
	basicTypeTests(unsigned_char,'h','i');
	basicTypeTests(short_int,5,6);
	basicTypeTests(signed_short_int,5,6);
	basicTypeTests(unsigned_short,5,6);
	basicTypeTests(unsigned_short_int,5,6);
	basicTypeTests(signed_int,5,6);
	basicTypeTests(unsigned_int,5,6);
	basicTypeTests(long_int,5,6);
	basicTypeTests(signed_long,5,6);
	basicTypeTests(signed_long_int,5,6);
	basicTypeTests(unsigned_long,5,6);
	basicTypeTests(unsigned_long_int,5,6);
	basicTypeTests(long_long,5,6);
	basicTypeTests(long_long_int,5,6);
	basicTypeTests(signed_long_long,5,6);
	basicTypeTests(signed_long_long_int,5,6);
	basicTypeTests(unsigned_long_long,5,6);
	basicTypeTests(unsigned_long_long_int,5,6);
	basicTypeTests(long_double,5,6);
#endif
}
