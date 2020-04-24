//
//  213.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/25/16.
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
        int res1 = 0, res2 = 0;
        for (int i = 0, prev1 = 0, prev2 = 0; i < nums.size()-1; i++) {
            res1 = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = res1;
        }
        for (int i = 1, prev1 = 0, prev2 = 0; i < nums.size(); i++) {
            res2 = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = res2;
        }
        return max(res1, res2);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 213. House Robber II, C++ ...\n\n";
    Solution sol;
    
    vector<int> nums {1,5,3,2,6,4};
    int r = sol.rob(nums);
    cout << r << '\n';
    
    return 0;
}