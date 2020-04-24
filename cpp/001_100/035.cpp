//
//  035.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/11/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = (int)nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            target <= nums[mid] ? right = mid : left = mid+1;
        }
        return target > nums[left] ? left + 1 : left;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 035 Search Insert Position, C++ ...\n\n";

    int a[] = {1, 3, 5, 6};
    int target = 8;
    vector<int> nums (a, a+sizeof(a)/sizeof(int));

    Solution sol;
    cout << sol.searchInsert(nums, target);

    return 0;
}