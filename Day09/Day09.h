//
//  Advent of Code 2024 Solutions: Day 9
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/09/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <list>

namespace AocDay09 {
//Function Definitions
struct BLOCK_S {
    BLOCK_S(){ fileId = -1; blockId = -1; size = 0;}
    BLOCK_S(int fId, int bId, size_t sz) {fileId = fId; blockId = bId; size = sz;}
    int fileId;
    int blockId;
    size_t size;
};

using block_t = BLOCK_S;
std::string printList(const std::list<block_t>& bList);
std::list<block_t> buildList(const std::string&);
int64_t increaseFrag(std::list<block_t>&);
int64_t defrag(std::list<block_t>&);

}
