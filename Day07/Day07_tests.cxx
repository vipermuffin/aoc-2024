//
//  Advent of Code 2024 Tests: Day 7
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/06/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day07.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay07{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay07;

TEST(Y2024_SolveDay7, FinalSolutionPartA) {
    EXPECT_EQ("21572148763543", solvea());
}

TEST(Y2024_SolveDay7, FinalSolutionPartB) {
    EXPECT_EQ("581941094529163", solveb());
}

TEST(Y2024_Day7Example,Test1a) {
    string x{"190: 10 19"};
    
    EXPECT_EQ(190,validateEquation(x));
}

TEST(Y2024_Day7Example,Test2a) {
    string x{"3267: 81 40 27"};
    
    EXPECT_EQ(3267,validateEquation(x));
}

TEST(Y2024_Day7Example,Test3a) {
    string x{"292: 11 6 16 20"};
    
    EXPECT_EQ(292,validateEquation(x));
}
TEST(Y2024_Day7Example,Test4a) {
    string x{"83: 17 5"};
    
    EXPECT_EQ(0,validateEquation(x));
}
TEST(Y2024_Day7Example,Test5a) {
    string x{"161011: 16 10 13"};
    
    EXPECT_EQ(0,validateEquation(x));
}
TEST(Y2024_Day7Example,Test6a) {
    string x{"156: 15 6"};
    
    EXPECT_EQ(0,validateEquation(x));
}

TEST(Y2024_Day7Example,Test7a) {
    string x{"7290: 6 8 6 15"};
    
    EXPECT_EQ(0,validateEquation(x));
}

TEST(Y2024_Day7Example,Test8a) {
    string x{"192: 17 8 14"};
    
    EXPECT_EQ(0,validateEquation(x));
}

TEST(Y2024_Day7Example,Test1b) {
    string x{"190: 10 19"};
    
    EXPECT_EQ(190,validateEquation(x,true));
}

TEST(Y2024_Day7Example,Test2b) {
    string x{"3267: 81 40 27"};
    
    EXPECT_EQ(3267,validateEquation(x,true));
}

TEST(Y2024_Day7Example,Test3b) {
    string x{"292: 11 6 16 20"};
    
    EXPECT_EQ(292,validateEquation(x,true));
}
TEST(Y2024_Day7Example,Test4b) {
    string x{"83: 17 5"};
    
    EXPECT_EQ(0,validateEquation(x,true));
}
TEST(Y2024_Day7Example,Test5b) {
    string x{"161011: 16 10 13"};
    
    EXPECT_EQ(0,validateEquation(x,true));
}
TEST(Y2024_Day7Example,Test6b) {
    string x{"156: 15 6"};
    
    EXPECT_EQ(156,validateEquation(x,true));
}

TEST(Y2024_Day7Example,Test7b) {
    string x{"7290: 6 8 6 15"};
    
    EXPECT_EQ(7290,validateEquation(x,true));
}

TEST(Y2024_Day7Example,Test8b) {
    string x{"192: 17 8 14"};
    
    EXPECT_EQ(192,validateEquation(x,true));
}

TEST(Y2024_Day7Example,Test6) {
    uint32_t maxOperations = 1 << (4*2);
    maxOperations--;
    maxOperations &= ~((1<<4)-1);
    EXPECT_EQ(0xf0,maxOperations);
}
