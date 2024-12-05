//
//  Advent of Code 2024 Main Runner: Day 4
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/04/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay04{
    extern std::string solvea();
    extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

    std::cout << "Day04" << "a: " << AocDay04::solvea() << std::endl;
    std::cout << "Day04" << "b: " << AocDay04::solveb() << std::endl;
    return 0;
}
