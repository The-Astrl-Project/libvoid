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
#include <stdarg.h>
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
 * Compares the value of ``string`` to the value of ``string_value``. The
 * locale is not taken into account. Under the hood this is a shorthand for
 * ``strcmp()``.
 *
 * @param string A pointer to an initialized ``lvd_string`` struct
 * @param string_value The string value to compare
 * @return An integer indicating the result of the comparision.
 * @see https://www.man7.org/linux/man-pages/man3/strcmp.3.html
 */
int lvd_string_compare(struct lvd_string **string, const char *string_value);

/**
 * Compares the value of ``string`` to the value of ``string_value`` withing bounds of
 * ``byte_length``. The locale is not taken into account. Under the hood this is a
 * shorthand for ``strncmp()``.
 *
 * @param string A pointer to an initialized ``lvd_string`` struct
 * @param string_value The string value to compare
 * @param byte_length The Nth amount of bytes to compare
 * @return An integer indicating the result of the comparision.
 * @see https://www.man7.org/linux/man-pages/man3/strcmp.3.html
 */
int lvd_string_compare_n(struct lvd_string **string, const char *string_value, const unsigned int byte_length);

/**
 * Concat ``string_value`` to the end of the ``lvd_string`` struct.
 * If ``string_value`` is set to ``NULL`` the method will exit.
 *
 * @param string A pointer to an initialized ``lvd_string`` struct
 * @param string_value The string value to concat
 * @return A pointer to the string value or ``NULL``
 */
void *lvd_string_concat(struct lvd_string **string, const char *string_value);

/**
 * Formats the ``lvd_string`` with the given ``string_format``. Fully supports
 * ``printf``'s formatting options and flags.
 *
 * @param string A pointer to an initialized ``lvd_string`` struct
 * @param string_format The formatting flags and options
 * @return A pointer to the string value or ``NULL``
 */
void *lvd_string_format_from(struct lvd_string **string, const char *string_format, ...);

/**
 * Formats the ``lvd_string`` with the given ``string_format`` and ``vargs`` list. Fully supports
 * ``printf``'s formatting options and flags.
 *
 * @param string A pointer to an initialized ``lvd_string`` struct
 * @param string_format The formatting flags and options
 * @param vargs An initialized list of variable arguments used for formatting
 * @return A pointer to the string value or ``NULL``
 */
void *lvd_string_format_from_vargs(struct lvd_string **string, const char *string_format, va_list vargs);

/**
 * Frees the ``string`` from memory. This action is
 * irreversible.
 *
 * @param array A pointer to an initialized ``lvd_string`` struct
 * @return ``void`` or ``NULL`` if the string is uninitialized
 */
void *lvd_string_free(struct lvd_string **string);

/**
 * Returns the string value of the ``lvd_string``.
 *
 * @param string A pointer to an initialized ``lvd_string`` struct
 * @return A pointer to the string value or ``NULL``
 */
void *lvd_string_get_value(struct lvd_string **string);

/**
 * Allocates a new ``lvd_string``. If ``NULL`` is passed in it will
 * be converted to ``""``
 *
 * @param string A pointer to an uninitialized ``lvd_string`` struct
 * @param string_value Optional string value
 * @return A pointer to the string value or ``NULL``
 */
void *lvd_string_new(struct lvd_string **string, const char *string_value);

/**
 * Sets the new ``string_value`` for the given ``lvd_string`` struct.
 * If ``string_value`` is set to ``NULL`` it will be converted to ``""``.
 *
 * @param string A pointer to an initialized ``lvd_string`` struct
 * @param string_value The new string value
 * @return A pointer to the string value or ``NULL``
 */
void *lvd_string_set_value(struct lvd_string **string, const char *string_value);
