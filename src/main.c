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
/* Sample struct for testing */
struct my_struct
{
    char *message;
    int value;
};

// Enum Definitions

// Type Definitions

// Variable Definitions

// Main
int main()
{
    // Logging/Error handling
    void *exit_status;

    // Allocate a new array
    struct lvd_array *array;

    // Create a new array with 2 indicies of size my_struct
    exit_status = lvd_array_new(&array, 2, sizeof(struct my_struct));

    // Check if an array was allocated
    if (exit_status == NULL)
    {
        // Log
        printf("Failed to allocate array\n");

        // Exit
        return -1;
    }

    // Allocate new structs
    struct my_struct *one;
    struct my_struct *two;
    struct my_struct *three;

    one = (struct my_struct *)calloc(1, sizeof(struct my_struct));
    two = (struct my_struct *)calloc(1, sizeof(struct my_struct));
    three = (struct my_struct *)calloc(1, sizeof(struct my_struct));

    // Populate with data
    one->message = "Hello Everynyan!\n";
    one->value = 0;

    two->message = "How are you?\n";
    two->value = -10;

    three->message = "Fine, thank you!\n";
    three->value = 10;

    // Append data
    lvd_array_append(&array, one, sizeof(*one));
    lvd_array_append(&array, two, sizeof(*two));

    // Declare return pointers
    struct my_struct *return_value_one;
    struct my_struct *return_value_two;
    struct my_struct *return_value_three;

    // Retrieve data
    lvd_array_get(&array, 0, (void *)&return_value_one);
    lvd_array_get(&array, 1, (void *)&return_value_two);

    // Log
    printf("Fits array\n---\n");
    printf("%s", return_value_one->message);
    printf("%s", return_value_two->message);
    printf("---\n");

    // Append
    lvd_array_append(&array, three, sizeof(*three));

    // Retrieve data
    lvd_array_get(&array, 2, (void *)&return_value_three);

    // Log
    printf("After realloc\n---\n");
    printf("%s", return_value_one->message);
    printf("%s", return_value_two->message);
    printf("%s", return_value_three->message);
    printf("%i\n", return_value_one->value);
    printf("%i\n", return_value_two->value);
    printf("%i\n", return_value_three->value);
    printf("---\n");

    // Free
    free(return_value_one);
    free(return_value_two);
    free(return_value_three);

    // Exit
    return 0;
}

// Methods
