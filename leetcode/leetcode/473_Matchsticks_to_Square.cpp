//
//  473_Matchsticks_to_Square.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/2/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
    bool dfs(vector<int>& nums, int index, vector<int>& vl, int target) {
        if (index == -1) {
            return vl[0] == vl[1] && vl[1] == vl[2] && vl[2] == vl[3];
        }
        for (int i = 0; i < 4; i++) {
            if (vl[i]+nums[index] > target) {   // one side is too long
                continue;
            }
            bool same = false;
            for (int j = 0; j < i; j++) {
                if (vl[i] == vl[j]) {
                    same = true;
                    break;
                }
            }
            if (same) { // skip same length that has been checked already
                continue;
            }

            vl[i] += nums[index];
            if (dfs(nums, index-1, vl, target)) {
                return true;
            }
            vl[i] -= nums[index];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (nums.size() < 4 || sum % 4 != 0) {
            return false;
        }
        sort(nums.begin(), nums.end());
        vector<int> vl (4, 0);
        return dfs(nums, (int)nums.size()-1, vl, sum/4);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 473. Matchsticks to Square, C++ ...\n\n";
    Solution sol;
    vector<int> nums {1,1,2,2,2};
    bool r = sol.makesquare(nums);
    cout << (r ? "true" : "false") << '\n';

    return 0;
}
