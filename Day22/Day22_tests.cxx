//
//  Advent of Code 2024 Tests: Day 22
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/21/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day22.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay22{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay22;

TEST(Y2024_SolveDay22, FinalSolutionPartA) {
    EXPECT_EQ("20441185092", solvea());
}

TEST(Y2024_SolveDay22, FinalSolutionPartB) {
    EXPECT_EQ("2268", solveb());
}

TEST(Y2024_Day22Example,Test1) {
    uint64_t x = 123;
    x = calcNextNumber(x);
    EXPECT_EQ(15887950,x);
    x = calcNextNumber(x);
    EXPECT_EQ(16495136,x);
    x = calcNextNumber(x);
    EXPECT_EQ(527345,x);
    x = calcNextNumber(x);
    EXPECT_EQ(704524,x);
    x = calcNextNumber(x);
    EXPECT_EQ(1553684,x);
    x = calcNextNumber(x);
    EXPECT_EQ(12683156,x);
    x = calcNextNumber(x);
    EXPECT_EQ(11100544,x);
    x = calcNextNumber(x);
    EXPECT_EQ(12249484,x);
    x = calcNextNumber(x);
    EXPECT_EQ(7753432,x);
    x = calcNextNumber(x);
    EXPECT_EQ(5908254,x);
}

TEST(Y2024_Day22Example,Test2) {
    int x = 123;
    EXPECT_EQ(5908254,calcNumberAfterSteps(x,10));
    EXPECT_EQ(8685429,calcNumberAfterSteps(1,2000));
    EXPECT_EQ(4700978,calcNumberAfterSteps(10,2000));
    EXPECT_EQ(15273692,calcNumberAfterSteps(100,2000));
    EXPECT_EQ(8667524,calcNumberAfterSteps(2024,2000));
}

TEST(Y2024_Day22Example,Test3) {
    auto m = generatePriceMap(123, 10);
    EXPECT_EQ(7,m.size());
}
