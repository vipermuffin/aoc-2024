//
//  Advent of Code 2024 Main Runner: Day 16
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/16/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay16{
    extern std::string solvea();
    extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

    std::cout << "Day16" << "a: " << AocDay16::solvea() << std::endl;
    std::cout << "Day16" << "b: " << AocDay16::solveb() << std::endl;
    return 0;
}
