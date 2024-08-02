/**
 * Copyright (c) 2024 Astrl.
 *
 * This file is part of libVoid. It is subject to the license terms in
 * the LICENSE file found in the top-level directory of this project and at
 * https://github.com/The-Astrl-Project/libvoid/blob/HEAD/LICENSE.
 *
 * This file may not be copied, modified, propagated, or distributed
 * except according to the terms contained in the LICENSE file.
 */

// Header Declarations
// ----------------------------------------------------------------
#include <stdio.h>
// ---
#include "include/main.h"
#include "include/array.h"
// ---

// ----------------------------------------------------------------

// Macro Definitions

// File Docstring
// --------------------------------
// libVoid || src/main.c <-> include/main.h
//
// Example project used for testing of features and functions.
//
// @author @MaxineToTheStars <https://github.com/MaxineToTheStars>
// ----------------------------------------------------------------

// Struct Definitions

// Enum Definitions

// Type Definitions

// Variable Definitions

// Main
int main()
{
    // Logging/Error handling
    void *status_one;

    // Allocate a new array
    struct lvd_array *array_one;

    // Create new arrays of different sizes
    status_one = lvd_array_new(&array_one, 8, sizeof(char));

    // Validate
    if (status_one == NULL)
    {
        // Log
        printf("Failed at check #1\n");

        // Return
        return -1;
    }

    // Append new data to the array
    status_one = lvd_array_append(&array_one, "The Quick Brown Fox Jumps Over The Lazy Dog\n", 45);

    // Validate
    if (status_one == NULL)
    {
        // Log
        printf("Failed at check #2\n");

        // Return
        return -1;
    }

    // Append new data to the array
    status_one = lvd_array_append(&array_one, "The Quick Brown Fox Jumps Over The Lazy Dog\n", 45);

    // Validate
    if (status_one == NULL)
    {
        // Log
        printf("Failed at check #3\n");

        // Return
        return -1;
    }

    // Print data
    printf("%s\n", (char *)status_one);

    // Exit
    return 0;
}

// Methods
