//
//  Advent of Code 2024 Solutions: Day 21
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/23/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day21.h"
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
#include <sstream>
//#include <thread>
//#include <tuple>
//#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay21 {
    static const std::string InputFileName = "Day21.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        int sum = 0;
        for(const auto& line : input) {
            sum += getComplexity(line);
        }
        //97482 too high
		return to_string(sum);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);

		return "---";
    }

    KeypadMap getDirectionalToNumericKeypadMap() {
        //Map each digit 0-A to every other digit 0-A
        //Keypad is arranged as follows:
        //  7 8 9
        //  4 5 6
        //  1 2 3
        //    0 A
        //Map movements as follows:
        // > = right
        // < = left
        // ^ = up
        // v = down
        // A = At location
        KeypadMap keyMap;
        keyMap['A'] = {{'A', "A"},     {'0', "<A"},   {'1', "^<<A"},  {'2', "^<A"}, {'3', "^A"},    {'4', "^^<<A"},{'5', "^^<A"},{'6', "^^A"}, {'7', "^^^<<A"},{'8', "^^^<A"}, {'9', "^^^A"} };
        keyMap['0'] = {{'A', ">A"},    {'0', "A"},    {'1', "^<A"},   {'2', "^A"},  {'3', "^>A"},   {'4', "^^<A"}, {'5', "^^A"}, {'6', "^^>A"},{'7', "^^^<A"}, {'8', "^^^A"},  {'9', "^^^>A"}};
        keyMap['1'] = {{'A', ">>vA"},  {'0', ">vA"},  {'1', "A"},     {'2', ">A"},  {'3', ">>A"},   {'4', "^A"},   {'5', "^>A"}, {'6', "^>>A"},{'7', "^^A"},   {'8', "^^>A"},  {'9', "^^>>A"}};
        keyMap['2'] = {{'A', ">vA"},   {'0', "vA"},   {'1', "<A"},    {'2', "A"},   {'3', ">A"},    {'4', "^<A"},  {'5', "^A"},  {'6', "^>A"}, {'7', "^^<A"},  {'8', "^^A"},   {'9', ">^^A"} };
        keyMap['3'] = {{'A', "vA"},    {'0', "v<A"},  {'1', "<<A"},   {'2', "<A"},  {'3', "A"},     {'4', "^<<A"}, {'5', "^<A"}, {'6', "^A"},  {'7', "<<^^A"}, {'8', "^^<A"},  {'9', "^^A"}  };
        keyMap['4'] = {{'A', ">>vA"},  {'0', ">vvA"}, {'1', "vA"},    {'2', ">vA"}, {'3', ">>vA"},  {'4', "A"},    {'5', ">A"},  {'6', ">>A"}, {'7', "^A"},    {'8', "^>A"},   {'9', "^>>A"} };
        keyMap['5'] = {{'A', ">vvA"},  {'0', "vvA"},  {'1', "v<A"},   {'2', "vA"},  {'3', ">vA"},   {'4', "<A"},   {'5', "A"},   {'6', ">A"},  {'7', "^<A"},   {'8', "^A"},    {'9', ">A"}  };
        keyMap['6'] = {{'A', "vvA"},   {'0', "vv<A"}, {'1', "v<<A"},  {'2', "v<A"}, {'3', "vA"},    {'4', "<<A"},  {'5', "<A"},  {'6', "A"},   {'7', "^<<A"},  {'8', "^<A"},   {'9', "^A"}   };
        keyMap['7'] = {{'A', ">>vvA"}, {'0', ">vvvA"},{'1', "vvA"},   {'2', ">vvA"},{'3', ">>vvA"}, {'4', "vA"},   {'5', "v>A"}, {'6', "v>>A"},{'7', "A"},     {'8', ">A"},    {'9', ">>A"}  };
        keyMap['8'] = {{'A', ">vvvA"}, {'0', "vvvA"}, {'1', "vv<A"},  {'2', "vvA"}, {'3', ">vvA"},  {'4', "v<A"},  {'5', "vA"},  {'6', ">vA"}, {'7', "<A"},    {'8', "A"},     {'9', ">A"}   };
        keyMap['9'] = {{'A', "vvvA"},  {'0', "vvv<A"},{'1', "vv<<A"}, {'2', "vv<A"},{'3', "vvA"},   {'4', "v<<A"}, {'5', "v<A"}, {'6', "vA"},  {'7', "<<A"},   {'8', "<A"},    {'9', "A"}    };
        return keyMap;
    }

    KeypadMap getDirectionalToDirectionalKeypadMap() {
        //Map each directional key to every other directional key
        //Keypad is arranged as follows:
        //  ^A
        // <v>
        KeypadMap keyMap;
        keyMap['v'] = {{'v', "A"},   {'^', "^A"},  {'<', "<A"},  {'>', ">A"},  {'A', ">^A"} };
        keyMap['^'] = {{'v', "vA"},  {'^', "A"},   {'<', "v<A"}, {'>', ">vA"}, {'A', ">A"}  };
        keyMap['<'] = {{'v', ">A"},  {'^', ">^A"}, {'<', "A"},   {'>', ">>A"}, {'A', ">>^A"}};
        keyMap['>'] = {{'v', "<A"},  {'^', "<^A"}, {'<', "<<A"}, {'>', "A"},   {'A', "^A"}  };
        keyMap['A'] = {{'v', "<vA"}, {'^', "<A"},  {'<', "v<<A"},{'>', "vA"},  {'A', "A"}   };
        return keyMap;
    }

    std::string KeypadSequencer::getKeypadSequence(const std::string& code) {
        char currentKey = 'A';
        stringstream sequence{};
        //debug
        cout << "----------------" << endl << code << endl;
        //end debug
        for (const auto& c : code) {
            //debug
            auto sq = keyMap[currentKey][c];
            cout << "sequence for " << currentKey << " to " << c << " is " << sq << endl;
            //end debug
            sequence << keyMap[currentKey][c];
            currentKey = c;
        }
        //debug
        cout << "----------------" << endl;
        //end debug
        return sequence.str();
    }

    int getComplexity(const std::string& code) {
        //Main keypad
        KeypadSequencer mainDoor(getDirectionalToNumericKeypadMap());
        //Radiation roomdirectional pad
        KeypadSequencer radiationRoomDirs(getDirectionalToDirectionalKeypadMap());
        //Frozen room directional pad
        KeypadSequencer frozenRoomDirs(getDirectionalToDirectionalKeypadMap());
        
        //Work backwards to get manned sequence
        string mannedSequence = mainDoor.getKeypadSequence(code);
        mannedSequence = radiationRoomDirs.getKeypadSequence(mannedSequence);
        mannedSequence = frozenRoomDirs.getKeypadSequence(mannedSequence);

        //debug
        cout << "Manned sequence for " << code << " is " << mannedSequence << endl;
        cout << "Complexity for " << code << " is " << mannedSequence.size() * stoi(code) << endl;
        cout << "Size of manned sequence is " << mannedSequence.size() << endl;
        cout << "Value of code is " << stoi(code) << endl;
        //end debug

        //Complexity calculation is length of the manned sequence * numeric value of the code
        return mannedSequence.size() * stoi(code);
    }

}

