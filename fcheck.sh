#!/bin/bash

usage='
CREDIT: Jason
OVERVIEW
    fcheck.sh is a wrapper script of LLVM/clang-format.
USAGE
    fcheck.sh <error|write> [<file> [<file> ...]]

DESCRIPTION
    fcheck.sh provides two flavors of format-checking

        <error> will dump the error messages of violating contents
        <write> will modify violating contents in-place [BE CAREFUL!]

    The format targets are specified by file paths following the flavor option.
    If file list is not given, a file collector is executed to recursively
    collects "*.[ch]pp" files in .../outline/ that are p4-opened.

EXAMPLE
    a) `$ fcheck.sh error Outline.cpp Outline.hpp`
        dumps error messages for violating contents found in Outline.cpp and
        Outline.hpp.

    b) `$ fcheck.sh write Outline.cpp Outline.hpp`
        modifies violating contents found in Outline.cpp and Outline.hpp.

    c) `$ fcheck.sh error *.[ch]pp`
        does format-checking on all ".cpp" and ".hpp" files found in current
        directory.

    d) `$ find -type f -name "*.[ch]pp" | xargs ./fcheck.sh error`
        does format-checking on all ".cpp" and ".hpp" files found recursively
        in current and child directories.
# bash fcheck.sh error ./*.cpp
'

# CF_PATH='/u/ltgdev/depot/llvm/13/bin/clang-format'
CF_PATH='/usr/bin/clang-format'

# Get clang-format flags
if [[ $1 == 'error' ]]; then
    CF_FLAGS='--dry-run --Werror --verbose'
elif [[ $1 == 'write' ]]; then
    CF_FLAGS='-i --verbose'
else
    echo "first argument should be either 'write' or 'error'"
    echo -e "${usage}"
    exit 1
fi
shift 1

# Collect format targets
if [ $# -gt 0 ]; then
    CF_TARGETS=$*
else
    echo "[outline/fcheck.sh] <Files> are not given.  Try collecting '*.[ch]pp' files in current and child directories that are p4-opend"
    CF_TARGETS=`p4 opened ./... | grep -v 'delete' | sed -e 's/#.*//' |
                grep -e='*.[ch]pp' | xargs -r p4 have | sed -e 's/.* - //'`
fi

# Generate and execute clang-format command
CF_COMMAND="${CF_PATH} ${CF_FLAGS} ${CF_TARGETS}"
exec ${CF_COMMAND}