//
//  Advent of Code 2024 Solutions: Day 17
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/18/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay17 {
//Function Definitions
std::vector<std::pair<int,int>> parseProgram(const std::vector<std::string>& input, std::vector<int>& registers);
std::string runProgram(const std::vector<std::pair<int,int>>& program, std::vector<int> registers = {0,1,2,3,0,0,0,0});
int findInitValProgram(const std::vector<std::string>& input);
}
