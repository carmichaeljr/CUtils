#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GenericList.h"
#include "../objectSystem/Object.h"
//#include "Print.h"

static void constructor(void *obj);
static void* copyConstructor(void *obj, const void * const other, size_t size);
//static void print(const GenericList * const obj);
static int comparator(const void *self, const void *other, size_t size);
static void destructor(void *obj);
static bool setElementSize(GenericList *self, const size_t newSize);
static bool setListSize(GenericList *self, const int numElements);
static bool set(GenericList *self, const void * const newELements, const int numElements);
static bool setAt(GenericList *self, const void * const newElements, const int numElements, const int index);
static bool add(GenericList *self, const void * const newElement, const int numElements);
static bool addAt(GenericList *self, const void * const newElement, const int numElements, int index);
static bool copyOtherBetween(GenericList *self, const GenericList * const other, const int startIndex, const int EndIndex);
static void* get(const GenericList * const self, const int index);
static bool contains(const GenericList * const self, const void * const token);
static int getFirstIndexOf(const GenericList *self, const void *token);
static int getLastIndexOf(const GenericList * const self, const void * const token);
static bool _remove(GenericList *self, const void * const token);
static bool removeAll(GenericList *self, const void * const tokens, const int numTokens);
static bool removeAt(GenericList *self, const int index);
static bool removeBetween(GenericList *self, const int startIndex, const int endIndex);
static bool trimToSize(GenericList *self);
static bool clear(GenericList *self);
static bool clearElements(GenericList *self);
static bool isEmpty(const GenericList * const self);
static bool isInit(const GenericList * const self);
static bool resizeMemoryBlock(GenericList *self, const int newLen);
static bool resizeMemoryBlockStrict(GenericList *self, const int newLen);
static void* getPointerToLocation(const GenericList *self, const int index);
static bool areListsCompatible(const GenericList *self, const GenericList *other);

const struct GenericList_t GenericList_t={
	.class=ALLOC_ONLY_DEFAULT_CLASS,
	.setElementSize=setElementSize,
	.setListSize=setListSize,
	.set=set,
	.setAt=setAt,
	.add=add,
	.addAt=addAt,
	.copyOtherBetween=copyOtherBetween,
	.get=get,
	.contains=contains,
	.getFirstIndexOf=getFirstIndexOf,
	.getLastIndexOf=getLastIndexOf,
	.remove=_remove,
	.removeAll=removeAll,
	.removeAt=removeAt,
	.removeBetween=removeBetween,
	.trimToSize=trimToSize,
	.clear=clear,
	.clearElements=clearElements,
	.isEmpty=isEmpty,
};

//Class Methods=================================================================
static void constructor(void *obj){
	GenericList *glObj=(GenericList*)obj;
	glObj->list=NULL;
	glObj->listSize=0;
	glObj->strictAlloc=false;
	glObj->numElements=0;
	glObj->elementSize=0;
}

static void* copyConstructor(void *obj, const void * const other, size_t size){
	GenericList *newObj=(GenericList*)obj;
	GenericList *copyObj=(GenericList*)other;
	newObj->list=NULL;
	newObj->listSize=0;
	newObj->numElements=0;
	newObj->elementSize=copyObj->elementSize;
	newObj->strictAlloc=copyObj->strictAlloc;
	GenericList_t.copyOtherBetween(newObj,copyObj,0,copyObj->numElements);
	return (void*)newObj;
}

//static void print(const GenericList * const obj){
//	Print_t.print("<GenericList Obj[Addr: %p]: NumElements: %d  ElementSize: %d>",
//			obj,obj->numElements,obj->elementSize);
//}

static int comparator(const void *first, const void *second, size_t size){
	bool rv=false;
	GenericList *self=(GenericList*)first;
	GenericList *other=(GenericList*)second;
	if (areListsCompatible(self,other) && self->numElements==other->numElements &&
	    self->list!=NULL && other->list!=NULL){
		int size=self->numElements*self->elementSize;
		if (memcmp(self->list,other->list,size)==0){
			rv=true;
		}
	}
	return rv;
}

