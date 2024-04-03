#!/bin/sh

gcc -c *.c
ar rc -o libmy.a *.o
if [ ! -d "../../include" ]
then
   mkdir ../../include
fi
cp my.h ../../include
