//
//  565_Array_Nesting.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/12/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<bool> v (nums.size(), false);
        int r = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (v[i]) {
                continue;
            }
            int cur = 0;
            for (int next = i; !v[next]; next = nums[next]) {
                v[next] = true;
                cur++;
            }
            r = max(r, cur);
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 565. Array Nesting, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        5,4,0,3,1,6,2
    };

    int r = sol.arrayNesting(nums);
    cout << r << '\n';

    return 0;
}
