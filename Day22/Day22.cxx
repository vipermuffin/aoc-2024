//
//  Advent of Code 2024 Solutions: Day 22
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/21/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day22.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
//#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
//#include <chrono>
//#include <iostream>
//#include <fstream> //ifstream
//#include <functional> //std::function
//#include <iomanip> //setfill setw hex
//#include <map>
//#include <math.h> //sqrt
#include <numeric> //std::accumulate
//#include <queue>
//#include <regex>
//#include <set>
//#include <sstream>
//#include <thread>
//#include <tuple>
//#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay22 {

    static const std::string InputFileName = "Day22.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        uint64_t sum = 0;
        auto nums = convertStringsToIntegers<uint64_t>(input);
        for(const auto num : nums) {
            sum += calcNumberAfterSteps(num, 2000);
        }
        return to_string(sum);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);

		return "---";
    }

    uint64_t calcNextNumber(const uint64_t secretNum) {
        const uint64_t pruneVal = 16777216-1;
        uint64_t newNum = secretNum;
        newNum ^= (secretNum<<6);
        newNum &= pruneVal;
        newNum ^= (newNum>>5);
        newNum &= pruneVal;
        newNum ^= (newNum<<11);
        newNum &= pruneVal;
        
        return newNum;
    }

    uint64_t calcNumberAfterSteps(const uint64_t secretNum, const uint64_t steps) {
        auto val{secretNum};
        for(auto i = 0; i < steps; i++) {
            val = calcNextNumber(val);
        }
        return val;
    }

}
