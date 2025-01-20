# libVoid || meson.build
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

# Run the globber script
# NOTE: This is not really recommended
# https://github.com/mesonbuild/meson/blob/master/docs/markdown/FAQ.md#but-i-really-want-to-use-wildcards
globber_source = run_command('bash', './scripts/globber.sh', '-s', capture: true, check: true)
globber_include = run_command('bash', './scripts/globber.sh', '-i', capture: true, check: true)


# Parse the outputs
parsed_source_files = globber_source.stdout().strip().replace('./', '').split('\n')
parsed_include_files = globber_include.stdout().strip().replace('./', '').split('\n')

# Declare the unit test executable
unit_test_executable = executable(
    'libvoid_unit_test',
    'tests/tests.c',
    c_args: '-g3',
    include_directories: [include_directories('include'), 'tests'],
    install: false,
    sources: parsed_source_files,
)

# Declare the unit test
test(
    'Sanity Check',
    unit_test_executable,
)

# Declare the project library
library(
    'void',
    parsed_source_files,
    install: true,
    install_dir: 'lib/astrl/libvoid',
)

# Declare the project headers
install_headers(
    parsed_include_files,
    follow_symlinks: true,
    install_dir: 'include/astrl/libvoid',
    preserve_path: false,
)
