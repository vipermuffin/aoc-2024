//
//  Advent of Code 2024 Tests: Day 8
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/07/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day08.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay08{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay08;

TEST(Y2024_SolveDay8, FinalSolutionPartA) {
    EXPECT_EQ("354", solvea());
}

TEST(Y2024_SolveDay8, FinalSolutionPartB) {
    EXPECT_EQ("1263", solveb());
}

TEST(Y2024_Day8Example,Test1) {
    vector<string> x{
        "............",
        "........0...",
        ".....0......",
        ".......0....",
        "....0.......",
        "......A.....",
        "............",
        "............",
        "........A...",
        ".........A..",
        "............",
        "............"
    };
    auto am = GenerateMap(x);
    EXPECT_EQ(2,am.size());
    EXPECT_EQ(4,am['0'].size());
    EXPECT_EQ(3,am['A'].size());
}

TEST(Y2024_Day8Example,Test2) {
    vector<string> x{
        "..........",
        "..........",
        "..........",
        "....a.....",
        "..........",
        ".....a....",
        "..........",
        "..........",
        "..........",
        ".........."
    };
    auto am = GenerateMap(x);
    ASSERT_EQ(1,am.size());
    EXPECT_EQ(1,am.size());
    EXPECT_EQ(2,am['a'].size());
    Coord tmp{};
    tmp.all = am['a'].front();
    EXPECT_EQ(4,X(tmp));
    EXPECT_EQ(3,Y(tmp));
    tmp.all = am['a'].back();
    EXPECT_EQ(5,X(tmp));
    EXPECT_EQ(5,Y(tmp));
    auto antiAm = GenerateAntinodeMap(am, static_cast<int32_t>(x.back().size()), static_cast<int32_t>(x.size()));
    ASSERT_EQ(1,antiAm.size());
    EXPECT_EQ(1,antiAm.size());
    EXPECT_EQ(2,antiAm['a'].size());
    tmp.all = antiAm['a'].front();
    EXPECT_EQ(3,X(tmp));
    EXPECT_EQ(1,Y(tmp));
    tmp.all = antiAm['a'].back();
    EXPECT_EQ(6,X(tmp));
    EXPECT_EQ(7,Y(tmp));
}

TEST(Y2024_Day8Example,Test3) {
    vector<string> x{
        "..........",
        "...#......",
        "#.........",
        "....a.....",
        "........a.",
        ".....a....",
        "..#.......",
        "......#...",
        "..........",
        ".........."
    };
    auto am = GenerateMap(x);
    auto antiAm = GenerateAntinodeMap(am, static_cast<int32_t>(x.back().size()), static_cast<int32_t>(x.size()));
    EXPECT_EQ(4,antiAm['a'].size());
}

TEST(Y2024_Day8Example,Test4) {
    vector<string> x{
        "............",
        "........0...",
        ".....0......",
        ".......0....",
        "....0.......",
        "......A.....",
        "............",
        "............",
        "........A...",
        ".........A..",
        "............",
        "............"
    };
    auto am = GenerateMap(x);
    auto antiAm = GenerateAntinodeMap(am, static_cast<int32_t>(x.back().size()), static_cast<int32_t>(x.size()));
    EXPECT_EQ(14,calculateUniqueLocations(antiAm));
}

TEST(Y2024_Day8Example,Test4b) {
    vector<string> x{
        "............",
        "........0...",
        ".....0......",
        ".......0....",
        "....0.......",
        "......A.....",
        "............",
        "............",
        "........A...",
        ".........A..",
        "............",
        "............"
    };
    auto am = GenerateMap(x);
    auto antiAm = GenerateAntinodeMap(am, static_cast<int32_t>(x.back().size()), static_cast<int32_t>(x.size()),true);
    for(const auto& kvp : am) {
        for(const auto& loc : kvp.second) {
            antiAm[kvp.first].push_back(loc);
        }
    }
    EXPECT_EQ(34,calculateUniqueLocations(antiAm));
}
