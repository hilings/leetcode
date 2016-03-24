//
//  198.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/23/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> v {nums[0]};
        if (nums.size() >= 2)
            v.push_back(max(nums[0], nums[1]));
        for (int i = 2; i < nums.size(); i++) {
            v.push_back(max(v[i-2]+nums[i], v[i-1]));
        }
        return v.back();
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 198. House Robber, C++ ...\n\n";
    Solution sol;

    vector<int> nums {1,2,3,4,3,2,1};
    int r = sol.rob(nums);
    cout << r << '\n';
    
    return 0;
}