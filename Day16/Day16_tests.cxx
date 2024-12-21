//
//  Advent of Code 2024 Tests: Day 16
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/16/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day16.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay16{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay16;

TEST(Y2024_SolveDay16, FinalSolutionPartA) {
    EXPECT_EQ("72400", solvea());
}

TEST(Y2024_SolveDay16, FinalSolutionPartB) {
    EXPECT_EQ("435", solveb());
}

TEST(Y2024_Day16Example,Test1) {
    vector<string> input {
        "###############",
        "#.......#....E#",
        "#.#.###.#.###.#",
        "#.....#.#...#.#",
        "#.###.#####.#.#",
        "#.#.#.......#.#",
        "#.#.#####.###.#",
        "#...........#.#",
        "###.#.#####.#.#",
        "#...#.....#.#.#",
        "#.#.#.###.#.#.#",
        "#.....#...#.#.#",
        "#.###.#.#.#.#.#",
        "#S..#.....#...#",
        "###############"
    };
    auto startEnd = findStartEnd(input);
    ASSERT_EQ(2,startEnd.size());
    EXPECT_EQ(1,startEnd[0].first);
    EXPECT_EQ(13,startEnd[0].second);
    EXPECT_EQ(13,startEnd[1].first);
    EXPECT_EQ(1,startEnd[1].second);    
}

TEST(Y2024_Day16Example,Test2) {
    vector<string> input {
        "###############",
        "#.......#....E#",
        "#.#.###.#.###.#",
        "#.....#.#...#.#",
        "#.###.#####.#.#",
        "#.#.#.......#.#",
        "#.#.#####.###.#",
        "#...........#.#",
        "###.#.#####.#.#",
        "#...#.....#.#.#",
        "#.#.#.###.#.#.#",
        "#.....#...#.#.#",
        "#.###.#.#.#.#.#",
        "#S..#.....#...#",
        "###############"
    };
    EXPECT_EQ(7036,findShortestPathScore(input));
}

TEST(Y2024_Day16Example,Test2b) {
    vector<string> input {
        "###############",
        "#.......#....E#",
        "#.#.###.#.###.#",
        "#.....#.#...#.#",
        "#.###.#####.#.#",
        "#.#.#.......#.#",
        "#.#.#####.###.#",
        "#...........#.#",
        "###.#.#####.#.#",
        "#...#.....#.#.#",
        "#.#.#.###.#.#.#",
        "#.....#...#.#.#",
        "#.###.#.#.#.#.#",
        "#S..#.....#...#",
        "###############"
    };
    EXPECT_EQ(45,findShortestPathScore(input,true));
}

TEST(Y2024_Day16Example,Test3) {
    vector<string> input {
        "#################",
        "#...#...#...#..E#",
        "#.#.#.#.#.#.#.#.#",
        "#.#.#.#...#...#.#",
        "#.#.#.#.###.#.#.#",
        "#...#.#.#.....#.#",
        "#.#.#.#.#.#####.#",
        "#.#...#.#.#.....#",
        "#.#.#####.#.###.#",
        "#.#.#.......#...#",
        "#.#.###.#####.###",
        "#.#.#...#.....#.#",
        "#.#.#.#####.###.#",
        "#.#.#.........#.#",
        "#.#.#.#########.#",
        "#S#.............#",
        "#################"
    };
    EXPECT_EQ(11048,findShortestPathScore(input));
}

TEST(Y2024_Day16Example,Test3b) {
    vector<string> input {
        "#################",
        "#...#...#...#..E#",
        "#.#.#.#.#.#.#.#.#",
        "#.#.#.#...#...#.#",
        "#.#.#.#.###.#.#.#",
        "#...#.#.#.....#.#",
        "#.#.#.#.#.#####.#",
        "#.#...#.#.#.....#",
        "#.#.#####.#.###.#",
        "#.#.#.......#...#",
        "#.#.###.#####.###",
        "#.#.#...#.....#.#",
        "#.#.#.#####.###.#",
        "#.#.#.........#.#",
        "#.#.#.#########.#",
        "#S#.............#",
        "#################"
    };
    EXPECT_EQ(64,findShortestPathScore(input,true));
}
