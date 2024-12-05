//
//  Advent of Code 2024 Tests: Day 4
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/04/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day04.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay04{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay04;

TEST(Y2024_SolveDay4, FinalSolutionPartA) {
    EXPECT_EQ("2644", solvea());
}

TEST(Y2024_SolveDay4, FinalSolutionPartB) {
    EXPECT_EQ("1952", solveb());
}

TEST(Y2024_Day4Example,Test1) {
    vector<string> x{
            "..X...",
            ".SAMX.",
            ".A..A.",
            "XMAS.S",
            ".X...."};
    string w{"XMAS"};
    EXPECT_EQ(4,findWordInGrid(x, w));
}

TEST(Y2024_Day4Example,Test2) {
    vector<string> x{
        "MMMSXXMASM",
        "MSAMXMSMSA",
        "AMXSXMAAMM",
        "MSAMASMSMX",
        "XMASAMXAMM",
        "XXAMMXXAMA",
        "SMSMSASXSS",
        "SAXAMASAAA",
        "MAMMMXMMMM",
        "MXMXAXMASX"};
    string w{"XMAS"};
    EXPECT_EQ(18,findWordInGrid(x, w));
}

TEST(Y2024_Day4Example,Test3) {
    vector<string> x{
        "MMMSXXMASM",
        "MSAMXMSMSA",
        "AMXSXMAAMM",
        "MSAMASMSMX",
        "XMASAMXAMM",
        "XXAMMXXAMA",
        "SMSMSASXSS",
        "SAXAMASAAA",
        "MAMMMXMMMM",
        "MXMXAXMASX"};
    string w{"MAS"};
    EXPECT_EQ(9,findXWordInGrid(x, w));
}
