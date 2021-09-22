#ifndef OPERATOR_FRAMEWORK
#define OPERATOR_FRAMEWORK

//All operators have to return a pointer to the object that was manipulated in
//order to allow for chaining of commands
//
//Result *result=new(Result);
//opSqrt(opPowEq(opAddEq(one,two),five),opPowEq(opAddEq(three,four),six),result);
typedef struct ArithLogicOperators {
	void* (*resultOp)(const void * const self, const void * const other, void *result);
	void* (*selfResultOp)(void *self, const void * const other);
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

#define eq(type,obj1,obj2) type##_t.comparisonOperators.eqOperator((void*)obj1,(void*)obj2,sizeof(type))
#define neq(type,obj1,obj2) type##_t.comparisonOperators.neqOperator((void*)obj1,(void*)obj2,sizeof(type))
#define gt(type,obj1,obj2) type##_t.comparisonOperators.gtOperator((void*)obj1,(void*)obj2,sizeof(type))
#define lt(type,obj1,obj2) type##_t.comparisonOperators.ltOperator((void*)obj1,(void*)obj2,sizeof(type))
#define gte(type,obj1,obj2) type##_t.comparisonOperators.gteOperator((void*)obj1,(void*)obj2,sizeof(type))
#define lte(type,obj1,obj2) type##_t.comparisonOperators.lteOperator((void*)obj1,(void*)obj2,sizeof(type))

#define DEFAULT_COMPARISON_OPERATORS {\
	.eqOperator=eqOperator,\
	.neqOperator=neqOperator,\
	.gtOperator=gtOperator,\
	.ltOperator=ltOperator,\
	.gteOperator=gteOperator,\
	.lteOperator=lteOperator,\
}

typedef struct ComparisonOperators {
	bool (*eqOperator)(const void * const first, const void * const second, size_t size);
	bool (*neqOperator)(const void * const first, const void * const second, size_t size);
	bool (*gtOperator)(const void * const first, const void * const second, size_t size);
	bool (*ltOperator)(const void * const first, const void * const second, size_t size);
	bool (*gteOperator)(const void * const first, const void * const second, size_t size);
	bool (*lteOperator)(const void * const first, const void * const second, size_t size);
} ComparisonOperators;

typedef struct AccessOperators {
	void* (*brackOperator)(const void * const self, const int num);
} AccessOperators;


#endif
