<!-- Warning text -->
> [!NOTE]
> This repository is under moderate development. Code will change but hopefully not break. You have been warned.

<!-- Move text down -->
<br>

<!-- Header -->
<h1 align="center">libVoid</h1>

<!-- Subheading -->
<h3 align="center">A memory management library for C</h3>

<!-- Installing -->
## Installing

```bash
# Clone the repository
git clone https://github.com/The-Astrl-Project/libvoid -b development && cd ./libvoid

# Build the project
./scripts/build.sh -c -b

# Run tests (optional)
./scripts/build.sh -t

# Install
./scripts/build.sh -i
```

<!-- Example -->
## Example

```c
// A *simple* Hello World for C

// Header files
#include <stdio.h>
#include <astrl/libvoid/arrays.h>
#include <astrl/libvoid/strings.h>

// Variables
int main()
{
    struct lvd_string *message_one;
    struct lvd_string *message_two;
    struct lvd_array  *message_array;
    struct lvd_string *message_return_value;

    // Instance a new string struct
    lvd_string_new(&message_one, "Hello!\n");
    lvd_string_new(&message_two, "Bye!\n");

    // Instance a new array struct
    lvd_array_new(&message_array, 1, sizeof(struct lvd_string *));

    // Populate the array
    lvd_array_append(&message_array, message_one, sizeof(struct lvd_string *));
    lvd_array_append(&message_array, message_two, sizeof(struct lvd_string *));

    // Print
    message_return_value = lvd_array_get(&message_array, 0);
    printf("%s", lvd_string_get_value(&message_return_value));
    message_return_value = lvd_array_get(&message_array, 1);
    printf("%s", lvd_string_get_value(&message_return_value));

    // Cleanup
    lvd_string_free(&message_one);
    lvd_string_free(&message_two);
    lvd_array_free(&message_array);
}
```
