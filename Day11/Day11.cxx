//
//  Advent of Code 2024 Solutions: Day 11
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/11/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day11.h"
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
#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay11 {

    static const std::string InputFileName = "Day11.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto stones = initList(input[0]);
        for(auto i = 0;i<25;i++) {
            blink(stones);
        }
        return to_string(stones.size());
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto stones = initListMap(input[0]);
        for(auto i = 0;i<75;i++) {
            blink(stones);
//            cout << printList(stones) << endl;
        }
        return to_string(countStones(stones));
    }

std::list<uint64_t> initList(const std::string& input) {
    list<uint64_t> l{};
    auto words = parseLineForLongNumbers(input);
    for(const auto& word : words) {
        l.emplace_back(static_cast<uint64_t>(word));
    }
    return l;
}

void blink(std::unordered_map<uint64_t,uint64_t>& stones) {
    unordered_map<uint64_t, uint64_t> newStones{};
    auto itr = stones.begin();
    while(itr != stones.end()) {
        if(itr->first == 0) {
            newStones[1] += itr->second;
        } else {
            auto i{0};
            auto divider{1};
            auto val{itr->first};
            while(val > 0) {
                i++;
                val /= 10;
                if((i&1) == 0) {
                    divider *= 10;
                }
            }
            if(i & 1) {
                newStones[itr->first*2024] += itr->second;
            } else {
                newStones[itr->first/divider] += itr->second;
                newStones[itr->first%divider] += itr->second;
            }
        }
        std::advance(itr, 1);
    }
    std::swap(stones,newStones);
}

void blink(std::list<uint64_t>& stones) {
    auto itr = stones.begin();
    while(itr != stones.end()) {
        if(*itr == 0) {
            *itr = 1;
        } else {
            auto i{0};
            auto divider{1};
            auto val{*itr};
            while(val > 0) {
                i++;
                val /= 10;
                if((i&1) == 0) {
                    divider *= 10;
                }
            }
            if(i & 1) {
                *itr *= 2024;
            } else {
                stones.insert(itr, *itr/divider);
                *itr %= divider;
            }
        }
        std::advance(itr, 1);
    }
}

uint64_t countStones(const std::unordered_map<uint64_t, uint64_t>& stones) {
    uint64_t sum = 0;
    for(const auto& kvp : stones) {
        sum += kvp.second;
    }
    return sum;
}

std::unordered_map<uint64_t, uint64_t> initListMap(const std::string& input) {
    std::unordered_map<uint64_t, uint64_t> l{};
    auto words = parseLineForLongNumbers(input);
    for(const auto& word : words) {
        l[static_cast<uint64_t>(word)]++;
    }
    return l;
}

std::string printList(const std::list<uint64_t>& l) {
    stringstream ss{};
    bool firstVal = true;
    for(const auto& val : l) {
        if(!firstVal) {
            ss << " ";
        }
        ss << val;
        firstVal = false;
    }
    return ss.str();
}
}
