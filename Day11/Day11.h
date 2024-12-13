//
//  Advent of Code 2024 Solutions: Day 11
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/11/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//
#pragma once
#include <list>
#include <string>
#include <vector>
#include <unordered_map>

namespace AocDay11 {
//Function Definitions
std::list<uint64_t> initList(const std::string&);
std::unordered_map<uint64_t, uint64_t> initListMap(const std::string&);
void blink(std::list<uint64_t>&);
void blink(std::unordered_map<uint64_t,uint64_t>& stones);
uint64_t countStones(const std::unordered_map<uint64_t, uint64_t>& stones);
std::string printList(const std::list<uint64_t>&);
}
