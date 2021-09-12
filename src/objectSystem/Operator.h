#ifndef OPERATOR_FRAMEWORK
#define OPERATOR_FRAMEWORK

typedef struct ArithLogicOperators {
	void (*newResultOp)(const void * const self, const void * const other, void *result);
	void (*selfResultOp)(void *self, const void * const other);
} ArithLogicOperators;



#endif
