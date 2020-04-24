//
//  016.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/22/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int l = (int)nums.size();
        if (l < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int diff = numeric_limits<int>::max();
        int sum = 0;
        for (int i = 0; i < l - 2; i++) {
            if (i-1 >= 0 && nums[i] == nums[i-1])
                continue;
            int j = i + 1;
            int k = l - 1;
            while (j < k) {
                int t = nums[i] + nums[j] + nums[k];
                int d = abs(t - target);
                if (d < diff) {
                    diff = d;
                    sum = t;
                }
                if (t < target) {
                    j++;
                } else if (t > target) {
                    k--;
                } else {
                    return sum;
                }
            }
        }
        return sum;
    }

    int threeSumClosest2(vector<int>& nums, int target) {
        if (nums.size() < 3) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        long r = nums[0]+nums[1]+nums[2], diff = abs(r-target);
        for (int i = 2; i < nums.size(); i++) {
            for (int j = 0, k = i-1; j < k; ) {
                int sum = nums[j] + nums[k] + nums[i];
                if (sum == target) {
                    return target;
                }
                int d = abs(sum-target);
                if (d < diff) {
                    diff = d;
                    r = sum;
                }
                if (sum > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return (int)r;
    }
};


int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 16. 3Sum Closest, C++ ... ...\n";
    Solution sol;

    vector<int> num {
        //-1,2,1,-4   // 2
        //0,0,0   // 1
        //1,1,-1
        1,1,1,0
    };
    int target = 1;
    target = 0; // 1
    target = 100;    // 3

    int r = sol.threeSumClosest(num, target);
    cout << r << '\n';

    int r2 = sol.threeSumClosest2(num, target);
    cout << r2 << '\n';

    return 0;}
