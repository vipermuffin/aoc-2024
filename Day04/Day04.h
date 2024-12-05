//
//  Advent of Code 2024 Solutions: Day 4
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/04/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay04 {
//Function Definitions
int32_t findWordInGrid(const std::vector<std::string>& grid, const std::string& word2Find);
int32_t findXWordInGrid(const std::vector<std::string>& grid, const std::string& word2Find, const size_t xLetterIdx = 1);
bool findWordInGridAtLocation(const std::vector<std::string>& grid, const std::string& word2Find, const int xPos, const int yPos, const size_t currentLetterIndex, const int xInc, const int yInc);
}
