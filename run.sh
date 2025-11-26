#!/bin/bash

PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

if [[ "$(pwd)" != "$PROJECT_ROOT" ]]; then
    cd "$PROJECT_ROOT" || exit
fi

# Nuke old build
rm -rf build

# Configure & build
cmake -B build
cmake --build build

cd build/tests
$SHELL
