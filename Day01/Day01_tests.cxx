//
//  Advent of Code 2024 Tests: Day 1
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 11/30/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day01.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay01{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay01;

TEST(Y2024_SolveDay1, FinalSolutionPartA) {
    EXPECT_EQ("1830467", solvea());
}

TEST(Y2024_SolveDay1, FinalSolutionPartB) {
    EXPECT_EQ("26674158", solveb());
}
