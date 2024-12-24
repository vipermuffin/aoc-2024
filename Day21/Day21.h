//
//  Advent of Code 2024 Solutions: Day 21
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/23/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace AocDay21 {
//Function Definitions
using KeypadMap = std::unordered_map<char, std::unordered_map<char, std::string>>;
struct KeypadSequencer {
    KeypadSequencer() = default;
    ~KeypadSequencer() = default;
    KeypadSequencer(KeypadMap keyMap) : keyMap(keyMap) {}
    std::string getKeypadSequence(const std::string& code);
    KeypadMap keyMap;
};
KeypadMap getDirectionalToNumericKeypadMap();
KeypadMap getDirectionalToDirectionalKeypadMap();
int getComplexity(const std::string& code);

}
