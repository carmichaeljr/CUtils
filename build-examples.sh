#!/bin/bash

function printLine {
	str=$1
	num=$2
	v=$(printf "%-${num}s" "$str")
	echo -n "${v// / }"
	printf "$3"
}

mkdir -p build
rm -r build/*

declare -i fileID=0
for inputFile in $(find ./src -type f \( -iname "*.c" \))
do
	printf "Running: C Pre-Processor     : $inputFile -> ./build/$fileID.i"
	printLine " " 100 "\r"
	if [[ "$1" == "enabled" ]]; then
		./src/objectSystem/customPreProcessor.sh $inputFile ./build/$fileID.i
	else
		gcc -E $inputFile > ./build/$fileID.i
	fi

	printf "Running: GCC Compiler        : ./build/$fileID.i -> ./build/$fileID.o"
	printLine " " 100 "\r"
	gcc -Wpointer-arith -Wall -g -c ./build/$fileID.i -o ./build/$fileID.o

	fileID=$(( fileID+1 ))
done

fileID=$(( fileID+1 ))
for inputFile in $(find ./examples -type f \( -iname "*.c" \))
do
	printf "Running: C Pre-Processor     : $inputFile -> ./build/$fileID.i"
	printLine " " 100 "\r"
	if [[ "$1" == "enabled" ]]; then
		./src/objectSystem/customPreProcessor.sh $inputFile ./build/$fileID.i
	else
		gcc -E $inputFile > ./build/$fileID.i
	fi

	printf "Running: GCC Compiler        : ./build/$fileID.i -> ./build/$fileID.o"
	printLine " " 100 "\r"
	gcc -Wpointer-arith -Wall -c ./build/$fileID.i -o ./build/$fileID.o

	printf "Running: GCC Linker          : ./build/*.o -> ./bin/${inputFile%.*}_$OSTYPE.exe"
	printLine " " 100 "\r"
	gcc ./build/*.o -o ${inputFile%.*}_${OSTYPE}.exe
done
