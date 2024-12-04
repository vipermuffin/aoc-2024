//
//  Advent of Code 2024 Solutions: Day 2
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/01/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day02.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.



using namespace std;
namespace AocDay02 {

    static const std::string InputFileName = "Day02.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        int safe = 0;
        for(const auto& line : input) {
            auto report = parseLineForNumbers(line);
            if(isSafeReport(report)) {
                safe++;
            }
        }

        return to_string(safe);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        int safe = 0;
        for(const auto& line : input) {
            auto report = parseLineForNumbers(line);
            if(isSafeReport(report,true)) {
                safe++;
            }
        }

        return to_string(safe);
    }

bool isSafeReport(const std::vector<int>& report, bool useDampener) {
    auto itr = report.begin();
    auto nItr = std::next(report.begin());
    bool isSafe = true;
    bool isIncreasing = *nItr > *itr;
    while(isSafe && nItr != report.end()) {
        auto diff = isIncreasing ? *nItr - *itr : *itr - *nItr;
        if(diff > 0 && diff < 4) {
            //good
        } else {
            
            if(useDampener) {
                //Try removing all combinations if at least one report is good then ship it.
                //Originally only removed the two that it had failed on but that missed a few
                for(auto i = 0; i < report.size();i++) {
                    auto x{report};
                    x.erase(x.begin()+i);
                    if(isSafeReport(x)) {
                        return true;
                    }
                }
                return false;
            } else {
                isSafe = false;
            }
        }
        itr = nItr;
        std::advance(nItr, 1);
    }
    
    return isSafe;
}
}
