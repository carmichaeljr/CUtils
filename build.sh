#!/bin/bash

function printLine {
	str=$1
	num=$2
	v=$(printf "%-${num}s" "$str")
	echo -n "${v// / }"
	printf "$3"
}

mkdir -p build

declare -i fileID=0
for inputFile in $(find ./debug ./src -type f \( -iname "*.h" -o -iname "*.c" \))
do
	if [[ $? -eq 0 ]]; then
		printf "Running: C Pre-Processor     : $inputFile -> ./build/$fileID.i"
		printLine " " 100 "\r"
		gcc -D CUSTOM_PRE_PROC_ENABLED -E $inputFile > ./build/$fileID.i
	else
		return $?
	fi

	if [[ $? -eq 0 ]]; then
		printf "Running: Custom Pre-Processor: $inputFile -> ./build/$fileID.i"
		printLine " " 100 "\r"
		./src/customPreProcessor.sh ./build/$fileID.i
	else
		return $?
	fi

	if [[ $? -eq 0 ]]; then
		printf "Running: GCC Compiler        : ./build/$fileID.i -> ./build/$fileID.o"
		printLine " " 100 "\r"
		gcc -Wpointer-arith -Wall -c ./build/$fileID.i -o ./build/$fileID.o
	else
		return $?
	fi

	fileID=$(( fileID+1 ))
done

if [[ $? -eq 0 ]]; then
	printf "Running: GCC Linker                  : ./build/*.o -> ./bin/main_$OSTYPE.exe"
	printLine " " 150 "\r"
	gcc ./build/*.o -o ./bin/main_${OSTYPE}.exe
else
	return $?
fi

if [[ $? -eq 0 ]]; then
	printf "Running: ./bin/main_${OSTYPE}.exe"
	printLine " " 150 "\n"
	./bin/main_$OSTYPE.exe
fi
