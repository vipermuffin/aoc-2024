//
//  Advent of Code 2024 Solutions: Day 7
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/06/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day07.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <sstream>

using namespace std;
namespace AocDay07 {

    static const std::string InputFileName = "Day07.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        long sum{0};
        for(const auto& line : input) {
            sum += validateEquation(line);
        }
        return to_string(sum);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        int64_t sum{0};
        for(const auto& line : input) {
            sum += validateEquation(line,true);
        }

        return to_string(sum);
    }

    int64_t validateEquation(const std::string& input, bool addCat) {
        auto inVec = parseLineForLongNumbers(input);
        uint32_t operations{0};
        auto numOperators = inVec.size()-2;
        uint32_t maxOperations{0};
        if(addCat) {
            maxOperations = 1 << (numOperators*2);
            maxOperations--;
            maxOperations &= ~((1<<numOperators)-1);
        } else {
            maxOperations = 1 << (numOperators);
            maxOperations--;
        }
        while(operations <= maxOperations) {
            int64_t result{inVec[1]};
            uint32_t opShift{0};
            for(auto i = 2; i < inVec.size(); i++) {
                bool isCat  = (operations & (1 << (opShift+numOperators)))!=0;
                bool isMult = (operations & (1 << opShift))!=0;
                if(isCat) {
                    auto cpy = inVec[i];
                    auto mult = 1;
                    while(cpy > 0) {
                        mult *= 10;
                        cpy  /= 10;
                    }
                    result = result * mult + inVec[i];
                } else {
                    result = isMult ? result * inVec[i] : result + inVec[i];
                }
                
                opShift++;
            }
            if(result == inVec[0]) {
                return inVec[0];
            }
            operations++;
        }
        return 0;
    }
}
