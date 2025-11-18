#!/bin/bash

# Detect the directory of this script — this *is* your project root
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Move to project root if not already there
if [[ "$(pwd)" != "$PROJECT_ROOT" ]]; then
    cd "$PROJECT_ROOT" || exit
fi

# Nuke old build
rm -rf build

# Configure & build
cmake -B build
cmake --build build

# Move into build/tests if it exists
if [[ -d build/tests ]]; then
    cd build/tests || exit
    echo "Now inside build/tests ✔"
else
    echo "Warning: build/tests does not exist ❗"
fi
