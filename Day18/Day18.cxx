//
//  Advent of Code 2024 Solutions: Day 18
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/21/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day18.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <queue>
#include <tuple>



using namespace std;
namespace AocDay18 {

    static const std::string InputFileName = "Day18.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);

		return to_string(findShortestPathSteps(input, coordXY(70,70), 70, 1024));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        return findBlockingCoordinates(input, coordXY(70,70));
    }

    //parseInput parses lines of format "x,y" into a vector of ints by multiplying y by 1000 and adding x
    std::unordered_set<int> parseInput(const std::vector<std::string>& input, size_t numLines) {
        std::unordered_set<int> parsedInput;
        for (auto i = 0; i < numLines;i++) {
            auto splitLine = parseCsvLineForNum(input[i]);
            parsedInput.insert(coordXY(splitLine[0],splitLine[1]));
        }
        return parsedInput;
    }

    int findShortestPathSteps(const std::vector<std::string>& input, int endCoord, size_t gridSize, size_t simBytes) {
        auto corruptCells = parseInput(input, simBytes);
        //CorruptCells contains the coordinates of all obstacles
        //The goal is to find the shortest path from the start to the end without passing through any of the corrupt cells
        //The start is at 0,0
        //The end is at endCoord
        std::queue<std::tuple<int, int, int>> q; // x, y, steps
        std::unordered_map<int,bool> visited;
        q.push({0,0,0});
        visited[0] = true;
        while(!q.empty()) {
            auto [x,y,steps] = q.front();
            q.pop();
            if (coordXY(x,y) == endCoord) {
                return steps;
            }
            for (const auto& [dx,dy] : std::array<std::pair<int,int>, 4>{{{0,1},{1,0},{0,-1},{-1,0}}}) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx <= gridSize && ny <= gridSize) {
                    if(corruptCells.count(coordXY(nx,ny)) == 0) {
                        if (!visited[coordXY(nx,ny)]) {
                            visited[coordXY(nx,ny)] = true;
                            q.push({nx,ny,steps+1});
                        }
                    } else {
                    }
                }
            }
        }
        return INT_MAX;
    }

    std::string findBlockingCoordinates(const std::vector<std::string>& input, int endCoord) {
        auto startVal = 0;
        auto itr = input.begin();

        while(itr != input.end() && findShortestPathSteps(input, endCoord, endCoord/1000, startVal) < INT_MAX) {
            startVal++;
            itr++;
        }
        if(itr != input.end()) {
            return *--itr;
        }
        return "---";
    }
}
