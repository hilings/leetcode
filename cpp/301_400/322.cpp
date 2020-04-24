//
//  322.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/15/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {	// dp
        vector<int> dp (amount+1, amount+1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin: coins) {
                if (i >= coin && dp[i-coin] <= amount)
                    dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }

    int coinChange2(vector<int>& coins, int amount) {	// dp
        vector<int> dp (amount+1, amount+1);
        dp[0] = 0;
        for (int coin: coins) {
            for (int i = coin; i <= amount; i++) {
                if (dp[i-coin] <= amount)
                    dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 322. Coin Change, C++ ...\n\n";
    Solution sol;

    vector<int> coins {1,2,5};
    int amount = 11;	// 3

    /*
     vector<int> coins {2};
     int amount = 3;	// -1
     
     vector<int> coins {2147483647};
     int amount = 2;	// -1
     */
    
    int r0 = sol.coinChange(coins, amount);
    cout << r0 << '\n';

    int r2 = sol.coinChange2(coins, amount);
    cout << r2 << '\n';

    return 0;
}