#!/bin/sh

set -e

usage() {
    echo "Usage: $0 -t <template>"
}

template="$1"

if [ -z "${template}" ]; then
    usage
    exit 1
fi

generate() {
    arr=("$@")
    syntax=${arr[0]}
    package_manager=${arr[1]}
    test_framework=${arr[2]}

    echo "Generating ${template}-${syntax}-${package_manager}-${test_framework}"

    rm -rf _generated;
    printf "Demo\n\n\n${syntax}\n${package_manager}\n${test_framework}\n2\n" | spin new "${template}" _generated
    cd _generated
    if [ $package_manager = "1" ]; then
        esy test
    else
        make test
    fi
    cd ..
}


configuration=(1 1 1)
generate "${configuration[@]}"

configuration=(1 1 2)
generate "${configuration[@]}"

configuration=(1 2 1)
generate "${configuration[@]}"

configuration=(1 2 2)
generate "${configuration[@]}"

configuration=(2 1 1)
generate "${configuration[@]}"

configuration=(2 1 2)
generate "${configuration[@]}"

configuration=(2 2 1)
generate "${configuration[@]}"

configuration=(2 2 2)
generate "${configuration[@]}"
