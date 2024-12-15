//
//  Advent of Code 2024 Tests: Day 14
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/13/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day14.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay14{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay14;

TEST(Y2024_SolveDay14, FinalSolutionPartA) {
    EXPECT_EQ("216027840", solvea());
}

TEST(Y2024_SolveDay14, FinalSolutionPartB) {
    EXPECT_EQ("6876", solveb());
}

TEST(Y2024_Day14Example,Test1) {
    vector<string> input {
        "p=0,4 v=3,-3",
        "p=6,3 v=-1,-3",
        "p=10,3 v=-1,2",
        "p=2,0 v=2,-1",
        "p=0,0 v=1,3",
        "p=3,0 v=-2,-2",
        "p=7,6 v=-1,-3",
        "p=3,0 v=-1,-2",
        "p=9,3 v=2,3",
        "p=7,3 v=-1,2",
        "p=2,4 v=2,-3",
        "p=9,5 v=-3,-3"
    };
    auto positions = parseFileForRoboPositions(input);
    
    EXPECT_EQ(12,positions.size());
    EXPECT_EQ(0,positions[0].x.position());
    EXPECT_EQ(4,positions[0].y.position());
    EXPECT_EQ(3,positions[0].x.velocity());
    EXPECT_EQ(-3,positions[0].y.velocity());
    EXPECT_EQ(6,positions[1].x.position());
    EXPECT_EQ(3,positions[1].y.position());
    EXPECT_EQ(-1,positions[1].x.velocity());
    EXPECT_EQ(-3,positions[1].y.velocity());
}

TEST(Y2024_Day14Example,Test2) {
    string x = "p=2,4 v=2,-3";
    auto pos = parseInput(x,"test");

    EXPECT_EQ(2,pos.x.position());
    EXPECT_EQ(4,pos.y.position());
    EXPECT_EQ(2,pos.x.velocity());
    EXPECT_EQ(-3,pos.y.velocity());
    vector<RoboPosition> positions;
    positions.push_back(pos);
    stepRoboPositions(positions,11,7);
    EXPECT_EQ(4,positions[0].x.position());
    EXPECT_EQ(1,positions[0].y.position());
    stepRoboPositions(positions,11,7);
    EXPECT_EQ(6,positions[0].x.position());
    EXPECT_EQ(5,positions[0].y.position());
}

TEST(Y2024_Day14Example,Test3) {
    vector<string> input {
        "p=0,4 v=3,-3",
        "p=6,3 v=-1,-3",
        "p=10,3 v=-1,2",
        "p=2,0 v=2,-1",
        "p=0,0 v=1,3",
        "p=3,0 v=-2,-2",
        "p=7,6 v=-1,-3",
        "p=3,0 v=-1,-2",
        "p=9,3 v=2,3",
        "p=7,3 v=-1,2",
        "p=2,4 v=2,-3",
        "p=9,5 v=-3,-3"
    };
    auto positions = parseFileForRoboPositions(input);
    for(int i = 0; i < 100; i++) {
        stepRoboPositions(positions,11,7);
    }
    auto counts = countInQuadrants(positions,11,7);
    std::sort(counts.begin(),counts.end());
    ASSERT_EQ(4,counts.size());
    EXPECT_EQ(1,counts[0]);
    EXPECT_EQ(1,counts[1]);
    EXPECT_EQ(3,counts[2]);
    EXPECT_EQ(4,counts[3]);
}
