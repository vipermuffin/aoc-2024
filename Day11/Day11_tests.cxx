//
//  Advent of Code 2024 Tests: Day 11
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/11/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day11.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay11{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay11;

TEST(Y2024_SolveDay11, FinalSolutionPartA) {
    EXPECT_EQ("202019", solvea());
}

TEST(Y2024_SolveDay11, FinalSolutionPartB) {
    EXPECT_EQ("239321955280205", solveb());
}

TEST(Y2024_Day11Example,Test1) {
    string x = "0 1 10 99 999";
    auto stones = initList(x);
    EXPECT_EQ(x,printList(stones));
}

TEST(Y2024_Day11Example,Test2) {
    string x = "0 1 10 99 999";
    auto stones = initList(x);
    blink(stones);
    EXPECT_EQ("1 2024 1 0 9 9 2021976",printList(stones));
}

TEST(Y2024_Day11Example,Test3) {
    string x = "0 1 10 99 999";
    auto stones = initListMap(x);
    blink(stones);
    //EXPECT_EQ("1 2024 1 0 9 9 2021976",printList(stones));
    EXPECT_EQ(2,stones[1]);
    EXPECT_EQ(1,stones[2024]);
    EXPECT_EQ(1,stones[0]);
    EXPECT_EQ(2,stones[9]);
    EXPECT_EQ(1,stones[2021976]);
    EXPECT_EQ(7,countStones(stones));
}
