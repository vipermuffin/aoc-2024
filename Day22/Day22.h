//
//  Advent of Code 2024 Solutions: Day 22
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/21/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <iostream>

namespace AocDay22 {
//Function Definitions
uint64_t calcNextNumber(const uint64_t secretNum);
uint64_t calcNumberAfterSteps(const uint64_t secretNum, const uint64_t steps);
template <typename T>
T stringToInteger(const std::string& str, bool isHex = false) {
    static_assert(std::is_integral<T>::value, "Template parameter must be an integral type");
    T result;
    try {
        auto conversion = std::stoull(str,nullptr,isHex ? 16:10);
        // if(conversion > std::numeric_limits<T>::max()) {
        //     throw std::overflow_error("Overflow detected during cast");
        // }
        result = static_cast<T>(conversion);
        return result;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }
    return 0;
}

template <typename T>
std::vector<T> convertStringsToIntegers(const std::vector<std::string>& stringVec, bool isHex = false) {
    std::vector<T> intVec;
    for (const auto& str : stringVec) {
        intVec.push_back(stringToInteger<T>(str,isHex));
    }
    return intVec;
}
}
