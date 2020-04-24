//
//  154.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/3/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = (int)nums.size()-1;
        while (i < j) {
            if (nums[i] < nums[j])
                break;
            if (nums[i] == nums[j]) {
                while (j > i && nums[j] == nums[i])
                    j--;
                while (i < j && nums[i+1] == nums[i])
                    i++;
                continue;
            }
            int m = (i + j) / 2;
            if (nums[i] <= nums[m])
                i = m+1;
            else
                j = m;
        }
        return nums[i];
    }

    int findMin0(vector<int>& nums) {
        return solve(nums, 0, (int)nums.size()-1);
    }
    int solve(vector<int>& nums, int i, int j) {
        if (i == j || nums[i] < nums[j])
            return nums[i];
        if (nums[i] == nums[j]) {
            while (j > i && nums[j] == nums[i])
                j--;
            while (i < j && nums[i+1] == nums[i])
                i++;
            return solve(nums, i, j);
        }
        int m = (i + j) / 2;
        return nums[i] <= nums[m] ? solve(nums, m+1, j) : solve(nums, i, m);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 154. Find Minimum in Rotated Sorted Array II, C++ ...\n\n";
    Solution sol;
    
    //vector<int> nums {2,4,5,6,7,7,0,1};
    vector<int> nums {10,1,10,10,10};
    //vector<int> nums {0,0,0,0,0};
    
    int r = sol.findMin(nums);
    cout << r << '\n';
    
    return 0;
}