//
//  Advent of Code 2024 Tests: Day 3
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/03/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day03.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay03{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay03;

TEST(Y2024_SolveDay3, FinalSolutionPartA) {
    EXPECT_EQ("166357705", solvea());
}

TEST(Y2024_SolveDay3, FinalSolutionPartB) {
    EXPECT_EQ("88811886", solveb());
}

TEST(Y2024_Day3Example,Test1) {
    string input{"xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))"};
    auto x = findMulMatches(input);
    ASSERT_EQ(4, x.size());
    EXPECT_EQ(2, x[0].first);
    EXPECT_EQ(4, x[0].second);
    EXPECT_EQ(5, x[1].first);
    EXPECT_EQ(5, x[1].second);
    EXPECT_EQ(11,x[2].first);
    EXPECT_EQ(8, x[2].second);
    EXPECT_EQ(8, x[3].first);
    EXPECT_EQ(5, x[3].second);
}

TEST(Y2024_Day3Example,Test2) {
    vector<string> input{"xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))"};
    auto x = accumulateMultiplies(input);
    EXPECT_EQ(161,x);
}

TEST(Y2024_Day3Example,Test3) {
    vector<string> input{"xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))","xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))"};
    auto x = accumulateMultiplies(input);
    EXPECT_EQ(322,x);
}

TEST(Y2024_Day3Example,Test4) {
    vector<string> input{"xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5))"};
    auto x = accumulateMultiplies(input, true);
    EXPECT_EQ(48,x);
}

TEST(Y2024_Day3Example,Test5) {
    vector<string> input{"xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5))don't()_mul(5,5)+mul(32,64](mul(11,8)do()?mul(2,5))don't()_mul(5,5)+mul(32,64](mul(11,8)"};
    auto x = accumulateMultiplies(input, true);
    EXPECT_EQ(58,x);
}
