#include <string.h>
#include "BasicType.h"

#include <stdio.h>

bool unsignedEqOperator(const void * const first, const void * const second, size_t size);
bool unsignedNeqOperator(const void * const first, const void * const second, size_t size);
bool unsignedGtOperator(const void * const first, const void * const second, size_t size);
bool unsignedGteOperator(const void * const first, const void * const second, size_t size);
bool unsignedLtOperator(const void * const first, const void * const second, size_t size);
bool unsignedLteOperator(const void * const first, const void * const second, size_t size);
void* unsignedAddOp(const void * const self, const void * const other, void *result, size_t size);
void* unsignedSubOp(const void * const self, const void * const other, void *result, size_t size);
void* unsignedMulOp(const void * const self, const void * const other, void *result, size_t size);
bool signedEqOperator(const void * const first, const void * const second, size_t size);
bool signedNeqOperator(const void * const first, const void * const second, size_t size);
bool signedGtOperator(const void * const first, const void * const second, size_t size);
bool signedGteOperator(const void * const first, const void * const second, size_t size);
bool signedLtOperator(const void * const first, const void * const second, size_t size);
bool signedLteOperator(const void * const first, const void * const second, size_t size);
void* signedAddOp(const void * const self, const void * const other, void *result, size_t size);
void* signedSubOp(const void * const self, const void * const other, void *result, size_t size);
void* signedMulOp(const void * const self, const void * const other, void *result, size_t size);
void* signedSubSelfOp(void *self, const void * const other, size_t size);
bool floatEqOperator(const void * const first, const void * const second, size_t size);
bool floatNeqOperator(const void * const first, const void * const second, size_t size);
bool floatGtOperator(const void * const first, const void * const second, size_t size);
bool floatGteOperator(const void * const first, const void * const second, size_t size);
bool floatLtOperator(const void * const first, const void * const second, size_t size);
bool floatLteOperator(const void * const first, const void * const second, size_t size);
void* floatAddOp(const void * const self, const void * const other, void *result, size_t size);
void* floatSubOp(const void * const self, const void * const other, void *result, size_t size);
void* floatMulOp(const void * const self, const void * const other, void *result, size_t size);

const struct BasicType_t UnsignedBasicType_t={
	.class={
		.allocator=malloc,
		.constructor=NULL,
		.copyConstructor=memcpy,
		.comparator=memcmp,
		.destructor=NULL,
	},
	.comparisonOperators={
		.eqOperator=unsignedEqOperator,
		.neqOperator=unsignedNeqOperator,
		.gtOperator=unsignedGtOperator,
		.gteOperator=unsignedGteOperator,
		.ltOperator=unsignedLtOperator,
		.lteOperator=unsignedLteOperator,
	},
	.operators={
		.add=unsignedAddOp,
		.sub=unsignedSubOp,
		.mul=unsignedMulOp,
	},
	.set=memcpy,
};

const struct BasicType_t SignedBasicType_t={
	.class={
		.allocator=malloc,
		.constructor=NULL,
		.copyConstructor=memcpy,
		.comparator=memcmp,
		.destructor=NULL,
	},
	.comparisonOperators={
		.eqOperator=signedEqOperator,
		.neqOperator=signedNeqOperator,
		.gtOperator=signedGtOperator,
		.gteOperator=signedGteOperator,
		.ltOperator=signedLtOperator,
		.lteOperator=signedLteOperator,
	},
	.operators={
		.add=signedAddOp,
		.sub=signedSubOp,
		.mul=signedMulOp,
	},
	.set=memcpy,
};

const struct BasicType_t FloatBasicType_t={
	.class={
		.allocator=malloc,
		.constructor=NULL,
		.copyConstructor=memcpy,
		.comparator=memcmp,
		.destructor=NULL,
	},
	.comparisonOperators={
		.eqOperator=floatEqOperator,
		.neqOperator=floatNeqOperator,
		.gtOperator=floatGtOperator,
		.gteOperator=floatGteOperator,
		.ltOperator=floatLtOperator,
		.lteOperator=floatLteOperator,
	},
	.operators={
		.add=floatAddOp,
		.sub=floatSubOp,
		.mul=floatMulOp,
	},
	.set=memcpy,
};

