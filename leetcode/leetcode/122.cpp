//
//  122.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/18/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        for (size_t i = 1; i < prices.size(); i++)
            if (prices[i] > prices[i-1])
                maxP += prices[i] - prices[i-1];
        return maxP;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 122 Best Time to Buy and Sell Stock II, C++ ...\n\n";
    Solution sol;

    vector<int> prices {1,2,4,3,6};
    int r = sol.maxProfit(prices);
    cout << r << '\n';

    return 0;
}