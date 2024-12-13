//
//  Advent of Code 2024 Solutions: Day 12
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/12/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day12.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <map>
#include <numeric> //std::accumulate
#include <queue>


using namespace std;
namespace AocDay12 {

    static const std::string InputFileName = "Day12.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);

        return to_string(calculatePrice(input));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);

        return to_string(calculatePrice(input,true));
    }

    std::vector<std::string> padInput(const std::vector<std::string>& input) {
        //Pad each string in the vector with a '.' at the beginning and end and pad a string of length input[0].size()+2 with all '.' at the beginning and end
        std::vector<std::string> paddedInput;
        std::string padding(input[0].size() + 2, '.');
        paddedInput.push_back(padding);
        for (const auto& line : input) {
            std::string paddedLine = "." + line + ".";
            paddedInput.push_back(paddedLine);
        }
        paddedInput.push_back(padding);

        return paddedInput;
    }

    int calculatePrice(const std::vector<std::string>& input, bool useSides) {
        //Pad the input so I don't have to worry about bounds checking
        auto paddedInput = padInput(input);
        vector<vector<bool>> visited(paddedInput.size(), vector<bool>(paddedInput[0].size(), false));
        
        //mark padded area as visited
        //for_each(visited.front().begin(), visited.front().end(), [](bool& b) { b = true; });
        //for_each(visited.back().begin(), visited.back().end(), [](bool& b) { b = true; });
        for(auto i = 0; i < visited.front().size();i++) {
            visited.front()[i] = true;
            visited.back()[i] = true;
        }
        for_each(visited.begin(), visited.end(), [](vector<bool>& v) { v.front() = true; v.back() = true; });

        //Find groups of adjacent characters using BFS
        char currentChar = input[0][0];
        queue<pair<int,int>> q;
        vector<vector<int>> groups{};
        vector<int> groupFaces{};

        for(auto row = 1; row < paddedInput.size()-1; ++row) {
            for(auto col = 1; col < paddedInput[row].size()-1; ++col) {
                if(!visited[row][col]) {
                    currentChar = paddedInput[row][col];
                    vector<int> group{};
                    vector<map<int,vector<int>>> edges{};
                    edges.resize(4);
                    q.push({row,col});
                    while(!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        if(!visited[r][c]) {
                            visited[r][c] = true;
                            int perimeter = 0;

                            for(auto i = -1; i <= 1; i+=2) {
                                if(paddedInput[r+i][c] == currentChar) {
                                    if(!visited[r+i][c]) {
                                        q.push({r+i,c});
                                    }
                                } else {
                                    ++perimeter;
                                    edges[1+i][r].push_back(c);
                                }
                                if(paddedInput[r][c+i] == currentChar) {
                                    if(!visited[r][c+i]) {
                                        q.push({r,c+i});
                                    }
                                } else {
                                    ++perimeter;
                                    edges[2+i][c].push_back(r);
                                }
                            }
                            group.push_back(perimeter);
                        }
                    }
                    int faces = 0;
                    for(auto& e : edges) {
                        for(auto& kvp : e) {
                            std::sort(kvp.second.begin(),kvp.second.end());
                            auto itr = kvp.second.begin();
                            if(kvp.second.size() > 0 && itr != kvp.second.end()) {
                                
                                faces++;
                                auto nItr = std::next(itr);
                                while(nItr != kvp.second.end()) {
                                    if(*nItr != (*itr + 1)) {
                                        faces++;
                                    }
                                    itr = nItr;
                                    std::advance(nItr, 1);
                                }
                            }
                        }
                    }
                    groups.push_back(group);
                    groupFaces.push_back(faces);
                }
            }
        }
        if(useSides) {
            int sum = 0;
            for(auto i = 0; i < groups.size();i++) {
                sum += groups[i].size()*groupFaces[i];
            }
            return sum;
        } else {
            return std::accumulate(groups.begin(), groups.end(), 0, [](int sum, const vector<int>& v) { return sum + v.size()*accumulate(v.begin(), v.end(),0); });
        }
    }
}
