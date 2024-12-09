//
//  Advent of Code 2024 Solutions: Day 8
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/07/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day08.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
//#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <unordered_set>


using namespace std;
namespace AocDay08 {

    static const std::string InputFileName = "Day08.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto antennas = GenerateMap(input);
        auto antiNodes = GenerateAntinodeMap(antennas, static_cast<int32_t>(input.back().size()), static_cast<int32_t>(input.size()));
        
        return to_string(calculateUniqueLocations(antiNodes));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto antennas = GenerateMap(input);
        auto antiNodes = GenerateAntinodeMap(antennas, static_cast<int32_t>(input.back().size()), static_cast<int32_t>(input.size()),true);
        for(const auto& kvp : antennas) {
            for(const auto& loc : kvp.second) {
                antiNodes[kvp.first].push_back(loc);
            }
        }
        return to_string(calculateUniqueLocations(antiNodes));
    }

    antennaMap GenerateMap(const std::vector<std::string>& scan) {
        antennaMap am{};
        Coord tmp{0};
        
        //Parse each row
        uint32_t expandAdj = 0;
        for(auto row = 0; row < scan.size(); row++) {
            for(auto col = 0; col < scan[row].size(); col++) {
                if(scan[row][col] != '.') {
                    tmp.xy[xIdx] = col;
                    tmp.xy[yIdx] = row;
                    am[scan[row][col]].push_back(tmp.all);
                }
            }
        }
        
        return am;
    }

    antennaMap GenerateAntinodeMap(const antennaMap& antennaCoords, const int xbounds, const int ybounds, bool partB) {
        antennaMap antiNodes{};
        Coord p1{};
        Coord p2{};
        Coord tmp{};

        for(const auto& kvp : antennaCoords) {
            for(auto i = 0; i < kvp.second.size()-1; i++) {
                for(auto j = i+1; j < kvp.second.size(); j++) {
                    p1.all = kvp.second[i];
                    p2.all = kvp.second[j];
                    int32_t dx = X(p1) - X(p2);
                    int32_t dy = Y(p1) - Y(p2);
                    
                    //Antinode 1 = p1 + (dx,dy)
                    tmp.all = p1.all;
                    tmp.xy[xIdx] += dx;
                    tmp.xy[yIdx] += dy;
                    if(partB) {
                        while(X(tmp) >= 0 && X(tmp) < xbounds && Y(tmp) >= 0 && Y(tmp) < ybounds) {
                            antiNodes[kvp.first].push_back(tmp.all);
                            tmp.xy[xIdx] += dx;
                            tmp.xy[yIdx] += dy;
                        }
                    } else {
                        if(X(tmp) >= 0 && X(tmp) < xbounds && Y(tmp) >= 0 && Y(tmp) < ybounds) {
                            antiNodes[kvp.first].push_back(tmp.all);
                        }
                    }
                    
                    //Antinode 2 = p2 - (dx,dy)
                    tmp.all = p2.all;
                    tmp.xy[xIdx] -= dx;
                    tmp.xy[yIdx] -= dy;
                    if(partB) {
                        while(X(tmp) >= 0 && X(tmp) < xbounds && Y(tmp) >= 0 && Y(tmp) < ybounds) {
                            antiNodes[kvp.first].push_back(tmp.all);
                            tmp.xy[xIdx] -= dx;
                            tmp.xy[yIdx] -= dy;
                        }
                    } else {
                        if(X(tmp) >= 0 && X(tmp) < xbounds && Y(tmp) >= 0 && Y(tmp) < ybounds) {
                            antiNodes[kvp.first].push_back(tmp.all);
                        }
                    }
                }
            }
        }
        
        return antiNodes;
    }

    int32_t calculateUniqueLocations(const antennaMap& antennaMap) {
        unordered_set<uint64_t> uniqueLocs{};
        for(const auto& kvp : antennaMap) {
            for(const auto& loc : kvp.second) {
                uniqueLocs.insert(loc);
            }
        }
        
        return static_cast<int32_t>(uniqueLocs.size());
    }
}
