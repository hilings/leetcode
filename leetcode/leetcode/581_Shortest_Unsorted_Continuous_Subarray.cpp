//
//  581_Shortest_Unsorted_Continuous_Subarray.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/13/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = 10000, right = -1;
        for (int i = 1, imax = 0; i < nums.size(); i++) {
            if (nums[i] >= nums[imax]) {
                imax = i;
            } else {
                right = i;
                printf("right = %d\n", right);
            }
        }
        for (int i = (int)nums.size()-2, imin = (int)nums.size()-1; i >= 0; i--) {
            if (nums[i] <= nums[imin]) {
                imin = i;
            } else {
                left = i;
                printf("left = %d\n", left);
            }
        }
        return left == 10000 ? 0 : right+1 - left;
    }

    int findUnsortedSubarray2(vector<int>& nums) {
        int n = (int)nums.size(), left = 10000, right = -1;
        for (int i = 1, imax = 0, j = n-2, imin = n-1; i < n && j >= 0; i++, j--) {
            if (nums[i] >= nums[imax]) {
                imax = i;
            } else {
                right = i;
            }
            if (nums[j] <= nums[imin]) {
                imin = j;
            } else {
                left = j;
            }
        }
        return left == 10000 ? 0 : right+1 - left;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 581. Shortest Unsorted Continuous Subarray, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        //2, 6, 4, 8, 10, 9, 15   // 5
        //2,3,3,2,4 // 3
        //1,2,4,5,3   // 3
        3,2
    };

    int r = sol.findUnsortedSubarray(nums);
    cout << r << '\n';

    int r2 = sol.findUnsortedSubarray2(nums);
    cout << r2 << '\n';

    return 0;
}
