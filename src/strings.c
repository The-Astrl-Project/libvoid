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
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
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

    // Declare the choosen string and it's length
    const char *choosen_string = (string_value == NULL) ? "" : string_value;
    const int choosen_string_length = strlen(choosen_string) + 1;

    // Allocate memory for a new lvd_string struct
    struct_alloc = calloc(1, sizeof(struct lvd_string));

    // Allocate memory for a new lvd_string string buffer
    string_buffer_alloc = calloc(choosen_string_length, sizeof(char));

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
    strcpy((*string)->_string_buffer, choosen_string);

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

    // Declare the choosen string and it's length
    const char *choosen_string = (string_value == NULL) ? "" : string_value;
    const int choosen_string_length = strlen(choosen_string) + 1;

    // Re-allocate the string buffer
    reallocated_string_buffer = realloc((*string)->_string_buffer, choosen_string_length);

    // Validate the re-allocation
    if (reallocated_string_buffer == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Update the string buffer
    (*string)->_string_buffer = reallocated_string_buffer;

    // Zero out the new memory chunk
    memset((*string)->_string_buffer, '\0', choosen_string_length);

    // Copy over the new string value
    strcpy((*string)->_string_buffer, choosen_string);

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

    // Avoid any funky errors
    if (string_value == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Declare the new string length
    const int new_string_length = (strlen((*string)->_string_buffer) + 1) + (strlen(string_value) + 1);

    // Re-allocate the string buffer
    reallocated_string_buffer = realloc((*string)->_string_buffer, new_string_length);

    // Validate the re-allocation
    if (reallocated_string_buffer == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Update the string buffer
    (*string)->_string_buffer = reallocated_string_buffer;

    // Zero out the new memory chunk
    memset((*string)->_string_buffer + (strlen((*string)->_string_buffer) + 1), '\0', (strlen(string_value) + 1));

    // Append the new string value
    strcat((*string)->_string_buffer, string_value);

    // Return the string buffer
    return (*string)->_string_buffer;

failure:
    // Return NULL
    return NULL;
}

void *lvd_string_format_from(struct lvd_string **string, const char *string_format, ...)
{
    // Temporary function scope variables
    va_list args_ptr;
    void *reallocated_string_buffer;

    // Validate the lvd_array struct is already initalized
    if ((*string) == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Initialize the argument list
    va_start(args_ptr, string_format);

    // Calculate string length
    size_t string_size = vsnprintf(NULL, 0, string_format, args_ptr) + 1;

    // End the argument list
    va_end(args_ptr);

    // Re-allocate the string buffer
    reallocated_string_buffer = realloc((*string)->_string_buffer, string_size);

    // Validate the re-allocation
    if (reallocated_string_buffer == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Update the string buffer
    (*string)->_string_buffer = reallocated_string_buffer;

    // Zero out the new memory chunk
    memset((*string)->_string_buffer, '\0', string_size);

    // Re-initialize the argument list
    va_start(args_ptr, string_format);

    // Format the string
    vsnprintf((*string)->_string_buffer, string_size, string_format, args_ptr);

    // End the argument list
    va_end(args_ptr);

    // Return the string buffer
    return (*string)->_string_buffer;

failure:
    // Return NULL
    return NULL;
}

void *lvd_string_format_from_vargs(struct lvd_string **string, const char *string_format, va_list vargs)
{
    // Temporary function scope variables
    va_list args_ptr;
    void *reallocated_string_buffer;

    // Validate the lvd_array struct is already initalized
    if ((*string) == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Initialize the argument list
    va_copy(args_ptr, vargs);

    // Calculate string length
    size_t string_size = vsnprintf(NULL, 0, string_format, args_ptr) + 1;

    // End the argument list
    va_end(args_ptr);

    // Re-allocate the string buffer
    reallocated_string_buffer = realloc((*string)->_string_buffer, string_size);

    // Validate the re-allocation
    if (reallocated_string_buffer == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Update the string buffer
    (*string)->_string_buffer = reallocated_string_buffer;

    // Zero out the new memory chunk
    memset((*string)->_string_buffer, '\0', string_size);

    // Re-initialize the argument list
    va_copy(args_ptr, vargs);

    // Format the string
    vsnprintf((*string)->_string_buffer, string_size, string_format, args_ptr);

    // End the argument list
    va_end(args_ptr);

    // Return the string buffer
    return (*string)->_string_buffer;

failure:
    // Return NULL
    return NULL;
}

void *lvd_string_get_value(struct lvd_string **string)
{
    // Validate the lvd_array struct is already initalized
    if ((*string) == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Return the string buffer
    return (*string)->_string_buffer;

failure:
    // Return NULL
    return NULL;
}

void *lvd_string_free(struct lvd_string **string)
{
    // Validate the lvd_string struct is already initalized
    if ((*string) == NULL)
    {
        // Jump to failure
        goto failure;
    }

    // Free the array pointer
    free((*string)->_string_buffer);

    // Free the array struct
    free((*string));

failure:
    // Return NULL
    return NULL;
}
