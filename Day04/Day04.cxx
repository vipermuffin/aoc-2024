//
//  Advent of Code 2024 Solutions: Day 4
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/04/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day04.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.


using namespace std;
namespace AocDay04 {

    static const std::string InputFileName = "Day04.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        string word2Find{"XMAS"};
        return to_string(findWordInGrid(input, word2Find));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        string word2Find{"MAS"};
        return to_string(findXWordInGrid(input, word2Find));
    }

    int32_t findWordInGrid(const std::vector<std::string>& grid, const std::string& word2Find) {
        int32_t numWords{0};
        for(auto row = 0; row < grid.size();row++) {
            for(auto col = 0; col < grid[row].size(); col++) {
                for(int y = -1;y <= 1; y++) {
                    for(int x = -1; x <= 1; x++) {
                        if(x==0 && y==0) {
                            //skip
                        } else {
                            if(findWordInGridAtLocation(grid, word2Find, col, row, 0, x, y)){
                                numWords++;
                            }
                        }
                    }
                }
            }
        }

        return numWords;
    }

    int32_t findXWordInGrid(const std::vector<std::string>& grid, const std::string& word2Find, const size_t xLetterIdx) {
        vector<vector<int>> aCount{};
        vector<int> initVec{};
        initVec.resize(grid.back().size());
        for(auto i = 0; i < grid.size();i++) {
            aCount.push_back(initVec);
        }
        
        for(auto row = 0; row < grid.size();row++) {
            for(auto col = 0; col < grid[row].size(); col++) {
                for(int y = -1;y <= 1; y+=2) {
                    for(int x = -1; x <= 1; x+=2) {
                        if(findWordInGridAtLocation(grid, word2Find, col, row, 0, x, y)){
                            //Count number of times A is found.  Should be next letter
                            aCount[row+y*xLetterIdx][col+x*xLetterIdx]++;
                        }
                    }
                }
            }
        }
        int32_t numWords{0};

        for_each(aCount.begin(),aCount.end(),[&numWords](const std::vector<int>& v){numWords += std::count(v.begin(),v.end(),2);});
        

        return numWords;
    }

    bool findWordInGridAtLocation(const std::vector<std::string>& grid, const std::string& word2Find, const int xPos, const int yPos, const size_t currentLetterIndex, const int xInc, const int yInc) {
        if(currentLetterIndex >= word2Find.size()) {
            return true;
        } else if (yPos < 0 || yPos >= grid.size() || xPos < 0 || xPos >= grid[yPos].size()) {
            return false;
        } else {
            if(grid[yPos][xPos] == word2Find[currentLetterIndex]) {
                return findWordInGridAtLocation(grid, word2Find, xPos + xInc, yPos + yInc, currentLetterIndex+1,xInc,yInc);
            } else {
                return false;
            }
        }
        return false;
    }
}
