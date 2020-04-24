//
//  121.cpp
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
        int maxP = 0, low = numeric_limits<int>::max();
        for (size_t i = 0; i < prices.size(); i++) {
            if (prices[i] < low)
                low = prices[i];
            else if (prices[i] - low > maxP)
                maxP = prices[i] - low;
        }
        return maxP;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 121 Best Time to Buy and Sell Stock, C++ ...\n\n";
    Solution sol;

    vector<int> prices {2,3,4,1,2,5};
    int r = sol.maxProfit(prices);
    cout << r << '\n';

    return 0;
}