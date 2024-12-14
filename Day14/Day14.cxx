//
//  Advent of Code 2024 Solutions: Day 14
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/13/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day14.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.


using namespace std;
namespace AocDay14 {

    static const std::string InputFileName = "Day14.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto positions = parseFileForRoboPositions(input);
        auto xMax = 101;
        auto yMax = 103;
        for(int i = 0; i < 100; i++) {
            stepRoboPositions(positions, xMax, yMax);
        }
        auto counts = countInQuadrants(positions, xMax, yMax);
		return to_string(counts[0] * counts[1] * counts[2] * counts[3]);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);

        auto positions = parseFileForRoboPositions(input);
        auto xMax = 101;
        auto yMax = 103;
        const auto limit = 30;
        auto minMult = INT_MAX;
        for(int i = 0; i < 7000; i++) {
            stepRoboPositions(positions, xMax, yMax);
            auto counts = countInQuadrants(positions, xMax, yMax);
            auto mult = counts[0] * counts[1] * counts[2] * counts[3];
            if(mult < minMult) {
                minMult = mult;
            //}
            //if(i == 6875)
            //{
                
                printVector(counts);
                cout << "-----------------------Step " << i << "----------------------------" << endl;
                printRoboPositions(positions, xMax, yMax);
            }
        }
		return "---";
    }

    RoboPosition parseInput(const std::string& input, const std::string& id) {
        RoboPosition result;
        int xPos = 0;
        int yPos = 0;
        int xVel = 0;
        int yVel = 0;
        sscanf(input.c_str(), "p=%d,%d v=%d,%d", &xPos, &yPos, &xVel, &yVel);
        result.x = AocUtils::LinearTraveler<int>(id + "_x", 1, 0, xVel, xPos, 1, 0);
        result.y = AocUtils::LinearTraveler<int>(id + "_y", 1, 0, yVel, yPos, 1, 0);
        return result;
    }

    std::vector<RoboPosition> parseFileForRoboPositions(const std::vector<std::string>& input) {
        std::vector<RoboPosition> result;
        auto i = 0;
        for (auto& line : input) {
            result.push_back(parseInput(line, "Robo"+std::to_string(i++)));
        }
        return result;
    }

    void stepRoboPositions(std::vector<RoboPosition>& positions, int xMax, int yMax) {
        for (auto& pos : positions) {
            pos.x.step();
            if(pos.x.position() >= xMax) {
                pos.x.setPosition(pos.x.position() - xMax);
            } else if(pos.x.position() < 0) {
                pos.x.setPosition(pos.x.position() + xMax);
            }
            pos.y.step();
            if(pos.y.position() >= yMax) {
                pos.y.setPosition(pos.y.position() - yMax);
            } else if(pos.y.position() < 0) {
                pos.y.setPosition(pos.y.position() + yMax);
            }
        }
    }

    std::ostream& operator<<(std::ostream& os, const RoboPosition& pos) {
        os << pos.x.name() << "<" << pos.x.position() << "," << pos.y.position() << ">";
        return os;
    }

    std::vector<int> countInQuadrants(const std::vector<RoboPosition>& positions, int xMax, int yMax) {
        std::vector<int> result(4,0);
        for (const auto& pos : positions) {
            
            if(pos.x.position() == xMax/2 || pos.y.position() == yMax/2) {
            } else if(pos.x.position() < xMax/2 && pos.y.position() < yMax/2) {
                result[0]++;
            } else if(pos.x.position() > xMax/2 && pos.y.position() < yMax/2) {
                result[1]++;
            } else if(pos.x.position() > xMax/2 && pos.y.position() > yMax/2) {
                result[2]++;
            } else if(pos.x.position() < xMax/2 && pos.y.position() > yMax/2) {
                result[3]++;
            }
        }
        return result;
    }

    void printRoboPositions(const std::vector<RoboPosition>& positions, int xMax, int yMax) {
        string blankLine(xMax,' ');
        vector<string> grid(yMax,blankLine);
        for (const auto& pos : positions) {
            grid[pos.y.position()][pos.x.position()] = '*';
        }
        for (const auto& line : grid) {
            cout << line << endl;
        }
    }
}
