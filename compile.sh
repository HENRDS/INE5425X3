#!/usr/bin/env bash


set -eu

if [[ -d bin/ ]]; then 
    rm -rf bin/**
else
    mkdir bin
fi
cd bin
cmake .. 
make
