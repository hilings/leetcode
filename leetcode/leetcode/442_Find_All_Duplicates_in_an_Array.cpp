//
//  442_Find_All_Duplicates_in_an_Array.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/16/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> r;
        for (int i = 0; i < nums.size(); i++) {
            int a = abs(nums[i]);
            if (nums[a-1] < 0) {
                r.push_back(a);
            }
            nums[a-1] = -nums[a-1];
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 442. Find All Duplicates in an Array, C++ ...\n\n";
    Solution sol;

    vector<int> nums {4,3,2,7,8,2,3,1}; // 2,3
    vector<int> r = sol.findDuplicates(nums);
    for (int a: r) {
        cout << a << ' ';
    }

    return 0;
}
