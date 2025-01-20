<!-- Warning text -->
> [!WARNING]
> This branch is solely for archival purposes. DO NOT USE

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
// Header files
#include <stdio.h>
#include <astrl/libvoid/arrays.h>
#include <astrl/libvoid/strings.h>

int main()
{
    // Variables
    struct lvd_string *message_one;
    struct lvd_string *message_two;
    struct lvd_array *message_array;

    // Instance a new lvd_array
    lvd_array_new(&message_array, 1, sizeof(struct lvd_string));

    // Instance new lvd_strings
    lvd_string_new(&message_one, "Hello World!");
    lvd_string_new(&message_two, "Goodbye World!");

    // Append
    // The lvd_array will automatically re-size itself
    lvd_array_append(&message_array, message_one, sizeof(*message_one));
    lvd_array_append(&message_array, message_two, sizeof(*message_two));

    // Free some data (it is already stored in the message_array)
    lvd_string_detach(&message_one);
    lvd_string_detach(&message_two);

    // Retrieve and modify some data
    message_two = lvd_array_get(&message_array, 1);
    // Since this is pass by reference we can directly edit the entry
    lvd_string_set_value(&message_two, "Or Goodbye Again?");

    // Print
    message_one = lvd_array_get(&message_array, 0);
    message_two = lvd_array_get(&message_array, 1);
    printf("%s\n", lvd_string_get_value(&message_one));
    printf("%s\n", lvd_string_get_value(&message_two));

    // Cleanup
    lvd_string_free(&message_one);
    lvd_string_free(&message_two);
    lvd_array_free(&message_array);

    // Exit
    return 0;
}
```
