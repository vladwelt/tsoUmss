#!/bin/bash
cd ~
for fichero in `ls -l | grep '^-' | awk '{print $NF}' | cut -d "." -f 1 | grep '[^A-Za-z]'`
    do
        echo $fichero
    done
