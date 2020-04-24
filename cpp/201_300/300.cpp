//
//  300.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/31/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS0(vector<int>& nums) {	// dp
        vector<int> vl;
        int ret = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            int cur = 1;
            for (int j = i-1; j >= 0; j--) {
                if (nums[j] < nums[i])
                    cur = max(cur, vl[j]+1);
            }
            vl.push_back(cur);
            ret = max(ret, cur);
        }
        return ret;
    }

    int lengthOfLIS(vector<int>& nums) {	// binary search
        if (nums.empty())
            return 0;
        vector<int> v {nums[0]};
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < v[0])
                v[0] = nums[i];
            else if (nums[i] > v.back())
                v.push_back(nums[i]);
            else {
                int left = 0, right = (int)v.size()-1;
                while (left < right) {
                    int mid = left + (right-left)/2;
                    if (nums[i] > v[mid])
                        left = mid + 1;
                    else
                        right = mid;
                }
                v[right] = nums[i];
            }
        }
        return (int)v.size();
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 300. Longest Increasing Subsequence, C++ ...\n\n";
    Solution sol;
    
    //vector<int> nums {10,9,2,5,3,7,101,18};	// 4
    vector<int> nums {1,3,6,7,9,4,10,5,6};	// 6
    
    int r0 = sol.lengthOfLIS0(nums);
    cout << r0 << '\n';
    
    int r = sol.lengthOfLIS(nums);
    cout << r << '\n';
    
    return 0;
}