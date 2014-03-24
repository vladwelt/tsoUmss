#!/bin/bash

if [[ $# -eq 2 ]]
then
    if [[ -e $1 ]] && [[ -e $2 ]]
    then
        cat $1 > nuevo
        cat $2 >> nuevo
    else
        echo "ERROR!! <--ARHIVOS NO EXISTEN-->"
    fi
else
    echo "ERROR!! <---NO INGRESO LOS PARAMETROS CORRECTAMENTE-->"
fi
