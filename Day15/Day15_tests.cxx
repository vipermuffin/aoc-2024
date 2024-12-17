//
//  Advent of Code 2024 Tests: Day 15
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/15/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day15.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay15{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay15;

TEST(Y2024_SolveDay15, FinalSolutionPartA) {
    EXPECT_EQ("1448589", solvea());
}

TEST(Y2024_SolveDay15, FinalSolutionPartB) {
    EXPECT_EQ("1472235", solveb());
}

TEST(Y2024_Day15Example,Test1) {
    vector<string> input {
        "#######",
        "#...O..",
        "#......"
    };
    EXPECT_EQ(104,calcGPS(input));
}

TEST(Y2024_Day15Example,Test2) {
    vector<string> input {
        "##########",
        "#.O.O.OOO#",
        "#........#",
        "#OO......#",
        "#OO@.....#",
        "#O#.....O#",
        "#O.....OO#",
        "#O.....OO#",
        "#OO....OO#",
        "##########"
    };
    EXPECT_EQ(10092,calcGPS(input));
}

TEST(Y2024_Day15Example,Test3) {
    vector<string> input {
        "########",
        "#..O.O.#",
        "##@.O..#",
        "#...O..#",
        "#.#.O..#",
        "#...O..#",
        "#......#",
        "########"
    };
    string sequence = "<^^>>>vv<v>>v<<";
    performMovementSequence(input,sequence);
    EXPECT_EQ(2028,calcGPS(input));
}

TEST(Y2024_Day15Example,Test4) {
    vector<string> input {
        "##########",
        "#..O..O.O#",
        "#......O.#",
        "#.OO..O.O#",
        "#..O@..O.#",
        "#O#..O...#",
        "#O..O..O.#",
        "#.OO.O.OO#",
        "#....O...#",
        "##########"
    };
    string sequence = "<vv>^<v^>v>^vv^v>v<>v^v<v<^vv<<<^><<><>>v<vvv<>^v^>^<<<><<v<<<v^vv^v>^vvv<<^>^v^^><<>>><>^<<><^vv^^<>vvv<>><^^v>^>vv<>v<<<<v<^v>^<^^>>>^<v<v><>vv>v^v^<>><>>>><^^>vv>v<^^^>>v^v^<^^>v^^>v^<^v>v<>>v^v^<v>v^^<^^vv<<<v<^>>^^^^>>>v^<>vvv^><v<<<>^^^vv^<vvv>^>v<^^^^v<>^>vvvv><>>v^<<^^^^^^><^><>>><>^^<<^^v>>><^<v>^<vv>>v>>>^v><>^v><<<<v>>v<v<v>vvv>^<><<>^><^>><>^v<><^vvv<^^<><v<<<<<><^v<<<><<<^^<v<^^^><^>>^<v^><<<^>>^v<v^v<v^>^>>^v>vv>^<<^v<>><<><<v<<v><>v<^vv<<<>^^v^>^^>>><<^v>>v^v><^^>>^<>vv^<><^^>^^^<><vvvvv^v<v<<>^v<v>v<<^><<><<><<<^^<<<^<<>><<><^^^>^^<>^>v<>^^>vv<^v^v<vv>^<><v<^v>^^^>>>^^vvv^>vvv<>>>^<^>>>>>^<<^v>^vvv<>^<><<v>v^^>>><<^^<>>^v^<v^vv<>v^<<>^<^v^v><^<<<><<^<v><v<>vv>>v><v^<vv<>v^<<^";
    performMovementSequence(input,sequence);
    EXPECT_EQ(10092,calcGPS(input));
}

TEST(Y2024_Day15Example,Test5) {
    vector<string> input {
        "#######",
        "#...#.#",
        "#.....#",
        "#..OO@#",
        "#..O..#",
        "#.....#",
        "#######"
    };
    expandMap(input);
    vector<string> expected {
        "##############",
        "##......##..##",
        "##..........##",
        "##....[][]@.##",
        "##....[]....##",
        "##..........##",
        "##############"
    };
    ASSERT_EQ(expected.size(),input.size());
    for(auto row = 0; row < input.size(); row++) {
        EXPECT_EQ(expected[row],input[row]);
    }
}

TEST(Y2024_Day15Example,Test6) {
    vector<string> input {
        "#######",
        "#...#.#",
        "#.....#",
        "#..OO@#",
        "#..O..#",
        "#.....#",
        "#######"
    };
    expandMap(input);
    string sequence = "<vv<<^^<<^^";
    vector<string> expected {
        "##############",
        "##...[].##..##",
        "##...@.[]...##",
        "##....[]....##",
        "##..........##",
        "##..........##",
        "##############"
    };
    performMovementSequence(input,sequence);

    for(auto row = 0; row < input.size(); row++) {
        EXPECT_EQ(expected[row],input[row]);
    }
}

TEST(Y2024_Day15Example,Test7) {
    vector<string> input {
        "####################",
        "##[].......[].[][]##",
        "##[]...........[].##",
        "##[]........[][][]##",
        "##[]......[]....[]##",
        "##..##......[]....##",
        "##..[]............##",
        "##..@......[].[][]##",
        "##......[][]..[]..##",
        "####################"
    };
    EXPECT_EQ(9021,calcGPS(input));
}

TEST(Y2024_Day15Example,Test8) {
    vector<string> input {
        "##########",
        "#..O..O.O#",
        "#......O.#",
        "#.OO..O.O#",
        "#..O@..O.#",
        "#O#..O...#",
        "#O..O..O.#",
        "#.OO.O.OO#",
        "#....O...#",
        "##########"
    };
    string sequence = "<vv>^<v^>v>^vv^v>v<>v^v<v<^vv<<<^><<><>>v<vvv<>^v^>^<<<><<v<<<v^vv^v>^vvv<<^>^v^^><<>>><>^<<><^vv^^<>vvv<>><^^v>^>vv<>v<<<<v<^v>^<^^>>>^<v<v><>vv>v^v^<>><>>>><^^>vv>v<^^^>>v^v^<^^>v^^>v^<^v>v<>>v^v^<v>v^^<^^vv<<<v<^>>^^^^>>>v^<>vvv^><v<<<>^^^vv^<vvv>^>v<^^^^v<>^>vvvv><>>v^<<^^^^^^><^><>>><>^^<<^^v>>><^<v>^<vv>>v>>>^v><>^v><<<<v>>v<v<v>vvv>^<><<>^><^>><>^v<><^vvv<^^<><v<<<<<><^v<<<><<<^^<v<^^^><^>>^<v^><<<^>>^v<v^v<v^>^>>^v>vv>^<<^v<>><<><<v<<v><>v<^vv<<<>^^v^>^^>>><<^v>>v^v><^^>>^<>vv^<><^^>^^^<><vvvvv^v<v<<>^v<v>v<<^><<><<><<<^^<<<^<<>><<><^^^>^^<>^>v<>^^>vv<^v^v<vv>^<><v<^v>^^^>>>^^vvv^>vvv<>>>^<^>>>>>^<<^v>^vvv<>^<><<v>v^^>>><<^^<>>^v^<v^vv<>v^<<>^<^v^v><^<<<><<^<v><v<>vv>>v><v^<vv<>v^<<^";
    expandMap(input);
    performMovementSequence(input,sequence,false);
    EXPECT_EQ(9021,calcGPS(input));
}

TEST(Y2024_Day15Example,Test9) {
    vector<string> input {
        "####################",
        "##....[]....[]..[]##",
        "##............[]..##",
        "##..[][]....[]..[]##",
        "##...[].......[]..##",
        "##[]##....[]......##",
        "##[]......[]..[]..##",
        "##..[][]..@[].[][]##",
        "##........[]......##",
        "####################"
    };
    
    string sequence = "^";
    vector<string> expected {
        "####################",
        "##....[]....[]..[]##",
        "##............[]..##",
        "##..[][]....[]..[]##",
        "##...[]...[]..[]..##",
        "##[]##....[]......##",
        "##[]......@...[]..##",
        "##..[][]...[].[][]##",
        "##........[]......##",
        "####################"
    };
    performMovementSequence(input,sequence, false);

    for(auto row = 0; row < input.size(); row++) {
        EXPECT_EQ(expected[row],input[row]);
    }
}
