//
//  518_Coin_Change_2.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/2/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp (amount+1, 0);
        dp[0] = 1;
        for (int c: coins) {
            for (int i = c; i <= amount; i++) {
                dp[i] += dp[i-c];
            }
        }
        return dp[amount];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 518. Coin Change 2, C++ ...\n\n";
    Solution sol;

    int amount = 5;
    vector<int> coins {
        1,2,5   // 4
    };

    int r = sol.change(amount, coins);
    cout << r << '\n';

    return 0;
}
