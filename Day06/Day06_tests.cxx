//
//  Advent of Code 2024 Tests: Day 6
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/06/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day06.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay06{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay06;

TEST(Y2024_SolveDay6, FinalSolutionPartA) {
    EXPECT_EQ("5409", solvea());
}

TEST(Y2024_SolveDay6, FinalSolutionPartB) {
    EXPECT_EQ("2022", solveb());
}

TEST(Y2024_Day6Example,Test1) {
    vector<string> input{
        "....#.....",
        ".........#",
        "..........",
        "..#.......",
        ".......#..",
        "..........",
        ".#..^.....",
        "........#.",
        "#.........",
        "......#..."
    };
    int x = findUnqiqueLocVisited(input);
    EXPECT_EQ(41,x);
}
