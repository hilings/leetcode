//
//  493_Reverse_Pairs.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/7/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int merge(vector<int>& nums, int i, int j) {
        if (i >= j) {
            return 0;
        }
        int m = i + (j-i)/2, r = merge(nums, i, m) + merge(nums, m+1, j);    // both halves are sorted after this step
        for (int p = i, k = m+1; p <= m; p++) {  // merge one nums[p] at a time
            for (; k <= j && nums[p] > 2L * nums[k]; k++);    // count all nums[k] on the right that nums[p] > twice time
            r += k - (m+1);
        }
        inplace_merge(nums.begin()+i, nums.begin()+m+1, nums.begin()+j+1);  // excluding end, see doc
        return r;
    }
public:
    int reversePairs(vector<int>& nums) {
        return merge(nums, 0, (int)nums.size()-1);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 493. Reverse Pairs, C++ ...\n\n";
    Solution sol;

    vector<int> nums {2,4,3,5,1};
    int r = sol.reversePairs(nums);
    cout << r << '\n';

    return 0;
}
