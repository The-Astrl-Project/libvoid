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
#include "include/array.h"
// ---

// ----------------------------------------------------------------

// Macro Definitions

// File Docstring
// --------------------------------
// libVoid || src/array.c <-> include/array.h
//
// Allows for dynamically sized arrays during runtime.
//
// @author @MaxineToTheStars <https://github.com/MaxineToTheStars>
// ----------------------------------------------------------------

// Struct Definitions
struct lvd_array
{
    /* Stores the pointer to the array */
    void *_ptr;

    /* Stores the array length */
    int _array_length;

    /* Stores the array block size */
    unsigned long _array_size;
};

// Enum Definitions

// Type Definitions

// Variable Definitions

// Main

// Methods
void *lvd_array_new(struct lvd_array **array, const int array_length, const unsigned long array_size)
{
    // Allocate memory for a new lvd_array struct
    *array = (struct lvd_array *)calloc(1, sizeof(struct lvd_array));

    // Check if the allocation was successful
    if (*array == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Allocate a new array
    (*array)->_ptr = calloc(array_length, array_size);

    // Check if allocation was successful
    if ((*array)->_ptr == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Update struct
    (*array)->_array_size = array_size;
    (*array)->_array_length = array_length;

    // Return
    return (*array)->_ptr;

failure:
    // Return NULL
    return NULL;
}

int lvd_array_append(struct lvd_array **array, const void *buffer, const int buffer_length_size)
{
    // Validate the lvd_array struct is already initalized
    if (*array == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Re-allocate the array pointer
    (*array)->_ptr = realloc((*array)->_ptr, ((*array)->_array_length * (*array)->_array_size) + buffer_length_size);

    // Validate the re-allocation
    if ((*array)->_ptr == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Copy over data
    memcpy((*array)->_ptr + ((*array)->_array_length * (*array)->_array_size) + 1, buffer, buffer_length_size);

    // Update length value
    (*array)->_array_length = (*array)->_array_length + (buffer_length_size / (*array)->_array_size);

    // Return
    return 0;

failure:
    // Return -1
    return -1;
}
