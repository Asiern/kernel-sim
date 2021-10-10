#!/bin/bash

set -e

BUILD_TYPE="Debug"
if test "$1" = "--build"; then
    if test "$2" = "Release"; then
        BUILD_TYPE="Relase"
        echo "BUILD TYPE SET TO RELASE"
    fi
else
    echo "BUILD TYPE SET TO DEBUG"
fi

cmake -B build -DCMAKE_BUILD_TYPE=$BUILD_TYPE
