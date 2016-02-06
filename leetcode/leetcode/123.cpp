//
//  123.cpp
//  leetcode
//
//  Created by Hang Zhang on 2/5/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> & prices) {
        if (prices.empty())
            return 0;
        vector<int> maxTilEnd (prices.size(), prices.back());
        for (int i = (int)prices.size()-2; i >= 0; i--)
            maxTilEnd[i] = max(maxTilEnd[i+1], prices[i]);
        int lowest = prices.front(), maxA = 0, maxSoFar = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < lowest)
                lowest = prices[i];
            else if (prices[i] - lowest > maxSoFar)
                maxSoFar = prices[i]-lowest;
            maxA = max(maxA, maxSoFar+maxTilEnd[i]-prices[i]);
        }
        return maxA;
    }

    int maxProfit2(vector<int>& prices) {
        int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;
        for (auto a: prices) {
            sell2 = max(sell2, buy2+a);
            buy2 = max(buy2, sell1-a);
            sell1 = max(sell1, buy1+a);
            buy1 = max(buy1, -a);
        }
        return sell2;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 123 Best Time to Buy and Sell Stock III, C++ ...\n\n";
    Solution sol;
    
    vector<int> prices {1,2,3,2,4,1,4};
    int r = sol.maxProfit2(prices);
    cout << r << '\n';
    
    
    return 0;
}