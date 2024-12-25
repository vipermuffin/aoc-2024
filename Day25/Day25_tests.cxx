//
//  Advent of Code 2024 Tests: Day 25
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/25/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day25.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay25{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay25;

TEST(Y2024_SolveDay25, FinalSolutionPartA) {
    EXPECT_EQ("3223", solvea());
}

