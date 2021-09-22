#!/bin/bash

#Class: CustomPreProcessor
#The custom pre-processor is meant to be run on the output of the standard
#C pre-processor and enables features such as extended basic data type support.
#
#The custom pre-processor does not have to be a bash script, this is mainly
#supplied of an example of what needs to be done.
#
#Note that the custom pre-processor does *NOT* need to be run unless the features
#it supplies are needed. This means that for most applications it will
#not be needed.
#
#The customPreProcessor must define the CUSTOM_PRE_PROC_ENABLED macro when 
#calling the standard C pre-processor to enable the features created by the custom
#pre-processor.
#
#> gcc -E -D CUSTOM_PRE_PROC_ENABLED ...
#
#Extended Basic Data Types:
#
#In order to support extended basic data types, the following string replacements
#must be made:
#
#  - "unsigned long long SignedBasicType_t": UnsignedBasicType_t
#  - "signed long long SignedBasicType_t": SignedBasicType_t
#  - "unsigned long SignedBasicType_t": UnsignedBasicType_t
#  - "signed long SignedBasicType_t": SignedBasicType_t
#  - "signed long SignedBasicType_t": SignedBasicType_t
#  - "long long SignedBasicType_t": SignedBasicType_t
#  - "unsigned short SignedBasicType_t": UnsignedBasicType_t
#  - "signed short SignedBasicType_t": SignedBasicType_t
#  - "unsigned SignedBasicType_t": UnsignedBasicType_t
#  - "signed SignedBasicType_t": SignedBasicType_t
#  - "short SignedBasicType_t" : SignedBasicType_t
#  - "long SignedBasicType_t" : SignedBasicType_t
#  - "long FloatBasicType_t" : FloatBasicType_t
#
#These replacements must be made because the standard C pre-processor cannot replace
#a string with a space in it. For example, the below statement is not valid, but would
#be required to implement all of the standard C data types as a BasicType object.
#
#> #define "unsigned int_t" UnsigedBasicType_t
#
#Parameters:
#
#  $1 - The file to pre-process.
#  $2 - The file to place the pre-processors output.
gcc -D CUSTOM_PRE_PROC_ENABLED -E $1 > $2
sed -i 's|unsigned long long SignedBasicType_t|UnsignedBasicType_t|g;
	s|signed long long SignedBasicType_t|SignedBasicType_t|g;
	s|unsigned long SignedBasicType_t|UnsignedBasicType_t|g;
	s|signed long SignedBasicType_t|SignedBasicType_t|g;
	s|signed long SignedBasicType_t|SignedBasicType_t|g;
	s|long long SignedBasicType_t|SignedBasicType_t|g;
	s|unsigned short SignedBasicType_t|UnsignedBasicType_t|g;
	s|signed short SignedBasicType_t|SignedBasicType_t|g;
	s|unsigned SignedBasicType_t|UnsignedBasicType_t|g;
	s|signed SignedBasicType_t|SignedBasicType_t|g;
	s|short SignedBasicType_t|SignedBasicType_t|g;
	s|long SignedBasicType_t|SignedBasicType_t|g;
	s|long FloatBasicType_t|FloatBasicType_t|g;' $2
