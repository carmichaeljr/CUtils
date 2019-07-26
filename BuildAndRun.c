#include <stdio.h>
//#include "Math.h"
#include "File.h"
#include "GenericList.h"
#include "GenericLinkedList.h"
#include "GenericDictionary.h"
#include "GenericTree.h"
//#include "Arguments.h"
#include "IntList.h"
#include "String.h"
#include "StringList.h"
#include "StrStrDictionary.h"
#include "XMLTag.h"
#include "XMLFile.h"


int main(int argc, char **argv){
	FileClass.debug();
	GenericListClass.debug();
	GenericLinkedListClass.debug();
	GenericDictionaryClass.debug();
	GenericTreeClass.debug();
	IntListClass.debug();
	StringClass.debug();
	StringListClass.debug();
	StrStrDictionaryClass.debug();
	XMLTagClass.debug();
	XMLFileClass.debug();

	//MathClass.debug();
	//ArgumentsClass.debug();
	return 0;
}
