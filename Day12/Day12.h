//
//  Advent of Code 2024 Solutions: Day 12
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/12/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay12 {
//Function Definitions
std::vector<std::string> padInput(const std::vector<std::string>& input);
int calculatePrice(const std::vector<std::string>& input, bool useSides = false);
}
