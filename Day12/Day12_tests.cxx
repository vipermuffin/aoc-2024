//
//  Advent of Code 2024 Tests: Day 12
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/12/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day12.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay12{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay12;

TEST(Y2024_SolveDay12, FinalSolutionPartA) {
    EXPECT_EQ("1446042", solvea());
}

TEST(Y2024_SolveDay12, FinalSolutionPartB) {
    EXPECT_EQ("902742", solveb());
}

TEST(Y2024_Day12Example,Test1) {
    vector<string> input {
        "RRRRIICCFF",
        "RRRRIICCCF",
        "VVRRRCCFFF",
        "VVRCCCJFFF",
        "VVVVCJJCFE",
        "VVIVCCJJEE",
        "VVIIICJJEE",
        "MIIIIIJJEE",
        "MIIISIJEEE",
        "MMMISSJEEE"
    };
    EXPECT_EQ(1930,calculatePrice(input));
}

TEST(Y2024_Day12Example,Test2) {
    vector<string> input {
        "RRRRIICCFF",
        "RRRRIICCCF",
        "VVRRRCCFFF",
        "VVRCCCJFFF",
        "VVVVCJJCFE",
        "VVIVCCJJEE",
        "VVIIICJJEE",
        "MIIIIIJJEE",
        "MIIISIJEEE",
        "MMMISSJEEE"
    };
    EXPECT_EQ(1206,calculatePrice(input,true));
}

TEST(Y2024_Day12Example,Test3) {
    int x = 0;
    EXPECT_EQ(0,x);
}
