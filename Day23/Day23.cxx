//
//  Advent of Code 2024 Solutions: Day 23
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/22/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day23.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <sstream>



using namespace std;
namespace AocDay23 {

    static const std::string InputFileName = "Day23.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto parsedInput = parseInput(input);
        return to_string(countNumberTupleWithStartLetter(parsedInput, 't'));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto parsedInput = parseInput(input);
        return getPassword(parsedInput);
    }

    std::unordered_map<std::string,std::vector<std::string>> parseInput(const std::vector<std::string>& input) {
        unordered_map<std::string,std::vector<std::string>> parsedInput;
        for (const auto& line : input) {
            //parse line
            string a{line.begin(), line.begin() + 2};
            string b{line.begin() + 3, line.end()};
            if(parsedInput.count(a) == 0) {
                parsedInput[a].push_back(a);
            }
            parsedInput[a].push_back(b);
            if(parsedInput.count(b) == 0) {
                parsedInput[b].push_back(b);
            }
            parsedInput[b].push_back(a);
        }
        for(auto& [key, value] : parsedInput) {
            sort(value.begin(), value.end());
        }
        return parsedInput;
    }

    int countNumberTupleWithStartLetter(const std::unordered_map<std::string,std::vector<std::string>>& input, const char startLetter) {
        int count = 0;
        vector<string> keys{};
        for(const auto& [key, value] : input) {
            keys.push_back(key);
        }
        std::sort(keys.begin(), keys.end());
        auto i = 0;
        auto j = 1;
        auto k = 2;
        do {
            //Check if each of the 3 elements of combos are found in the vectors 
            if (keys[i][0] == startLetter || keys[j][0] == startLetter || keys[k][0] == startLetter) {
                if(input.at(keys[i]).size() > 2 && input.at(keys[j]).size() > 2 && input.at(keys[k]).size() > 2
                && find(input.at(keys[i]).begin(), input.at(keys[i]).end(), keys[j]) != input.at(keys[i]).end()
                && find(input.at(keys[i]).begin(), input.at(keys[i]).end(), keys[k]) != input.at(keys[i]).end()
                && find(input.at(keys[j]).begin(), input.at(keys[j]).end(), keys[k]) != input.at(keys[j]).end()
                && find(input.at(keys[j]).begin(), input.at(keys[j]).end(), keys[i]) != input.at(keys[j]).end()
                && find(input.at(keys[k]).begin(), input.at(keys[k]).end(), keys[i]) != input.at(keys[k]).end()
                && find(input.at(keys[k]).begin(), input.at(keys[k]).end(), keys[j]) != input.at(keys[k]).end()) {
                    // printVector(combo);
                    count++;
                }
            }
            k++;
            if(k == keys.size()) {
                j++;
                if(j == keys.size()-1) {
                    i++;
                    j=i+1;
                }
                k = j+1;
            }
        } while (i < keys.size()-2);
        return count;
    }

    std::string getPassword(const std::unordered_map<std::string,std::vector<std::string>>& input) {
        vector<string> keys{};
        for(const auto& [key, value] : input) {
            keys.push_back(key);
        }
        //build list of 3 fully connected nodes
        vector<vector<string>> combos{};
        auto i = 0;
        auto j = 1;
        auto k = 2;
        do {
            //Check if each of the 3 elements of combos are found in the vectors 
            if(input.at(keys[i]).size() > 2 && input.at(keys[j]).size() > 2 && input.at(keys[k]).size() > 2
            && find(input.at(keys[i]).begin(), input.at(keys[i]).end(), keys[j]) != input.at(keys[i]).end()
            && find(input.at(keys[i]).begin(), input.at(keys[i]).end(), keys[k]) != input.at(keys[i]).end()
            && find(input.at(keys[j]).begin(), input.at(keys[j]).end(), keys[k]) != input.at(keys[j]).end()
            && find(input.at(keys[j]).begin(), input.at(keys[j]).end(), keys[i]) != input.at(keys[j]).end()
            && find(input.at(keys[k]).begin(), input.at(keys[k]).end(), keys[i]) != input.at(keys[k]).end()
            && find(input.at(keys[k]).begin(), input.at(keys[k]).end(), keys[j]) != input.at(keys[k]).end()) {
                vector<string> combo{};
                combo.push_back(keys[i]);
                combo.push_back(keys[j]);
                combo.push_back(keys[k]);
                combos.push_back(combo);
            }
            k++;
            if(k == keys.size()) {
                j++;
                if(j == keys.size()-1) {
                    i++;
                    j=i+1;
                }
                k = j+1;
            }
        } while (i < keys.size()-2);

        bool found = true;
        //add more to each combo
        while(found) {
            found = false;
            for(auto& combo : combos) {
                unordered_map<string,bool> visited{};
                for(const auto& neighbor : input.at(combo.back())) {
                    if(find(combo.begin(), combo.end(), neighbor) == combo.end()) {
                        //not part of this group yet
                        bool allConnected = true;
                        for(const auto& node : combo) {
                            if(find(input.at(node).begin(), input.at(node).end(), neighbor) == input.at(node).end()) {
                                //not connected to all nodes in the group
                                allConnected = false;
                                break;
                            }
                        }
                        if(allConnected) {
                            combo.push_back(neighbor);
                            found = true;
                        }
                    }
                }
            }
                
        }

        //find the longest combo
        auto max_key = max_element(combos.begin(), combos.end(), [](const vector<string>& a, const vector<string>& b) {
            return a.size() < b.size();
        });
         
        //build the password
        std::sort(max_key->begin(), max_key->end());
        stringstream ss;
        for(const auto& node : *max_key) {
            if(ss.str().empty()) {
                ss << node;
            } else {
                ss << "," << node;
            }
        }
        return ss.str();
    }
}
