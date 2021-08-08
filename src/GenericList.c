#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GenericList.h"
#include "Object.h"
#include "Print.h"

static GenericList* constructor(void);
static void destructor(GenericList **obj);
static void print(const GenericList * const obj);
static void setElementSize(GenericList *self, const size_t newSize);
static void setListSize(GenericList *self, const int numElements);
static void set(GenericList *self, const void * const newELements, const int numElements);
static void setAt(GenericList *self, const void * const newElements, const int numElements, const int index);
static void add(GenericList *self, const void * const newElement, const int numElements);
static void addAt(GenericList *self, const void * const newElement, const int numElements, int index);
static void copyOtherBetween(GenericList *self, const GenericList * const other, const int startIndex, const int EndIndex);
static void* get(const GenericList * const self, const int index);
static bool contains(const GenericList * const self, const void * const token);
static int getFirstIndexOf(const GenericList *self, const void *token);
static int getLastIndexOf(const GenericList * const self, const void * const token);
static void _remove(GenericList *self, const void * const token);
static void removeAt(GenericList *self, const int index);
static void removeBetween(GenericList *self, const int startIndex, const int endIndex);
static void trimToSize(GenericList *self, const int numElements);
static void clear(GenericList *self);
static bool isEmpty(const GenericList * const self);
static bool equals(const GenericList * const self, const GenericList * const other);
static bool isInit(const GenericList * const self);
static bool resizeMemoryBlock(GenericList *self, const int newLen);
static bool newMemoryBlock(GenericList *self, const int newLen);
static void* getPointerToLocation(const GenericList *self, const int index);
static bool areListsCompatible(const GenericList *self, const GenericList *other);

const struct GenericListClass GenericList_t={
	.new=constructor,
	.delete=destructor,
	.print=print,
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
	.removeAt=removeAt,
	.removeBetween=removeBetween,
	.trimToSize=trimToSize,
	.clear=clear,
	.isEmpty=isEmpty,
	.equals=equals
};

//Object Methods================================================================
//Public methods
static void setElementSize(GenericList *self, const size_t newSize){
	if (newSize!=self->elementSize){
		if (!GenericList_t.isEmpty(self)){
			GenericList_t.clear(self);
		}
		self->elementSize=newSize;
	}
}

static void setListSize(GenericList *self, const int numElements){
	if (isInit(self)){
		if (newMemoryBlock(self,numElements)){
			self->numElements=numElements;
		}
	}
}

static void set(GenericList *self, const void * const newElements, const int numElements){
	if (isInit(self)){
		if (newMemoryBlock(self,numElements)){
			memcpy(self->list,newElements,self->elementSize*numElements);
			self->numElements=numElements;
		}
	}
}

static void setAt(GenericList *self, const void * const newElements, const int numElements, const int index){
	if (isInit(self) && !GenericList_t.isEmpty(self) &&
	    index>=0 && index<self->numElements){
		void *destination=getPointerToLocation(self,index);
		int numCopieableElements=(numElements+index<self->numElements)? numElements: self->numElements-index;
		memcpy(destination,newElements,self->elementSize*numCopieableElements);
	} else if (GenericList_t.isEmpty(self)){
		GenericList_t.set(self,newElements,numElements);
	}
}

static void add(GenericList *self, const void * const newElements, const int numElements){
	if (isInit(self) && 
	    resizeMemoryBlock(self,self->numElements+numElements)){
		self->numElements+=numElements;
		void *temp=getPointerToLocation(self,self->numElements-numElements);
		memmove(temp,newElements,self->elementSize*numElements);
	}
}

static void addAt(GenericList *self, const void * const newElements, const int numElements, const int index){
	if (isInit(self) && !GenericList_t.isEmpty(self) && 
	    index>=0 && index<self->numElements){
		if (resizeMemoryBlock(self,self->numElements+numElements)){
			self->numElements+=numElements;
			void *source=getPointerToLocation(self,index);
			void *destination=getPointerToLocation(self,index+numElements);
			int size=self->elementSize*(self->numElements-index-1);
			memmove(destination,source,size);
			memcpy(source,newElements,self->elementSize*numElements);
		}
	} else if (GenericList_t.isEmpty(self) || index==self->numElements){
		GenericList_t.add(self,newElements,numElements);
	}
}

