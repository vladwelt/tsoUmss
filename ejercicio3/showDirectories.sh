#!/bin/bash

if [[ $# -eq 1 ]]
then
    for directory in `ls $1`
    do
        if [[ -d $1/$directory ]]
        then
           echo "DIRECTORY : " $directory
        fi
    done
else
    echo "ERROR!! <---Parametros no ingresados o ingresados de forma erronea-->"
fi
