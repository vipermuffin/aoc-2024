//
//  Advent of Code 2024 Solutions: Day 23
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/22/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace AocDay23 {
//Function Definitions
std::unordered_map<std::string,std::vector<std::string>> parseInput(const std::vector<std::string>& input);
int countNumberTupleWithStartLetter(const std::unordered_map<std::string,std::vector<std::string>>& input, const char startLetter);
std::string getPassword(const std::unordered_map<std::string,std::vector<std::string>>& input);
}