static void destructor(void *obj){
	free(((GenericList*)obj)->list);
}

//Object Methods================================================================
//Public methods
static bool setElementSize(GenericList *self, const size_t newSize){
	if (newSize!=self->elementSize){
		if (!GenericList_t.isEmpty(self)){
			GenericList_t.clear(self);
		}
		self->elementSize=newSize;
		return true;
	}
	return false;
}

static bool setListSize(GenericList *self, const int numElements){
	return (isInit(self) && numElements>=0 && resizeMemoryBlock(self,numElements));
}

static bool set(GenericList *self, const void * const newElements, const int numElements){
	if (isInit(self) && resizeMemoryBlock(self,numElements)){
	       	memcpy(self->list,newElements,self->elementSize*numElements);
	       	self->numElements=numElements;
		return true;
	}
	return false;
}

static bool setAt(GenericList *self, const void * const newElements, const int numElements, const int index){
	if (isInit(self) && !GenericList_t.isEmpty(self) &&
	    index>=0 && index<self->numElements){
		void *destination=getPointerToLocation(self,index);
		int numCopieableElements=(numElements+index<self->numElements)? numElements: self->numElements-index;
		memcpy(destination,newElements,self->elementSize*numCopieableElements);
		return true;
	} else if (GenericList_t.isEmpty(self)){
		return GenericList_t.set(self,newElements,numElements);
	}
	return false;
}

static bool add(GenericList *self, const void * const newElements, const int numElements){
	if (isInit(self) && numElements>0 && resizeMemoryBlock(self,self->numElements+numElements)){
		self->numElements+=numElements;
		void *temp=getPointerToLocation(self,self->numElements-numElements);
		memmove(temp,newElements,self->elementSize*numElements);
		return true;
	}
	return false;
}

static bool addAt(GenericList *self, const void * const newElements, const int numElements, const int index){
	if (isInit(self) && !GenericList_t.isEmpty(self) && 
	    index>=0 && index<self->numElements && resizeMemoryBlock(self,self->numElements+numElements)){
		self->numElements+=numElements;
		void *source=getPointerToLocation(self,index);
		void *destination=getPointerToLocation(self,index+numElements);
		int size=self->elementSize*(self->numElements-index-1);
		memmove(destination,source,size);
		memcpy(source,newElements,self->elementSize*numElements);
		return true;
	} else if (GenericList_t.isEmpty(self) || index==self->numElements){
		return GenericList_t.add(self,newElements,numElements);
	}
	return false;
}

static bool copyOtherBetween(GenericList *self, const GenericList * const other, const int startIndex, const int endIndex){
	if (areListsCompatible(self,other) && !GenericList_t.isEmpty(other) &&
	    startIndex>=0 && startIndex<endIndex && endIndex<=other->numElements){
		if (resizeMemoryBlock(self,endIndex-startIndex)){
			void *source=getPointerToLocation(other,startIndex);
			if (source!=NULL){
				memcpy(self->list,source,self->elementSize*(endIndex-startIndex));
				self->numElements=endIndex-startIndex;
				return true;
			}
		}
	}
	return false;
}

static void* get(const GenericList * const self, const int index){
	if (!GenericList_t.isEmpty(self) && isInit(self)){
		return getPointerToLocation(self,index);
	}
	return NULL;
}

static bool contains(const GenericList * const self, const void * const token){
	bool rv=false;
	for (int i=0; i<self->numElements && !rv; i++){
		void *iterElement=getPointerToLocation(self,i);
		if (memcmp(iterElement,token,self->elementSize)==0){
			rv=true;
		}
	}
	return rv;
}

static int getFirstIndexOf(const GenericList * const self, const void * const token){
	int rv=-1;
	for (int i=0; i<self->numElements && rv==-1; i++){
		void *iterElement=getPointerToLocation(self,i);
		if (memcmp(iterElement,token,self->elementSize)==0){
			rv=i;
		}
	}
	return rv;
}

