#!/bin/bash
mkdir -m 600 sourceC
mkdir -m 600 sourceJava
contador=0
for fichero in `ls`
do
    extension=`echo $fichero | awk -F"." '{print $NF}'`
    case $extension in
        "java")
            contador=`expr $contador + 1`
            mv $fichero sourceJava
            ;;
        "c")
            contador=`expr $contador + 1`
            mv $fichero sourceC
            ;;
        *)
            ;;
    esac
done
echo "Numero de movimientos : " $contador
