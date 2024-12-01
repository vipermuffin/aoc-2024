//
//  Advent of Code 2024 Solutions: Day 1
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 11/30/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day01.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <numeric> //std::accumulate



using namespace std;
namespace AocDay01 {

    static const std::string InputFileName = "Day01.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        vector<int> a{},b{};
        
        for(const auto& line: input) {
            auto x = parseLineForNumbers(line);
            a.push_back(x.front());
            b.push_back(x.back());
        }
        std::sort(a.begin(),a.end());
        std::sort(b.begin(),b.end());
        
        int d = 0;
        
        for(auto i = 0; i < a.size();i++) {
            d += a[i] < b[i] ? b[i]-a[i] : a[i]-b[i];
        }

        return to_string(d);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        vector<int> a{};
        unordered_map<int,int> bNums{};
        
        for(const auto& line: input) {
            auto x = parseLineForNumbers(line);
            a.push_back(x.front());
            bNums[x.back()]++;
        }
        
        return to_string(std::accumulate(a.begin(), a.end(), 0, [&bNums](int sum, const int x){return sum + x * bNums[x];}));
    }

}
