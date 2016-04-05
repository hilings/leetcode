//
//  209.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/4/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int length = (int)nums.size()+1, sum = 0;
        for (int i = 0, j = -1; i < (int)nums.size() && j < (int)nums.size(); i++) {
            while (sum < s && j+1 < nums.size())
                sum += nums[++j];
            if (sum >= s && j-i+1 < length)
                length = j-i+1;
            sum -= nums[i];
        }
        return length > nums.size() ? 0 : length;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 209. Minimum Size Subarray Sum, C++ ...\n\n";
    Solution sol;

    int s = 144;
    vector<int> nums {2,3,1,2,4,3};
    
    int r = sol.minSubArrayLen(s, nums);
    cout << r << '\n';
    
    return 0;
}