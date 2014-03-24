#!/bin/bash

for i in ${PATH//:/$'\n'}
do
    if [[ $i == "/usr/sbin" ]]
    then
        echo "/usr/bin <----EXISTE"
    elif [[ $i == "/sbin" ]]
    then
        echo "/sbin <---EXISTE"
    fi
done
