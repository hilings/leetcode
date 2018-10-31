//
//  673_Number_of_Longest_Increasing_Subsequence.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/29/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = (int)nums.size(), len = 1, count = 0;
        vector<pair<int,int>> dp (n, pair<int,int> (1,1));  // longest increasing subsequence ending with nums[i], and its count
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    int cur = dp[j].first+1;
                    if (cur > dp[i].first) {
                        dp[i].first = cur;
                        dp[i].second = dp[j].second;
                    } else if (cur == dp[i].first) {
                        dp[i].second += dp[j].second;
                    }
                }
            }
            if (dp[i].first > len) {
                len = dp[i].first;
                count = dp[i].second;
            } else if (dp[i].first == len) {
                count += dp[i].second;
            }
        }
        return count;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 673. Number of Longest Increasing Subsequence, C++ ...\n\n";
    Solution sol;

    vector<int> nums {
        //1,3,5,4,7   // 2
        //2,2,2,2,2   // 5
        1,2,4,3,5,4,7,2     //3

    };

    int r = sol.findNumberOfLIS(nums);
    cout << r << '\n';

    return 0;
}
