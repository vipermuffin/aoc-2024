//
//  Advent of Code 2024 Solutions: Day 13
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/13/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay13 {
//Function Definitions
struct ClawGame {
    ClawGame(const std::vector<std::string>& input);
    int64_t calcLowestCost() const;
    void applyOffset(int64_t offset);
    std::pair<int,int> aButton;
    std::pair<int,int> bButton;
    std::pair<int64_t,int64_t> result;
};

}
