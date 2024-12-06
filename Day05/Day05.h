//
//  Advent of Code 2024 Solutions: Day 5
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/05/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay05 {
struct Node_S {
    Node_S() {val=-1;};
    int val;
    std::vector<int> before;
    std::vector<int> after;
};

using Node = struct Node_S;

//Function Definitions
std::vector<Node> buildOrderingGuide(const std::vector<std::string>& input);
std::vector<int> buildOrderedList(const std::vector<Node>&);
bool verifyOrder(const std::vector<int>&,const std::string&);
bool verifyOrder(const std::vector<Node>& masterList,const std::string& pageOrderToVerify);
std::vector<int> reorder(const std::vector<Node>& masterList,const std::string& pageOrderToVerify);

}
