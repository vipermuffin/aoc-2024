//
//  Advent of Code 2024 Solutions: Day 9
//
//  https://adventofcode.com/2024
//
//  Created by vipermuffin on 12/09/2024.
//  Copyright © 2024 vipermuffin. All rights reserved.
//

#include "Day09.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
//#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <sstream>


using namespace std;
namespace AocDay09 {
    int64_t calcChecksum(const std::list<block_t>&);

    static const std::string InputFileName = "Day09.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto bList = buildList(input.front());
        auto cksum = increaseFrag(bList);
        return to_string(cksum);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto bList = buildList(input.front());
        auto cksum = defrag(bList);
        return to_string(cksum);
    }

std::list<block_t> buildList(const std::string& input) {
    list<block_t> bl{};
    
    auto itr = input.begin();
    int id{0};
    
    while(itr != input.end()) {
        //Populate File blocks
        int val = static_cast<int>(*itr - '0');
        for(int i = 0; i < val;i++) {
            bl.emplace_back(id,i,val);
        }
        id++;
        itr++;
        //Populate free space
        if(itr != input.end()) {
            val = static_cast<int>(*itr - '0');
            for(int i = 0; i < val;i++) {
                bl.emplace_back(-1,-1,val);
            }
            itr++;
        }
    }
    
    return bl;
}

std::string printList(const std::list<block_t>& bList) {
    stringstream ss{};
    for(const auto& b : bList) {
        if(b.fileId >= 0) {
            ss << b.fileId;
        } else {
            ss << '.';
        }
    }
    return ss.str();
}

int64_t calcChecksum(const std::list<block_t>&fs) {
    int64_t checksum{0};
    int i = 0;
    for(const auto& b : fs) {
        if(b.fileId >= 0) {
            checksum += i*b.fileId;
        }
        i++;
    }
    
    return checksum;
}
int64_t increaseFrag(std::list<block_t>& fs) {
    auto itr = fs.begin();
    auto rItr = std::prev(fs.end());
    bool notDone = true;
    while(notDone && itr != fs.end() && rItr != fs.begin() && rItr != itr) {
        //Find next empty block
        while(itr != fs.end() && itr->fileId >= 0) {
            std::advance(itr, 1);
        }
        
        //Find next non-empty block
        while(rItr != fs.begin() && rItr != itr && rItr->fileId < 0) {
            std::advance(rItr,-1);
        }
        if(itr->fileId == rItr->fileId && rItr->blockId == itr->blockId) {
            notDone = false;
        } else {
            std::swap(*itr,*rItr);
        }
    }
    
    return calcChecksum(fs);
}

int64_t defrag(std::list<block_t>& fs) {
    auto itr = fs.begin();
    auto rItr = std::prev(fs.end());
    //Assumes last block is not an empty one
    int nextVal = rItr->fileId;
    
    //Build list of free space
    vector<std::pair<size_t,list<block_t>::iterator>> freeSpace;
    while(itr != fs.end()) {
        while(itr != fs.end() && itr->fileId >= 0) {
            std::advance(itr, 1);
        }
        if(itr != fs.end()) {
            auto freeSz = itr->size;
            freeSpace.push_back(make_pair(freeSz,itr));
            std::advance(itr, freeSz);
        }
    }
//    cout << printList(fs) << endl;
    bool notDone = true;
    while(notDone && rItr != fs.begin()) {
        //Find next empty block
      
        //Find next non-empty block
        while(rItr != fs.begin() && rItr->fileId != nextVal) {
            std::advance(rItr,-1);
        }
        
        if(nextVal == 0 || fs.begin() == rItr) {
            notDone = false;
        } else {
            auto sz = rItr->size;
            auto vItr = freeSpace.begin();
            while(vItr != freeSpace.end() && vItr->first < sz) {
                vItr++;
            }
            if(vItr != freeSpace.end()) {
                //Free space found
                if(std::distance(fs.begin(), vItr->second) < std::distance(fs.begin(),rItr)) {
                    std::advance(rItr, -static_cast<int>(sz-1));
                    itr = vItr->second;
                    for(auto i = 0; i < sz; i++) {
                        std::swap(*itr,*rItr);
                        itr++;
                        rItr++;
                    }
                    vItr->first -= sz;
                    if(vItr->first > 0) {
                        vItr->second = itr;
                    }
                }
            }
            nextVal--;
        }
    }
    return calcChecksum(fs);
}
}
