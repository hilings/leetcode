//
//  376.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/9/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int nextup = 0, ret = 1;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] == nums[i-1])
                continue;
            if (nextup == 0)
                nextup = nums[i] > nums[i-1] ? 1 : -1;
            if ((nextup == 1) ^ (nums[i] < nums[i-1])) {
                ret++;
                nextup = -1*nextup;
            }
        }
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 376. Wiggle Subsequence, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        //1,4,7,2,5	// 4
        1,7,4,5,5	// 4

        //1,7,4,9,2,5	// 6
        //1,17,5,10,13,15,10,5,16,8	// 7
        //1,2,3,4,5,6,7,8,9	// 2
    };
    int r = sol.wiggleMaxLength(nums);
    cout << r << '\n';
    
    return 0;
}
