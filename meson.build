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
    license: 'GPLv3',
    license_files: 'LICENSE',
    version: '0.1.0',
)

# Run the grabber.sh script to prase through /src and echo
# out all the *.c files found.
# NOTE: This is not recommended:
# https://github.com/mesonbuild/meson/blob/master/docs/markdown/FAQ.md#but-i-really-want-to-use-wildcards
globber_source = run_command('bash', './scripts/grabber.sh', '-s', check: true)
globber_include = run_command('bash', './scripts/grabber.sh', '-i', check: true)
source_files = globber_source.stdout().strip().replace('./', '').split('\n')
include_files = globber_include.stdout().strip().replace('./', '').split('\n')

# Include the full include directory
include_directory = include_directories('include')

# Declare unit test executable
test_executable = executable(
    'libvoid_unit_test',
    'tests/tests.c',
    sources: source_files,
    include_directories: include_directory,
    install: false,
)

# Declare unit test
test('Core Functionality', test_executable)

# Declare a shared library
shared_library(
    'libvoid',
    sources: source_files,
    install: true,
)

# Install library headers
install_headers(
    include_files,
    subdir: 'libvoid',
)
