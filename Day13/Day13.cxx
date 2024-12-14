//
//  Advent of Code 2024 Solutions: Day 13
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/13/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day13.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.


using namespace std;
namespace AocDay13 {

    static const std::string InputFileName = "Day13.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        uint64_t sum = 0;
        for(int i = 0; i < input.size(); i += 4) {
            vector<string> gameInput(input.begin()+i, input.begin()+i+3);
            ClawGame game(gameInput);
            auto cost = game.calcLowestCost();
            if(cost < INT64_MAX) {
                sum += cost;
            }
        }
		return to_string(sum);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        uint64_t sum = 0;
        for(int i = 0; i < input.size(); i += 4) {
            vector<string> gameInput(input.begin()+i, input.begin()+i+3);
            ClawGame game(gameInput);
            game.applyOffset(10000000000000L);
            auto cost = game.calcLowestCost();
            if(cost < INT64_MAX) {
                sum += cost;
            }
        }
		return to_string(sum);
    }

    ClawGame::ClawGame(const std::vector<std::string>& input) {
        aButton = {0,0};
        bButton = {0,0};
        result = {0,0};
        sscanf(input[0].c_str(), "Button A: X+%d, Y+%d", &aButton.first, &aButton.second);
        sscanf(input[1].c_str(), "Button B: X+%d, Y+%d", &bButton.first, &bButton.second);
        sscanf(input[2].c_str(), "Prize: X=%lld, Y=%lld", &result.first, &result.second);
    }

    int64_t ClawGame::calcLowestCost() const {
        auto denom = aButton.first*bButton.second - aButton.second*bButton.first;
        if(denom == 0) {
            return INT64_MAX;
        }
        auto aPress = bButton.second*result.first - bButton.first*result.second;
        if(aPress % denom != 0) {
            return INT64_MAX;
        }
        auto bPress = aButton.first*result.second - aButton.second*result.first;
        if(bPress % denom != 0) {
            return INT64_MAX;
        }
        aPress /= denom;
        bPress /= denom;
        auto lowestCost = aPress*3 + bPress;
        
        return lowestCost;
    }

    void ClawGame::applyOffset(int64_t offset) {
        result.first += offset;
        result.second += offset;
    }

}
