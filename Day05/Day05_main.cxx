//
//  Advent of Code 2024 Main Runner: Day 5
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/05/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay05{
    extern std::string solvea();
    extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

    std::cout << "Day05" << "a: " << AocDay05::solvea() << std::endl;
    std::cout << "Day05" << "b: " << AocDay05::solveb() << std::endl;
    return 0;
}
