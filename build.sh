#!/bin/sh
FILE=./build/exe/schm

make clean && make all && "$FILE"