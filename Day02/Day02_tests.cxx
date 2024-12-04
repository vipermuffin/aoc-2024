//
//  Advent of Code 2024 Tests: Day 2
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/01/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day02.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay02{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay02;

TEST(Y2024_SolveDay2, FinalSolutionPartA) {
    EXPECT_EQ("421", solvea());
}

TEST(Y2024_SolveDay2, FinalSolutionPartB) {
    EXPECT_EQ("476", solveb());
}

TEST(Y2024_Day2Example,Test1a) {
    vector<int> x{7,6,4,2,1};
    EXPECT_TRUE(isSafeReport(x));
}

TEST(Y2024_Day2Example,Test2a) {
    vector<int> x{1,2,7,8,9};
    EXPECT_FALSE(isSafeReport(x));
}

TEST(Y2024_Day2Example,Test3a) {
    vector<int> x{9,7,6,2,1};
    EXPECT_FALSE(isSafeReport(x));
}

TEST(Y2024_Day2Example,Test4a) {
    vector<int> x{1,3,2,4,5};
    EXPECT_FALSE(isSafeReport(x));
}

TEST(Y2024_Day2Example,Test5a) {
    vector<int> x{8,6,4,4,1};
    EXPECT_FALSE(isSafeReport(x));
}

TEST(Y2024_Day2Example,Test6a) {
    vector<int> x{1,3,6,7,9};
    EXPECT_TRUE(isSafeReport(x));
}

TEST(Y2024_Day2Example,Test1b) {
    vector<int> x{7,6,4,2,1};
    EXPECT_TRUE(isSafeReport(x,true));
}

TEST(Y2024_Day2Example,Test2b) {
    vector<int> x{1,2,7,8,9};
    EXPECT_FALSE(isSafeReport(x,true));
}

TEST(Y2024_Day2Example,Test3b) {
    vector<int> x{9,7,6,2,1};
    EXPECT_FALSE(isSafeReport(x,true));
}

TEST(Y2024_Day2Example,Test4b) {
    vector<int> x{1,3,2,4,5};
    EXPECT_TRUE(isSafeReport(x,true));
}

TEST(Y2024_Day2Example,Test5b) {
    vector<int> x{8,6,4,4,1};
    EXPECT_TRUE(isSafeReport(x,true));
}

TEST(Y2024_Day2Example,Test6b) {
    vector<int> x{1,3,6,7,9};
    EXPECT_TRUE(isSafeReport(x,true));
}
