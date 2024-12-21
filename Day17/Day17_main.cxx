//
//  Advent of Code 2024 Main Runner: Day 17
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/18/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay17{
    extern std::string solvea();
    extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

    std::cout << "Day17" << "a: " << AocDay17::solvea() << std::endl;
    std::cout << "Day17" << "b: " << AocDay17::solveb() << std::endl;
    return 0;
}
