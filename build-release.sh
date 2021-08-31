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

mkdir -p release
rm -r release/*
mkdir -p release/lib
rm -r release/lib/*
mkdir -p release/include
rm -r release/include/*

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

printf "Running: Archive             : ./build/*.o -> ./release/lib/libcutil.a"
printLine " " 100 "\r"
ar -rc ./release/lib/libcutil.a ./build/*.o

for inputFile in $(find ./src -type f \( -iname "*.h" \))
do
	noSrcFile=${inputFile:5}
	printf "Running: Copy                : $inputFile -> ./release/include/cutil$noSrcFile"
	printLine " " 100 "\r"
	mkdir -p ./release/include/cutil${noSrcFile%/*} && cp $inputFile ./release/include/cutil${noSrcFile}
done
