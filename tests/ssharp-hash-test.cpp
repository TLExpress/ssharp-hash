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

#include "city.hpp"
#include "ssharp-hash.hpp"
#include "gtest/gtest.h"

using namespace ssharp::hash::cli;

TEST(hash, NoSalt)
{
    std::vector<std::string> strs = {"abc"};
    testing::internal::CaptureStdout();
    hash(strs, 0, false);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "3a912f483a4ece31\n");
}

TEST(hash, Salt)
{
    std::vector<std::string> strs = {"abc"};
    testing::internal::CaptureStdout();
    hash(strs, 123, false);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "82dcde919fa8355f\n");
}