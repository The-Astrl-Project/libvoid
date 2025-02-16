/**
 * Copyright (c) 2025 Astrl.
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
#include <stdlib.h>
#include <string.h>
// ---
#include "include/arraylist.h"
// ---

// ----------------------------------------------------------------

// Macro Definitions

// File Docstring
// --------------------------------
// libVoid || src/arraylist.c <-> include/arraylist.h
//
// An implementation of an ArrayList / Resizable Array.
//
// @author @MaxineToTheStars <https://github.com/MaxineToTheStars>
// ----------------------------------------------------------------

// Struct Definitions
/* Internal implementation of the libVoid ArrayList type. */
struct lvd_arraylist_t
{
    /* A pointer to the data buffer. */
    void *data;
    /* The size of the array. */
    size_t array_size;
    /* The length of the array. */
    size_t array_length;
    /* The number of items in the array */
    size_t array_items;
};

// Enum Definitions

// Type Definitions

// Variable Definitions

// Main

// Methods
struct lvd_arraylist_t *lvd_arraylist_init(size_t length, size_t size)
{
    // Allocate a new ArrayList type
    struct lvd_arraylist_t *arraylist = calloc(1, sizeof(struct lvd_arraylist_t));

    // Was allocation successful?
    if (arraylist == NULL)
    {
        // Error during allocation
        return NULL;
    }

    // Populate the ArrayList
    arraylist->array_items = 0;
    arraylist->array_size = size;
    arraylist->array_length = length;
    arraylist->data = calloc(length, size);

    // Was allocation successful?
    if (arraylist->data == NULL)
    {
        // Error during allocation
        return NULL;
    }

    // Return
    return arraylist;
}

void lvd_arraylist_free(struct lvd_arraylist_t *arraylist)
{
    // Is the ArrayList even initialized?
    if (arraylist == NULL)
    {
        // ArrayList is not initialized
        return;
    }

    // Free the array pointer
    free(arraylist->data);

    // Free the struct
    free(arraylist);

    // Update the ArrayList
    arraylist = NULL;
}

void lvd_arraylist_append(struct lvd_arraylist_t *arraylist, const void *data_buffer)
{
    // Temporary function scope variables
    void *realloc_pointer;

    // Is the ArrayList even initialized?
    if (arraylist == NULL)
    {
        // ArrayList is not initialized
        return;
    }

    // Check if a reallocation is needed
    if (arraylist->array_items + 1 > arraylist->array_length)
    {
        // Re-allocate the ArrayList data pointer
        realloc_pointer = calloc((arraylist->array_length + 1), arraylist->array_size);

        // Was re-allocation successful?
        if (realloc_pointer == NULL)
        {
            // Error during re-allocation
            return;
        }

        // Move the data over to the new pointer
        memmove(realloc_pointer, arraylist->data, (arraylist->array_length * arraylist->array_size));

        // Free the old pointer
        free(arraylist->data);

        // Update the ArrayList
        arraylist->array_length += 1;
        arraylist->data = realloc_pointer;
    }

    // Append the data to the arraylist
    memmove(arraylist->data + (arraylist->array_items * arraylist->array_size), data_buffer, arraylist->array_size);

    // Update the ArrayList
    arraylist->array_items += 1;
}

void lvd_arraylist_append_at(struct lvd_arraylist_t *arraylist, const void *data_buffer, const unsigned int index)
{
    // Temporary function scope variables
    void *realloc_pointer;

    // Is the ArrayList even initialized?
    if (arraylist == NULL)
    {
        // ArrayList is not initialized
        return;
    }

    // Avoid funky/invalid memory writes
    if (arraylist->array_items == 0)
    {
        // Append it to the end
        return lvd_arraylist_append(arraylist, data_buffer);
    }

    // Assume:
    // Array Length = 10, Array Items = 4, Index = 5
    //
    // Result:
    // A,B,C,D,0,X,0,0,0,0
    // 0,1,2,3,4,5,6,7,8,9
    //
    // Conclusion:
    // Should I add data before X or after X?
    // This is not nice to work with
    if (index >= arraylist->array_items)
    {
        // Index out of bounds
        return;
    }

    // Check if a reallocation is needed
    if (arraylist->array_items + 1 > arraylist->array_length)
    {
        // Re-allocate the ArrayList data pointer
        realloc_pointer = calloc((arraylist->array_length + 1), arraylist->array_size);

        // Was re-allocation successful?
        if (realloc_pointer == NULL)
        {
            // Error during re-allocation
            return;
        }

        // Move the data over to the new pointer
        memmove(realloc_pointer, arraylist->data, (arraylist->array_length * arraylist->array_size));

        // Free the old pointer
        free(arraylist->data);

        // Update the ArrayList
        arraylist->array_length += 1;
        arraylist->data = realloc_pointer;
    }

    // Move the array to the right
    memmove(arraylist->data + ((index + 1) * arraylist->array_size), arraylist->data + (index * arraylist->array_size), ((((arraylist->array_items - 1) - index) + 1) * arraylist->array_size));

    // Append the data to the arraylist
    memmove(arraylist->data + (index * arraylist->array_size), data_buffer, arraylist->array_size);

    // Update the ArrayList
    arraylist->array_items += 1;
}

void lvd_arraylist_remove_at(struct lvd_arraylist_t *arraylist, const unsigned int index)
{

    // Is the ArrayList even initialized?
    if (arraylist == NULL)
    {
        // ArrayList is not initialized
        return;
    }

    // Is the index out of bounds?
    if (index >= arraylist->array_items)
    {
        // Invalid bounds
        return;
    }

    // Clear the entry
    memset(arraylist->data + (index * arraylist->array_size), '\0', arraylist->array_size);

    // Shift the array to the left
    memmove(arraylist->data + (index * arraylist->array_size), arraylist->data + ((index + 1) * arraylist->array_size), (((arraylist->array_items - 1) - index) * arraylist->array_size));

    // Update the ArrayList
    arraylist->array_items -= 1;
}

void lvd_arraylist_replace_at(struct lvd_arraylist_t *arraylist, const void *data_buffer, const unsigned int index)
{
    // Is the ArrayList even initialized?
    if (arraylist == NULL)
    {
        // ArrayList is not initialized
        return;
    }

    // Can't remove data that just isin't there now can we
    if (index > arraylist->array_items || arraylist->array_items == 0)
    {
        // Invalid bounds
        return;
    }

    // Append the data to the arraylist
    memmove(arraylist->data + (index * arraylist->array_size), data_buffer, arraylist->array_size);
}

void *lvd_arraylist_get_at(struct lvd_arraylist_t *arraylist, const unsigned int index)
{
    // Is the ArrayList even initialized?
    if (arraylist == NULL)
    {
        // ArrayList is not initialized
        return NULL;
    }

    // Is the index out of bounds?
    if (index >= arraylist->array_length)
    {
        // Invalid bounds
        return NULL;
    }

    // Return
    return (char *)(arraylist->data) + (index * arraylist->array_size);
}

size_t lvd_arraylist_get_length(struct lvd_arraylist_t *arraylist)
{
    // Is the ArrayList even initialized?
    if (arraylist == NULL)
    {
        // ArrayList is not initialized
        return 0;
    }

    // Return item count
    return arraylist->array_items;
}
