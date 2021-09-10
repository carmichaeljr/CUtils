#!/bin/bash

function printLine {
	num=$(( 100-${#1} ))
	echo -n "$1"
	v=$(printf "%0*s\r" "${num}" "                                                                                      ")
	echo -n "${v// / }"
}

mkdir -p build
rm -r build/*

declare -i fileID=0
for inputFile in $(find ./src -type f \( -iname "*.c" \))
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

fileID=$(( fileID+1 ))
for inputFile in $(find ./examples -type f \( -iname "*.c" \))
do
	printLine "Running: C Pre-Processor     : $inputFile -> ./build/$fileID.i"
	if [[ "$1" == "enabled" ]]; then
		./src/objectSystem/customPreProcessor.sh $inputFile ./build/$fileID.i
	else
		gcc -E $inputFile > ./build/$fileID.i
	fi

	printLine "Running: GCC Compiler        : ./build/$fileID.i -> ./build/$fileID.o"
	gcc -Wpointer-arith -Wall -c ./build/$fileID.i -o ./build/$fileID.o

	printLine "Running: GCC Linker          : ./build/*.o -> ./bin/${inputFile%.*}_$OSTYPE.exe"
	gcc ./build/*.o -o ${inputFile%.*}_${OSTYPE}.exe
done
