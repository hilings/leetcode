//
//  033.cpp
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
    int search(vector<int>& nums, int target) {
        int left = 0, right = (int)nums.size()-1;
        while (left <= right) {
            int mid = (left + right) / 2;
            //cout << left << ' ' << right << '\n';
            if (target < nums[mid])
                target >= nums[left] ^ nums[left] > nums[mid] ? right = mid-1 : left = mid+1;
            else if (target > nums[mid])
                target <= nums[right] ^ nums[mid] > nums[right] ? left = mid+1: right = mid-1;
            else
                return mid;
        }
        return -1;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 033 Search in Rotated Sorted Array, C++ ...\n\n";

    int a[] = {4, 5, 6, 7, 8, 1, 2, 3};
    int target = 8;
    int n = sizeof(a)/sizeof(int);
    vector<int> nums (a, a+n);

    Solution sol;
    cout << sol.search(nums, target) << '\n';

    return 0;
}