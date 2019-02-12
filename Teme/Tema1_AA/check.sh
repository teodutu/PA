#! /bin/bash

if [ "$#" -ne 1 ]; then
    printf "Please specify which algorithm you want to test\n"
    printf "Usage: <./check.sh miller> or <./check.sh fermat>\n"
    exit 1
fi

if [ "$1" == "miller" ]; then
    printf "\n~~~~~~~~~~~~~~~~ Testing the Miller-Rabin Algorithm ~~~~~~~~~~~~~~~~\n\n"
    make build_miller
elif [ "$1" == "fermat" ]; then
    printf "\n~~~~~~~~~~~~~~~~ Testing Fermat's Algorithm ~~~~~~~~~~~~~~~~\n\n"
    make build_fermat
else
    printf "Please select either Fermat's or the Miller-Rabin Algorithm\n"
    printf "Usage: <./check.sh miller> or <./check.sh fermat>\n"
    exit 2
fi

if [ ! -d "out" ]; then
    mkdir "out"
fi

make generator

printf "\nGenerating input tests...\n"
./generator

printf "\nRunning the tests...\n"
./find_primes

make clean
