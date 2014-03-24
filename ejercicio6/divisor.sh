#!/bin/bash

if [[ $# -eq 2 ]]
then
    if [[ -e $1 ]]
    then
        split -n $2 -d $1 $1
    else
        echo "ERROR!! <--Fichero no existente-->"
    fi
else
    echo "ERROR!! <--Parametros no ingresados-->"
fi
