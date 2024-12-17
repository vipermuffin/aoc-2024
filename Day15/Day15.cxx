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
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <stack>
#include <unordered_map>

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
        auto itr = input.begin();
        //Find the first empty line
        while(itr != input.end() && itr->size() != 0) {
            itr++;
        }
        auto mapInput = vector<string>(input.begin(), itr);
        expandMap(mapInput);
        itr++;
        auto sequences = vector<string>(itr, input.end());
        for(auto sequence : sequences) {
         performMovementSequence(mapInput, sequence);
        }
        
		return to_string(calcGPS(mapInput));
    }

    int calcGPS(const std::vector<std::string>& input) {
        //Sum up coordinates of the 'O's multiplying row by 100 + col
        int sum = 0;
        for(auto row = 0; row < input.size(); row++) {
            for(auto col = 0; col < input[row].size(); col++) {
                if(input[row][col] == 'O' || input[row][col] == '[') {
                    sum += (row * 100) + col;
                }
            }
        }
        return sum;
    }

    void performMovementSequence(std::vector<std::string>& input, const std::string& sequence, bool debug) {
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
            stack<pair<int,int>> linearMoves;
            vector<stack<pair<int,int>>> moveStack;
            //reserve enough vector size so my iterator doesn't get invalidated when adding to the back.
            moveStack.reserve(input.size()*100);
            linearMoves.push({newRow,newCol});
            moveStack.push_back(linearMoves);
            auto moves = moveStack.begin();
            vector<vector<bool>> visited(input.size(), vector<bool>(input[0].size(), false));
            //no range checks, assuming will always have a wall
            while(!moveStack.empty() && moves != moveStack.end()) {
                newRow = moves->top().first;
                newCol = moves->top().second;
                moves->pop();
                while(input[newRow][newCol] != '.' && input[newRow][newCol] != '#') {
                    moves->push({newRow,newCol});
                    visited[newRow][newCol] = true;
                    newRow += direction.first;
                    newCol += direction.second;
                    if(input[newRow][newCol] == '#') {
                        //hit a wall
                        // Clear the stack
                        moveStack.clear();
                        moves = moveStack.end();
                    } else if(input[newRow][newCol] == '[') {
                        //hit a box
                        // Add a new stack
                        stack<pair<int,int>> newStack{};
                        if(direction.second == 0 && !visited[newRow][newCol+1]) {
                            newStack.push({newRow,newCol+1});
                            visited[newRow][newCol+1] = true;
                            auto d = std::distance(moveStack.begin(), moves);
                            moveStack.push_back(newStack);
                            moves = moveStack.begin() + d;
                        }
                    } else if(input[newRow][newCol] == ']') {
                        //hit a box
                        // Add a new stack
                        stack<pair<int,int>> newStack{};
                        if(direction.second == 0 && !visited[newRow][newCol-1]) {
                            newStack.push({newRow,newCol-1});
                            visited[newRow][newCol-1] = true;
                            auto d = std::distance(moveStack.begin(), moves);
                            moveStack.push_back(newStack);
                            moves = moveStack.begin() + d;
                        }
                    }
                }
                if(input[newRow][newCol] == '.') {
                    moves->push({newRow,newCol});
                }

                if(moves != moveStack.end()) {
                    moves++;
                }
            }
            
            //move the '@' character
            auto rMoves = moveStack.rbegin();
            vector<vector<bool>> swapped(input.size(), vector<bool>(input[0].size(), false));
            while(!moveStack.empty() && rMoves != moveStack.rend()) {
                newRow = rMoves->top().first;
                newCol = rMoves->top().second;
                rMoves->pop();
                while (!rMoves->empty()) {
                    auto moveLoc = rMoves->top();
                    rMoves->pop();
                    if(!swapped[moveLoc.first][moveLoc.second]) {
                        swapped[moveLoc.first][moveLoc.second] = true;
                        
                        if(debug) {
                            cout << "Swapping " << input[newRow][newCol] << "<->" << input[moveLoc.first][moveLoc.second] << " from (" << newRow << "," << newCol << ")<->(" << moveLoc.first << "," << moveLoc.second << ")" << endl;
                        }
                        std::swap(input[newRow][newCol], input[moveLoc.first][moveLoc.second]);
                    }
                    currentRow = newRow;
                    currentCol = newCol;
                    newRow = moveLoc.first;
                    newCol = moveLoc.second;
                }
                rMoves++;
            }

            // Debug
            if(debug) {
                cout << "Move: " << move << endl;
                for(auto row = 0; row < input.size(); row++) {
                    cout << input[row] << endl;
                }
            }
            
        }
    }

    void expandMap(std::vector<std::string>& input) {
        //Each line becomes 2x as long
        //'#' becomes '##'
        //'O' becomes '[]'
        //The '@' character becomes '@.'
        vector<string> newMap;
        for(auto row = 0; row < input.size(); row++) {
            string newRow(input[row].size() * 2, '#');
            auto itr = newRow.begin();
            for(auto col = 0; col < input[row].size(); col++) {
                if(input[row][col] == '#') {
                    *itr = '#';
                    itr++;
                    *itr = '#';
                    itr++;
                } else if(input[row][col] == 'O') {
                    *itr = '[';
                    itr++;
                    *itr = ']';
                    itr++;
                } else if(input[row][col] == '@') {
                    *itr = '@';
                    itr++;
                    *itr = '.';
                    itr++;
                } else if(input[row][col] == '.') {
                    *itr = '.';
                    itr++;
                    *itr = '.';
                    itr++;
                }else {
                    cout << "Error: Unknown character in input" << endl;
                }
            }
            newMap.push_back(newRow);
        }

        std::swap(input, newMap);
    }
}
