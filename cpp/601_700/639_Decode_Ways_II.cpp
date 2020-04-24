//
//  639_Decode_Ways_II.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/23/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    long decode1(char& a) {
        if (a == '*') {
            return 9;
        } else if (a == '0') {
            return 0;
        }
        return 1;
    }
    long decode2(char& a, char& b) {
        if (a == '*') {
            return b == '*' ? 15 : (b <= '6' ? 2 : 1);
        } else if (a == '1') {
            return b == '*' ? 9 : 1;
        } else if (a == '2') {
            return b == '*' ? 6 : (b <= '6' ? 1 : 0);
        }
        return 0;
    }
public:
    int numDecodings(string s) {
        int n = (int)s.size(), M = 1000000007;
        vector<int> dp (n, 0);
        dp[0] = decode1(s[0]);
        if (n >= 2) {
            dp[1] = dp[0] * decode1(s[1]) + decode2(s[0], s[1]);
        }
        for (int i = 2; i < n; i++) {
            long sum = dp[i-1] * decode1(s[i]) + dp[i-2] * decode2(s[i-1], s[i]);
            dp[i] = (int)(sum % M);
        }
        return dp[n-1];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 639. Decode Ways II, C++ ...\n\n";
    Solution sol;

    string s = "1*";
    s = "*1*1*0";   // 404
    s = "**********1111111111"; // 133236775
    s = "********************"; // 104671669

    int r = sol.numDecodings(s);
    cout << r << '\n';

    return 0;
}
