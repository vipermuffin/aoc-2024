//
//  Advent of Code 2024 Tests: Day 5
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/05/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day05.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay05{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay05;

TEST(Y2024_SolveDay5, FinalSolutionPartA) {
    EXPECT_EQ("4774", solvea());
}

TEST(Y2024_SolveDay5, FinalSolutionPartB) {
    EXPECT_EQ("6004", solveb());
}

TEST(Y2024_Day5Example,Test1) {
    vector<string> input{
        "47|53",
        "97|13",
        "97|61",
        "97|47",
        "75|29",
        "61|13",
        "75|53",
        "29|13",
        "97|29",
        "53|29",
        "61|53",
        "97|53",
        "61|29",
        "47|13",
        "75|47",
        "97|75",
        "47|61",
        "75|61",
        "47|29",
        "75|13",
        "53|13",
        "",
        "75,47,61,53,29",
        "97,61,53,29,13",
        "75,29,13",
        "75,97,47,61,53",
        "61,13,29",
        "97,13,75,29,47"
    };
    auto x = buildOrderingGuide(input);
    ASSERT_EQ(100,x.size());
    ASSERT_EQ(2,x[47].before.size());
    EXPECT_EQ(97,x[47].before[0]);
    EXPECT_EQ(75,x[47].before[1]);
    ASSERT_EQ(4,x[47].after.size());
    EXPECT_EQ(53,x[47].after[0]);
    EXPECT_EQ(13,x[47].after[1]);
    EXPECT_EQ(61,x[47].after[2]);
    EXPECT_EQ(29,x[47].after[3]);
}

TEST(Y2024_Day5Example,Test2) {
    vector<string> input{
        "47|53",
        "97|13",
        "97|61",
        "97|47",
        "75|29",
        "61|13",
        "75|53",
        "29|13",
        "97|29",
        "53|29",
        "61|53",
        "97|53",
        "61|29",
        "47|13",
        "75|47",
        "97|75",
        "47|61",
        "75|61",
        "47|29",
        "75|13",
        "53|13",
        "",
        "75,47,61,53,29",
        "97,61,53,29,13",
        "75,29,13",
        "75,97,47,61,53",
        "61,13,29",
        "97,13,75,29,47"
    };
    
    auto x = buildOrderingGuide(input);

    string line{"75,47,61,53,29"};
    EXPECT_TRUE(verifyOrder(x, line));
    line = "97,61,53,29,13";
    EXPECT_TRUE(verifyOrder(x, line));
    line = "75,29,13";
    EXPECT_TRUE(verifyOrder(x, line));
    line = "75,97,47,61,53";
    EXPECT_FALSE(verifyOrder(x, line));
    auto y = reorder(x, line);
    ASSERT_EQ(5,y.size());
    EXPECT_EQ(97,y[0]);
    EXPECT_EQ(75,y[1]);
    EXPECT_EQ(47,y[2]);
    EXPECT_EQ(61,y[3]);
    EXPECT_EQ(53,y[4]);
    line = "61,13,29";
    EXPECT_FALSE(verifyOrder(x, line));
    y = reorder(x, line);
    ASSERT_EQ(3,y.size());
    EXPECT_EQ(61,y[0]);
    EXPECT_EQ(29,y[1]);
    EXPECT_EQ(13,y[2]);
    
}
