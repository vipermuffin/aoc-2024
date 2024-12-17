//
//  Advent of Code 2024 Solutions: Day 15
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/15/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay15 {
//Function Definitions
int calcGPS(const std::vector<std::string>& input);
void performMovementSequence(std::vector<std::string>& input, const std::string& sequence, bool debug = false);
void expandMap(std::vector<std::string>& input);

}
