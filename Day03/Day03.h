//
//  Advent of Code 2024 Solutions: Day 3
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/03/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay03 {
//Function Definitions
std::vector<std::pair<int,int>> findMulMatches(const std::string& input);
int64_t accumulateMultiplies(const std::vector<std::string>& corruptLines, bool enableDo = false);
}
