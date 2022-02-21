1. Rework
  - Remove debug code from production code
  - Fix memory leaks
  - Add const qualifiers to applicable function parameters
1. Object System
  - Add iterator to string class
  - Add setVal to iterator
  - Add operator overloading (separate equals from class struct, add move to class struct)
  - Add forEachResult (calls a given function on each member of a list and stores the result in a genericlist)
1. Finish implementing file class
  - Windows support
  - Linux support
1. Finish implementing OutputFileStream class
  - Rename (is it really a stream?)
  - Update Print_t to work with OutputFileStream and stdout
1. Add InputFileStream class
  - Works with stdin
  - Parse various data types
1. Finish adding generic data collections
  - Doubly linked list
  - Map
  - Set
  - BinaryTree
  - Heap
1. Add sorting functions that act on generic collections
  - Relies on operator overloading
    - quick sort, merge sort, radix sort


Add color support to print class

```
IO/InputFileStream.c
	FILE
	.readLine
	.nextInt
	.nextFloat
	.nextDouble
	.nextBool
	.nextChar
	.readUntil
	.isOk=returns true if the stream has not encountered an error
	.eof=returns true if end of steam has been reached
	.close
	.rewind(bytes)
```
