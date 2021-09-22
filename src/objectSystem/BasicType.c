#include <string.h>
#include "BasicType.h"

bool unsignedEqOperator(const void * const first, const void * const second, size_t size);
bool unsignedNeqOperator(const void * const first, const void * const second, size_t size);
bool unsignedGtOperator(const void * const first, const void * const second, size_t size);
bool unsignedGteOperator(const void * const first, const void * const second, size_t size);
bool unsignedLtOperator(const void * const first, const void * const second, size_t size);
bool unsignedLteOperator(const void * const first, const void * const second, size_t size);
bool signedEqOperator(const void * const first, const void * const second, size_t size);
bool signedNeqOperator(const void * const first, const void * const second, size_t size);
bool signedGtOperator(const void * const first, const void * const second, size_t size);
bool signedGteOperator(const void * const first, const void * const second, size_t size);
bool signedLtOperator(const void * const first, const void * const second, size_t size);
bool signedLteOperator(const void * const first, const void * const second, size_t size);
bool floatEqOperator(const void * const first, const void * const second, size_t size);
bool floatNeqOperator(const void * const first, const void * const second, size_t size);
bool floatGtOperator(const void * const first, const void * const second, size_t size);
bool floatGteOperator(const void * const first, const void * const second, size_t size);
bool floatLtOperator(const void * const first, const void * const second, size_t size);
bool floatLteOperator(const void * const first, const void * const second, size_t size);

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
	.set=memcpy,
};

//Unsigned Operators===========================================================
bool unsignedEqOperator(const void * const first, const void * const second, size_t size){
	if (size==sizeof(unsigned char)){
		return (*(unsigned char*)first==*(unsigned char*)second); 
	} else if (size==sizeof(unsigned short)){	//also unsigned short int
		return (*(unsigned short*)first==*(unsigned short*)second); 
	} else if (size==sizeof(unsigned)){		//also unsigned int
		return (*(unsigned*)first==*(unsigned*)second);
	} else if (size==sizeof(unsigned long)){	//also unsigned long int
		return (*(unsigned long*)first==*(unsigned long*)second); 
	} else if (size==sizeof(unsigned long long)){	//also unsigned long long int
		return (*(unsigned long long*)first==*(unsigned long long*)second); 
	}
	return false;
}

bool unsignedNeqOperator(const void * const first, const void * const second, size_t size){
	return !unsignedEqOperator(first,second,size);
}

bool unsignedGtOperator(const void * const first, const void * const second, size_t size){
	if (size==sizeof(unsigned char)){
		return (*(unsigned char*)first>*(unsigned char*)second); 
	} else if (size==sizeof(unsigned short)){	//also unsigned short int
		return (*(unsigned short*)first>*(unsigned short*)second); 
	} else if (size==sizeof(unsigned)){		//also unsigned int
		return (*(unsigned*)first>*(unsigned*)second);
	} else if (size==sizeof(unsigned long)){	//also unsigned long int
		return (*(unsigned long*)first>*(unsigned long*)second); 
	} else if (size==sizeof(unsigned long long)){	//also unsigned long long int
		return (*(unsigned long long*)first>*(unsigned long long*)second); 
	}
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

//Signed Operators=============================================================
bool signedEqOperator(const void * const first, const void * const second, size_t size){
	if (size==sizeof(char)){
		return (*(char*)first==*(char*)second); 
	} else if (size==sizeof(signed char)){
		return (*(signed char*)first==*(signed char*)second);
	} else if (size==sizeof(short)){	//also short int, signed short, signed short int
		return (*(short*)first==*(short*)second); 
	} else if (size==sizeof(int)){		//also signed int
		return (*(int*)first==*(int*)second); 
	} else if (size==sizeof(long)){		//also long int, signed long, signed long int
		return (*(long*)first==*(long*)second); 
	} else if (size==sizeof(long long)){	//also long long int, signed long long, signed long long int
		return (*(long long*)first==*(long long*)second);
	}
	return false;
}

bool signedNeqOperator(const void * const first, const void * const second, size_t size){
	return !signedEqOperator(first,second,size);
}

bool signedGtOperator(const void * const first, const void * const second, size_t size){
	if (size==sizeof(char)){
		return (*(char*)first>*(char*)second); 
	} else if (size==sizeof(signed char)){
		return (*(signed char*)first>*(signed char*)second);
	} else if (size==sizeof(short)){	//also short int, signed short, signed short int
		return (*(short*)first>*(short*)second); 
	} else if (size==sizeof(int)){		//also signed int
		return (*(int*)first>*(int*)second); 
	} else if (size==sizeof(long)){		//also long int, signed long, signed long int
		return (*(long*)first>*(long*)second); 
	} else if (size==sizeof(long long)){	//also long long int, signed long long, signed long long int
		return (*(long long*)first>*(long long*)second);
	}
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

//Float Operations=============================================================
bool floatEqOperator(const void * const first, const void * const second, size_t size){
	if (size==sizeof(float)){
		return (*(float*)first==*(float*)second);
	} else if (size==sizeof(double)){
		return (*(double*)first==*(double*)second);
	} else if (size==sizeof(long double)){
		return (*(long double*)first==*(long double*)second);
	}
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
	} else if (size==sizeof(long double)){
		return (*(long double*)first>*(long double*)second);
	}
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
