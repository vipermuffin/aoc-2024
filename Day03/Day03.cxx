//
//  Advent of Code 2024 Solutions: Day 3
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/03/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day03.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <numeric> //std::accumulate
#include <regex>



using namespace std;
namespace AocDay03 {

    static const std::string InputFileName = "Day03.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);

        return to_string(accumulateMultiplies(input));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);

        return to_string(accumulateMultiplies(input,true));
    }

    std::vector<std::pair<int,int>> findMulMatches(const std::string& input) {
        std::regex pattern("mul\\((\\d+),(\\d+)\\)");
        std::vector<std::pair<int,int>> matches;
        auto words_begin = std::sregex_iterator(input.begin(), input.end(), pattern);
        auto words_end = std::sregex_iterator();
        
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;
            // match[1] and match[2] contain the captured groups
            int first = std::stoi(match[1]);
            int second = std::stoi(match[2]);
            matches.emplace_back(first, second);
        }
        return matches;
    }

int64_t accumulateMultiplies(const std::vector<std::string>& corruptLines, bool enableDo) {
    int64_t sum = 0;
    //Enabled is global, not per line
    bool enabled = true;
    for(const auto& line : corruptLines) {
        std::vector<std::pair<int,int>> pairs{};
        if(enableDo) {
           string searchPattern = enabled ? "don't()" : "do()";
           auto itr = line.begin();
           auto index = line.find(searchPattern);
           while(index != string::npos) {
               if(enabled) {
                   searchPattern = "do()";
                   string searchStr{itr,line.begin()+index};
                   auto pv = findMulMatches(searchStr);
                   for_each(pv.begin(), pv.end(), [&pairs](const std::pair<int,int>& p){pairs.push_back(p);});
                   enabled = false;
               } else {
                   searchPattern = "don't()";
                   enabled = true;
                   itr = line.begin() + index + 1;
               }
               index = line.find(searchPattern,index+1);
           }
           if(enabled) {
               string searchStr{itr,line.end()};
               auto pv = findMulMatches(searchStr);
               for_each(pv.begin(), pv.end(), [&pairs](const std::pair<int,int>& p){pairs.push_back(p);});
            }
        } else {
            pairs = findMulMatches(line);
        }
        for_each(pairs.begin(), pairs.end(), [&sum](const std::pair<int,int>& p){sum += p.first*p.second;});
    }
    
    return sum;
}

}
