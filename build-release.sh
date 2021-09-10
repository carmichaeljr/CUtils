#!/bin/bash

function printLine {
	num=$(( 100-${#1} ))
	echo -n "$1"
	v=$(printf "%0*s\r" "${num}" "                                                                                      ")
	echo -n "${v// / }"
}

mkdir -p build
rm -r build/*

mkdir -p release
rm -r release/*
mkdir -p release/lib
rm -r release/lib/*
mkdir -p release/include
rm -r release/include/*

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

printLine "Running: Archive             : ./build/*.o -> ./release/lib/libcutil.a"
ar -rc ./release/lib/libcutil.a ./build/*.o

for inputFile in $(find ./src -type f \( -iname "*.h" \))
do
	noSrcFile=${inputFile:5}
	printLine "Running: Copy                : $inputFile -> ./release/include/cutil$noSrcFile"
	mkdir -p ./release/include/cutil${noSrcFile%/*} && cp $inputFile ./release/include/cutil${noSrcFile}
done
