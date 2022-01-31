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
void* unsignedAddSelfOp(void *self, const void * const other, size_t size);
void* unsignedSubOp(const void * const self, const void * const other, void *result, size_t size);
void* unsignedSubSelfOp(void *self, const void * const other, size_t size);
bool signedEqOperator(const void * const first, const void * const second, size_t size);
bool signedNeqOperator(const void * const first, const void * const second, size_t size);
bool signedGtOperator(const void * const first, const void * const second, size_t size);
bool signedGteOperator(const void * const first, const void * const second, size_t size);
bool signedLtOperator(const void * const first, const void * const second, size_t size);
bool signedLteOperator(const void * const first, const void * const second, size_t size);
void* signedAddOp(const void * const self, const void * const other, void *result, size_t size);
void* signedAddSelfOp(void *self, const void * const other, size_t size);
void* signedSubOp(const void * const self, const void * const other, void *result, size_t size);
void* signedSubSelfOp(void *self, const void * const other, size_t size);
bool floatEqOperator(const void * const first, const void * const second, size_t size);
bool floatNeqOperator(const void * const first, const void * const second, size_t size);
bool floatGtOperator(const void * const first, const void * const second, size_t size);
bool floatGteOperator(const void * const first, const void * const second, size_t size);
bool floatLtOperator(const void * const first, const void * const second, size_t size);
bool floatLteOperator(const void * const first, const void * const second, size_t size);
void* floatAddOp(const void * const self, const void * const other, void *result, size_t size);
void* floatAddSelfOp(void *self, const void * const other, size_t size);
void* floatSubOp(const void * const self, const void * const other, void *result, size_t size);
void* floatSubSelfOp(void *self, const void * const other, size_t size);

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
	.addOperators={
		.op=unsignedAddOp,
		.opSelf=unsignedAddSelfOp,
	},
	.subOperators={
		.op=unsignedSubOp,
		.opSelf=unsignedSubSelfOp,
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
	.addOperators={
		.op=signedAddOp,
		.opSelf=signedAddSelfOp,
	},
	.subOperators={
		.op=signedSubOp,
		.opSelf=signedSubSelfOp,
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
	.addOperators={
		.op=floatAddOp,
		.opSelf=floatAddSelfOp,
	},
	.subOperators={
		.op=floatSubOp,
		.opSelf=floatSubSelfOp,
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
		result=((result==NULL)? new(unsigned): result);
		*(unsigned*)result=*(unsigned*)self+*(unsigned*)other;
		return result;
	} 
#ifdef CUSTOM_PRE_PROC_ENABLED
	if (size==sizeof(unsigned char)){
		result=((result==NULL)? new(unsigned char): result);
		*(unsigned char*)result=0;		//adding chars is undefined
		return result;
	} else if (size==sizeof(unsigned short)){
		//also unsigned short int
		result=((result==NULL)? new(unsigned short): result);
		*(unsigned short*)result=*(unsigned short*)self+*(unsigned short*)other;
		return result;
	} else if (size==sizeof(unsigned long)){
		//also unsigned long int
		result=((result==NULL)? new(unsigned long): result);
		*(unsigned long*)result=*(unsigned long*)self+*(unsigned long*)other;
		return result;
	} else if (size==sizeof(unsigned long long)){
		//also unsigned long long int
		result=((result==NULL)? new(unsigned long long): result);
		*(unsigned long long*)result=*(unsigned long long*)self+*(unsigned long long*)other;
		return result;
	}
#endif
	return result;
}

void* unsignedAddSelfOp(void *self, const void * const other, size_t size){
	return unsignedAddOp(self,other,self,size);
}

void* unsignedSubOp(const void * const self, const void * const other, void *result, size_t size){
	if (size==sizeof(unsigned)){
		//also unsigned int
		result=((result==NULL)? new(unsigned): result);
		*(unsigned*)result=*(unsigned*)self-*(unsigned*)other;
		return result;
	} 
#ifdef CUSTOM_PRE_PROC_ENABLED
	if (size==sizeof(unsigned char)){
		result=((result==NULL)? new(unsigned char): result);
		*(unsigned char*)result=0;		//subtracting chars is undefined
		return result;
	} else if (size==sizeof(unsigned short)){
		//also unsigned short int
		result=((result==NULL)? new(unsigned short): result);
		*(unsigned short*)result=*(unsigned short*)self-*(unsigned short*)other;
		return result;
	} else if (size==sizeof(unsigned long)){
		//also unsigned long int
		result=((result==NULL)? new(unsigned long): result);
		*(unsigned long*)result=*(unsigned long*)self-*(unsigned long*)other;
		return result;
	} else if (size==sizeof(unsigned long long)){
		//also unsigned long long int
		result=((result==NULL)? new(unsigned long long): result);
		*(unsigned long long*)result=*(unsigned long long*)self-*(unsigned long long*)other;
		return result;
	}
#endif
	return result;
}


void* unsignedSubSelfOp(void *self, const void * const other, size_t size){
	return unsignedSubOp(self,other,self,size);
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
		result=((result==NULL)? new(char): result);
		*(char*)result=0;	//Adding characters is undefined
		return result;
	} else if (size==sizeof(short)){
		//also short int, signed short, signed short int
		result=((result==NULL)? new(short): result);
		*(short*)result=*(short*)self+*(short*)other;
		return result;
	} else if (size==sizeof(int)){
		//also signed int
		result=((result==NULL)? new(int): result);
		*(int*)result=*(int*)self+*(int*)other;
		return result;
	} else if (size==sizeof(long)){
		//also long int, signed long, signed long int
		result=((result==NULL)? new(long): result);
		*(long*)result=*(long*)self+*(long*)other;
		return result;
	} 
#ifdef CUSTOM_PRE_PROC_ENABLED	
	if (size==sizeof(long long)){
		//also long long int, signed long long, signed long long int
		result=((result==NULL)? new(long long): result);
		*(long long*)result=*(long long*)self+*(long long*)other;
		return result;
	}
#endif
	return result;
}

