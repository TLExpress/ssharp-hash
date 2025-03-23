# Copyright (C) 2025 TLExpress.
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

project(
    'ssharp-hash',
    'cpp',
    default_options: {
        'debug': true,
        'optimization': 'g',
        'warning_level': '3',
        'werror': true,
        'cpp_std': 'c++23',
        'b_ndebug': 'if-release',
    }
)

cpp = meson.get_compiler('cpp')

if cpp.has_header('CLI/CLI.hpp')
    CLI11_dep = declare_dependency()
else
    CLI11_dep = dependency('CLI11')
endif

if get_option('tests').allowed()
    gtest = dependency('gtest', main: true, disabler: true, required: false)
    gmock = dependency('gmock', disabler: true, required: false)
    if not gtest.found() or not gmock.found()
        gtest_proj = import('cmake').subproject('gtest', required: false)
        if gtest_proj.found()
            gtest = declare_dependency(
                dependencies: [
                    dependency('threads'),
                    gtest_proj.dependency('gtest'),
                    gtest_proj.dependency('gtest_main'),
                ],
            )
            gmock = gtest_proj.dependency('gmock')
        else
            assert(
                not get_option('tests').allowed(),
                'Googletest is required if tests are enabled',
            )
        endif
    endif
endif

subdir('cityhash')

ssharp_hash = static_library(
    'ssharp-hash',
    'ssharp-hash.cpp',
    include_directories: include_directories('cityhash'),
    link_with: cityhash,
    dependencies: [CLI11_dep],
)

# Define the executable and link it with the parser library
executable('ssharp-hash',
    'ssharp-hash-main.cpp',
    link_with: ssharp_hash,
    dependencies: [CLI11_dep],
)

if get_option('tests').allowed()
    subdir('cityhash/tests')
    subdir('tests')
endif


ssharp_hash_dep = declare_dependency(
    include_directories: include_directories('cityhash', '.'),
    link_with: ssharp_hash,
    dependencies: [CLI11_dep],
    version: meson.project_version(),
)

meson.override_dependency('ssharp-hash', ssharp_hash_dep)

