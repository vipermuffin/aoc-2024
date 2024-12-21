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
#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <functional> //std::function
#include <sstream>
#include <thread>


using namespace std;
namespace AocDay17 {
    void findInitValProg(const std::vector<std::string>& input, uint64_t& result, uint64_t startVal, uint64_t endVal);

    static const std::string InputFileName = "Day17.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        vector<int> registers;
        auto program = parseProgram(input, registers);
        return runProgram(program, registers);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        //1568468369408 is too low
        //281479540113408 is too high
        vector<uint64_t> results(8,0);
        vector<thread> threads;
        uint64_t startVal = 36314372088831;
        uint64_t endVal = 281474976710655;
        uint64_t stepSize = (endVal - startVal) / 8;
        threads.reserve(8);
        

        for(uint64_t i = 0; i < 8; i++) {
            threads.emplace_back(findInitValProg, std::ref(input), std::ref(results[i]), startVal +i*stepSize, startVal + (i+1)*stepSize); 
        }
        for(auto& t : threads) {
            t.join();
        }
        printVector(results);
		//return to_string(findInitValProgram(input,35184372088831,281474976710655));
        return "---";
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

//hardcoded for my input
    void findInitValProg(const std::vector<std::string>& input, uint64_t& result, uint64_t startVal, uint64_t endVal) {
        cout << "Starting search for range " << startVal << " to " << endVal << endl;
        vector<int> initRegs(8,0);
        auto program = parseProgram(input, initRegs);
        vector<uint64_t> expectedVals;
        for(const auto p : program) {
            expectedVals.push_back(static_cast<uint64_t>(p.first));
            expectedVals.push_back(static_cast<uint64_t>(p.second));
        }
        auto itr = expectedVals.begin();
        bool isGood = true;
        uint64_t regVal = startVal;
        bool notFound = true;
        while(notFound && regVal < endVal) {
            isGood = true;
            itr = expectedVals.begin();
            uint64_t regA = regVal;
            uint64_t regB = 0;
            uint64_t regC = 0;
            while(regA > 0 && isGood && itr != expectedVals.end()) {
                regB = regA&0b111;    //2,4
                regB = regB^1;        //1,1
                regC = regA >> regB;  //7,5
                regB = regB^5;        //1,5
                regA = regA >> 3;     //0,3
                regB = regB^regC;     //4,3
                if((regB&0b111) == *itr) {
                    //5,5
                    itr++;
                } else {
                    isGood = false;
                }
            }
            if(isGood && itr == expectedVals.end()) {
                notFound = false;
                cout << "Found " << regVal << endl;
                result = regVal;
            } else {
                regVal++;
            }
        }
    }

     uint64_t findInitValProgram(const std::vector<std::string>& input, uint64_t startVal, uint64_t endVal) {
         uint64_t pc = 0;
         vector<int> initRegs(8,0);
         auto program = parseProgram(input, initRegs);
         vector<uint64_t> registers{initRegs.begin(),initRegs.end()};
         vector<uint64_t> expectedVals;
         for(const auto p : program) {
             expectedVals.push_back(static_cast<uint64_t>(p.first));
             expectedVals.push_back(static_cast<uint64_t>(p.second));
         }
         auto itr = expectedVals.begin();
         bool isGood = true;
         const vector<std::function<void(uint64_t)>> instructions = {
             [&](uint64_t x) {registers[4] >>= registers[x];pc++;}, // adv instruction (opcode 0), reg[4]/(2 << reg[x])
             [&](uint64_t x) {registers[5] ^= x;pc++;},  //bxl (opcode 1) calculates the bitwise XOR of register B and the literal operand, then stores in register B.
             [&](uint64_t x) {registers[5] = registers[x]&7;pc++;}, //bst (opcode 2) calculates the value of its combo operand modulo 8, then writes that value to the B register.
             [&](uint64_t x) {if(registers[4] == 0){pc++;}else{pc=x/2;}}, //jnz (opcode 3) does nothing if the A register is 0, else it jumps by setting the instruction pointer to the value of its literal operand
             [&](uint64_t x) {registers[5] = registers[5] ^ registers[6];pc++;}, //bxc instruction (opcode 4) calculates the bitwise XOR of register B and register C, then stores the result in register B.
             [&](uint64_t x) {isGood = (*itr == (registers[x] & 7));itr++;pc++;}, // out (opcode 5) calculates the value of its combo operand modulo 8, then outputs that value.
             [&](uint64_t x) {registers[5] = registers[4] >> registers[x];pc++;}, //bdv...adv but store in b
             [&](uint64_t x) {registers[6] = registers[4] >> registers[x];pc++;} //illegal instruction
         };
         uint64_t regVal = startVal;
         bool notFound = true;
         while(notFound && regVal < endVal) {
             isGood = true;
             for(auto i = 0; i < registers.size(); i++) {
                 registers[i] = initRegs[i];
             }
             registers[4] = regVal;
             itr = expectedVals.begin();
             pc = 0;
             while(pc >= 0 && pc < program.size() && isGood && itr != expectedVals.end()) {
                 instructions[program[pc].first](program[pc].second);
             }
             if(isGood && itr == expectedVals.end()) {
                 notFound = false;
             } else {
                 regVal++;
             }
         }
        
         return regVal;
     }
}
