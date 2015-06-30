//
//  041.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/17/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive0(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int missing = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < missing)
                continue;
            else if (nums[i] == missing)
                missing++;
            else
                return missing;
        }
        return missing;
    }

    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0 && nums[i] <= nums.size() && nums[i]-1 != i) {
                int tmp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = tmp;
                if (nums[i]-1 < i && nums[nums[i]-1] != nums[i])
                    i--;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            cout << i << nums[i]<<'\n';
            if (nums[i] != i+1)
                return i+1;
        }
        return (int)nums.size()+1;
    }



};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 041 First Missing Positive, C++ ...\n\n";

    int a[] = {1, 1};
    vector<int> nums (a, a + sizeof(a)/sizeof(int));

    Solution sol;
    cout << sol.firstMissingPositive(nums);

    return 0;
}