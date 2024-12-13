//
//  Advent of Code 2024 Main Runner: Day 12
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/12/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay12{
    extern std::string solvea();
    extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

    std::cout << "Day12" << "a: " << AocDay12::solvea() << std::endl;
    std::cout << "Day12" << "b: " << AocDay12::solveb() << std::endl;
    return 0;
}
