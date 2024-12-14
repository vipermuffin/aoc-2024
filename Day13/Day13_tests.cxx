//
//  Advent of Code 2024 Tests: Day 13
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/13/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day13.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay13{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay13;

TEST(Y2024_SolveDay13, FinalSolutionPartA) {
    EXPECT_EQ("33481", solvea());
}

TEST(Y2024_SolveDay13, FinalSolutionPartB) {
    EXPECT_EQ("92572057880885", solveb());
}

TEST(Y2024_Day13Example,Test1) {
    vector<string> input {
        "Button A: X+94, Y+34",
        "Button B: X+22, Y+67",
        "Prize: X=8400, Y=5400"
    };
    ClawGame game(input);
    EXPECT_EQ(94,game.aButton.first);
    EXPECT_EQ(34,game.aButton.second);
    EXPECT_EQ(22,game.bButton.first);
    EXPECT_EQ(67,game.bButton.second);
    EXPECT_EQ(8400,game.result.first);
    EXPECT_EQ(5400,game.result.second);
}

TEST(Y2024_Day13Example,Test2) {
    vector<string> input {
        "Button A: X+94, Y+34",
        "Button B: X+22, Y+67",
        "Prize: X=8400, Y=5400"
    };
    ClawGame game(input);
    EXPECT_EQ(280,game.calcLowestCost());
}

TEST(Y2024_Day13Example,Test3) {
    vector<string> input {
        "Button A: X+26, Y+66",
        "Button B: X+67, Y+21",
        "Prize: X=12748, Y=12176"
    };
    ClawGame game(input);
    EXPECT_EQ(INT64_MAX,game.calcLowestCost());
}

TEST(Y2024_Day13Example,Test4) {
    vector<string> input {
        "Button A: X+17, Y+86",
        "Button B: X+84, Y+37",
        "Prize: X=7870, Y=6450"
    };
    ClawGame game(input);
    EXPECT_EQ(200,game.calcLowestCost());
}

TEST(Y2024_Day13Example,Test5) {
    vector<string> input {
        "Button A: X+69, Y+23",
        "Button B: X+27, Y+71",
        "Prize: X=18641, Y=10279"
    };
    ClawGame game(input);
    EXPECT_EQ(INT64_MAX,game.calcLowestCost());
}