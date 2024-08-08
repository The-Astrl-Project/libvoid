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
#include <stdlib.h>
#include <string.h>
// ---
#include "include/str.h"
// ---

// ----------------------------------------------------------------

// Macro Definitions

// File Docstring
// --------------------------------
// libVoid || src/str.c <-> include/str.h
//
// A string type implementation.
//
// @author @MaxineToTheStars <https://github.com/MaxineToTheStars>
// ----------------------------------------------------------------

// Struct Definitions
struct lvd_string
{
    /* Stores the pointer to the string buffer */
    char *_string_buffer;
};

// Enum Definitions

// Type Definitions

// Variable Definitions

// Main

// Methods
void *lvd_string_new(struct lvd_string **string, const char *string_value)
{
    // Temporary function scope variables
    void *struct_alloc;
    void *string_buffer_ptr_alloc;

    // Allocate memory for a new lvd_string struct
    struct_alloc = calloc(1, sizeof(struct lvd_string));

    // Allocate memory for a new lvd_string string buffer
    string_buffer_ptr_alloc = calloc(strlen(string_value), sizeof(char));

    // Check if allocation was successful
    if (struct_alloc == NULL || string_buffer_ptr_alloc == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Update the string struct
    (*string) = struct_alloc;
    (*string)->_string_buffer = string_buffer_ptr_alloc;

    // Return the string buffer pointer
    return (*string)->_string_buffer;

failure:
    // Return NULL
    return NULL;
}
