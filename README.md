# Generic Collections In C
A library to make dynamic memory management easier in C

As stated above, this is a library and does nothing useful on its own. The goals of this project are two fold:
  - Bring a pseudo-OO paradigm to C. This paradigm is a subset of full OOP and is comprised of composition and interfaces.
  - Bring generic collections (a.k.a. generic data structures) to C.

### Pseudo OO
This library adds the ability to create, destroy, and manage objects in C. Every object has a allocator, constructor, copy constructor, destructor, and deallocator. These operations form the basis of an objects life cycle, implicitly creating a memory management system.

Other features of the pseudo OO system are:
  - Full support for basic types\* with zero memory overhead on a per-object level. In other words, an ```int``` is still just an ```int```. See ```BasicTypeDemo``` in the examples folder for more details.


###### Footnotes
* When the custom preprocessor is enabled. Only a subset (basic types without spaces in there names) are supported without it.

### NOTE: This repository is undergoing a major rework and the README below this point is no longer accurate. It will be updated when the rework is farther along. See the docs for accurate information.
A library to make dynamic memory management easier in C

As stated above, this is a library and does nothing usefull on its own. Its main purpose is for easy creation of collections in C. The following collections are provided by this library:
* GenericList - represented by an array in memory, this is intended for small items like characters and integers.
* GenericLinkedList - represented by a series of linked nodes in memory, this is for larger items like structres.
* GenericDictionary - represented by two linked lists, this is for storing key value pairs.
* GenericTree - represented by a hierarchy of nodes, this is for storing hierarchical information

Built ontop of each of these generic structres are the below non-generic collections. These are an example of how to extend the above generic representations. You can create more non-generic collections as necessary.
* IntList - Build ontop of the GenericList for storing lists of integers.
* String - Built ontop of the GenericList for storing character arrays, and supports dynamic operations such as concat, trimSubstring, etc.
* StringList - Built ontop of the GenericLinkedList, for storing a list of strings
* StrStrDictionary - Built ontop of the generic dictionary for storing key/value pairs that are both strings.
* XMLFile - Built ontop of the GenericTree, for parsing and writing an XML file.

### Sudo OOP
The code in this repository is orginized in a sudo OOP way. A class structure is defined in tandem with an object structure to form the basis of the OO model. There is a very clear template for defining a class and its associated object structure that is shown in every source file.
This is not a full OO system, advanced features like inheritance and method overloading are not supported. (Do note that composition is supported)

### Building The Library
Building the program is easy, just run the below command in the same directory as all of the source files.

```shell
gcc -Wpointer-arith -Wall -o bin/main.exe debug/*.h debug/*.c src/*
```

When run the only thing executed is the debug operations. The output of the debug operations is shown below. If there are any errors, the text in the bracket will say 'Error' not 'Ok'

```shell
./main
[Ok   ]: 'File' class
[Ok   ]: 'GenericList' class
[Ok   ]: 'GenericLinkedList' class
[Ok   ]: 'GenericDictionary' class
[Ok   ]: 'GenericTree' class
[Ok   ]: 'IntList' class
[Ok   ]: 'String' class
[Ok   ]: 'StringList' class
[Ok   ]: 'StrStrDictionary' class
[Ok   ]: 'XMLTag' class
[Ok   ]: 'XMLFile' class
```
### Todo/Fix
* Create [profiler](https://www.youtube.com/watch?v=xlAH4dbMVnU) and [this](https://gist.github.com/TheCherno/31f135eea6ee729ab5f26a6908eb3a5e).
* Add a reference counter to the object system along with getReference/deleteReference methods so an object can be deleted with its last reference. [This link](http://calmarius.net/?lang=en&page=programming%2Fresource_management_exceptions_and_templates_in_c) may be usefull.
* The file class needs some major work. It works as it is, but barely
* Look into using templates to define classes. [This link](https://stackoverflow.com/questions/10950828/simulation-of-templates-in-c-for-a-queue-data-type) may be usefull
* The GenericDictionary class allows the addition of multiple keys with the same value
* Add copyBetween methods to GenericTree and XMLFile
