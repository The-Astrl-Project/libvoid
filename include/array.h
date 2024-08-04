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

// ---

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
/* A representation of an array */
struct lvd_array;

// Enum Definitions

// Type Definitions

// Variable Definitions

// Main

// Methods
/**
 * Allocates a new ``lvd_array`` with the specified length and memory chunk size.
 *
 * @param array A pointer to an uninitialized ``lvd_array`` struct
 * @param array_length The starting length of the array
 * @param array_size The size of each chunk in the array
 * @return A pointer to the new array or ``NULL``
 */
void *lvd_array_new(struct lvd_array **array, const unsigned int array_length, const unsigned long array_size);

/**
 * Appends the given ``buffer`` to ``array``. The ``buffer`` must be
 * of the same ``size`` as the array.
 *
 * @param array A pointer to an initialized ``lvd_array`` struct
 * @param buffer A pointer to a buffer of data
 * @param buffer_length_size The total length of the buffer (including the chunk size)
 * @return A pointer to the array or ``NULL``
 */
void *lvd_array_append(struct lvd_array **array, const void *buffer, const unsigned int buffer_length_size);

/**
 * Retrieves the data located at the given index.
 *
 * @param array A pointer to an initialized ``lvd_array`` struct
 * @param array_index The array index to access
 * @return A pointer to the data entry or ``NULL``
 */
void *lvd_array_get(struct lvd_array **array, const unsigned int array_index);
