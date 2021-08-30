#include "../src/objectSystem/Object.h"
#include "../src/collections/String.h"

int main(int argc, char **argv){
	String *demoString=new(String);

	delete(String,demoString);
}
