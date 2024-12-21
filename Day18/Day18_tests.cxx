//
//  Advent of Code 2024 Tests: Day 18
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/21/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day18.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay18{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay18;

TEST(Y2024_SolveDay18, FinalSolutionPartA) {
    EXPECT_EQ("314", solvea());
}

TEST(Y2024_SolveDay18, FinalSolutionPartB) {
    EXPECT_EQ("15,20", solveb());
}

TEST(Y2024_Day18Example,Test1) {
    vector<string> input {
        "5,4",
        "4,2",
        "4,5",
        "3,0",
        "2,1",
        "6,3",
        "2,4",
        "1,5",
        "0,6",
        "3,3",
        "2,6",
        "5,1",
        "1,2",
        "5,5",
        "2,5",
        "6,5",
        "1,4",
        "0,4",
        "6,4",
        "1,1",
        "6,1",
        "1,0",
        "0,5",
        "1,6",
        "2,0"
    };
    auto parsedInput = parseInput(input, input.size());
    ASSERT_EQ(25,parsedInput.size());
    EXPECT_EQ(1,parsedInput.count(5 + 4 * 1000));
    EXPECT_EQ(1,parsedInput.count(4 + 2 * 1000));
    EXPECT_EQ(1,parsedInput.count(4 + 5 * 1000));
    EXPECT_EQ(1,parsedInput.count(3 + 0 * 1000));
    EXPECT_EQ(1,parsedInput.count(2 + 1 * 1000));
    EXPECT_EQ(1,parsedInput.count(6 + 3 * 1000));
    EXPECT_EQ(1,parsedInput.count(2 + 4 * 1000));
    EXPECT_EQ(1,parsedInput.count(1 + 5 * 1000));
    EXPECT_EQ(0 ,parsedInput.count(0));
}

TEST(Y2024_Day18Example,Test2) {
    vector<string> input {
        "5,4",
        "4,2",
        "4,5",
        "3,0",
        "2,1",
        "6,3",
        "2,4",
        "1,5",
        "0,6",
        "3,3",
        "2,6",
        "5,1",
        "1,2",
        "5,5",
        "2,5",
        "6,5",
        "1,4",
        "0,4",
        "6,4",
        "1,1",
        "6,1",
        "1,0",
        "0,5",
        "1,6",
        "2,0"
    };
    EXPECT_EQ(22,findShortestPathSteps(input, coordXY(6,6), 6, 12) );
}

TEST(Y2024_Day18Example,Test3) {
    vector<string> input {
        "5,4",
        "4,2",
        "4,5",
        "3,0",
        "2,1",
        "6,3",
        "2,4",
        "1,5",
        "0,6",
        "3,3",
        "2,6",
        "5,1",
        "1,2",
        "5,5",
        "2,5",
        "6,5",
        "1,4",
        "0,4",
        "6,4",
        "1,1",
        "6,1",
        "1,0",
        "0,5",
        "1,6",
        "2,0"
    };
    EXPECT_EQ("6,1",findBlockingCoordinates(input, coordXY(6,6)));
}