static int getLastIndexOf(const GenericList * const self, const void * const token){
	int rv=-1;
	for (int i=self->numElements-1; i>=0 && rv==-1; i--){
		void *iterElement=getPointerToLocation(self,i);
		if (memcmp(iterElement,token,self->elementSize)==0){
			rv=i;
		}
	}
	return rv;
}

static bool _remove(GenericList *self, const void * const token){
	return removeAll(self,token,1);
}

static bool removeAll(GenericList *self, const void * const tokens, const int numTokens){
	int offset=0;
	if (isInit(self) && !GenericList_t.isEmpty(self)){
		for (int j=0; j<numTokens; j++){
			void *iterToken=(void*)((char*)tokens+self->elementSize*j);
			for (int i=0; i<self->numElements; i++){
				void *iterElement=getPointerToLocation(self,i);
				if (memcmp(iterElement,iterToken,self->elementSize)!=0){
					void *destination=getPointerToLocation(self,i-offset);
					memmove(destination,iterElement,self->elementSize);
				} else {
					offset++;
				}
			}
			self->numElements-=offset;
			offset=0;
		}
		return resizeMemoryBlock(self,self->numElements);
	}
	return false;
}

static bool removeAt(GenericList *self, const int index){
	return removeBetween(self,index,index+1);
}

static bool removeBetween(GenericList *self, const int startIndex, const int endIndex){
	if (isInit(self) && !GenericList_t.isEmpty(self) &&
	    startIndex>=0 && startIndex<endIndex && endIndex<=self->numElements){
		void *destination=getPointerToLocation(self,startIndex);
		void *source=getPointerToLocation(self,endIndex);
		int size=self->elementSize*(self->numElements-endIndex);
		if (destination!=NULL && source!=NULL){
			memmove(destination,source,size);
		}
		self->numElements-=(endIndex-startIndex);
		return resizeMemoryBlock(self,self->numElements);
	}
	return false;
}

static bool trimToSize(GenericList *self){
	if (!GenericList_t.isEmpty(self) && isInit(self) && 
	    !self->strictAlloc && self->numElements!=self->listSize){
		return resizeMemoryBlockStrict(self,self->numElements);
	}
	return false;
}

static bool clear(GenericList *self){
	if (!GenericList_t.isEmpty(self) && resizeMemoryBlock(self,0)){
		self->numElements=0;
		return true;
	}
	return false;
}

static bool clearElements(GenericList *self){
	self->numElements=0;
	return true;
}

static bool isEmpty(const GenericList * const self){
	if (self->list==NULL || self->numElements==0){
		return true;
	}
	return false;
}

//Private Methods
static bool isInit(const GenericList * const self){
	return (self->elementSize>0);
}

static bool resizeMemoryBlock(GenericList *self, const int newLen){
	if (!self->strictAlloc){
		if (newLen>0 && (self->listSize>newLen*2 || self->listSize<newLen)){
			void *reallocPntr=realloc(self->list,self->elementSize*newLen);
			if (reallocPntr!=NULL){
				self->list=reallocPntr;
				self->listSize=newLen;
				return true;
			}
		} else if (newLen==0){
			free(self->list);
			self->list=NULL;
			self->listSize=0;
			return true;
		} else if (self->listSize>=newLen){
			return true;
		}
		return false;
	} else {
		return resizeMemoryBlockStrict(self,newLen);
	}
}

static bool resizeMemoryBlockStrict(GenericList *self, const int newLen){
	if (newLen>0){
		void *reallocPntr=realloc(self->list,self->elementSize*newLen);
		if (reallocPntr!=NULL){
			self->list=reallocPntr;
			self->listSize=newLen;
			return true;
		}
	} else if (newLen==0){
		free(self->list);
		self->list=NULL;
		self->listSize=0;
		return true;
	}
	return false;
}

static void* getPointerToLocation(const GenericList *self, const int index){
	if (index>=0 && index<self->numElements){
		return (void*)((char*)(self->list)+(self->elementSize*index));
	}
	return NULL;
}

static bool areListsCompatible(const GenericList *self, const GenericList *other){
	return (
		isInit(self) &&
		isInit(other) &&
		self->elementSize==other->elementSize
	       );
}