//Unsigned Operators===========================================================
bool unsignedEqOperator(const void * const first, const void * const second, size_t size){
	if (size==sizeof(unsigned)){
		//also unsigned int
		return (*(unsigned*)first==*(unsigned*)second);
	}
#ifdef CUSTOM_PRE_PROC_ENABLED
	if (size==sizeof(unsigned char)){
		return (*(unsigned char*)first==*(unsigned char*)second); 
	} else if (size==sizeof(unsigned short)){
		//also unsigned short int
		return (*(unsigned short*)first==*(unsigned short*)second); 
	} else if (size==sizeof(unsigned long)){
		//also unsigned long int
		return (*(unsigned long*)first==*(unsigned long*)second); 
	} else if (size==sizeof(unsigned long long)){
		//also unsigned long long int
		return (*(unsigned long long*)first==*(unsigned long long*)second); 
	}
#endif
	return false;
}

bool unsignedNeqOperator(const void * const first, const void * const second, size_t size){
	return !unsignedEqOperator(first,second,size);
}

bool unsignedGtOperator(const void * const first, const void * const second, size_t size){
	if (size==sizeof(unsigned)){
		//also unsigned int
		return (*(unsigned*)first>*(unsigned*)second);
	}
#ifdef CUSTOM_PRE_PROC_ENABLED
	if (size==sizeof(unsigned char)){
		return (*(unsigned char*)first>*(unsigned char*)second); 
	} else if (size==sizeof(unsigned short)){
		//also unsigned short int
		return (*(unsigned short*)first>*(unsigned short*)second); 
	} else if (size==sizeof(unsigned long)){
		//also unsigned long int
		return (*(unsigned long*)first>*(unsigned long*)second); 
	} else if (size==sizeof(unsigned long long)){
		//also unsigned long long int
		return (*(unsigned long long*)first>*(unsigned long long*)second); 
	}
#endif
	return false;
}

bool unsignedLtOperator(const void * const first, const void * const second, size_t size){
	return unsignedGteOperator(second,first,size);
}

bool unsignedGteOperator(const void * const first, const void * const second, size_t size){
	return (
		unsignedGtOperator(first,second,size) ||
		unsignedEqOperator(first,second,size)
		);
}

bool unsignedLteOperator(const void * const first, const void * const second, size_t size){
	return !unsignedGtOperator(first,second,size);
}

void* unsignedAddOp(const void * const self, const void * const other, void *result, size_t size){
	if (size==sizeof(unsigned)){
		//also unsigned int
		*(unsigned*)result=*(unsigned*)self+*(unsigned*)other;
		return result;
	} 
#ifdef CUSTOM_PRE_PROC_ENABLED
	if (size==sizeof(unsigned char)){
		*(unsigned char*)result=0;		//adding chars is undefined
		return result;
	} else if (size==sizeof(unsigned short)){
		//also unsigned short int
		*(unsigned short*)result=*(unsigned short*)self+*(unsigned short*)other;
		return result;
	} else if (size==sizeof(unsigned long)){
		//also unsigned long int
		*(unsigned long*)result=*(unsigned long*)self+*(unsigned long*)other;
		return result;
	} else if (size==sizeof(unsigned long long)){
		//also unsigned long long int
		*(unsigned long long*)result=*(unsigned long long*)self+*(unsigned long long*)other;
		return result;
	}
#endif
	return result;
}

void* unsignedSubOp(const void * const self, const void * const other, void *result, size_t size){
	if (size==sizeof(unsigned)){
		//also unsigned int
		*(unsigned*)result=*(unsigned*)self-*(unsigned*)other;
		return result;
	} 
#ifdef CUSTOM_PRE_PROC_ENABLED
	if (size==sizeof(unsigned char)){
		*(unsigned char*)result=0;		//subtracting chars is undefined
		return result;
	} else if (size==sizeof(unsigned short)){
		//also unsigned short int
		*(unsigned short*)result=*(unsigned short*)self-*(unsigned short*)other;
		return result;
	} else if (size==sizeof(unsigned long)){
		//also unsigned long int
		*(unsigned long*)result=*(unsigned long*)self-*(unsigned long*)other;
		return result;
	} else if (size==sizeof(unsigned long long)){
		//also unsigned long long int
		*(unsigned long long*)result=*(unsigned long long*)self-*(unsigned long long*)other;
		return result;
	}
#endif
	return result;
}


