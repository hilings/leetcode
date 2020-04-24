//
//  486_Predict_the_Winner.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/4/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if (nums.size() <= 2 || nums.size() % 2 == 0) {
            return true;
        }
        int n = (int)nums.size();
        vector<vector<int>> dp (n, vector<int> (n, 0)); // advantage within range nums[i, j]
        /*
          |0 1 2
         -+-----
         0|1 4 -2
         1|  5 3
         2|    2
         */
        for (int i = n-1; i >= 0; i--) {
            dp[i][i] = nums[i];
            for (int j = i+1; j < n; j++) {
                dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
            }
        }
        return dp[0][n-1] > 0;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 486. Predict the Winner, C++ ...\n\n";
    Solution sol;

    vector<int> nums {1,5,2};
    bool r = sol.PredictTheWinner(nums);
    cout << (r ? "true" : "false") << '\n';

    return 0;
}
