//
//  704_Binary_Search.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/26/19.
//  Copyright © 2019 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0, j = (int)nums.size()-1; i <= j; ) {
            int mid = (i+j)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (target < nums[mid]) {
                j = mid-1;
            } else {
                i = mid+1;
            }
        }
        return -1;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 704. Binary Search, C++ ...\n\n";
    Solution sol;

    vector<int> nums {-1,0,3,5,9,12};
    int target = 9;

    int r = sol.search(nums, target);
    cout << r << '\n';

    return 0;
}
