//
//  Advent of Code 2024 Solutions: Day 16
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/16/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay16 {
//Function Definitions
std::vector<std::pair<int,int>> findStartEnd(const std::vector<std::string>& input);
int findShortestPathScore(const std::vector<std::string>& input, const bool countTiles = false);

}
