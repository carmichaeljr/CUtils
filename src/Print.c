#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include "Print.h"

int indentLevel=0;
int spacesPerIndent=4;
static void _PrintClass_IncrementIndentLevel(const int increment);
static void _PrintClass_SetSpacesPerIndent(const int numSpaces);
static void _PrintClass_Print(const char* format, ...);
static void _PrintClass_PrintWithoutIndent(const char *format, ...);
static void _PrintClass_ObjectDebug(const char *className, const bool success);

const struct PrintClass_t PrintClass={
	.incrementIndentLevel=&_PrintClass_IncrementIndentLevel,
	.setSpacesPerIndent=&_PrintClass_SetSpacesPerIndent,
	.objectDebug=&_PrintClass_ObjectDebug,
	.print=&_PrintClass_Print,
	.printWithoutIndent=&_PrintClass_PrintWithoutIndent,
};

//Class Methods================================================================
static void _PrintClass_IncrementIndentLevel(const int increment){
	if (indentLevel+increment>=0){
		indentLevel+=increment;
	}
}

static void _PrintClass_SetSpacesPerIndent(const int numSpaces){
	if (numSpaces>0){
		spacesPerIndent=numSpaces;
	}
}

static void _PrintClass_Print(const char *format, ...){
	va_list argp;
	va_start(argp,format);
	for (int i=0; i<indentLevel*spacesPerIndent; i++){
		printf(" ");
	}
	//printf("%.*c",indentLevel*2,'~');
	vprintf(format,argp);
	va_end(argp);
}

static void _PrintClass_PrintWithoutIndent(const char *format, ...){
	va_list argp;
	va_start(argp,format);
	vprintf(format,argp);
	va_end(argp);
}

static void _PrintClass_ObjectDebug(const char *className, const bool success){
	PrintClass.print("[%-5s]: '%s' class\n",(success)? "Ok": "Error",className);	
}
