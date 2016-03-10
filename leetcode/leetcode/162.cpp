//
//  162.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/7/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if ((i+1 < nums.size() && nums[i] <= nums[i+1]) || (i-1 >= 0 && nums[i] <= nums[i-1]))
                continue;
            return i;
        }
        return 0;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 162. Find Peak Element, C++ ...\n\n";
    Solution sol;

    vector<int> nums {1,2,3,1};
    int r = sol.findPeakElement(nums);
    cout << r << '\n';
    
    return 0;
}