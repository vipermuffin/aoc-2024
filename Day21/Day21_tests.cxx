//
//  Advent of Code 2024 Tests: Day 21
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/23/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day21.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay21{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay21;

TEST(Y2024_SolveDay21, FinalSolutionPartA) {
    EXPECT_EQ("---", solvea());
}

TEST(Y2024_SolveDay21, FinalSolutionPartB) {
    EXPECT_EQ("---", solveb());
}

TEST(Y2024_Day21Example,Test1) {
    string testSequence = "029A";
    KeypadSequencer sequencer(getDirectionalToNumericKeypadMap());
    string result = sequencer.getKeypadSequence(testSequence);
    EXPECT_EQ("<A^A>^^AvvvA",result);
    EXPECT_EQ(12,result.size());
}

TEST(Y2024_Day21Example,Test2a) {
    string testSequence = "029A";
    KeypadSequencer sequencer(getDirectionalToNumericKeypadMap());
    KeypadSequencer sequencer2(getDirectionalToDirectionalKeypadMap());
    string result = sequencer.getKeypadSequence(testSequence);
    result = sequencer2.getKeypadSequence(result);
    EXPECT_EQ(28,result.size());
}

TEST(Y2024_Day21Example,Test2b) {
    string testSequence = "029A";
    KeypadSequencer sequencer(getDirectionalToNumericKeypadMap());
    KeypadSequencer sequencer2(getDirectionalToDirectionalKeypadMap());
    string result = sequencer.getKeypadSequence(testSequence);
    result = sequencer2.getKeypadSequence(result);
    result = sequencer2.getKeypadSequence(result);

    string expected = "<vA<AA>>^AvAA<^A>A<v<A>>^AvA^A<vA>^A<v<A>^A>AAvA^A<v<A>A>^AAAvA<^A>A";
    EXPECT_EQ(expected.size(),result.size());
}

TEST(Y2024_Day21Example,Test3a) {
    string code = "029A";
    EXPECT_EQ(68*29,getComplexity(code));
}

TEST(Y2024_Day21Example,Test3b) {
    string code = "980A";
    EXPECT_EQ(60*980,getComplexity(code));
}
TEST(Y2024_Day21Example,Test3c) {
    string code = "179A";
    EXPECT_EQ(68*179,getComplexity(code));
}

TEST(Y2024_Day21Example,Test3d) {
    string code = "456A";
    EXPECT_EQ(64*456,getComplexity(code));
}

TEST(Y2024_Day21Example,Test3e) {
    string code = "379A";
    EXPECT_EQ(64*379,getComplexity(code));
}
