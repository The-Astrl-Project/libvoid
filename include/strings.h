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
// libVoid || src/strings.c <-> include/strings.h
//
// A string type implementation.
//
// @author @MaxineToTheStars <https://github.com/MaxineToTheStars>
// ----------------------------------------------------------------

// Struct Definitions
/* A representation of a string type */
struct lvd_string;

// Enum Definitions

// Type Definitions

// Variable Definitions

// Main

// Methods
/**
 * Allocates a new ``lvd_string``. The string value can be optionally passed
 * along during creation.
 *
 * @param string A pointer to an uninitialized ``lvd_string`` struct
 * @param string_value Optional string value
 * @return A pointer to the string value or ``NULL``
 */
void *lvd_string_new(struct lvd_string **string, const char *string_value);

/**
 * Sets the new ``string_value`` for the given ``lvd_string`` struct.
 * If ``string_value`` is set to ``NULL`` it will empty the ``string_value``.
 *
 * @param string A pointer to an initialized ``lvd_string`` struct
 * @param string_value The new string value
 * @return A pointer to the string value or ``NULL``
 */
void *lvd_string_set(struct lvd_string **string, const char *string_value);

/**
 * Concat ``string_value`` to the end of the ``lvd_string`` struct.
 *
 * @param string A pointer to an initialized ``lvd_string`` struct
 * @param string_value The string value to concat
 * @return A pointer to the string value or ``NULL``
 */
void *lvd_string_concat(struct lvd_string **string, const char *string_value);
