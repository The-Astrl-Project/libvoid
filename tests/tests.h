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

// ---

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
/* Struct used for testing */
struct lvd_testing_struct
{
    /* Numeric value field */
    int numeric_value;
    /* Pointer value field  */
    void *pointer_value;
};

// Enum Definitions

// Type Definitions

// Variable Definitions

// Main

// Methods
/**
 * Tests ``lvd_arraylist_append`` and ``lvd_arraylist_append_at``
 * functionality.
 *
 * @return ``void``
 */
void tests_lvd_arraylist_append();

/**
 * Tests ``lvd_arraylist_remove_at`` functionality.
 *
 * @return ``void``
 */
void tests_lvd_arraylist_remove();

/**
 * Tests ``lvd_arraylist_replace_at`` functionality.
 *
 * @return ``void``
 */
void tests_lvd_arraylist_replace();
