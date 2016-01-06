//
//  078.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/5/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void printV(vector<int> v) {
    cout << "[";
    if (!v.empty())
        cout << v.front();
    for (size_t i = 1; i < v.size(); i++) {
        cout << ',' << v[i];
    }
    cout << "]\n";
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> m;
        int f = pow(2, nums.size());
        for (size_t i = 0; i < f; i++) {
            vector<int> t;
            for (size_t j = 0; j < nums.size(); j++) {
                if (1<<j & i) {
                    t.push_back(nums[j]);
                }
            }
            m.push_back(t);
        }
        return m;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 078 Subsets, C++ ...\n\n";
    Solution sol;
    
    vector<int> nums {4,1,0};
    vector<vector<int>> r = sol.subsets(nums);
    
    for (auto v: r) {
        printV(v);
    }
    
    return 0;
}