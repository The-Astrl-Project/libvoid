# Copyright (c) 2025 Astrl.
#
# This file is part of libVoid. It is subject to the license terms in
# the LICENSE file found in the top-level directory of this project and at
# https://github.com/The-Astrl-Project/libvoid/blob/HEAD/LICENSE.
#
# This file may not be copied, modified, propagated, or distributed
# except according to the terms contained in the LICENSE file.

# Shebang
#!/usr/bin/env bash

# Constants
declare -r POSSIBLE_OPTIONS=":ghcbti"

# Main
function main()
{
    # Parse arguments
    while getopts ${POSSIBLE_OPTIONS} opt; do
        case ${opt} in
            g)
                # Show the license blurb
                blurb

                # Exit
                exit
            ;;
            h)
                # Show the help message
                help

                # Exit
                exit
            ;;
            c)
                # Clean the build directory
                clean

                # Exit
                exit
            ;;
            b)
                # Build from source
                build

                # Exit
                exit
            ;;
            t)
                # Run meson tests
                tests

                # Exit
                exit
            ;;
            i)
                # Install project
                install

                # Exit
                exit
            ;;
            ?)
                # Invalid argument/option
                echo "Invalid argument!"
                echo

                # Show the help message
                help

                # Exit
                exit
            ;;
        esac
    done
}

# Functions
function blurb()
{
    echo
    echo "Copyright (c) 2025 Astrl."
    echo
    echo "This program is part of libVoid. It is subject to the license terms in"
    echo "the LICENSE file found in the top-level directory of this project and at"
    echo "https://github.com/The-Astrl-Project/libvoid/blob/HEAD/LICENSE."
    echo
    echo "This program may not be copied, modified, propagated, or distributed"
    echo "except according to the terms contained in the LICENSE file."
    echo
}

function help()
{
    echo "Astrl: libVoid Build Script - Provide utility functions for building libVoid"
    echo
    echo "Syntax: build.sh [-g|h|c|b|t]"
    echo "options:"
    echo "g     Print the GPL license"
    echo "h     Print this help message"
    echo "c     Clean the build directory"
    echo "b     Build the project"
    echo "t     Run project unit tests"
    echo
}

function clean()
{
    # Check if ./build exists
    if [ -d ./build ]; then
        # Nuke
        rm -rf ./build > /dev/null 2>&1
    fi

    # Create a new build directory
    meson setup ./build > /dev/null 2>&1

    # Log
    echo "Build directory cleaned!"
}

function build()
{
    # Check if ./build exists
    if [ -d ./build ]; then
        # Switch to ./build
        cd ./build

        # Compile
        meson compile

        # Exit
        exit
    fi

    # Create a new build directory
    meson setup ./build > /dev/null 2>&1

    # Log
    echo "Created build directory"

    # Re-run
    build
}

function tests()
{
    # Check if ./build exists
    if [ -d ./build ]; then
        # Switch to ./build
        cd ./build

        # Compile
        meson test

        # Exit
        exit
    fi

    # Create a new build directory
    meson setup ./build > /dev/null 2>&1

    # Log
    echo "Created build directory"

    # Re-run
    tests
}

function install()
{
    # Check if ./build exists
    if [ -d ./build ]; then
        # Switch to ./build
        cd ./build

        # Compile
        meson install

        # Exit
        exit
    fi

    # Create a new build directory
    meson setup ./build > /dev/null 2>&1

    # Log
    echo "Created build directory"

    # Re-run
    install
}

# Execute
main ${@}
