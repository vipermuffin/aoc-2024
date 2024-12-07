//
//  Advent of Code 2024 Solutions: Day 7
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/06/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay07 {
//Function Definitions
//bool isValidEquation(const std::string& input);
int64_t validateEquation(const std::string& input, bool addCat = false);
std::vector<std::string> generatePermutations(const std::string& line);
}
