//
//  416_partition_equal_subset_sum.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/6/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>	// accumulate
#include <bitset>
using namespace std;

class Solution {
    bool helper(vector<int>& nums, int i, int sum) {	// canPartition0
        //printf("i = %d, sum = %d\n", i, sum);
        if (sum == 0) {
            return true;
        } else if (sum < 0 || i == nums.size()) {
            return false;
        }
        return helper(nums, i+1, sum) || helper(nums, i+1, sum-nums[i]);
    }
public:
    bool canPartition0(vector<int>& nums) {	// DFS
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum/2;
        return sum%2 == 0 && helper(nums, 0, target);
    }

    bool canPartition1(vector<int>& nums) {	// DP, space O(n * target)
        int n = (int)nums.size(), sum = accumulate(nums.begin(), nums.end(), 0), target = sum/2;
        if (sum%2 == 1) {
            return false;
        }
        vector<vector<bool>> v (n, vector<bool> (target+1, false));
        v[0][0] = true;
        if (nums[0] <= target) {
            v[0][nums[0]] = true;
        }
        for (int i = 1; i < n; i++) {
            v[i][0] = true;
            for (int k = 1; k <= target; k++) {
                v[i][k] = v[i-1][k] || (nums[i] <= k && v[i-1][k-nums[i]]);
            }
        }
        return v[n-1][target];
    }

    bool canPartition2(vector<int>& nums) {	// DP, space O(target)
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum/2;
        if (sum%2 == 1) {
            return false;
        }
        vector<bool> v (target+1, false);
        v[0] = true;
        for (int a: nums) {
            for (int k = target; k >= a; k--) {	// from target down to a
                v[k] = v[k] || v[k-a];
            }
        }
        return v[target];
    }

    bool canPartition3(vector<int>& nums) {	// bitset
        bitset<100*200/2+1> bs(1);
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum/2;
        if (sum%2 == 1) {
            return false;
        }
        for (int a: nums) {
            bs |= bs << a;	//
        }
        return bs[target];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 416. Partition Equal Subset Sum, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        //1,5,11,5	// true
        1,2,5
    };
    
    bool r0 = sol.canPartition0(nums);
    cout << (r0 ? "true" : "false") << '\n';
    
    bool r1 = sol.canPartition1(nums);
    cout << (r1 ? "true" : "false") << '\n';
    
    bool r2 = sol.canPartition2(nums);
    cout << (r2 ? "true" : "false") << '\n';
    
    bool r3 = sol.canPartition3(nums);
    cout << (r3 ? "true" : "false") << '\n';
    
    return 0;
}
