#include <stddef.h>
#include "../src/Print.h"
#include "Debug.h"

int main(int argc, char **argv){
	resetTestResults();
	genericListDebug();
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
