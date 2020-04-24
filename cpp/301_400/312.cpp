//
//  312.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/25/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins0(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> copy (nums);
            int left = i-1 >= 0 ? nums[i-1] : 1;
            int right = i+1 < nums.size() ? nums[i+1] : 1;
            copy.erase(copy.begin()+i);
            sum = max(sum, left*nums[i]*right + maxCoins(copy));
        }
        return sum;
    }

    int maxCoins(vector<int> &nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = (int)nums.size();
        vector<vector<int>> dp (n, vector<int> (n, 0));

        for (int k = 2; k < n; k++) {
            for (int left = 0; left < n-k; left++) {
                int right = left+k;
                for (int i = left + 1; i < right; i++) {
                    dp[left][right] = max(dp[left][right], nums[left]*nums[i]*nums[right] + dp[left][i] + dp[i][right]);
                }
                //cout << "dp[" << left << "][" << right << "] = " << dp[left][right] << "\n";
            }
        }
        return dp[0][n-1];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 312. Burst Balloons, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        3,1,5,8	// 167
        //1,8,5,3	// 160
        //35,16,83,87,84,59,48,41,20,54	// 1849648
    };
    
    int r0 = sol.maxCoins0(nums);
    cout << r0 << '\n';
    
    int r = sol.maxCoins(nums);
    cout << r << '\n';
    
    return 0;
}