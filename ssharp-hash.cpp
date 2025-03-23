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

#include "ssharp-hash.hpp"
#include "city.hpp"

namespace ssharp::hash::cli
{

void hash(const std::vector<std::string>& strs, uint16_t salt, bool verbose,
          std::optional<filepath_t> output)
{
    std::ofstream out;
    if (output)
    {
        out.open(*output, std::ios::app);
        if (!out.is_open())
        {
            throw std::runtime_error("Failed to open output file");
        }
    }
    for (auto str : strs)
    {
        hash_t hash;
        if (salt)
        {
            str = std::to_string(salt) + str;
        }
        hash = cityhash::CityHash64(str);
        if (output)
        {
            out << str << ',' << std::hex << hash << std::endl;
        }
        if (verbose)
        {
            std::cout << "Length: " << str.size() << std::endl;
            std::cout << "Hash of \"" << str << "\": " << std::endl;
            std::cout << std::hex << hash << std::endl;
        }
        else if (!output)
        {
            std::cout << std::hex << hash << std::endl;
        }
    }
}

void assign_command_impl(CLI::App& app, std::vector<std::string>& strs,
                         uint16_t& salt, bool& verbose, bool& empty_string,
                         std::optional<std::string>& output)
{
    app.add_option("--salt,-s", salt, "Specify the salt to use");
    app.add_flag("--verbose,-v", verbose,
                 "Print the string along with the hash");
    app.add_flag("--empty-string,-e", empty_string, "Hash an empty string");
    app.add_option("--output,-o", output, "The file to write the output to");
    app.add_option("strings", strs, "The string to hash");
    app.callback([&]() {
        if (empty_string)
        {
            strs.emplace(strs.begin(), "");
        }
        if (strs.empty())
        {
            throw CLI::CallForHelp();
        }
        std::optional<filepath_t> output_path = std::nullopt;
        if (output)
        {
            output_path = filepath_t{std::move(*output)};
        }
        hash(strs, salt, verbose, output_path);
    });
}

} // namespace ssharp::hash::cli
