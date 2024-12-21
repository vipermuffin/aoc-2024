//
//  Advent of Code 2024 Solutions: Day 18
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/21/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <unordered_set>
namespace AocDay18 {
//Function Definitions
std::unordered_set<int> parseInput(const std::vector<std::string>& input, size_t numLines);
int findShortestPathSteps(const std::vector<std::string>& input, int endCoord, size_t gridSize, size_t simBytes);
std::string findBlockingCoordinates(const std::vector<std::string>& input, int endCoord);

constexpr int coordXY(int x, int y) { return x + y * 1000; }
}
