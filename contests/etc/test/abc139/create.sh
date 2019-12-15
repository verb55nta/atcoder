#!/bin/bash

t=`pwd`
k=`basename $t`

mkdir $k
cp main.cpp Makefile $k/a
cp main.cpp Makefile $k/b
cp main.cpp Makefile $k/c
cp main.cpp Makefile $k/d
cp main.cpp Makefile $k/e
cp main.cpp Makefile $k/f
acc new $k -c all
