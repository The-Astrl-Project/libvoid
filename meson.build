# libVoid || meson.build
# --------------------------------
# Meson build configuration.
#
# Authors: @MaxineToTheStars <https://github.com/MaxineToTheStars>
# ----------------------------------------------------------------

# Project declaration
project(
    'libVoid',
    'c',
    default_options: {
        'prefix': '/usr',
        'buildtype': 'debug',
        'debug': 'true',
        'default_library': 'shared',
        'errorlogs': 'true',
        'optimization': '0',
        'stdsplit': 'true',
        'c_std': 'gnu99'
    },
    license: 'GPLv3',
    license_files: ['LICENSE'],
    meson_version: '>= 1.5.0',
    version: '0.1.0-dev'
)

# Project variables
PROJECT_VERSION = '0.1.0-dev'

# Run the globber.sh script to collect all source and header files
# NOTE: This is not recommended
# https://github.com/mesonbuild/meson/blob/master/docs/markdown/FAQ.md#but-i-really-want-to-use-wildcards
g_source = run_command('bash', './scripts/globber.sh', '-s', capture: true, check: true)
g_include = run_command('bash', './scripts/globber.sh', '-i', capture: true, check: true)
g_source_files = g_source.stdout().strip().replace('./', '').split('\n')
g_include_files = g_include.stdout().strip().replace('./', '').split('\n')

# Unit test declaration
test(
    'libVoid - Unit Test',
    executable(
        'libvoid_unit_test',
        'tests/tests.c',
        include_directories: [include_directories('include'), 'tests'],
        install: false,
        sources: g_source_files,
    ),
)

# Library files declaration
lvd = library(
    'void',
    g_source_files,
    install: true,
    install_dir: 'lib/astrl/libvoid',
)

# Library headers declaration
lvdh = install_headers(
    g_include_files,
    follow_symlinks: true,
    install_dir: 'include/astrl/libvoid',
    preserve_path: false
)

# Generate pkg-config
pkg = import('pkgconfig')
pkg.generate(
    lvd,
    description: 'Practical data structures and utilities for C development - Provided by Astrl',
    install_dir: '/usr/lib/pkgconfig',
    name: 'libvoid',
    url: 'https://github.com/The-Astrl-Project/libvoid',
    version: PROJECT_VERSION,
)
