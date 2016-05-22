//
//  268.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/21/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <climits>
using namespace std;

class Solution {
public:
    int missingNumber0(vector<int>& nums) {
        long int n = (int)nums.size();
        return (int)((1+n)*n/2 - accumulate(nums.begin(), nums.end(), 0));
    }
    int missingNumber(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            ret += i+1 - nums[i];
        }
        return ret;
    }
    int missingNumber2(vector<int>& nums) {	// bit manipulation
        int mask = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            mask ^= (i+1) ^ nums[i];
        }
        return mask;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 268. Missing Number, C++ ...\n\n";
    Solution sol;

    vector<int> nums {3,0,1};

    int r0 = sol.missingNumber0(nums);
    cout << r0 << '\n';

    int r1 = sol.missingNumber(nums);
    cout << r1 << '\n';
    
    int r = sol.missingNumber2(nums);
    cout << r << '\n';
    
    return 0;
}