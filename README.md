<!-- Move text down -->
<br>

<!-- Header -->
<h1 align="center">libVoid</h1>

<!-- Subheading -->
<h3 align="center">Practical data structures and utilities for C development</h3>

<!-- Installing -->

## Installing

```bash
# Clone the repository
git clone https://github.com/The-Astrl-Project/libvoid.git -b development --recurse-submodules

# Build the project
./scripts/build.sh -b

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
#include <stdlib.h>
#include <astrl/libvoid/arraylist.h>

int main()
{
    /* Example Struct */
    struct my_struct
    {
        /* Age */
        int age;
        /* Name */
        void *name;
    };

    // Data
    struct my_struct *data_one = calloc(1, sizeof(struct my_struct));
    struct my_struct *data_two = calloc(1, sizeof(struct my_struct));

    // Populate
    data_one->age = 1;
    data_one->name = "The letter A";
    data_two->age = 2;
    data_two->name = "The letter B";

    // Instance a new array
    struct lvd_arraylist_t *arraylist = lvd_arraylist_init(1, sizeof(struct my_struct));

    // Populate
    lvd_arraylist_append(arraylist, data_one);
    lvd_arraylist_append(arraylist, data_two);

    // Free the structs
    free(data_one);
    free(data_two);

    // Pull data from the ArrayList
    data_one = lvd_arraylist_get_at(arraylist, 0);

    // Print
    printf("Age: %d\n", data_one->age);
    printf("Name: %s\n", data_one->name);

    // Free the ArrayList
    lvd_arraylist_free(arraylist);

    // Exit
    return 0;
}
```