void* unsignedMulOp(const void * const self, const void * const other, void *result, size_t size){
	if (size==sizeof(unsigned)){
		//also unsigned int
		*(unsigned*)result=(*(unsigned*)self)*(*(unsigned*)other);
		return result;
	} 
#ifdef CUSTOM_PRE_PROC_ENABLED
	if (size==sizeof(unsigned char)){
		*(unsigned char*)result=0;		//multiplying chars is undefined
		return result;
	} else if (size==sizeof(unsigned short)){
		//also unsigned short int
		*(unsigned short*)result=(*(unsigned short*)self)*(*(unsigned short*)other);
		return result;
	} else if (size==sizeof(unsigned long)){
		//also unsigned long int
		*(unsigned long*)result=(*(unsigned long*)self)*(*(unsigned long*)other);
		return result;
	} else if (size==sizeof(unsigned long long)){
		//also unsigned long long int
		*(unsigned long long*)result=(*(unsigned long long*)self)*(*(unsigned long long*)other);
		return result;
	}
#endif
	return result;
}

//Signed Operators=============================================================
bool signedEqOperator(const void * const first, const void * const second, size_t size){
	if (size==sizeof(char)){
		//also signed char
		return (*(char*)first==*(char*)second); 
	} else if (size==sizeof(short)){
		//also short int, signed short, signed short int
		return (*(short*)first==*(short*)second); 
	} else if (size==sizeof(int)){
		//also signed int
		return (*(int*)first==*(int*)second); 
	} else if (size==sizeof(long)){	
		//also long int, signed long, signed long int
		return (*(long*)first==*(long*)second); 
	}
#ifdef CUSTOM_PRE_PROC_ENABLED
	if (size==sizeof(long long)){
		//also long long int, signed long long, signed long long int
		return (*(long long*)first==*(long long*)second);
	}
#endif
	return false;
}

bool signedNeqOperator(const void * const first, const void * const second, size_t size){
	return !signedEqOperator(first,second,size);
}

bool signedGtOperator(const void * const first, const void * const second, size_t size){
	if (size==sizeof(char)){
		//also signed char
		return (*(char*)first>*(char*)second); 
	} else if (size==sizeof(short)){	
		//also short int, signed short, signed short int
		return (*(short*)first>*(short*)second); 
	} else if (size==sizeof(int)){
		//also signed int
		return (*(int*)first>*(int*)second); 
	} else if (size==sizeof(long)){
		//also long int, signed long, signed long int
		return (*(long*)first>*(long*)second); 
	}
#ifdef CUSTOM_PRE_PROC_ENABLED
	if (size==sizeof(long long)){
		//also long long int, signed long long, signed long long int
		return (*(long long*)first>*(long long*)second);
	}
#endif
	return false;
}

bool signedLtOperator(const void * const first, const void * const second, size_t size){
	return signedGteOperator(second,first,size);
}

bool signedGteOperator(const void * const first, const void * const second, size_t size){
	return (signedGtOperator(first,second,size) || signedEqOperator(first,second,size));
}

bool signedLteOperator(const void * const first, const void * const second, size_t size){
	return !signedGtOperator(first,second,size);
}

void* signedAddOp(const void * const self, const void * const other, void *result, size_t size){
	if (size==sizeof(char)){
		//also signed char
		*(char*)result=0;	//Adding characters is undefined
		return result;
	} else if (size==sizeof(short)){
		//also short int, signed short, signed short int
		*(short*)result=*(short*)self+*(short*)other;
		return result;
	} else if (size==sizeof(int)){
		//also signed int
		*(int*)result=*(int*)self+*(int*)other;
		return result;
	} else if (size==sizeof(long)){
		//also long int, signed long, signed long int
		*(long*)result=*(long*)self+*(long*)other;
		return result;
	} 
#ifdef CUSTOM_PRE_PROC_ENABLED	
	if (size==sizeof(long long)){
		//also long long int, signed long long, signed long long int
		*(long long*)result=*(long long*)self+*(long long*)other;
		return result;
	}
#endif
	return result;
}

void* signedSubOp(const void * const self, const void * const other, void *result, size_t size){
	if (size==sizeof(char)){
		//also signed char
		*(char*)result=0;	//subtracting characters is undefined
		return result;
	} else if (size==sizeof(short)){
		//also short int, signed short, signed short int
		*(short*)result=*(short*)self-*(short*)other;
		return result;
	} else if (size==sizeof(int)){
		//also signed int
		*(int*)result=*(int*)self-*(int*)other;
		return result;
	} else if (size==sizeof(long)){
		//also long int, signed long, signed long int
		*(long*)result=*(long*)self-*(long*)other;
		return result;
	} 
#ifdef CUSTOM_PRE_PROC_ENABLED	
	if (size==sizeof(long long)){
		//also long long int, signed long long, signed long long int
		*(long long*)result=*(long long*)self-*(long long*)other;
		return result;
	}
#endif
	return result;
}

