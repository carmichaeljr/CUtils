#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include "Print.h"

static int indentLevel=0;
static int lineLength=120;
static int spacesPerIndent=4;
static void incrementIndentLevel(const int increment);
static void setSpacesPerIndent(const int numSpaces);
static void print(const char* format, ...);
static void println(const char* format, ...);
static void printWithoutIndent(const char *format, ...);
static void objectDebug(const char *className, const char *methodName, const bool success);
static void objectDebugWithLine(const char *className, const char *methodName, const int line, const bool success);
static int printIndent(void);
static void printLineFiller(int charsPrinted);

const struct PrintClass Print_t={
	.incrementIndentLevel=incrementIndentLevel,
	.setSpacesPerIndent=setSpacesPerIndent,
	.objectDebug=objectDebug,
	.objectDebugWithLine=objectDebugWithLine,
	.print=print,
	.println=println,
	.printWithoutIndent=printWithoutIndent
};

//Class Methods================================================================
static void incrementIndentLevel(const int increment){
	if (indentLevel+increment>=0){
		indentLevel+=increment;
	}
}

static void setSpacesPerIndent(const int numSpaces){
	if (numSpaces>0){
		spacesPerIndent=numSpaces;
	}
}

static void print(const char *format, ...){
	va_list argp;
	va_start(argp,format);
	printLineFiller(printIndent()+vprintf(format,argp));
	va_end(argp);
}

static void println(const char *format, ...){
	va_list argp;
	va_start(argp,format);
	printLineFiller(printIndent()+vprintf(format,argp));
	va_end(argp);
	printf("\n");
}

static void printWithoutIndent(const char *format, ...){
	va_list argp;
	va_start(argp,format);
	printLineFiller(vprintf(format,argp));
	va_end(argp);
}

static void objectDebug(const char *className, const char *methodName, const bool success){
	if (methodName!=NULL){
		Print_t.print("[%-5s]: Class '%s': Method '%s'",(success)? "Ok": "Error",className, methodName);	
	} else {
		Print_t.print("[%-5s]: Class '%s'",(success)? "Ok": "Error",className);	
	}
	printf("%c",(success)? '\r': '\n');
}

static void objectDebugWithLine(const char *className, const char *methodName, const int line, const bool success){
	if (methodName!=NULL){
		Print_t.print("[%-5s]: Class '%s': Method '%s': Test Line %d",(success)? "Ok": "Error",className, methodName,line);	
	} else {
		Print_t.print("[%-5s]: Class '%s': Test Line %d",(success)? "Ok": "Error",className,line);	
	}
	printf("%c",(success)? '\r': '\n');
}

//Private methods
static int printIndent(void){
	for (int i=0; i<indentLevel*spacesPerIndent; i++){
		printf(" ");
	}
	return indentLevel*spacesPerIndent;
}

static void printLineFiller(int charsPrinted){
	for (int i=0; i<(lineLength-charsPrinted); printf(" "), i++);
}
