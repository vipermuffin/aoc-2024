//
//  Advent of Code 2024 Solutions: Day 14
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/13/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "LinearTraveler.h"

namespace AocDay14 {
//Function Definitions
struct RoboPosition {
    RoboPosition() = default;
    friend std::ostream& operator<<(std::ostream& os, const RoboPosition& pos);
    AocUtils::LinearTraveler<int> x;
    AocUtils::LinearTraveler<int> y;
};

RoboPosition parseInput(const std::string& input, const std::string& id);
std::vector<RoboPosition> parseFileForRoboPositions(const std::vector<std::string>& input);
void stepRoboPositions(std::vector<RoboPosition>& positions, int xMax, int yMax);
std::vector<int> countInQuadrants(const std::vector<RoboPosition>& positions, int xMax, int yMax);
void printRoboPositions(const std::vector<RoboPosition>& positions, int xMax, int yMax);
}
