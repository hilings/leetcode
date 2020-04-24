//
//  441_Arranging_Coins.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/15/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        // k*(k+1) <= n, then k <= sqrt...
        return (int)((sqrt(8*(long)n+1)-1)/2);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 441. Arranging Coins, C++ ...\n\n";
    Solution sol;
    int n = 1804289383; // 60070
    int r = sol.arrangeCoins(n);
    cout << r << '\n';

    return 0;
}
