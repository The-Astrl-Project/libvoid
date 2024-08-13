<!-- Warning text -->
> [!WARNING]
> This repository is under heavy development. Code will break/change. You have been warned.

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
// Headers
#include <stdlib.h>
#include <libvoid/arrays.h>

// Declare a struct
struct my_struct
{
    void *some_pointer;
    int some_value;
};

// Instance a new array
struct lvd_array *my_array;
lvd_array_new(&my_array, 1, sizeof(struct my_struct));

// Allocate
struct my_struct *my_data = (struct my_struct *)malloc(1 * sizeof(struct my_struct));

// Add data
my_data->some_value = 1;

// Append data
lvd_array_append(&my_array, my_data, sizeof(*my_data));

// Print data
struct my_struct *return_data = (struct my_struct *)lvd_array_get(&my_array, 0);
printf("%i\n", return_data->some_value);
```
