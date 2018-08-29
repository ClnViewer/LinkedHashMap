#!/bin/bash

    if [[ "${1}" == "0" ]] ;
    then
        echo "repo path is null"
        exit 100
    fi

    export PATH=/usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin:/root/bin

    cd "${1}/build"

    /usr/bin/gcc -std=gnu99 -Wall -pedantic -D__BUILD_HASHMAP=1 -I../src \
        -Wfatal-errors -pedantic-errors \
        ../src/hashmap-link-hash.c ../test/main.c -o ./testDeployBuild
    rc=$?
    if [[ "${rc}" != "0" ]] ;
    then
        echo "${3} rev.${2} - make/gcc stage error: ${rc}"
        exit ${rc}
    fi

    ./testDeployBuild
    rc=$?

    rm -f ./testDeployBuild

    exit ${rc}
