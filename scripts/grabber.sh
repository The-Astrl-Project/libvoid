# Copyright (c) 2024 Astrl.
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
declare -r POSSIBLE_OPTIONS=":ghsi"
declare -r SOURCE_DIRECTORY="./src"
declare -r INCLUDE_DIRECTORY="./include"

# Main
function main()
{
    # Parse arguments
    while getopts ${POSSIBLE_OPTIONS} opt; do
        case ${opt} in
            g)
                # Show the license blurb
                blurb
            ;;
            h)
                # Show the help message
                help
            ;;
            s)
                # Glob files found in ./src
                glob $SOURCE_DIRECTORY
            ;;
            i)
                # Glob all files found in ./include
                glob $INCLUDE_DIRECTORY
            ;;
            ?)
                # Invalid
                echo "Invalid argument!"
                echo

                # Show the help message
                help
            ;;
        esac
    done
}

# Functions
function blurb()
{
    echo
    echo "Copyright (c) 2024 Astrl."
    echo
    echo "This file is part of libVoid. It is subject to the license terms in"
    echo "the LICENSE file found in the top-level directory of this project and at"
    echo "https://github.com/The-Astrl-Project/libvoid/blob/HEAD/LICENSE."
    echo
    echo "This file may not be copied, modified, propagated, or distributed"
    echo "except according to the terms contained in the LICENSE file."
    echo
}

function help()
{
    echo "Astrl: libVoid Grabber - Globs all *.c files found in /src"
    echo
    echo "Syntax: grabber.sh [-g|h|c]"
    echo "options:"
    echo "g     Print the GPL license"
    echo "h     Print this help message"
    echo "s     Collects and echos all found source files"
    echo "i     Collects and echos all found header files"
    echo
}

function glob()
{
    # Recursively list all *.c files
    _recursive_search $1
}

function _recursive_search()
{
    for file in "${1}"/*; do
        # Is a directory?
        if [ -d "${file}" ]; then
            # Begin recursive search
            _recursive_search "${file}"

            # Is a file?
            elif [ -f "${file}" ]; then
            # Print
            echo "${file}"
        fi
    done
}

# Execute
main ${@}
