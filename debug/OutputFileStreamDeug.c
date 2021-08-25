#include "Debug.h"
#include "../src/objectSystem/Object.h"
#include "../src/IO/OutputFileStream.h"
#include "../src/IO/Print.h"

#define ofStreamTest(result) test(result,"OutputFileStream",__FUNCTION__,__LINE__)

static void setFileFromPntr(void);
static void close(void);

void outputStreamDebug(void){
        setFileFromPntr();
        close();
}

static void setFileFromPntr(void){
        OutputFileStream *test=new(OutputFileStream);
        ofStreamTest(test->output==NULL);
        ofStreamTest(OutputFileStream_t.setFileFromPntr(test,stdout));
        ofStreamTest(test->output==stdout);
        ofStreamTest(!OutputFileStream_t.setFileFromPntr(test,stdout));
        delete(OutputFileStream,test);
}

static void close(void){
        OutputFileStream *test=new(OutputFileStream);
        ofStreamTest(!OutputFileStream_t.close(test));
        OutputFileStream_t.setFileFromPntr(test,stdout);
        ofStreamTest(!OutputFileStream_t.close(test));
        OutputFileStream_t.setFileFromPntr(test,stderr);
        ofStreamTest(!OutputFileStream_t.close(test));
        delete(OutputFileStream,test);
}
