//
//  Advent of Code 2024 Main Runner: Day 18
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/21/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay18{
    extern std::string solvea();
    extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

    std::cout << "Day18" << "a: " << AocDay18::solvea() << std::endl;
    std::cout << "Day18" << "b: " << AocDay18::solveb() << std::endl;
    return 0;
}
