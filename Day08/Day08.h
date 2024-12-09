//
//  Advent of Code 2024 Solutions: Day 8
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/07/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace AocDay08 {
//Function Definitions
typedef union {
    uint64_t all;
    int32_t xy[2];
} Coord;

constexpr size_t xIdx = 0;
constexpr size_t yIdx = 1;

constexpr int32_t X(const Coord& position) {
return position.xy[xIdx];
}

constexpr int32_t Y(const Coord& position) {
return position.xy[yIdx];
}

uint32_t manhattanDistance(const Coord& p1, const Coord& p2);
using antennaMap = std::unordered_map<char, std::vector<uint64_t>>;
antennaMap GenerateMap(const std::vector<std::string>&);
antennaMap GenerateAntinodeMap(const antennaMap&,const int xbounds, const int ybounds, bool partB = false);
int32_t calculateUniqueLocations(const antennaMap&);
}
