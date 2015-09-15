//
//  047.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/6/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printV(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> v;
        v.push_back(nums);
        while(next_permutation(nums.begin(), nums.end())) {
            v.push_back(nums);
        }

        return v;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 047 Permutations II, C++ ...\n\n";

    vector<int> nums {-1,-1,0};
    printV(nums);

    Solution sol;
    vector<vector<int>> v = sol.permuteUnique(nums);
    for (int i = 0; i < v.size(); i++) {
        printV(v[i]);
    }

    return 0;
}