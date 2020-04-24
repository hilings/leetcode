//
//  034.cpp
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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        int left = 0, right = (int)nums.size()-1;
        while (left < right) {
            int mid = (left + right) / 2;
            target <= nums[mid] ? right = mid : left = mid+1;
        }
        if (nums[left] == target)
            v.push_back(left);
        else {
            v.assign(2, -1);
            return v;
        }

        right = (int)nums.size()-1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            target >= nums[mid] ? left = mid : right = mid-1;
        }
        v.push_back(right);
        return v;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 034 Search for a Range, C++ ...\n\n";

    int a[] = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> nums (a, a+sizeof(a)/sizeof(int));

    Solution sol;
    vector<int> v = sol.searchRange(nums, target);
    cout << v[0] << ' ' << v[1];

    return 0;
}