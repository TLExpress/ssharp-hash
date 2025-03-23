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

#include "gtest/gtest.h"

using namespace cityhash;

TEST(CityHash64, Strings)
{
    // Test empty string
    EXPECT_EQ(CityHash64(""), 0x9ae16a3b2f90404f);

    // Test strings of < 4 bytes
    EXPECT_EQ(CityHash64("abc"), 0x3a912f483a4ece31);

    // Test strings of 4-8 bytes
    EXPECT_EQ(CityHash64("abcd"), 0xf75a3b8a1499428d);

    // Test strings of 9-16 bytes
    EXPECT_EQ(CityHash64("abcdefghi"), 0x66c7fa4eb3fab8d1);

    // Test strings of 17-32 bytes
    EXPECT_EQ(CityHash64("abcdefghijklmnopqrst"), 0x5b908404a85121a6);

    // Test strings of 33-64 bytes
    EXPECT_EQ(CityHash64("abcdefghijklmnopqrstuvwxyz12345678909876"),
              0x75c86f881997190c);

    // Test strings of 65-96 bytes
    EXPECT_EQ(
        CityHash64(
            "abcdefghijklmnopqrstuvwxyz1234567890987654321zyxwvutsrqponmlkjihgfedcba"),
        0xbc2af24a12b150cd);
}
