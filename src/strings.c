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
#include "include/strings.h"
// ---

// ----------------------------------------------------------------

// Macro Definitions

// File Docstring
// --------------------------------
// libVoid || src/strings.c <-> include/strings.h
//
// A string type implementation.
//
// @author @MaxineToTheStars <https://github.com/MaxineToTheStars>
// ----------------------------------------------------------------

// Struct Definitions
struct lvd_string
{
    /* Stores the string value */
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
    void *string_buffer_alloc;

    // Allocate memory for a new lvd_string struct
    struct_alloc = calloc(1, sizeof(struct lvd_string));

    // Allocate memory for a new lvd_string string buffer
    string_buffer_alloc = calloc(strlen((string_value != NULL) ? string_value : ""), sizeof(char));

    // Check if allocation was successful
    if (struct_alloc == NULL || string_buffer_alloc == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Update the string struct
    (*string) = struct_alloc;
    (*string)->_string_buffer = string_buffer_alloc;

    // Copy over the string value to the newly allocated string buffer
    strcpy((*string)->_string_buffer, (string_value != NULL) ? string_value : "");

    // Return the string buffer
    return (*string)->_string_buffer;

failure:
    // Return NULL
    return NULL;
}

void *lvd_string_set(struct lvd_string **string, const char *string_value)
{
    // Temporary function scope variables
    void *reallocated_string_buffer;

    // Validate the lvd_array struct is already initalized
    if ((*string) == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Re-allocate the string buffer
    reallocated_string_buffer = realloc((*string)->_string_buffer, strlen((string_value != NULL) ? string_value : ""));

    // Validate the re-allocation
    if (reallocated_string_buffer == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Update the string buffer
    (*string)->_string_buffer = reallocated_string_buffer;

    // Zero out the new memory chunk
    memset((*string)->_string_buffer, '\0', strlen((string_value != NULL) ? string_value : ""));

    // Copy over the new string value
    strcpy((*string)->_string_buffer, (string_value != NULL) ? string_value : "");

    // Return the string buffer
    return (*string)->_string_buffer;

failure:
    // Return NULL
    return NULL;
}

void *lvd_string_concat(struct lvd_string **string, const char *string_value)
{
    // Temporary function scope variables
    void *reallocated_string_buffer;

    // Validate the lvd_array struct is already initalized
    if ((*string) == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Re-allocate the string buffer
    reallocated_string_buffer = realloc((*string)->_string_buffer, strlen(string_value));

    // Validate the re-allocation
    if (reallocated_string_buffer == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Update the string buffer
    (*string)->_string_buffer = reallocated_string_buffer;

    // Zero out the new memory chunk
    memset((*string)->_string_buffer + strlen(string_value), '\0', strlen(string_value));

    // Append the new string value
    strcat((*string)->_string_buffer, string_value);

    // Return the string buffer
    return (*string)->_string_buffer;

failure:
    // Return NULL
    return NULL;
}
