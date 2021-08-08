#include <stddef.h>
#include "../src/Print.h"
#include "Debug.h"

int main(int argc, char **argv){
	Print_t.objectDebug("GenericList",NULL,genericListDebug());
	Print_t.objectDebug("String",NULL,stringDebug());
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
