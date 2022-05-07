#!/bin/sh
FILE=./build/exe/schm

if test -f "$FILE"; then 
    "$FILE"
else 
    echo "$FILE doesn't exist!"
fi