#if 0
KeypadMap getDirectionalToNumericKeypadMap() {
        //Map each digit 0-A to every other digit 0-A
        //Keypad is arranged as follows:
        //  7 8 9
        //  4 5 6
        //  1 2 3
        //    0 A
        //Map movements as follows:
        // > = right
        // < = left
        // ^ = up
        // v = down
        // A = At location
        KeypadMap keyMap;
        keyMap['A'] = {{'A', "A"},     {'0', "<A"},   {'1', "^<<A"},  {'2', "^<A"}, {'3', "^A"},    {'4', "^^<<A"},{'5', "^^<A"},{'6', "^^A"}, {'7', "^^^<<A"},{'8', "^^^<A"}, {'9', "^^^A"} };
        keyMap['0'] = {{'A', ">A"},    {'0', "A"},    {'1', "^<A"},   {'2', "^A"},  {'3', "^>A"},   {'4', "^^<A"}, {'5', "^^A"}, {'6', "^^>A"},{'7', "^^^<A"}, {'8', "^^^A"},  {'9', "^^^>A"}};
        keyMap['1'] = {{'A', ">>vA"},  {'0', ">vA"},  {'1', "A"},     {'2', ">A"},  {'3', ">>A"},   {'4', "^A"},   {'5', "^>A"}, {'6', "^>>A"},{'7', "^^A"},   {'8', "^^>A"},  {'9', "^^>>A"}};
        keyMap['2'] = {{'A', ">vA"},   {'0', "vA"},   {'1', "<A"},    {'2', "A"},   {'3', ">A"},    {'4', "^<A"},  {'5', "^A"},  {'6', "^>A"}, {'7', "^^<A"},  {'8', "^^A"},   {'9', "^^>A"} };
        keyMap['3'] = {{'A', "vA"},    {'0', "v<A"},  {'1', "<<A"},   {'2', "<A"},  {'3', "A"},     {'4', "^<<A"}, {'5', "^<A"}, {'6', "^A"},  {'7', "^^<<A"}, {'8', "^^<A"},  {'9', "^^A"}  };
        keyMap['4'] = {{'A', ">>vA"},  {'0', ">vvA"}, {'1', "vA"},    {'2', ">vA"}, {'3', ">>vA"},  {'4', "A"},    {'5', ">A"},  {'6', ">>A"}, {'7', "^A"},    {'8', "^>A"},   {'9', "^>>A"} };
        keyMap['5'] = {{'A', ">vvA"},  {'0', "vvA"},  {'1', "v<A"},   {'2', "vA"},  {'3', ">vA"},   {'4', "<A"},   {'5', "A"},   {'6', ">A"},  {'7', "^<A"},   {'8', "^A"},    {'9', "^>A"}  };
        keyMap['6'] = {{'A', "vvA"},   {'0', "vv<A"}, {'1', "v<<A"},  {'2', "v<A"}, {'3', "vA"},    {'4', "<<A"},  {'5', "<A"},  {'6', "A"},   {'7', "^<<A"},  {'8', "^<A"},   {'9', "^A"}   };
        keyMap['7'] = {{'A', ">>vvA"}, {'0', ">vvvA"},{'1', "vvA"},   {'2', ">vvA"},{'3', ">>vvA"}, {'4', "vA"},   {'5', "v>A"}, {'6', "v>>A"},{'7', "A"},     {'8', ">A"},    {'9', ">>A"}  };
        keyMap['8'] = {{'A', ">vvvA"}, {'0', "vvvA"}, {'1', "vv<A"},  {'2', "vvA"}, {'3', ">vvA"},  {'4', "v<A"},  {'5', "vA"},  {'6', ">vA"}, {'7', "<A"},    {'8', "A"},     {'9', ">A"}   };
        keyMap['9'] = {{'A', "vvvA"},  {'0', "vvv<A"},{'1', "vv<<A"}, {'2', "vv<A"},{'3', "vvA"},   {'4', "v<<A"}, {'5', "v<A"}, {'6', "vA"},  {'7', "<<A"},   {'8', "<A"},    {'9', "A"}    };
        return keyMap;
    }
    #endif