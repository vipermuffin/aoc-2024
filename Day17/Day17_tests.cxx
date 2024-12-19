//
//  Advent of Code 2024 Tests: Day 17
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/18/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day17.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay17{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay17;

TEST(Y2024_SolveDay17, FinalSolutionPartA) {
    EXPECT_EQ("4,1,5,3,1,5,3,5,7", solvea());
}

TEST(Y2024_SolveDay17, FinalSolutionPartB) {
    // EXPECT_EQ("---", solveb());
}

TEST(Y2024_Day17Example,Test1) {
    vector<string> input {
        "Register A: 729",
        "Register B: 0",
        "Register C: 0",
        "",
        "Program: 0,1,5,4,3,0"
    };
    vector<int> registers;
    auto program = parseProgram(input, registers);

    ASSERT_EQ(8, registers.size());
    EXPECT_EQ(729, registers[4]);
    EXPECT_EQ(0, registers[5]);
    EXPECT_EQ(0, registers[6]);
    EXPECT_EQ(0, registers[0]);
    EXPECT_EQ(1, registers[1]);
    EXPECT_EQ(2, registers[2]);
    EXPECT_EQ(3, registers[3]);
    ASSERT_EQ(3, program.size());
    EXPECT_EQ(0, program[0].first);
    EXPECT_EQ(1, program[0].second);
    EXPECT_EQ(5, program[1].first);
    EXPECT_EQ(4, program[1].second);
    EXPECT_EQ(3, program[2].first);
    EXPECT_EQ(0, program[2].second);
}

TEST(Y2024_Day17Example,Test2) {
    vector<string> input {
        "Register A: 729",
        "Register B: 0",
        "Register C: 0",
        "",
        "Program: 0,1,5,4,3,0"
    };
    vector<int> registers;
    auto program = parseProgram(input, registers);
    auto result = runProgram(program, registers);
    EXPECT_EQ("4,6,3,5,6,3,5,2,1,0", result);
}

TEST(Y2024_Day17Example,Test3) {
    vector<string> input {
        "Register A: 2024",
        "Register B: 0",
        "Register C: 0",
        "",
        "Program: 0,3,5,4,3,0"
    };
    vector<int> registers;
    EXPECT_EQ(117440,findInitValProgram(input));
}

TEST(Y2024_Day17Example,Test4) {
    vector<string> input {
        "Register A: 117440",
        "Register B: 0",
        "Register C: 0",
        "",
        "Program: 0,3,5,4,3,0"
    };
    vector<int> registers;
    auto program = parseProgram(input, registers);
    EXPECT_EQ("0,3,5,4,3,0",runProgram(program,registers));
}
