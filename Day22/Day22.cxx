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
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <numeric> //std::accumulate
#include <unordered_map>


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
        vector<unordered_map<uint32_t, int>> priceMaps{};
        unordered_map<uint32_t,int> bananas{};
        priceMaps.reserve(input.size());
        auto nums = convertStringsToIntegers<uint64_t>(input);
        for(const auto num : nums) {
            priceMaps.push_back(generatePriceMap(num, 2000));
            for(const auto& kvp:priceMaps.back()) {
                bananas[kvp.first] += kvp.second;
            }
        }
        
        int maxBananas = 0;
        for(const auto& banana : bananas) {
            if(banana.second > maxBananas) {
                maxBananas = banana.second;
            }
        }
        
        return to_string(maxBananas);
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

    unordered_map<uint32_t, int> generatePriceMap(const uint64_t secretNum, const uint64_t steps) {
        unordered_map<uint32_t, int> priceMap;
        auto val{secretNum};
        vector<int8_t> prices{static_cast<int8_t>(val%10)};
        prices.reserve(steps);
        union {
            uint32_t all;
            int8_t   prices[4];
        } priceSequence;
        priceSequence.all = 0;
        for(auto i = 0; i < steps; i++) {
            val = calcNextNumber(val);
            int8_t price = static_cast<int8_t>(val%10);
            priceSequence.all <<= 8;
            priceSequence.prices[0] = price - prices.back();
            prices.push_back(price);
            if(i >= 3) {
                //take last 4
                if(priceMap.count(priceSequence.all) == 0) {
                    priceMap[priceSequence.all] = price;
                }
            }
        }

        return priceMap;
    }

}
