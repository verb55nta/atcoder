#!/bin/bash

t=`pwd`
k=`basename $t`

#arr=("a" "b" "c" "d" "e" "f")

acc new $k -c all

for i in a b c d e f
do
    cp main.cpp Makefile $k/$i
    mv $k/$i/tests $k/$i/test
done


