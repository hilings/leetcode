//
//  674_Longest_Continuous_Increasing_Subsequence.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/29/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int r = 0;
        for (int i = 0, j = 0; i < nums.size(); i=j+1) {
            for (j = i; j+1 < nums.size() && nums[j] < nums[j+1]; j++);
            r = max(r, j-i+1);
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 674. Longest Continuous Increasing Subsequence, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        //1,3,5,4,7   // 3
        2,2,2,2,2   // 1
    };

    int r = sol.findLengthOfLCIS(nums);
    cout << r << '\n';

    return 0;
}
