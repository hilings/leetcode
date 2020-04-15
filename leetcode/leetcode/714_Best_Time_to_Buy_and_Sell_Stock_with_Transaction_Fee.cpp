//
//  714_Best_Time_to_Buy_and_Sell_Stock_with_Transaction_Fee.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/16/19.
//  Copyright © 2019 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty()) {
            return 0;
        }
        int sold = 0, hold = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            int tmpsold = max(sold, hold+prices[i]-fee);
            int tmphold = max(hold, sold-prices[i]);
            sold = tmpsold;
            hold = tmphold;
        }
        return max(sold, hold);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 714. Best Time to Buy and Sell Stock with Transaction Fee, C++ ...\n\n";
    Solution sol;

    vector<int> prices {1,3,2,8,4,9};
    int fee = 2;
    int r = sol.maxProfit(prices, fee);
    cout << r << '\n';

    return 0;
}
