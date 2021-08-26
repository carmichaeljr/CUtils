#!/bin/bash

#$1 - The folder to place the class files
#$2 - The name of the class

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

cp "${SCRIPT_DIR}/ClassTemplate.h" "${1}"
cp "${SCRIPT_DIR}/ClassTemplate.c" "${1}"
mv "${1}/ClassTemplate.h" "${1}/${2}.h"
mv "${1}/ClassTemplate.c" "${1}/${2}.c"
sed -i "s|%CLASS_NAME%|${2}|g;" "${1}/${2}.h"
sed -i "s|%CLASS_NAME%|${2}|g;" "${1}/${2}.c"
