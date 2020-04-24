//
//  153.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/3/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        return solve(nums, 0, (int)nums.size()-1);
    }
    int solve(vector<int>& nums, int i, int j) {
        if (nums[i] <= nums[j])
            return nums[i];
        int m = (i + j) / 2;
        return nums[i] <= nums[m] ? solve(nums, m+1, j) : solve(nums, i, m);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 153. Find Minimum in Rotated Sorted Array, C++ ...\n\n";
    Solution sol;

    vector<int> nums {2,4,5,6,7,0,1};

    int r = sol.findMin(nums);
    cout << r << '\n';
    
    return 0;
}