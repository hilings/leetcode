//
//  template.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/9/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int til = nums[0];
        for (int i = 0; i <= til; i++) {
            if (i+nums[i] > til)
                til = i+nums[i];
            if (til >= nums.size()-1)
                return true;
        }
        return false;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 055 Jump Game, C++ ...\n\n";

    //vector<int> nums {2,3,1,1,4};
    vector<int> nums {3,2,1,0,4};

    Solution sol;

    cout << (sol.canJump(nums) ? "true" : "false") << '\n';

    return 0;
}