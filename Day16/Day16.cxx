//
//  Advent of Code 2024 Solutions: Day 16
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/16/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day16.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <queue>
#include <tuple>
#include <unordered_set>
#include <utility>

using namespace std;
namespace AocDay16 {

    static const std::string InputFileName = "Day16.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        
		return to_string(findShortestPathScore(input));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);

		return to_string(findShortestPathScore(input,true));
    }

    std::vector<std::pair<int,int>> findStartEnd(const std::vector<std::string>& input) {
        std::vector<std::pair<int,int>> startEnd;
        std::pair<int,int> start;
        std::pair<int,int> end;

        for (int i = 0; i < input.size(); i++) {
            for (int j = 0; j < input[i].size(); j++) {
                if (input[i][j] == 'S') {
                    start.first = j;
                    start.second = i;
                }
                if (input[i][j] == 'E') {
                    end.first = j;
                    end.second = i;
                }
            }
        }
        startEnd.push_back(start);
        startEnd.push_back(end);
        return startEnd;
    }

    int findShortestPathScore(const std::vector<std::string>& input, const bool countTiles) {
        auto startEnd = findStartEnd(input);
        auto start = startEnd[0];
        auto end = startEnd[1];
        auto bestScore = INT_MAX;
        
        std::vector<std::vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        std::queue<std::tuple<int, int, int, int, vector<int>>> q; // x, y, direction, score
        std::vector<std::vector<std::vector<int>>> visited(input.size(), std::vector<std::vector<int>>(input[0].size(), std::vector<int>(4, INT_MAX)));

        unordered_set<int> tiles;
        vector<int> tStart{start.first + start.second * 1000};
        q.push({start.second, start.first, 0, 0, tStart});
        visited[start.second][start.first][0] = 0;
        
        while (!q.empty()) {
            int x = std::get<0>(q.front());
            int y = std::get<1>(q.front());
            int dir = std::get<2>(q.front());
            int score = std::get<3>(q.front());
            vector<int> tileCount = std::get<4>(q.front());
            q.pop();
            
            if (x == end.second && y == end.first && score <= bestScore) {
                if(countTiles) {
                    if(score < bestScore) {
                        tiles.clear();
                    }
                    for(auto t : tileCount) {
                        tiles.insert(t);
                    }
                }
                bestScore = score;
            } else {
                // Turn right
                int newDir = (dir + 1) & 3;
                if (visited[x][y][newDir] >= score) {
                    visited[x][y][newDir] = score + 1000;
                    q.push({x, y, newDir, score + 1000, tileCount});
                }

                // Turn left
                newDir = (dir - 1) & 3;
                if (visited[x][y][newDir] >= score) {
                    visited[x][y][newDir] = score + 1000;
                    q.push({x, y, newDir, score + 1000, tileCount});
                }

                // Move forward
                int nx = x + directions[dir][0];
                int ny = y + directions[dir][1];
                if (nx >= 0 && nx < input.size() && ny >= 0 && ny < input[0].size() 
                    && input[nx][ny] != '#' && visited[nx][ny][dir] >= score) {
                    visited[nx][ny][dir] = score;
                    if(countTiles) {
                        tileCount.push_back(ny + nx * 1000);
                    }
                    q.push({nx, ny, dir, score + 1, tileCount});
                }
            }
        }

        return countTiles ? static_cast<int>(tiles.size()) : bestScore;
    }
}
