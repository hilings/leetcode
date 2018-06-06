//
//  485_Max_Consecutive_Ones.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/4/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int r = 0;
        for (int i = 0, j; i < nums.size(); i = j) {
            for (; i < nums.size() && nums[i] == 0; i++);
            for (j = i; j < nums.size() && nums[j] == 1; j++);
            r = max(r, j-i);
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 485. Max Consecutive Ones, C++ ...\n\n";
    Solution sol;

    vector<int> nums {1,1,0,1,1,1};
    int r = sol.findMaxConsecutiveOnes(nums);
    cout << r << '\n';

    return 0;
}