void* signedAddSelfOp(void *self, const void * const other, size_t size){
	return signedAddOp(self,other,self,size);
}

void* signedSubOp(const void * const self, const void * const other, void *result, size_t size){
	if (size==sizeof(char)){
		//also signed char
		result=((result==NULL)? new(char): result);
		*(char*)result=0;	//subtracting characters is undefined
		return result;
	} else if (size==sizeof(short)){
		//also short int, signed short, signed short int
		result=((result==NULL)? new(short): result);
		*(short*)result=*(short*)self-*(short*)other;
		return result;
	} else if (size==sizeof(int)){
		//also signed int
		result=((result==NULL)? new(int): result);
		*(int*)result=*(int*)self-*(int*)other;
		return result;
	} else if (size==sizeof(long)){
		//also long int, signed long, signed long int
		result=((result==NULL)? new(long): result);
		*(long*)result=*(long*)self-*(long*)other;
		return result;
	} 
#ifdef CUSTOM_PRE_PROC_ENABLED	
	if (size==sizeof(long long)){
		//also long long int, signed long long, signed long long int
		result=((result==NULL)? new(long long): result);
		*(long long*)result=*(long long*)self-*(long long*)other;
		return result;
	}
#endif
	return result;
}

void* signedSubSelfOp(void *self, const void * const other, size_t size){
	return signedSubOp(self,other,self,size);
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
		result=((result==NULL)? new(float): result);
		*(float*)result=*(float*)self+*(float*)other;
		return result;
	} else if (size==sizeof(double)){
		result=((result==NULL)? new(double): result);
		*(double*)result=*(double*)self+*(double*)other;
		return result;
	}
#ifdef CUSTOM_PRE_PROC_ENABLED
	if (size==sizeof(long double)){
		result=((result==NULL)? new(long double): result);
		*(long double*)result=*(long double*)self+*(long double*)other;
		return result;
	}
#endif
	return result;
}

void* floatAddSelfOp(void *self, const void * const other, size_t size){
	return floatAddOp(self,other,self,size);
}

void* floatSubOp(const void * const self, const void * const other, void *result, size_t size){
	if (size==sizeof(float)){
		result=((result==NULL)? new(float): result);
		*(float*)result=*(float*)self-*(float*)other;
		return result;
	} else if (size==sizeof(double)){
		result=((result==NULL)? new(double): result);
		*(double*)result=*(double*)self-*(double*)other;
		return result;
	}
#ifdef CUSTOM_PRE_PROC_ENABLED
	if (size==sizeof(long double)){
		result=((result==NULL)? new(long double): result);
		*(long double*)result=*(long double*)self-*(long double*)other;
		return result;
	}
#endif
	return result;
}

void* floatSubSelfOp(void *self, const void * const other, size_t size){
	return floatSubOp(self,other,self,size);
}

