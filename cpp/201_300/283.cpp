//
//  283.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/24/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int inz = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] == 0)
                continue;
            if (inz < i)
                swap(nums[inz], nums[i]);
            inz++;
        }
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 283. Move Zeroes, C++ ...\n\n";
    Solution sol;

    vector<int> nums {0,1,0,3,12};
    sol.moveZeroes(nums);
    
    for (int a: nums) {
        cout << a << ' ';
    }
    
    return 0;
}