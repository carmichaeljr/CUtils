#!/bin/bash

# $1 is the time to sleep
# $2 is the bash script to run
while true
do
	clear
	source $2
	sleep $1
done
