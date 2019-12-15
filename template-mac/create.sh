#!/bin/bash

acc new $1 -c all
cp main.cpp Makefile $1/a
cp main.cpp Makefile $1/b
cp main.cpp Makefile $1/c
cp main.cpp Makefile $1/d
cp main.cpp Makefile $1/e
cp main.cpp Makefile $1/f

mv $1/a/tests $1/a/test
mv $1/b/tests $1/b/test
mv $1/c/tests $1/c/test
mv $1/d/tests $1/d/test
mv $1/e/tests $1/e/test
mv $1/f/tests $1/f/test