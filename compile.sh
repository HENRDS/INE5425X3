#!/usr/bin/env bash

set -eu
shopt -s extglob nullglob

if [[ ! -d ./bin/ ]]; then
    mkdir ./bin
    echo "Creating ./bin"
fi

if type cmake &> /dev/null; then
    cd bin
    if [[ ../CMakeLists.txt -nt ./bin/CMakeCache.txt ]]; then
        cmake ..
    fi
    make
else
    for f in *.cc; do
        obj_f="./bin/${f%.*}.o"
        if [[ "$f" -nt "$obj_f" ]]; then
            g++ -Wall -c -std=c++11 -no-pie -o "$obj_f" "$f"
            echo "compile $f -> $obj_f"
        fi
    done
    g++ -Wall -no-pie ./bin/*.o -o ./bin/INE5425X3
    echo "----------------------------"
    echo "Compiled to ./bin/INE5425X3."
fi
