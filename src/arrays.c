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
#include "include/arrays.h"
// ---

// ----------------------------------------------------------------

// Macro Definitions

// File Docstring
// --------------------------------
// libVoid || src/arrays.c <-> include/arrays.h
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
int lvd_array_get_length(struct lvd_array **array)
{
    // Validate the lvd_array struct is already initalized
    if ((*array) == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Return the array pointer
    return (*array)->_array_length;

failure:
    // Return -1
    return -1;
}

void *lvd_array_append(struct lvd_array **array, const void *buffer, const unsigned int buffer_length_size)
{
    // Temporary function scope variables
    void *reallocated_array_pointer;

    // Validate the lvd_array struct is already initalized
    if ((*array) == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Avoid any funky errors
    if (buffer == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Calculate the amount of free memory left in the array
    const int free_memory = (*array)->_array_length - (*array)->_array_index_end;

    // Validate the array pointer has enough memory for the new buffer
    if (free_memory == 0 || free_memory < (buffer_length_size / (*array)->_array_size))
    {
        // Re-allocate the array pointer
        reallocated_array_pointer = realloc((*array)->_ptr, ((*array)->_array_length * (*array)->_array_size) + buffer_length_size);

        // Validate the re-allocation
        if (reallocated_array_pointer == NULL)
        {
            // Jump to failure
            goto failure;
        }

        // Update the array pointer
        (*array)->_ptr = reallocated_array_pointer;

        // Zero out the new memory chunk
        memset((*array)->_ptr + ((*array)->_array_length * (*array)->_array_size), '\0', buffer_length_size);

        // Update the array length value
        (*array)->_array_length += (buffer_length_size / (*array)->_array_size);
    }

    // Find the first NULL terminator from array_index_end -> array_length (inclusive)
    int terminator_index = 0;
    for (int i = (*array)->_array_index_end; i <= (*array)->_array_length; i++)
    {
        // Get the current memory entry
        unsigned char *current_entry = (*array)->_ptr + (i * (*array)->_array_size);

        // Check if the current entry is a NULL terminator
        if (*current_entry == '\0')
        {
            // Set the return index
            terminator_index = i;

            // Break
            break;
        }
    }

    // Copy data from the buffer to the pointer
    memcpy((*array)->_ptr + (terminator_index * (*array)->_array_size), buffer, buffer_length_size);

    // Set the new array end
    // NOTE: This seems kinda redundant(?). Possible change in the future
    (*array)->_array_index_end = terminator_index + (buffer_length_size / (*array)->_array_size);

    // Return the array pointer
    return (*array)->_ptr;

failure:
    // Return NULL
    return NULL;
}

void *lvd_array_free(struct lvd_array **array)
{
    // Validate the lvd_array struct is already initalized
    if ((*array) == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Free the array pointer
    free((*array)->_ptr);

    // Free the array struct
    free((*array));

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
    if (array_index > (*array)->_array_length || array_index < 0)
    {
        // Jump to failure
        goto failure;
    }

    // Return the data entry at array_index
    return ((*array)->_ptr + ((array_index * (*array)->_array_size)));

failure:
    // Return NULL
    return NULL;
}

void *lvd_array_get_ptr(struct lvd_array **array)
{
    // Validate the lvd_array struct is already initalized
    if ((*array) == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Return the array pointer
    return (*array)->_ptr;

failure:
    // Return NULL
    return NULL;
}

void *lvd_array_insert_at(struct lvd_array **array, const unsigned int array_index, const void *buffer, const unsigned int buffer_length_size)
{
    // Temporary function scope variables
    void *reallocated_array_pointer;

    // Validate the lvd_array struct is already initalized
    if ((*array) == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Avoid any funky errors
    if (buffer == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Validate the index is not out of bounds
    // @see void *lvd_array_get
    if (array_index > (*array)->_array_length || array_index < 0)
    {
        // Jump to failure
        goto failure;
    }

    // Check if data is present at the specified array index
    unsigned char *is_data_present = (*array)->_ptr + (array_index * (*array)->_array_size);
    if (is_data_present != NULL)
    {
        // Re-allocate the array pointer
        reallocated_array_pointer = realloc((*array)->_ptr, ((*array)->_array_length * (*array)->_array_size) + buffer_length_size);

        // Validate the re-allocation
        if (reallocated_array_pointer == NULL)
        {
            // Jump to failure
            goto failure;
        }

        // Update the array pointer
        (*array)->_ptr = reallocated_array_pointer;

        // Zero out the new memory chunk
        memset((*array)->_ptr + ((*array)->_array_length * (*array)->_array_size), '\0', buffer_length_size);

        // Shift the data right by one in a single operation
        memmove((*array)->_ptr + ((array_index + 1) * (*array)->_array_size), (*array)->_ptr + (array_index * (*array)->_array_size), ((*array)->_array_length - array_index) * (*array)->_array_size);

        // Update the array length value
        (*array)->_array_length += (buffer_length_size / (*array)->_array_size);
    }

    // Copy data from the buffer to the specified array index
    memcpy((*array)->_ptr + (array_index * (*array)->_array_size), buffer, buffer_length_size);

    // Update the array end index
    (*array)->_array_index_end += (buffer_length_size / (*array)->_array_size);

    // Return the array pointer
    return (*array)->_ptr;

failure:
    // Return NULL
    return NULL;
}

void *lvd_array_new(struct lvd_array **array, const unsigned int array_length, const unsigned long array_size)
{
    // Temporary function scope variables
    void *struct_alloc;
    void *array_ptr_alloc;

    // Avoid any funky errors
    if (array_length <= 0 || array_size <= 0)
    {
        // Jump to failure
        goto failure;
    }

    // Allocate memory for a new lvd_array struct
    struct_alloc = calloc(1, sizeof(struct lvd_array));

    // Allocate memory for a new lvd_array array pointer
    array_ptr_alloc = calloc(array_length, array_size);

    // Check if allocation was successful
    if (struct_alloc == NULL || array_ptr_alloc == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Update the array struct
    (*array) = struct_alloc;
    (*array)->_ptr = array_ptr_alloc;
    (*array)->_array_size = array_size;
    (*array)->_array_length = array_length;
    (*array)->_array_index_end = 0;

    // Return the array pointer
    return (*array)->_ptr;

failure:
    // Return NULL
    return NULL;
}

void *lvd_array_remove_at(struct lvd_array **array, const unsigned int array_index)
{
    // Temporary function scope variables
    void *reallocated_array_pointer;

    // Validate the lvd_array struct is already initalized
    if ((*array) == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Validate the index is not out of bounds
    // @see void *lvd_array_get
    if (array_index > (*array)->_array_length || array_index < 0)
    {
        // Jump to failure
        goto failure;
    }

    // Shift the data left by one overwriting any other data
    memmove((*array)->_ptr + (array_index * (*array)->_array_size), (*array)->_ptr + ((array_index + 1) * (*array)->_array_size), (((*array)->_array_length - 1) - array_index) * (*array)->_array_size);

    // Check if the array should be re-allocated
    if ((*array)->_array_index_end == (*array)->_array_length)
    {
        // Re-allocate the array pointer
        reallocated_array_pointer = realloc((*array)->_ptr, ((*array)->_array_length - 1) * (*array)->_array_size);

        // Validate the re-allocation
        if (reallocated_array_pointer == NULL)
        {
            // Jump to failure
            goto failure;
        }

        // Update the array pointer
        (*array)->_ptr = reallocated_array_pointer;

        // Update the array length
        (*array)->_array_length -= 1;
    }

    // Update the array end index
    (*array)->_array_index_end -= 1;

    // Return the array pointer
    return (*array)->_ptr;

failure:
    // Return NULL
    return NULL;
}

void *lvd_array_replace_at(struct lvd_array **array, const unsigned int array_index, const void *buffer, const unsigned int buffer_length_size)
{
    // Validate the lvd_array struct is already initalized
    if ((*array) == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Avoid any funky errors
    if (buffer == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Validate the index is not out of bounds
    // @see void *lvd_array_get
    if (array_index > (*array)->_array_length || array_index < 0)
    {
        // Jump to failure
        goto failure;
    }

    // Copy data from the buffer to the specified array index
    memcpy((*array)->_ptr + (array_index * (*array)->_array_size), buffer, buffer_length_size);

    // Update the array end index
    (*array)->_array_index_end += (buffer_length_size / (*array)->_array_size);

    // Return the array pointer
    return (*array)->_ptr;

failure:
    // Return NULL
    return NULL;
}
