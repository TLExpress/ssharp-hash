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

int main(int argc, char** argv)
{
    CLI::App app{"ssharp-hash"};

    uint16_t salt = 0;
    std::vector<std::string> strs{};
    bool verbose = false;
    bool empty_string = false;
    std::optional<std::string> output = std::nullopt;
    ssharp::hash::cli::assign_command_impl(app, strs, salt, verbose, empty_string, output);

    CLI11_PARSE(app, argc, argv);
}
