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
    unsigned int _array_length;

    /* Stores the array block size */
    unsigned long _array_size;

    /* Stores the end index of the array */
    unsigned int _array_index_end;
};

// Enum Definitions

// Type Definitions

// Variable Definitions

// Main

// Methods
void *lvd_array_new(struct lvd_array **array, const unsigned int array_length, const unsigned long array_size)
{
    // Function scope variables
    void *tmp;

    // Allocate memory for a new lvd_array struct
    tmp = calloc(1, sizeof(struct lvd_array));

    // Check if the allocation was successful
    if (tmp == NULL)
    {
        // Set the array struct to NULL
        (*array) = NULL;

        // Jump to failure
        goto failure;
    }

    // Set the struct pointer
    (*array) = tmp;

    // Allocate a new array
    tmp = calloc(array_length, array_size);

    // Check if allocation was successful
    if (tmp == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Set the array pointer
    (*array)->_ptr = tmp;

    // Update struct
    (*array)->_array_size = array_size;
    (*array)->_array_length = array_length;
    (*array)->_array_index_end = 0;

    // Return
    return (*array)->_ptr;

failure:
    // Check if the array struct was initialized
    if ((*array) != NULL)
    {
        // Free
        free((*array));
    }

    // Return NULL
    return NULL;
}

void *lvd_array_append(struct lvd_array **array, const void *buffer, const unsigned int buffer_length_size)
{
    // Function scope variables
    void *tmp;

    // Validate the lvd_array struct is already initalized
    if ((*array) == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Validate the array still has available space
    int free_memory = ((*array)->_array_length - (*array)->_array_index_end);
    if (free_memory == 0 || free_memory < (buffer_length_size / (*array)->_array_size))
    {
        // Re-allocate the array pointer
        tmp = realloc((*array)->_ptr, ((*array)->_array_length * (*array)->_array_size) + buffer_length_size);

        // Validate the re-allocation
        if (tmp == NULL)
        {
            // Jump to failure
            goto failure;
        }

        // Update the array pointer
        (*array)->_ptr = tmp;

        // Zero out the new memory chunk
        memset((*array)->_ptr + ((*array)->_array_size * (*array)->_array_index_end), '\0', buffer_length_size);

        // Update the array length value
        (*array)->_array_length = (*array)->_array_length + (buffer_length_size / (*array)->_array_size);
    }

    // Stores the found terminator index
    int terminator_index = 0;
    // Find the first NULL terminator from array_index_end -> array_length (inclusive)
    for (int i = (*array)->_array_index_end; i <= (*array)->_array_length; i++)
    {
        // Get the current memory entry
        unsigned char *current_entry = (*array)->_ptr + (i * (*array)->_array_size);

        // Check if current entry is NULL
        if (*current_entry == '\0')
        {
            // Set the terminator index
            terminator_index = i;

            // Break
            break;
        }
    }

    // Copy over data
    memcpy((*array)->_ptr + (terminator_index * (*array)->_array_size), buffer, buffer_length_size);

    // Set the new array end
    (*array)->_array_index_end = terminator_index + (buffer_length_size / (*array)->_array_size);

    // Return
    return (*array)->_ptr;

failure:
    // Return NULL
    return NULL;
}

void *lvd_array_get(struct lvd_array **array, const unsigned int array_index)
{
    // Validate the lvd_array struct is already initalized
    if ((*array) == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Validate the index is not out of bounds
    // NOTE: I *could* have it check if the index is between
    //      start_index < index < end_index but that wouldn't
    //      be vary "array like". So capping it at the array
    //      length is a better alternative however, that means
    //      that NULL could be returned. It's really a matter
    //      of preference.
    if (array_index > (*array)->_array_length)
    {
        // Jump to failure
        goto failure;
    }

    // Return
    return (*array)->_ptr + ((array_index * (*array)->_array_size));

failure:
    // Return NULL
    return NULL;
}

void *lvd_array_insert_at(struct lvd_array **array, const unsigned int array_index, const void *buffer, const unsigned int buffer_length_size)
{
    // Function scope variables
    void *tmp;

    // Validate the lvd_array struct is already initalized
    if ((*array) == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Validate the index is not out of bounds
    // @see void *lvd_array_get
    if (array_index > (*array)->_array_length)
    {
        // Jump to failure
        goto failure;
    }

    // Check if data is present at array index
    unsigned char *data_presence = (*array)->_ptr + (array_index * (*array)->_array_size);
    if (data_presence != NULL)
    {
        // Re-allocate the array pointer
        tmp = realloc((*array)->_ptr, ((*array)->_array_length * (*array)->_array_size) + buffer_length_size);

        // Validate the re-allocation
        if (tmp == NULL)
        {
            // Jump to failure
            goto failure;
        }

        // Update the array pointer
        (*array)->_ptr = tmp;

        // Zero out the new memory chunk
        memset((*array)->_ptr + ((*array)->_array_size * (*array)->_array_index_end), '\0', buffer_length_size);

        // Recursively shift data down by one
        for (int i = (*array)->_array_length; i >= (int)array_index; i--)
        {
            // Move data down by one
            memcpy((*array)->_ptr + ((i + 1) * (*array)->_array_size), (*array)->_ptr + (i * (*array)->_array_size), (*array)->_array_size);
        }

        // Update the array length value
        (*array)->_array_length = (*array)->_array_length + (buffer_length_size / (*array)->_array_size);
    }

    // Insert data at index
    memcpy((*array)->_ptr + (array_index * (*array)->_array_size), buffer, buffer_length_size);

failure:
    // Return NULL
    return NULL;
}
