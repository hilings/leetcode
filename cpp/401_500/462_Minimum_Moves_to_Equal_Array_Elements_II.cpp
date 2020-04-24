//
//  462_Minimum_Moves_to_Equal_Array_Elements_II.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/27/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int r = 0, m = nums[nums.size()/2];
        for (int a: nums) {
            r += abs(a - m);
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 462. Minimum Moves to Equal Array Elements II, C++ ...\n\n";
    Solution sol;

    vector<int> nums {1,2,3};
    int r = sol.minMoves2(nums);
    cout << r << '\n';

    return 0;
}
