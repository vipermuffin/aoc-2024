//
//  Advent of Code 2024 Solutions: Day 6
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/06/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day06.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <numeric> //std::accumulate

using namespace std;
namespace AocDay06 {

    static const std::string InputFileName = "Day06.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);

        return to_string(findUnqiqueLocVisited(input));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        std::vector<std::vector<int>> visited{};
        findUnqiqueLocVisited(input,&visited);
        int32_t loopCount{0};
        
        for(auto row = 0; row < input.size(); row++) {
            for(auto col =0; col < input[row].size(); col++) {
                if(visited[row][col] > 0) {
                    auto bkup = input[row][col];
                    input[row][col] = '#';
                    if(findUnqiqueLocVisited(input) == -1) {
                        loopCount++;
                    }
                    input[row][col] = bkup;
                }
            }
        }

        return to_string(loopCount);
    }

    int32_t findUnqiqueLocVisited(const std::vector<std::string>& input, std::vector<std::vector<int>>* vLoc) {
        //Find ^ and initialize visited
        std::vector<std::vector<int>> visited{};
        std::pair<int,int> startLoc{0,0};
        for(auto row = 0; row < input.size();row++) {
            vector<int> visitRow{};
            visitRow.reserve(input[row].size());
            for(auto col = 0; col < input[row].size();col++){
                visitRow.push_back(0);
                if(input[row][col] == '^') {
                    startLoc.first = row;
                    startLoc.second = col;
                }
            }
            visited.push_back(visitRow);
        }
        
        visited[startLoc.first][startLoc.second]++;
        
        //simulate path
        int curRow = startLoc.first;
        int curCol = startLoc.second;
        auto incIdx{0};
        const std::vector<std::pair<int,int>> inc{{-1,0},{0,1},{1,0},{0,-1}};
        while(curRow >= 0 && curRow < input.size() && curCol >= 0 && curCol < input[curRow].size()) {
            int nextRow = curRow + inc[incIdx].first;
            int nextCol = curCol + inc[incIdx].second;
            if(nextRow >= 0 && nextRow < input.size() && nextCol >= 0 && nextCol < input[nextRow].size()) {
                if(input[nextRow][nextCol] == '#') {
                    incIdx = (incIdx + 1) & 0x3;
                } else {
                    curRow = nextRow;
                    curCol = nextCol;
                    auto mask = 1<<incIdx;
                    if((visited[curRow][curCol] & mask) == 0) {
                        visited[curRow][curCol] |= 1 << incIdx;
                    } else {
                        return -1;
                    }
                }
                
            } else {
                curRow = nextRow;
                curCol = nextCol;
            }
        }
        if(vLoc != nullptr) {
            std::swap(*vLoc,visited);
        }
        // Determine number of locations visited
        return std::accumulate(visited.begin(), visited.end(), static_cast<int32_t>(0),[](int32_t sum, const std::vector<int>& row){
            return sum + row.size() - std::count(row.begin(), row.end(),0);
        });
    }
}
