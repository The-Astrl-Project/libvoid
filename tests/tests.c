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
#include <assert.h>
// ---
#include "tests/tests.h"
#include "include/arraylist.h"
// ---

// ----------------------------------------------------------------

// Macro Definitions

// File Docstring
// --------------------------------
// libVoid || tests/tests.c <-> tests/tests.h
//
// Sanity checks and tests for making sure everything works.
//
// @author @MaxineToTheStars <https://github.com/MaxineToTheStars>
// ----------------------------------------------------------------

// Struct Definitions

// Enum Definitions

// Type Definitions

// Variable Definitions

// Main
int main()
{
    // ArrayList tests
    tests_lvd_arraylist_append();
    tests_lvd_arraylist_remove();
    tests_lvd_arraylist_replace();
}

// Methods
void tests_lvd_arraylist_append()
{
    // Declare testing data
    struct lvd_testing_struct *data_one = calloc(1, sizeof(struct lvd_testing_struct));
    struct lvd_testing_struct *data_two = calloc(1, sizeof(struct lvd_testing_struct));

    // Populate
    data_one->numeric_value = 3072025;
    data_one->pointer_value = "Astrl";
    data_two->numeric_value = 7686426;
    data_two->pointer_value = "Acheron";

    // Declare ArrayList
    struct lvd_arraylist_t *arraylist = lvd_arraylist_init(1, sizeof(struct lvd_testing_struct));

    // Check if the array was correctly initialized
    printf("[ARRAYLIST - APPEND](1/3) Check if the array was correctly initialized\n");
    assert(lvd_arraylist_get_length(arraylist) == 0);

    // Append data to the array
    lvd_arraylist_append(arraylist, data_one);

    // Free
    free(data_one);

    // Check if data was correctly pushed
    printf("[ARRAYLIST - APPEND](2/3) Check if data was correctly pushed to the ArrayList\n");
    data_one = lvd_arraylist_get_at(arraylist, 0);
    assert(data_one->numeric_value == 3072025);

    // Insert data to the array
    lvd_arraylist_append_at(arraylist, data_two, 0);

    // Free
    free(data_two);

    // Check if data was correctly inserted
    printf("[ARRAYLIST - APPEND](3/3) Check if data was correctly inserted to the ArrayList\n");
    data_two = lvd_arraylist_get_at(arraylist, 0);
    data_one = lvd_arraylist_get_at(arraylist, 1);
    assert(data_two->numeric_value == 7686426);
    assert(data_one->numeric_value == 3072025);

    // Free the arraylist
    lvd_arraylist_free(arraylist);
}

void tests_lvd_arraylist_remove()
{
    // Declare testing data
    struct lvd_testing_struct *data_one = calloc(1, sizeof(struct lvd_testing_struct));
    struct lvd_testing_struct *data_two = calloc(1, sizeof(struct lvd_testing_struct));

    // Populate
    data_one->numeric_value = 3072025;
    data_one->pointer_value = "Astrl";
    data_two->numeric_value = 7686426;
    data_two->pointer_value = "Acheron";

    // Declare ArrayList
    struct lvd_arraylist_t *arraylist = lvd_arraylist_init(1, sizeof(struct lvd_testing_struct));

    // Check if the array was correctly initialized
    printf("[ARRAYLIST - REMOVE](1/2) Check if the array was correctly initialized\n");
    assert(lvd_arraylist_get_length(arraylist) == 0);

    // Append data to the array
    lvd_arraylist_append(arraylist, data_one);

    // Insert data to the array
    lvd_arraylist_append_at(arraylist, data_two, 0);

    // Free
    free(data_one);
    free(data_two);

    // Remove data
    lvd_arraylist_remove_at(arraylist, 0);

    // Check if data was correctly removed
    printf("[ARRAYLIST - REMOVE](2/2) Check if data was correctly removed from the ArrayList\n");
    data_two = lvd_arraylist_get_at(arraylist, 0);
    assert(data_two->numeric_value == 3072025);

    // Free the arraylist
    lvd_arraylist_free(arraylist);
}

void tests_lvd_arraylist_replace()
{
    // Declare testing data
    struct lvd_testing_struct *data_one = calloc(1, sizeof(struct lvd_testing_struct));
    struct lvd_testing_struct *data_two = calloc(1, sizeof(struct lvd_testing_struct));

    // Populate
    data_one->numeric_value = 3072025;
    data_one->pointer_value = "Astrl";
    data_two->numeric_value = 7686426;
    data_two->pointer_value = "Acheron";

    // Declare ArrayList
    struct lvd_arraylist_t *arraylist = lvd_arraylist_init(1, sizeof(struct lvd_testing_struct));

    // Check if the array was correctly initialized
    printf("[ARRAYLIST - REPLACE](1/2) Check if the array was correctly initialized\n");
    assert(lvd_arraylist_get_length(arraylist) == 0);

    // Append data to the array
    lvd_arraylist_append(arraylist, data_one);

    // Insert data to the array
    lvd_arraylist_append_at(arraylist, data_two, 0);

    // Replace data
    lvd_arraylist_replace_at(arraylist, data_two, 1);

    // Free
    free(data_one);
    free(data_two);

    // Check if data was correctly removed
    printf("[ARRAYLIST - REPLACE](2/2) Check if data was correctly replaced from the ArrayList\n");
    data_one = lvd_arraylist_get_at(arraylist, 0);
    data_two = lvd_arraylist_get_at(arraylist, 1);
    assert(data_one->numeric_value == 7686426);
    assert(data_two->numeric_value == 7686426);

    // Free the arraylist
    lvd_arraylist_free(arraylist);
}
