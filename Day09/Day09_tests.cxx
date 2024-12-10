//
//  Advent of Code 2024 Tests: Day 9
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/09/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day09.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay09{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay09;

TEST(Y2024_SolveDay9, FinalSolutionPartA) {
    EXPECT_EQ("6279058075753", solvea());
}

TEST(Y2024_SolveDay9, FinalSolutionPartB) {
    EXPECT_EQ("6301361958738", solveb());
}

TEST(Y2024_Day9Example,Test1) {
    string x{"12345"};
    auto bList = buildList(x);
    EXPECT_EQ(15,bList.size());
    EXPECT_EQ("0..111....22222", printList(bList));
}

TEST(Y2024_Day9Example,Test2) {
    string x{"12345"};
    auto bList = buildList(x);
    auto cksum = increaseFrag(bList);
    EXPECT_EQ("022111222......", printList(bList));
}

TEST(Y2024_Day9Example,Test3) {
    string x{"2333133121414131402"};
    auto bList = buildList(x);
    EXPECT_EQ("00...111...2...333.44.5555.6666.777.888899", printList(bList));
}

TEST(Y2024_Day9Example,Test4) {
    string x{"2333133121414131402"};
    auto bList = buildList(x);
    auto cksum = increaseFrag(bList);
    EXPECT_EQ("0099811188827773336446555566..............", printList(bList));
    EXPECT_EQ(1928,cksum);
}

TEST(Y2024_Day9Example,Test5) {
    string x{"2333133121414131402"};
    auto bList = buildList(x);
    auto cksum = defrag(bList);
    EXPECT_EQ("00992111777.44.333....5555.6666.....8888..", printList(bList));
    EXPECT_EQ(2858,cksum);
}
