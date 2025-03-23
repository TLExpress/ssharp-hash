// Copyright (C) 2025 TLExpress.
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "CLI/CLI.hpp"

#include <filesystem>
#include <optional>

namespace ssharp::hash::cli
{
using hash_t = uint64_t;
using filepath_t = std::filesystem::path;

/**
 * @brief Hashes the given strings
 *
 * @param strs The strings to hash
 * @param salt The salt to use
 * @param verbose Whether to print the string along with the hash
 * @param output The file to write the output to
 */
void hash(const std::vector<std::string>& strs, uint16_t salt, bool verbose, std::optional<filepath_t> output = std::nullopt);

/**
 * @brief Assigns the command to the given CLI app
 *
 * @param app The CLI app to assign the command to
 * @param strs The strings to hash
 * @param salt The salt to use
 * @param verbose Whether to print the string along with the hash
 * @param empty_string Whether to hash an empty string
 * @param output The file to write the output to
 */
void assign_command_impl(CLI::App& app, std::vector<std::string>& strs,
                         uint16_t& salt, bool& verbose, bool& empty_string, std::optional<std::string>& output);
} // namespace ssharp::hash::cli
