#ifndef PRINT_CLASS
#define PRINT_CLASS

#include <stdbool.h>

struct PrintClass {
	void (*incrementIndentLevel)(const int increment);
	void (*setSpacesPerIndent)(const int numSpaces);
	void (*objectDebug)(const char *className, const char *methodName, const bool success);
	void (*print)(const char *format, ...);
	void (*println)(const char *format, ...);
	void (*printWithoutIndent)(const char *format, ...);
};

extern const struct PrintClass Print_t;

#endif
