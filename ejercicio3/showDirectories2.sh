#!/bin/bash

if [[ $# -eq 1 ]]
then
    for directory in `ls -l $1 | grep "^d" | awk '{print $NF}'`
    do
        echo $directory
    done
else
    echo "ERROR!! <---Parametros no ingresados o ingresados de forma erronea-->"
fi
