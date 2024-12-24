//
//  Advent of Code 2024 Tests: Day 23
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/22/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day23.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay23{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay23;

TEST(Y2024_SolveDay23, FinalSolutionPartA) {
    EXPECT_EQ("1098", solvea());
}

TEST(Y2024_SolveDay23, FinalSolutionPartB) {
    EXPECT_EQ("ar,ep,ih,ju,jx,le,ol,pk,pm,pp,xf,yu,zg", solveb());
}

TEST(Y2024_Day23Example,Test1) {
    vector<string> pairs{
        "kh-tc",
        "qp-kh",
        "de-cg",
        "ka-co",
        "yn-aq",
        "qp-ub",
        "cg-tb",
        "vc-aq",
        "tb-ka",
        "wh-tc",
        "yn-cg",
        "kh-ub",
        "ta-co",
        "de-co",
        "tc-td",
        "tb-wq",
        "wh-td",
        "ta-ka",
        "td-qp",
        "aq-cg",
        "wq-ub",
        "ub-vc",
        "de-ta",
        "wq-aq",
        "wq-vc",
        "wh-yn",
        "ka-de",
        "kh-ta",
        "co-tc",
        "wh-qp",
        "tb-vc",
        "td-yn"
    };
    auto input = parseInput(pairs);
    int x = countNumberTupleWithStartLetter(input,'t');
    EXPECT_EQ(7,x);
}

TEST(Y2024_Day23Example,Test2) {
    vector<string> pairs{
        "kh-tc",
        "qp-kh",
        "de-cg",
        "ka-co",
        "yn-aq",
        "qp-ub",
        "cg-tb",
        "vc-aq",
        "tb-ka",
        "wh-tc",
        "yn-cg",
        "kh-ub",
        "ta-co",
        "de-co",
        "tc-td",
        "tb-wq",
        "wh-td",
        "ta-ka",
        "td-qp",
        "aq-cg",
        "wq-ub",
        "ub-vc",
        "de-ta",
        "wq-aq",
        "wq-vc",
        "wh-yn",
        "ka-de",
        "kh-ta",
        "co-tc",
        "wh-qp",
        "tb-vc",
        "td-yn"
    };
    auto input = parseInput(pairs);
    EXPECT_EQ("co,de,ka,ta",getPassword(input));
}
