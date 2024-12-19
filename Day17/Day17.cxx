//
//  Advent of Code 2024 Solutions: Day 17
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/18/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day17.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
//#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
//#include <chrono>
//#include <iostream>
//#include <fstream> //ifstream
#include <functional> //std::function
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
namespace AocDay17 {

    static const std::string InputFileName = "Day17.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        vector<int> registers;
        auto program = parseProgram(input, registers);
        return runProgram(program, registers);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);

		return to_string(findInitValProgram(input));
    }

    std::vector<std::pair<int,int>> parseProgram(const std::vector<std::string>& input, std::vector<int>& registers) {
        std::vector<std::pair<int,int>> program;
        registers.resize(8,0);
        for(int i = 0; i < registers.size(); i++) {
            registers[i] = i;
        }

        sscanf(input[0].c_str(), "Register A: %d", &registers[4]);
        sscanf(input[1].c_str(), "Register B: %d", &registers[5]);
        sscanf(input[2].c_str(), "Register C: %d", &registers[6]);
        auto words = parseLineForWords(input[4]);
        auto vals = parseCsvLineForNum(words[1]);
        for(int i = 0; i < vals.size(); i+=2) {
            program.push_back({vals[i],vals[i+1]});
        }
        
        return program;
    }

    std::string runProgram(const std::vector<std::pair<int,int>>& program, std::vector<int> registers) {
        int pc = 0;
        stringstream ss{};
        const vector<std::function<void(int)>> instructions = {
            [&](int x) {registers[4] >>= registers[x];pc++;}, // adv instruction (opcode 0), reg[4]/(2 << reg[x])
            [&](int x) {registers[5] ^= x;pc++;},  //bxl (opcode 1) calculates the bitwise XOR of register B and the literal operand, then stores in register B.
            [&](int x) {registers[5] = registers[x]&7;pc++;}, //bst (opcode 2) calculates the value of its combo operand modulo 8, then writes that value to the B register.
            [&](int x) {if(registers[4] == 0){pc++;}else{pc=x/2;}}, //jnz (opcode 3) does nothing if the A register is 0, else it jumps by setting the instruction pointer to the value of its literal operand
            [&](int x) {registers[5] = registers[5] ^ registers[6];pc++;}, //bxc instruction (opcode 4) calculates the bitwise XOR of register B and register C, then stores the result in register B.
            [&](int x) {if(ss.str().size() > 0) {ss << ",";}ss << (registers[x] & 7);pc++;}, // out (opcode 5) calculates the value of its combo operand modulo 8, then outputs that value.
            [&](int x) {registers[5] = registers[4] >> registers[x];pc++;}, //bdv...adv but store in b
            [&](int x) {registers[6] = registers[4] >> registers[x];pc++;} //illegal instruction
        };
        while(pc >= 0 && pc < program.size()) {
            instructions[program[pc].first](program[pc].second);
        }
        return ss.str();
    }

    int findInitValProgram(const std::vector<std::string>& input) {
        int pc = 0;
        vector<int> registers(8,0);
        auto program = parseProgram(input, registers);
        vector<int> initRegs{registers.begin(),registers.end()};
        vector<int> expectedVals;
        for(const auto p : program) {
            expectedVals.push_back(p.first);
            expectedVals.push_back(p.second);
        }
        auto itr = expectedVals.begin();
        bool isGood = true;
        const vector<std::function<void(int)>> instructions = {
            [&](int x) {registers[4] >>= registers[x];pc++;}, // adv instruction (opcode 0), reg[4]/(2 << reg[x])
            [&](int x) {registers[5] ^= x;pc++;},  //bxl (opcode 1) calculates the bitwise XOR of register B and the literal operand, then stores in register B.
            [&](int x) {registers[5] = registers[x]&7;pc++;}, //bst (opcode 2) calculates the value of its combo operand modulo 8, then writes that value to the B register.
            [&](int x) {if(registers[4] == 0){pc++;}else{pc=x/2;}}, //jnz (opcode 3) does nothing if the A register is 0, else it jumps by setting the instruction pointer to the value of its literal operand
            [&](int x) {registers[5] = registers[5] ^ registers[6];pc++;}, //bxc instruction (opcode 4) calculates the bitwise XOR of register B and register C, then stores the result in register B.
            [&](int x) {isGood = (*itr == (registers[x] & 7));itr++;pc++;}, // out (opcode 5) calculates the value of its combo operand modulo 8, then outputs that value.
            [&](int x) {registers[5] = registers[4] >> registers[x];pc++;}, //bdv...adv but store in b
            [&](int x) {registers[6] = registers[4] >> registers[x];pc++;} //illegal instruction
        };
        int regVal = 0;
        bool notFound = true;
        while(notFound && regVal >= 0) {
            isGood = true;
            for(auto i = 0; i < registers.size(); i++) {
                registers[i] = initRegs[i];
            }
            registers[4] = regVal;
            itr = expectedVals.begin();
            // printVector(registers);
            pc = 0;
            while(pc >= 0 && pc < program.size() && isGood && itr != expectedVals.end()) {
                // if(program[pc].first == 5) {
                //     cout << "Checking " << *itr << " against " << (registers[program[pc].second] & 7) << endl;
                // }
                instructions[program[pc].first](program[pc].second);
            }
            if(isGood && itr == expectedVals.end()) {
                notFound = false;
            } else {
                regVal++;
                // if(regVal % 100000 == 0) {
                //     cout << regVal << endl;
                // }
                // if(regVal > 117445) {
                //     cout << "No solution found" << endl;
                //     break;
                // }
            }
        }
        
        return regVal;
    }
}
