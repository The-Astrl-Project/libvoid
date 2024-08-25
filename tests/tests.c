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
#include <stdarg.h>
// ---
#include "include/strings.h"
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
void vargs_test(const char *format, ...);

int main()
{
    // TODO: Implement a proper test suite

    // Declare new lvd_string
    struct lvd_string *my_string;

    // Populate with some data
    lvd_string_new(&my_string, "Hello World!\n");

    // Print
    printf("[LOG] %s", (char *)lvd_string_get_value(&my_string));

    // Test formatting
    lvd_string_format_from(&my_string, "floats: %4.2f %+.0e %E\n", 3.1416, 3.1416, 3.1416);

    // Print
    printf("[FMT] %s", (char *)lvd_string_get_value(&my_string));

    // Re-test
    lvd_string_format_from(&my_string, "Preceding with zeros: %010d\n", 1977);

    // Print
    printf("[FMT] %s", (char *)lvd_string_get_value(&my_string));

    // Set the string value
    lvd_string_set_value(&my_string, "Goodbye World!\n");

    // Print
    printf("[LOG] %s", (char *)lvd_string_get_value(&my_string));

    // Reset the string value
    lvd_string_set_value(&my_string, NULL);

    // Print
    printf("[LOG] %s (Should be empty)\n", (char *)lvd_string_get_value(&my_string));

    // Set the string value
    lvd_string_set_value(&my_string, "Hello ");

    // Concat the string
    lvd_string_concat(&my_string, "again World!\n");

    // Print
    printf("[LOG] %s", (char *)lvd_string_get_value(&my_string));

    // Free
    lvd_string_free(&my_string);

    // Vargs testing
    vargs_test("floats: %4.2f %+.0e %E\n", 3.1416, 3.1416, 3.1416);
    vargs_test("Scientific notation: %e\n", 3.1416);

    // Exit
    return 0;
}

// Methods
void vargs_test(const char *format, ...)
{
    // Declare new lvd_string
    struct lvd_string *my_vargs_string;

    // Populate with some data
    lvd_string_new(&my_vargs_string, NULL);

    // Declare vargs list
    va_list args_ptr;

    // Initialize the argument list
    va_start(args_ptr, format);

    // Format
    lvd_string_format_from_vargs(&my_vargs_string, format, args_ptr);

    // End the argument list
    va_end(args_ptr);

    // Print
    printf("[FMT @ VARGS] %s", (char *)lvd_string_get_value(&my_vargs_string));

    // Free
    lvd_string_free(&my_vargs_string);
}
