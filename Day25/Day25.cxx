//
//  Advent of Code 2024 Solutions: Day 25
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/25/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day25.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.


using namespace std;
namespace AocDay25 {

    static const std::string InputFileName = "Day25.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        vector<vector<int>> locks{};
        vector<vector<int>> keys{};
        
        auto itr = input.begin();
        while(itr != input.end()) {
            auto startItr = itr;
            while(itr != input.end() && !itr->empty()) {
                itr++;
            }
            string id(startItr->size(),'.');
            vector<string> schematic(startItr,itr);
            bool isKey = id == *startItr;
            if(isKey) {
                schematic.pop_back();
            } else {
                schematic.erase(schematic.begin());
            }
            vector<int> tmpKeyLock(schematic.back().size(),0);
            for(auto row = 0; row < schematic.size();row++) {
                for(auto col = 0; col < schematic[row].size();col++) {
                    tmpKeyLock[col] += schematic[row][col] == '#' ? 1 : 0;
                }
            }
            
            if(isKey) {
                //is key
                keys.push_back(tmpKeyLock);
            } else {
                //is Lock
                locks.push_back(tmpKeyLock);
            }
            if(itr != input.end()) {
                itr++;
            }
        }
        int sum = 0;
        for(const auto& lock : locks) {
            for(const auto& key : keys) {
                bool fit = true;
                for(auto i = 0; i < key.size(); i++) {
                    if(key[i]+lock[i] >5) {
                        fit = false;
                    }
                }
                if(fit) {
                    sum++;
                }
            }
        }

		return to_string(sum);
    }

    std::string solveb() {
		return "---";
    }

}