static void copyOtherBetween(GenericList *self, const GenericList * const other, const int startIndex, const int endIndex){
	if (areListsCompatible(self,other) && !GenericList_t.isEmpty(other)){
		int start=(startIndex<0)? 0: startIndex;
		int end=(endIndex>other->numElements)? other->numElements: endIndex;
		if (end>start && newMemoryBlock(self,end-start)){
			void *source=getPointerToLocation(other,start);
			if (source!=NULL){
				memcpy(self->list,source,self->elementSize*(end-start));
				self->numElements=end-start;
			}
		}
	}
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

static void _remove(GenericList *self, const void * const token){
	int offset=0;
	if (isInit(self) && !GenericList_t.isEmpty(self)){
		for (int i=0; i<self->numElements; i++){
			void *iterElement=getPointerToLocation(self,i);
			if (memcmp(iterElement,token,self->elementSize)!=0){
				void *destination=getPointerToLocation(self,i-offset);
				memmove(destination,iterElement,self->elementSize);
			} else {
				offset++;
			}
		}
		resizeMemoryBlock(self,self->numElements-offset);
		self->numElements-=offset;
	}
}

static void removeAt(GenericList *self, const int index){
	removeBetween(self,index,index+1);
}

static void removeBetween(GenericList *self, const int startIndex, const int endIndex){
	if (isInit(self) && !GenericList_t.isEmpty(self) &&
	    startIndex>=0 && startIndex<endIndex && endIndex<=self->numElements){
		void *destination=getPointerToLocation(self,startIndex);
		void *source=getPointerToLocation(self,endIndex);
		int size=self->elementSize*(self->numElements-endIndex);
		if (destination!=NULL && source!=NULL){
			memmove(destination,source,size);
		}
		resizeMemoryBlock(self,self->numElements-(endIndex-startIndex));
		self->numElements-=(endIndex-startIndex);
	}
}

static void trimToSize(GenericList *self, const int numElements){
	if (!GenericList_t.isEmpty(self) && isInit(self) && 
	    numElements<self->numElements){
		if (numElements>0 && resizeMemoryBlock(self,numElements)){
			self->numElements=numElements;
		} else if (numElements==0){
			clear(self);
		}
	}
}

static void clear(GenericList *self){
	if (!GenericList_t.isEmpty(self)){
		if (self->list!=NULL){
			free(self->list);
			self->list=NULL;
		}
		self->numElements=0;
	}
}

static bool isEmpty(const GenericList * const self){
	if (self->list==NULL || self->numElements==0){
		return true;
	}
	return false;
}

static bool equals(const GenericList * const self, const GenericList * const other){
	bool rv=false;
	if (areListsCompatible(self,other) && self->numElements==other->numElements &&
	    self->list!=NULL && other->list!=NULL){
		int size=self->numElements*self->elementSize;
		if (memcmp(self->list,other->list,size)==0){
			rv=true;
		}
	}
	return rv;
}

//Private Methods
static bool isInit(const GenericList * const self){
	return (self->elementSize>0)? true: false;
}

static bool resizeMemoryBlock(GenericList *self, const int newLen){
	void *reallocPntr=realloc(self->list,self->elementSize*newLen);
	if (reallocPntr!=NULL){
		self->list=reallocPntr;
		return true;
	}
	self->list=NULL;
	return false;
}

static bool newMemoryBlock(GenericList *self, const int newLen){
	if (self->list!=NULL){
		free(self->list);
	}
	void *mallocPntr=malloc(self->elementSize*newLen);
	if (mallocPntr!=NULL){
		self->list=mallocPntr;
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

//Class Methods=================================================================
static GenericList* constructor(void){
	GenericList *rv=createObject(sizeof(GenericList));
	rv->list=NULL;
	rv->elementSize=0;
	rv->numElements=0;
	return rv;
}

static void print(const GenericList * const obj){
	Print_t.print("<GenericList Obj[Addr: %p]: NumElements: %d  ElementSize: %d>\n",
			obj,obj->numElements,obj->elementSize);
}

static void destructor(GenericList **obj){
	free((*obj)->list);
	deleteObject((void**)obj);
}
