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
//#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
//#include <chrono>
//#include <iostream>
//#include <fstream> //ifstream
//#include <functional> //std::function
//#include <iomanip> //setfill setw hex
//#include <map>
//#include <math.h> //sqrt
//#include <numeric> //std::accumulate
//#include <queue>
//#include <regex>
//#include <set>
#include <sstream>
//#include <thread>
//#include <tuple>
//#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay07 {

    static const std::string InputFileName = "Day07.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        long sum{0};
        for(const auto& line : input) {
            if(isValidEquation(line)) {
                auto x = parseLineForLongNumbers(line);
                sum += x[0];
            }
        }
        return to_string(sum);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        int64_t sum{0};
        for(const auto& line : input) {
            //            cout << line << endl;
            if(isValidEquation2(line)) {
                auto x = parseLineForLongNumbers(line);
                sum += x[0];
                //                cout << sum << "<--" << line << endl;
            }
        }
        //22074577819041 too low
        //581941094529163
        return to_string(sum);
    }

bool isValidEquation(const std::string& input) {
    auto inVec = parseLineForLongNumbers(input);
    uint32_t operations{0};
    uint32_t maxOperations = 1 << (inVec.size()-2);
    while(operations < maxOperations) {
        int64_t result{inVec[1]};
        uint32_t opShift{0};
//        cout << result;
        for(auto i = 2; i < inVec.size(); i++) {
            bool isMult = (operations & (1 << opShift))!=0;
//            cout << (isMult ? "*" : "+") << inVec[i];
            result = isMult ? result * inVec[i] : result + inVec[i];
            opShift++;
        }
//        cout << "=" << result <<endl;
        if(result == inVec[0]) {
            return true;
        }
        operations++;
    }
    return false;
}

std::vector<std::string> generatePermutations(const std::string& line) {
    std::vector<std::string> newLines{};
    auto words = parseLineForWords(line);
    
    uint32_t operations{1};
    uint32_t maxOperations = 1 << (words.size()-2);
    while(operations < maxOperations) {
        stringstream ss{};
        ss << words[0] << " " << words[1];
        uint32_t opShift{0};
        for(auto i = 2; i < words.size(); i++) {
            bool isCat = (operations & (1 << opShift))!=0;
            if(!isCat) {
                ss << " ";
            }
            ss << words[i];
            opShift++;
        }

        newLines.push_back(ss.str());
//        cout << newLines.back() << endl;
        operations++;
    }

    return newLines;
}

bool isValidEquation2(const std::string& input) {
    auto inVec = parseLineForLongNumbers(input);
    uint32_t operations{0};
    auto numOperators = inVec.size()-2;
    uint32_t maxOperations = 1 << (numOperators*2);
    
    maxOperations--;
    maxOperations &= ~((1<<numOperators)-1);
    while(operations <= maxOperations) {
        int64_t result{inVec[1]};
        uint32_t opShift{0};
//        cout << result;
        for(auto i = 2; i < inVec.size(); i++) {
            bool isCat  = (operations & (1 << (opShift+numOperators)))!=0;
            bool isMult = (operations & (1 << opShift))!=0;
//            cout << (isMult ? "*" : "+") << inVec[i];
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
//        cout << "=" << result <<endl;
        if(result == inVec[0]) {
            return true;
        }
        operations++;
    }
    return false;
}

}
