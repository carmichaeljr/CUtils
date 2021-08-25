#include <stddef.h>
#include "Debug.h"

#define DEBUG_CUSTOM_PREPROC

int main(int argc, char **argv){
	resetTestResults();
	outputStreamDebug();
	basicTypesDebug();
	genericListDebug();
	genericLinkedListDebug();
	stringDebug();
	printTestResults();
	//FileClass.debug();
	//GenericListClass.debug();
	//GenericLinkedListClass.debug();
	//GenericDictionaryClass.debug();
	//GenericTreeClass.debug();
	//IntListClass.debug();
	//StringClass.debug();
	//StringListClass.debug();
	//StrStrDictionaryClass.debug();
	//XMLTagClass.debug();
	//XMLFileClass.debug();
	return 0;
}
