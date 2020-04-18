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

    if [ $syntax = "1" ]; then
        syntax_name="reason"
    elif [ $syntax = "2" ]; then
        syntax_name="ocaml"
    fi

    if [ $package_manager = "1" ]; then
        package_manager_name="esy"
    elif [ $package_manager = "2" ]; then
        package_manager_name="opam"
    fi

    if [ $test_framework = "1" ]; then
        test_framework_name="rely"
    elif [ $test_framework = "2" ]; then
        test_framework_name="alcotest"
    fi
    
    full_name="${template}-${syntax_name}-${package_manager_name}-${test_framework_name}"

    echo "Generating ${full_name}"

    rm -rf _generated;
    printf "Demo\n\n\n${syntax}\n${package_manager}\n${test_framework}\n1\n" | spin new "${template}" _generated
    cd _generated
    if [ $package_manager = "1" ]; then
        esy test
    else
        make test
    fi
    # Uncomment to publish to Github
    # gh repo create "spin-playground/${full_name}" --public | true
    # git init
    # git add -A
    # git commit -m "Initial commit"
    # git remote add origin "git@github.com:spin-playground/${full_name}.git"
    # git push -f origin master
    cd ..
    echo "Created repository https://github.com/spin-playground/${full_name}"
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
