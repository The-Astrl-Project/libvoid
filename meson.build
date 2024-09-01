# libvoid || meson.build
# --------------------------------
# Meson build configuration.
#
# Authors: @MaxineToTheStars <https://github.com/MaxineToTheStars>
# ----------------------------------------------------------------

# Project Declaration
project(
    'libvoid',
    'c',
    default_options: {'default_library': 'shared', 'c_std': 'c99'},
    license: 'GPLv3',
    license_files: ['LICENSE'],
    meson_version: '>= 1.5.0',
    version: '0.1.0-dev',
)

# Run the grabber.sh script to prase through /src and /include and echo
# out all the *.c and .h files found.
# NOTE: This is not recommended
# https://github.com/mesonbuild/meson/blob/master/docs/markdown/FAQ.md#but-i-really-want-to-use-wildcards
globber_source = run_command(
    'bash',
    './scripts/grabber.sh',
    '-s',
    capture: true,
    check: true,
)
globber_include = run_command(
    'bash',
    './scripts/grabber.sh',
    '-i',
    capture: true,
    check: true,
)
source_files = globber_source.stdout().strip().replace('./', '').split('\n')
include_files = globber_include.stdout().strip().replace('./', '').split('\n')

# Include the full include directory
include_directory = include_directories('include')

# Declare unit test executable
test_executable = executable(
    'libvoid_unit_test',
    'tests/tests.c',
    c_args: '-g3',
    include_directories: [include_directory, 'tests'],
    install: false,
    sources: source_files,
)

# Declare unit test
test(
    'Core Functionality',
    test_executable,
)

# Declare a library
library(
    'void',
    source_files,
    install: true,
    install_dir: 'lib/astrl/libvoid',
)

# Install library headers
install_headers(
    include_files,
    follow_symlinks: true,
    install_dir: 'include/astrl/libvoid',
    preserve_path: false,
)
