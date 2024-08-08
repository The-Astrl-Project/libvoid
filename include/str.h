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
// libVoid || src/str.c <-> include/str.h
//
// A string type implementation.
//
// @author @MaxineToTheStars <https://github.com/MaxineToTheStars>
// ----------------------------------------------------------------

// Struct Definitions
/* A representation of a string */
struct lvd_string;

// Enum Definitions

// Type Definitions

// Variable Definitions

// Main

// Methods
/**
 * Allocates a new ``lvd_string`` with the specified ``string_value``.
 *
 * @param string A pointer to an uninitialized ``lvd_string`` struct
 * @param string_value A pointer to the string value
 * @return A pointer to the new string or ``NULL``
 */
void *lvd_string_new(struct lvd_string **string, const char *string_value);
