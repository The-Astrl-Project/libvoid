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
// libVoid || src/arrays.c <-> include/arrays.h
//
// Allows for dynamically sized arrays during runtime.
//
// @author @MaxineToTheStars <https://github.com/MaxineToTheStars>
// ----------------------------------------------------------------

// Struct Definitions
/* A representation of an array */
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
/**
 * Appends the given ``buffer`` to ``array``. The ``buffer`` must be
 * of the same ``size`` as the array. If ``buffer`` is ``NULL``
 * the method will exit.
 *
 * @param array A pointer to an initialized ``lvd_array`` struct
 * @param buffer A pointer to a buffer of data
 * @param buffer_length_size The total length of the buffer multiplied by memory chunk size
 * @return ``EXIT_SUCCESS`` or ``EXIT_FAILURE`` if the method fails
 */
int lvd_array_append(struct lvd_array **array, const void *buffer, const unsigned int buffer_length_size);

/**
 * Detaches the ``lvd_array`` struct from the ``array``.
 * The ``lvd_array`` struct that was passed in can then
 * be re-used for another ``array``.
 *
 * @param array A pointer to an initialized ``lvd_array`` struct
 * @return ``EXIT_SUCCESS`` or ``EXIT_FAILURE`` if the array is uninitialized
 * @warning Memory leaks are possible with this. Make sure ``lvd_array_free`` is called
 *          when cleaning up detached arrays.
 * @note Possible future deprecation. You have been warned.
 */
int lvd_array_detach(struct lvd_array **array);

/**
 * Empties the given ``array``. This action is
 * irreversible.
 *
 * @param array A pointer to an initialized ``lvd_array`` struct
 * @return ``EXIT_SUCCESS`` or ``EXIT_FAILURE`` if the array is uninitialized
 */
int lvd_array_empty(struct lvd_array **array);

/**
 * Frees the ``array`` from memory. This action is
 * irreversible.
 *
 * @param array A pointer to an initialized ``lvd_array`` struct
 * @return ``EXIT_SUCCESS`` or ``EXIT_FAILURE`` if the array is uninitialized
 */
int lvd_array_free(struct lvd_array **array);

/**
 * Retrieves the ``array_length`` from the specified ``array``.
 *
 * @param array A pointer to an initialized ``lvd_array`` struct
 * @return The ``array_length`` or ``-EXIT_FAILURE`` if the method fails
 */
int lvd_array_get_length(struct lvd_array **array);

/**
 * Inserts the given ``buffer`` at the specified ``array_index``.
 * Any data located at ``array_index`` will be shifted right by one.
 * If ``buffer`` is ``NULL`` the method will exit.
 *
 * @param array A pointer to an initialized ``lvd_array`` struct
 * @param array_index The array index to access
 * @param buffer A pointer to a buffer of data
 * @param buffer_length_size The total length of the buffer multiplied by memory chunk size
 * @return ``EXIT_SUCCESS`` or ``EXIT_FAILURE`` if the method fails
 */
int lvd_array_insert_at(struct lvd_array **array, const unsigned int array_index, const void *buffer, const unsigned int buffer_length_size);

/**
 * Allocates a new ``lvd_array`` with the specified ``array_length``
 * and ``array_size``. If ``array_length`` or ``array_size`` is
 * ``0`` the method will exit.
 *
 * @param array A pointer to an uninitialized ``lvd_array`` struct
 * @param array_length The starting length of the array
 * @param array_size The size of each chunk in the array
 * @return ``EXIT_SUCCESS`` or ``EXIT_FAILURE`` if the method fails
 */
int lvd_array_new(struct lvd_array **array, const unsigned int array_length, const unsigned long array_size);

/**
 * Removes the data located at ``array_index``. All data
 * within the array will be shifted left by one after the
 * removal.
 *
 * @param array A pointer to an initialized ``lvd_array`` struct
 * @param array_index The array index to access
 * @return ``EXIT_SUCCESS`` or ``EXIT_FAILURE`` if the method fails
 */
int lvd_array_remove_at(struct lvd_array **array, const unsigned int array_index);

/**
 * Replaces any data located at ``array_index`` with the given ``buffer``.
 * Any data at ``array_index`` will be overwritten. If ``buffer`` is
 * ``NULL`` the method will exit.
 *
 * @param array A pointer to an initialized ``lvd_array`` struct
 * @param array_index The array index to access
 * @param buffer A pointer to a buffer of data
 * @param buffer_length_size The total length of the buffer multiplied by memory chunk size
 * @return ``EXIT_SUCCESS`` or ``EXIT_FAILURE`` if the method fails
 */
int lvd_array_replace_at(struct lvd_array **array, const unsigned int array_index, const void *buffer, const unsigned int buffer_length_size);

/**
 * Retrieves the data located at the given ``array_index``.
 * If the ``array_index`` results in an ``OOBE`` this method
 * will exit.
 *
 * @param array A pointer to an initialized ``lvd_array`` struct
 * @param array_index The array index to access
 * @return A ``pointer`` to the data entry or ``NULL`` if the method fails
 */
void *lvd_array_get(struct lvd_array **array, const unsigned int array_index);

/**
 * Retrieves the ``array_pointer`` from the given ``array``.
 *
 * @param array A pointer to an initialized ``lvd_array`` struct
 * @return A ``pointer`` to the array or ``NULL`` if the array is uninitialized
 */
void *lvd_array_get_ptr(struct lvd_array **array);
