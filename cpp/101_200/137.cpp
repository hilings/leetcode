//
//  137.cpp
//  leetcode
//
//  Created by Hang Zhang on 2/25/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int c: nums) {
            b = b ^ c & ~a;
            a = a ^ c & ~b;
        }
        return b;
    }
    int singleNumber2(vector<int>& nums) {
        unordered_map<int,int> um (nums.size());
        for (int a: nums) {
            if (um.find(a) == um.end()) {
                um[a] = 1;
            } else {
                um[a]++;
            }
        }
        for (auto a: um) {
            if (a.second == 1)
                return a.first;
        }
        return 0;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 137. Single Number II, C++ ...\n\n";
    Solution sol;
    
    vector<int> nums {1,2,4,1,2,1,2};
    
    int r = sol.singleNumber2(nums);
    cout << r << '\n';
    
    return 0;
}