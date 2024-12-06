//
//  Advent of Code 2024 Solutions: Day 5
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/05/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day05.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <cstdio>

using namespace std;
namespace AocDay05 {

    static const std::string InputFileName = "Day05.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto orderGuide = buildOrderingGuide(input);
        
        auto itr = input.begin();
        while(itr != input.end() && *itr != "") {
            itr++;
        }
        itr++;
        
        int sum{0};
        while(itr != input.end()) {
            if(verifyOrder(orderGuide, *itr)) {
                auto x = parseCsvLineForNum(*itr);
                sum += x[x.size()/2];
            }
            itr++;
        }

        return to_string(sum);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto orderGuide = buildOrderingGuide(input);
        
        auto itr = input.begin();
        while(itr != input.end() && *itr != "") {
            itr++;
        }
        itr++;
        
        int sum{0};
        while(itr != input.end()) {
            if(!verifyOrder(orderGuide, *itr)) {
                auto x = reorder(orderGuide, *itr);
                sum += x[x.size()/2];
            }
            itr++;
        }

        return to_string(sum);
    }

std::vector<Node> buildOrderingGuide(const std::vector<std::string>& input) {
    vector<Node> orderingGuide{};
    orderingGuide.resize(100);
    auto itr = input.begin();
    while(itr != input.end() && *itr != "") {
        int b,a;
        sscanf(itr->c_str(),"%d|%d",&b,&a);
        orderingGuide[b].val = b;
        orderingGuide[b].after.push_back(a);
        orderingGuide[a].val = a;
        orderingGuide[a].before.push_back(b);
        itr++;
    }
    return orderingGuide;
}

void orderNodes(const std::vector<Node>& nodes, std::vector<int>& nodeList, std::vector<bool>& placed, int currentNode) {
    const Node& n = nodes[currentNode];
    for(const auto& bN : n.before) {
        if(!placed[bN]) {
            orderNodes(nodes, nodeList, placed, bN);
        }
    }
    
    if(!placed[currentNode]) {
        nodeList.push_back(currentNode);
        placed[currentNode] = true;
    }

    for(const auto& aN : n.after) {
        if(!placed[aN]) {
            orderNodes(nodes, nodeList, placed, aN);
        }
    }
}

std::vector<int> buildOrderedList(const std::vector<Node>& nodes) {
    vector<int> orderedList{};
    vector<bool> placed{};
    placed.resize(100);
    auto itr = nodes.begin();
    bool notFound = true;
    while(notFound && itr != nodes.end()) {
        if(itr->val == -1) {
            itr++;
        } else if(itr->before.size() == 0) {
            notFound = false;
        } else {
            itr++;
        }
    }
    orderNodes(nodes, orderedList, placed, itr->val);

    return orderedList;
}

bool verifyOrder(const std::vector<int>& masterList,const std::string& pageOrderToVerify) {
    auto pages = parseCsvLineForNum(pageOrderToVerify);
    auto masterItr = masterList.begin();
    auto itr = pages.begin();
    while(itr != pages.end()) {
        if(masterItr == masterList.end()) {
            return false;
        } else if(*itr == *masterItr) {
            itr++;
        } else {
            masterItr++;
        }
    }
    return true;
}

bool verifyOrder(const std::vector<Node>& masterList,const std::string& pageOrderToVerify) {
    auto pages = parseCsvLineForNum(pageOrderToVerify);
    auto rItr = pages.rbegin();
    std::vector<int> prevs{};
    while(rItr != pages.rend()) {
        for(const auto& p : prevs) {
            if(std::find(masterList[*rItr].after.begin(),masterList[*rItr].after.end(),p) == masterList[*rItr].after.end()) {
                return false;
            }
        }
        prevs.push_back(*rItr);
        rItr++;
    }
    return true;
}

std::vector<int> reorder(const std::vector<Node>& masterList,const std::string& pageOrderToVerify) {
    auto pages = parseCsvLineForNum(pageOrderToVerify);
    auto i = 0;
    while(i<pages.size()-1) {
        auto first = pages[i];
        auto second = pages[i+1];
        auto itr = std::find(masterList[first].after.begin(),masterList[first].after.end(),second);
        if(itr == masterList[first].after.end()) {
            //Order not good
            std::swap(pages[i],pages[i+1]);
            i=0;
        } else {
            //order is good
            i++;
        }
    }
    return pages;
}

}
