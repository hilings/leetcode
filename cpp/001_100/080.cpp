//
//  080.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/5/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void printV(vector<int> v) {
    for (auto a: v) {
        cout << a << ' ';
    }
    cout << '\n';
}

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        size_t i = 2;
        while (i < nums.size()) {
            if (nums[i] == nums[i-1] && nums[i] == nums[i-2])
                nums.erase(nums.begin()+i);
            else
                i++;
        }
        return (int)nums.size();
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 080 Remove Duplicates from Sorted Array II, C++ ...\n\n";
    Solution sol;

    vector<int> nums {1,1,2,2,3};
    int r = sol.removeDuplicates(nums);
    
    cout << r << '\n';
    
    return 0;
}