void* signedMulOp(const void * const self, const void * const other, void *result, size_t size){
	if (size==sizeof(char)){
		//also signed char
		*(char*)result=0;	//subtracting characters is undefined
		return result;
	} else if (size==sizeof(short)){
		//also short int, signed short, signed short int
		*(short*)result=(*(short*)self)*(*(short*)other);
		return result;
	} else if (size==sizeof(int)){
		//also signed int
		*(int*)result=(*(int*)self)*(*(int*)other);
		return result;
	} else if (size==sizeof(long)){
		//also long int, signed long, signed long int
		*(long*)result=(*(long*)self)*(*(long*)other);
		return result;
	} 
#ifdef CUSTOM_PRE_PROC_ENABLED	
	if (size==sizeof(long long)){
		//also long long int, signed long long, signed long long int
		*(long long*)result=(*(long long*)self)*(*(long long*)other);
		return result;
	}
#endif
	return result;
}

//Float Operations=============================================================
bool floatEqOperator(const void * const first, const void * const second, size_t size){
	if (size==sizeof(float)){
		return (*(float*)first==*(float*)second);
	} else if (size==sizeof(double)){
		return (*(double*)first==*(double*)second);
	}
#ifdef CUSTOM_PRE_PROC_ENABLED	
	if (size==sizeof(long double)){
		return (*(long double*)first==*(long double*)second);
	}
#endif
	return false;
}

bool floatNeqOperator(const void * const first, const void * const second, size_t size){
	return !floatEqOperator(first,second,size);
}

bool floatGtOperator(const void * const first, const void * const second, size_t size){
	if (size==sizeof(float)){
		return (*(float*)first>*(float*)second);
	} else if (size==sizeof(double)){
		return (*(double*)first>*(double*)second);
	}
#ifdef CUSTOM_PRE_PROC_ENABLED
	if (size==sizeof(long double)){
		return (*(long double*)first>*(long double*)second);
	}
#endif
	return false;
}

bool floatLtOperator(const void * const first, const void * const second, size_t size){
	return floatGteOperator(second,first,size);
}

bool floatGteOperator(const void * const first, const void * const second, size_t size){
	return (floatGtOperator(first,second,size) || floatEqOperator(first,second,size));
}

bool floatLteOperator(const void * const first, const void * const second, size_t size){
	return !floatGtOperator(first,second,size);
}

void* floatAddOp(const void * const self, const void * const other, void *result, size_t size){
	if (size==sizeof(float)){
		*(float*)result=*(float*)self+*(float*)other;
		return result;
	} else if (size==sizeof(double)){
		*(double*)result=*(double*)self+*(double*)other;
		return result;
	}
#ifdef CUSTOM_PRE_PROC_ENABLED
	if (size==sizeof(long double)){
		*(long double*)result=*(long double*)self+*(long double*)other;
		return result;
	}
#endif
	return result;
}

void* floatSubOp(const void * const self, const void * const other, void *result, size_t size){
	if (size==sizeof(float)){
		*(float*)result=*(float*)self-*(float*)other;
		return result;
	} else if (size==sizeof(double)){
		*(double*)result=*(double*)self-*(double*)other;
		return result;
	}
#ifdef CUSTOM_PRE_PROC_ENABLED
	if (size==sizeof(long double)){
		*(long double*)result=*(long double*)self-*(long double*)other;
		return result;
	}
#endif
	return result;
}

void* floatMulOp(const void * const self, const void * const other, void *result, size_t size){
	if (size==sizeof(float)){
		*(float*)result=(*(float*)self)*(*(float*)other);
		return result;
	} else if (size==sizeof(double)){
		*(double*)result=(*(double*)self)*(*(double*)other);
		return result;
	}
#ifdef CUSTOM_PRE_PROC_ENABLED
	if (size==sizeof(long double)){
		*(long double*)result=(*(long double*)self)*(*(long double*)other);
		return result;
	}
#endif
	return result;
}

