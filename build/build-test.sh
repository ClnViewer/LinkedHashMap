#!/bin/bash

    mkdir -p tests
    rm -Rf tests/*
    cd tests

    cmake -G "Unix Makefiles" .. -DCMAKE_BUILD_TYPE=Debug
    rc=$?
    if [[ "${rc}" != "0" ]] ;
    then
        echo "cmake stage #1 error: ${rc}"
        exit ${rc}
    fi


    cmake --build . --config "Debug"
    rc=$?
    if [[ "${rc}" != "0" ]] ;
    then
        echo "cmake stage #2 error: ${rc}"
        exit ${rc}
    fi

    cd ..

    exit ${rc}
