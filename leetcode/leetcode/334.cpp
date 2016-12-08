//
//  334.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/7/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool increasingTriplet0(vector<int>& nums) {
        if (nums.size() < 3)
            return false;
        vector<int> cache {nums.front()};
        vector<int> cache2;
        for (int i = 1; i < nums.size(); i++) {
            if (cache.size() == 1) {
                if (nums[i] > cache.back()) {
                    cache.push_back(nums[i]);
                } else {
                    cache.back() = nums[i];
                }
            } else { // cache.size() == 2
                if (nums[i] > cache.back()) {
                    return true;
                } else if (nums[i] > cache.front()) {
                    cache.back() = nums[i];
                } else if (cache2.empty()) {
                    cache2.push_back(nums[i]);
                } else if (nums[i] > cache2.back()) {
                    cache.front() = cache2.front();
                    cache.back() = nums[i];
                    cache2.clear();
                } else {
                    cache2.back() = nums[i];
                }
            }
        }
        return false;
    }
    bool increasingTriplet(vector<int>& nums) {
        int f1 = INT_MAX, f2 = INT_MAX;
        for (int a: nums) {
            if (a <= f1) {
                f1 = a;
            } else if (a <= f2) {
                f2 = a;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 334. Increasing Triplet Subsequence, C++ ...\n\n";
    Solution sol;
    
    vector<int> nums {
        //1,2,3,4,5	// true
        //5,4,3,2,1	// false
        //3,4,1,5	// true
        2,4,-2,-3	// false
    };
    
    bool r0 = sol.increasingTriplet0(nums);
    cout << (r0 ? "true" : "false") << '\n';
    
    bool r = sol.increasingTriplet(nums);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}
