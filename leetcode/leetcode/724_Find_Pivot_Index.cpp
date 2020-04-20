//
//  724_Find_Pivot_Index.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/19/20.
//  Copyright © 2020 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
  public:
    int pivotIndex(vector<int> &nums) {
		if (nums.empty()) {
			return -1;
		}
        int left = 0, right = accumulate(nums.begin(), nums.end(), -nums[0]);
        for (int i = 0; i < nums.size(); i++) {
            if (left == right) {
                return i;
            }
            left += nums[i];
            if (i + 1 < nums.size()) {
                right -= nums[i + 1];
            }
        }
        return -1;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 724. Find Pivot Index, C++ ...\n\n";
    Solution sol;

    vector<int> nums{
        // 1, 7, 3, 6, 5, 6

        1, 2, 3

    };

    int r = sol.pivotIndex(nums);
    cout << r << '\n';

    return 0;
}
