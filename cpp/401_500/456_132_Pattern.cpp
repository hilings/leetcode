//
//  456_132_Pattern.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/26/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int s3 = INT_MIN;
        stack<int> stk; // store a local descending sequence from right to left
        for (int i = (int)nums.size()-1; i >= 0; i--) {
            if (nums[i] < s3) {
                return true;
            } else {
                while (!stk.empty() && stk.top() < nums[i]) {
                    s3 = stk.top(); // greatest that is less the nums[i] so far
                    stk.pop();
                }
            }
            stk.push(nums[i]);
        }
        return false;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 456. 132 Pattern, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        -2, 1, 1
        //1, 3, 2   true
    };
    bool r = sol.find132pattern(nums);
    cout << (r ? "true" : "false") << '\n';

    return 0;
}
