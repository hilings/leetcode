//
//  464_Can_I_Win.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/28/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool helper(int n, int t, int k, vector<int>& dp) {
        // k is bitmap of integer availability, 0 = available, 1 = used
        // dp is map of subproblem result so far
        if (dp[k] != 0) {
            return dp[k] > 0;
        }
        if (t <= 0) {   // last turn won already
            return false;
        }
        for (int i = 1; i <= n; i++) {
            if (!(k & (1<<i)) && !helper(n, t-i, k|(1<<i), dp)) {
                dp[k] = 1;
                return true;
            }
        }
        dp[k] = -1;
        return false;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) {
            return true;
        }
        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (sum < desiredTotal) {
            return false;
        } else if (sum == desiredTotal) {
            return maxChoosableInteger % 2 == 1;
        }
        vector<int> dp (1<<(maxChoosableInteger+1), 0);
        return helper(maxChoosableInteger, desiredTotal, 0, dp);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 464. Can I Win, C++ ...\n\n";
    Solution sol;

    int maxChoosableInteger = 10, desiredTotal = 11;    // flse

    maxChoosableInteger = 18;
    desiredTotal = 79;

    bool r = sol.canIWin(maxChoosableInteger, desiredTotal);
    cout << (r ? "true" : "false") << '\n';

    return 0;
}
