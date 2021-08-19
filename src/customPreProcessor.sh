#!/bin/bash
sed -i 's|unsigned BasicType_t|BasicType_t|g;
	s|signed BasicType_t|BasicType_t|g;
	s|shot BasicType_t|BasicType_t|g;
	s|signed short BasicType_t|BasicType_t|g;
	s|unsigned short BasicType_t|BasicType_t|g;
	s|long BasicType_t|BasicType_t|g;
	s|signed long BasicType_t|BasicType_t|g;
	s|unsigned long BasicType_t|BasicType_t|g;
	s|long BasicType_t|BasicType_t|g;
	s|long long BasicType_t|BasicType_t|g;
	s|signed long BasicType_t|BasicType_t|g;
	s|signed long long BasicType_t|BasicType_t|g;
	s|unsigned long BasicType_t|BasicType_t|g;
	s|unsigned long long BasicType_t|BasicType_t|g;' $1
