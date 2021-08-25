#include <stdbool.h>
#include "OutputFileStream.h"

static void constructor(void *obj);
static void* copyConstructor(void *obj, const void * const other, size_t size);
//static void print(const GenericList * const obj);
static int comparator(const void *self, const void *other, size_t size);
static void destructor(void *obj);
//setFile
static bool setFileFromPntr(OutputFileStream *self, FILE *fPntr);
//write
//writeln
//flush
static bool close(OutputFileStream *self);

const struct OutputFileStream_t OutputFileStream_t={
	.class=ALLOC_ONLY_DEFAULT_CLASS,
        .setFileFromPntr=setFileFromPntr,
        .close=close,
};

//Class Methods=================================================================
static void constructor(void *obj){
	OutputFileStream *ofStreamObj=(OutputFileStream*)obj;
        ofStreamObj->output=NULL;
        ofStreamObj->errorCode=0;
}

static void* copyConstructor(void *obj, const void * const other, size_t size){
        return NULL;
}

//static void print(const GenericList * const obj){
//	Print_t.print("<GenericList Obj[Addr: %p]: NumElements: %d  ElementSize: %d>",
//			obj,obj->numElements,obj->elementSize);
//}

static int comparator(const void *first, const void *second, size_t size){
        return -1;
}

static void destructor(void *obj){
        OutputFileStream *ofStreamObj=(OutputFileStream*)obj;
        close(ofStreamObj);
}

//Object Methods================================================================
//Public methods
static bool setFile(OutputFileStream *self, const char * const path){
        //TODO - Use files class to check files existence later
        return false;
}

static bool setFileFromPntr(OutputFileStream *self, FILE *fPntr){
        if (self->output!=fPntr){
                close(self);
                self->output=fPntr;
                return true;
        }
        return false;
}

static bool close(OutputFileStream *self){
        //call flush
        if (self->output!=NULL && self->output!=stdout &&
            self->output!=stdin && self->output!=stderr){
                return (fclose(self->output)==0)? true: false;
        }
        return false;
}

//Private Methods
