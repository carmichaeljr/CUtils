#ifndef OUTPUT_FILE_STREAM_CLASS
#define OUTPUT_FILE_STREAM_CLASS

#include <stdio.h>
#include <stdbool.h>
#include "../objectSystem/Object.h"

//Class: OutputFileStream
//The struct that appends formatted output to a file.
//
//General usage is as follows:
//--- Code
//OutputFileStream *stream=new(OutputFileStream);
//OutputFileStream_t.<func to call>(stream, <params>);
//...
//delete(OutputFileStream,stream);
//---
typedef struct OutputFileStream {
        //Variable: output
        //
        //  - Default: NULL
        FILE *output;
        //Variable: errorCode
        //Stores the error code if any errors occur while writing to the output file.
        //
        //  - Default: 0
        int errorCode;
} OutputFileStream;

extern const struct OutputFileStream_t {
        Class class;
        //Function: setFileFromPntr
        //Sets the file for the output stream to write to from an already opened file.
        //The file is assumed to be in write mode.
        //This is useful for setting the output file to stdout.
        //
        //Parameters:
        //
        //  self - The file stream to perform the operation on.
        //  fPntr - The pointer to the already opened file to write to.
        //
        //Returns:
        //
        //  True if the output file was changed, false if not.
        bool (*setFileFromPntr)(OutputFileStream *self, FILE *fPntr);
        bool (*close)(OutputFileStream *self);
} OutputFileStream_t;

#endif
