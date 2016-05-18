//
//  238.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/16/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> ret (n, 1);
        for (int i = 1; i < n; i++) {
            ret[i] = ret[i-1] * nums[i-1];
        }
        for (int i = n-1; i > 0; i--) {
            ret[i] *= ret[0];
            ret[0] *= nums[i];
        }
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 238. Product of Array Except Self, C++ ...\n\n";
    Solution sol;

    vector<int> nums {1,2,3,4};

    vector<int> r = sol.productExceptSelf(nums);
    for (int a: r) {
        cout << a << ' ';
    }
    
    return 0;
}