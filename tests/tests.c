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
#include <assert.h>
#include <stdlib.h>
// ---
#include "include/array.h"
// ---

// ----------------------------------------------------------------

// Macro Definitions

// File Docstring
// --------------------------------
// libVoid || tests/tests.c <-> none
//
// libVoid testing suite.
//
// @author @MaxineToTheStars <https://github.com/MaxineToTheStars>
// ----------------------------------------------------------------

// Struct Definitions

// Enum Definitions

// Type Definitions

// Variable Definitions

// Main
void tests_basic_functionality();

int main()
{
    // Test basic functionality
    tests_basic_functionality();
}

// Methods
void tests_basic_functionality()
{
    // Logging/Error handling
    void *exit_status;

    // Delcare a new lvd_array
    struct lvd_array *array;

    // Separator
    printf("-- tests_basic_functionality::1 --\n");

    // Create a new array with 16 indicies of size char
    exit_status = lvd_array_new(&array, 16, sizeof(char));

    // Validate
    printf("Validating new lvd_array of length 16, size char...\n");
    assert(exit_status != NULL && array != NULL);
    printf("Success!\n");

    // Clean up
    lvd_array_free(&array);

    // Separator
    printf("-- tests_basic_functionality::2 --\n");

    // Create a new array with 0 indicies of size int
    exit_status = lvd_array_new(&array, 0, sizeof(int));

    // Validate
    printf("Validating new lvd_array of length 0, size int...\n");
    assert(exit_status != NULL && array != NULL);
    printf("Success!\n");

    // Clean up
    lvd_array_free(&array);
}
