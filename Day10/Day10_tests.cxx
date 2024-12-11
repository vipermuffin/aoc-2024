//
//  Advent of Code 2024 Tests: Day 10
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/10/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day10.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay10{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay10;

TEST(Y2024_SolveDay10, FinalSolutionPartA) {
    EXPECT_EQ("719", solvea());
}

TEST(Y2024_SolveDay10, FinalSolutionPartB) {
    EXPECT_EQ("1530", solveb());
}

TEST(Y2024_Day10Example,Test1a) {
    vector<string> tm{
        "...0...",
        "...1...",
        "...2...",
        "6543456",
        "7.....7",
        "8.....8",
        "9.....9"
    };
    EXPECT_EQ(2,getMapScore(tm));
}

TEST(Y2024_Day10Example,Test1b) {
    vector<string> tm{
        "..90..9",
        "...1.98",
        "...2..7",
        "6543456",
        "765.987",
        "876....",
        "987...."
    };
    EXPECT_EQ(4,getMapScore(tm));
}

TEST(Y2024_Day10Example,Test1c) {
    vector<string> tm{
        "10..9..",
        "2...8..",
        "3...7..",
        "4567654",
        "...8..3",
        "...9..2",
        ".....01"
    };
    EXPECT_EQ(3,getMapScore(tm));
}

TEST(Y2024_Day10Example,Test2) {
    vector<string> tm{
        "89010123",
        "78121874",
        "87430965",
        "96549874",
        "45678903",
        "32019012",
        "01329801",
        "10456732"
    };
    EXPECT_EQ(36,getMapScore(tm));
}

TEST(Y2024_Day10Example,Test3) {
    vector<string> tm{
        "89010123",
        "78121874",
        "87430965",
        "96549874",
        "45678903",
        "32019012",
        "01329801",
        "10456732"
    };
    EXPECT_EQ(81,getMapScore(tm,true));
}
