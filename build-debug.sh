#!/bin/bash

function printLine {
	num=$(( 100-${#1} ))
	echo -n "$1"
	v=$(printf "%0*s\r" "${num}" "                                                                                      ")
	echo -n "${v// / }"
}

mkdir -p build
rm -r build/*

mkdir -p bin

declare -i fileID=0
for inputFile in $(find ./debug ./src -type f \( -iname "*.c" \))
do
	printLine "Running: C Pre-Processor     : $inputFile -> ./build/$fileID.i"
	if [[ "$1" == "enabled" ]]; then
		./src/objectSystem/customPreProcessor.sh $inputFile ./build/$fileID.i
	else
		gcc -E $inputFile > ./build/$fileID.i
	fi

	printLine "Running: GCC Compiler        : ./build/$fileID.i -> ./build/$fileID.o"
	gcc -Wpointer-arith -Wall -g -c ./build/$fileID.i -o ./build/$fileID.o

	fileID=$(( fileID+1 ))
done

printLine "Running: GCC Linker          : ./build/*.o -> ./bin/main_$OSTYPE.exe"
gcc ./build/*.o -lm -o ./bin/main_${OSTYPE}.exe

printLine "Running: ./bin/main_${OSTYPE}.exe"
./bin/main_$OSTYPE.exe
