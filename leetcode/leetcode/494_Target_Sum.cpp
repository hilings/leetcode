//
//  494_Target_Sum.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/7/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
    void dfs(vector<int>& nums, int S, int i, int sum, int& r) {    // 0 brutal force
        if (i == nums.size()) {
            if (sum == S) {
                r++;
            }
        } else {
            dfs(nums, S, i+1, sum+nums[i], r);
            dfs(nums, S, i+1, sum-nums[i], r);
        }
    }
    int subsetSum(vector<int>& nums, int target) {  // 2 subsetSum
        vector<int> dp (target+1, 0);
        dp[0] = 1;
        for (int a: nums) {
            for (int k = target; k >= a; k--) {
                dp[k] += dp[k-a];
            }
        }
        return dp[target];
    }
public:
    int findTargetSumWays0(vector<int>& nums, int S) {
        int r = 0;
        dfs(nums, S, 0, 0, r);
        return r;
    }

    int findTargetSumWays(vector<int>& nums, int S) {   // 2D array dp
        int n = (int)nums.size();
        vector<vector<int>> dp (n, vector<int> (2001, 0));
        dp[0][nums[0]+1000] = 1;
        dp[0][-nums[0]+1000] += 1;
        for (int i = 1; i < n; i++) {
            for (int sum = -1000; sum <= 1000; sum++) {
                if (dp[i-1][sum+1000] > 0) {
                    dp[i][sum+nums[i]+1000] += dp[i-1][sum+1000];
                    dp[i][sum-nums[i]+1000] += dp[i-1][sum+1000];
                }
            }
        }
        return S > 1000 ? 0 : dp[n-1][S+1000];
    }

    int findTargetSumWays2(vector<int>& nums, int S) {   // subsetSum == target
        /*
         P + N = accum
         P - N = S
         P = (S + accum) / 2
         problem equivalent to finding a subset P whose sum = (S+accum)/2
         */
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < S || (S + sum) % 2 == 1) {
            return 0;
        }
        return subsetSum(nums, (S + sum) / 2);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 494. Target Sum, C++ ...\n\n";
    Solution sol;

    vector<int> nums {1,1,1,1,1};
    int S = 3;

    int r0 = sol.findTargetSumWays0(nums, S);
    cout << r0 << '\n';

    int r = sol.findTargetSumWays(nums, S);
    cout << r << '\n';

    int r2 = sol.findTargetSumWays2(nums, S);
    cout << r2 << '\n';

    return 0;
}
