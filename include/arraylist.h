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
#include <stdio.h>
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
/* libVoid's implementation of an ArrayList type. */
struct lvd_arraylist_t;

// Enum Definitions

// Type Definitions

// Variable Definitions

// Main

// Methods
/**
 * Instances a new ``lvd_arraylist_t`` of the specified ``length`` and ``size``.
 *
 * @param length The starting length of the array
 * @param size The size of each index in the array
 * @returns A ``lvd_arraylist_t`` pointer else ``NULL``
 */
struct lvd_arraylist_t *lvd_arraylist_init(size_t length, size_t size);

/**
 * Frees the given ``lvd_arraylist_t`` and its underlying data.
 *
 * @param arraylist An initialized ``lvd_arraylist_t``
 * @return ``void``
 */
void lvd_arraylist_free(struct lvd_arraylist_t *arraylist);

/**
 * Appends the given ``data_buffer`` to the ``arraylist``.
 *
 * @param arraylist An initialized ``lvd_arraylist_t``
 * @param data_buffer A pointer to a valid buffer
 * @return ``void``
 * @note Will silently fail/possibly corrupt if the specified ``data_buffer`` does not match the
 *       arraylist index size.
 */
void lvd_arraylist_append(struct lvd_arraylist_t *arraylist, const void *data_buffer);

/**
 * Appends the given ``data_buffer`` to the ``arraylist``
 * at the given ``index``.
 *
 * @param arraylist An initialized ``lvd_arraylist_t``
 * @param data_buffer A pointer to a valid buffer
 * @param index A valid index
 * @return ``void``
 * @note Will silently fail/possibly corrupt if the specified ``data_buffer`` does not match the
 *       arraylist index size.
 */
void lvd_arraylist_append_at(struct lvd_arraylist_t *arraylist, const void *data_buffer, const unsigned int index);

/**
 * Removes the data at the given ``index``. The resulting indicies will be shifted left.
 *
 * @param arraylist An initialized ``lvd_arraylist_t``
 * @param index A valid index
 * @return ``void``
 */
void lvd_arraylist_remove_at(struct lvd_arraylist_t *arraylist, const unsigned int index);

/**
 * Replaces the data at the given ``index`` with the given ``data``.
 *
 * @param arraylist An initialized ``lvd_arraylist_t``
 * @param data_buffer A pointer to a valid buffer
 * @param index A valid index
 * @return ``void``
 * @note Will silently fail/possibly corrupt if the specified ``data_buffer`` does not match the
 *       arraylist index size.
 */
void lvd_arraylist_replace_at(struct lvd_arraylist_t *arraylist, const void *data_buffer, const unsigned int index);

/**
 * Returns the data at the given ``index``.
 *
 * @param arraylist An initialized ``lvd_arraylist_t``
 * @param index A valid index
 * @return A ``pointer`` to the specified data else ``NULL``
 */
void *lvd_arraylist_get_at(struct lvd_arraylist_t *arraylist, const unsigned int index);

/**
 * Returns the length of the given ``arraylist``.
 *
 * @param arraylist An initialized ``lvd_arraylist_t``
 * @return ``size_t``
 * @note This will not return the true length which is the maximum capacity (at call time)
 *       that the array can hold.
 */
size_t lvd_arraylist_get_length(struct lvd_arraylist_t *arraylist);
