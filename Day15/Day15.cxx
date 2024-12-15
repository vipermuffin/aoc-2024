//
//  Advent of Code 2024 Solutions: Day 15
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/15/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day15.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
//#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
//#include <chrono>
//#include <iostream>
//#include <fstream> //ifstream
//#include <functional> //std::function
//#include <iomanip> //setfill setw hex
//#include <map>
//#include <math.h> //sqrt
//#include <numeric> //std::accumulate
//#include <queue>
//#include <regex>
//#include <set>
//#include <sstream>
#include <stack>
//#include <thread>
//#include <tuple>
#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay15 {

    static const std::string InputFileName = "Day15.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto itr = input.begin();
        //Find the first empty line
        while(itr != input.end() && itr->size() != 0) {
            itr++;
        }
        auto mapInput = vector<string>(input.begin(), itr);
        itr++;
        auto sequences = vector<string>(itr, input.end());
        for(auto sequence : sequences) {
            performMovementSequence(mapInput, sequence);
        }

		return to_string(calcGPS(mapInput));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);

		return "---";
    }

    int calcGPS(const std::vector<std::string>& input) {
        //Sum up coordinates of the 'O's multiplying row by 100 + col
        int sum = 0;
        for(auto row = 0; row < input.size(); row++) {
            for(auto col = 0; col < input[row].size(); col++) {
                if(input[row][col] == 'O') {
                    sum += (row * 100) + col;
                }
            }
        }
        return sum;
    }

    void performMovementSequence(std::vector<std::string>& input, const std::string& sequence) {
        //Move the '@' character around the grid according to the sequence
        //The sequence is a string of characters '^', 'v', '<', '>' for up, down, left, right
        //The '@' character cannot move through walls ('#')
        //The '@' character can push the 'O' characters if there is no '#' behind them
        //The '@' character can push multiple 'O' characters if there is no '#' behind them
        unordered_map<char, pair<int,int>> directions = {
            {'^',{-1,0}},
            {'v',{1,0}},
            {'<',{0,-1}},
            {'>',{0,1}}
        };

        //find the starting position of the '@' character
        int currentRow = 0;
        int currentCol = 0;
        for(auto row = 0; row < input.size(); row++) {
            for(auto col = 0; col < input[row].size(); col++) {
                if(input[row][col] == '@') {
                    currentRow = row;
                    currentCol = col;
                    break;
                }
            }
        }

        //Move the '@' character around the grid according to the sequence
        for(auto move : sequence) {
            auto direction = directions[move];
            auto newRow = currentRow;
            auto newCol = currentCol;
            stack<pair<int,int>> moves;
            //no range checks, assuming will always have a wall
            while(input[newRow][newCol] != '.' && input[newRow][newCol] != '#') {
                moves.push({newRow,newCol});
                newRow += direction.first;
                newCol += direction.second;
                if(input[newRow][newCol] == '#') {
                    //hit a wall
                    // Clear the stack
                    while (!moves.empty()) {
                        moves.pop();
                    }
                }
            }
            //move the '@' character
            while (!moves.empty()) {
                auto moveLoc = moves.top();
                moves.pop();
                std::swap(input[newRow][newCol], input[moveLoc.first][moveLoc.second]);
                currentRow = newRow;
                currentCol = newCol;
                newRow = moveLoc.first;
                newCol = moveLoc.second;
            }
        }
    }
}
