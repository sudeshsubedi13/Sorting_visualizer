#!/usr/bin/bash

mkdir -p builds
FILES="main.cpp"
for i in $(find src -type f -name "*.cpp"); do
    FILES+=" "
    FILES+=$i
done
g++ $FILES -I include -o builds/sorting -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network