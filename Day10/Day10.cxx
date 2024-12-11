//
//  Advent of Code 2024 Solutions: Day 10
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/10/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day10.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <numeric> //std::accumulate


using namespace std;
namespace AocDay10 {

    static const std::string InputFileName = "Day10.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);

        return to_string(getMapScore(input));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);

		return to_string(getMapScore(input,true));
    }

int getTrailScore(const std::vector<std::string>& topMap, std::vector<std::vector<bool>>& found, const int row, const int col, const int curVal) {
    int score{0};
    if(curVal == 9) {
        found[row][col] = true;
        return 1;
    }
    int nextVal = curVal + 1;
    
    for(int delta = -1; delta <= 1; delta += 2) {
        int nextRow = row + delta;
        int nextCol = col + delta;
        int val{curVal};
        if(nextRow >= 0 && nextRow < topMap.size()) {
            val = static_cast<int>(topMap[nextRow][col] - '0');
            if(val == nextVal) {
                score += getTrailScore(topMap, found, nextRow, col, nextVal);
            }
        }
        if(nextCol >= 0 && nextCol < topMap[row].size()) {
            int val = static_cast<int>(topMap[row][nextCol] - '0');
            if(val == nextVal) {
                score += getTrailScore(topMap, found, row, nextCol, nextVal);
            }
        }
    }
    
    return score;
}

int getMapScore(const std::vector<std::string>& topMap, const bool distinctPaths) {
    int score{0};
    int score2{0};
    
    for(auto row = 0; row < topMap.size(); row++) {
        for(auto col = 0; col < topMap[row].size();col++) {
            int val = static_cast<int>(topMap[row][col] - '0');
            if(val == 0) {
                std::vector<std::vector<bool>> found{};
                found.reserve(topMap.size());
                vector<bool> tmp{};
                tmp.resize(topMap.back().size());
                for(auto i = 0; i < topMap.size();i++) {
                    found.push_back(tmp);
                }
                score2 += getTrailScore(topMap, found, row, col, 0);
                score += std::accumulate(found.begin(), found.end(), 0,[](int sum, const std::vector<bool>& f){return sum + std::count(f.begin(),f.end(),true);});
            }
        }
    }
    
    return distinctPaths ? score2 : score;
}
}
