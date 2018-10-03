//
//  516_Longest_Palindromic_Subsequence.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/1/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = (int)s.size();
        vector<vector<int>> dp (n, vector<int> (n, 0));
        dp[0][0] = s[0] == s[n-1] ? 1 : 0;
        for (int j = 1; j < n; j++) {
            dp[0][j] = (s[0] == s[n-1-j] || dp[0][j-1] == 1) ? 1 : 0;
        }
        for (int i = 1; i < n; i++) {
            dp[i][0] = (s[i] == s[n-1] || dp[i-1][0] == 1) ? 1 : 0;
            for (int j = 1; j < n; j++) {
                dp[i][j] = s[i] == s[n-1-j] ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n-1][n-1];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 516. Longest Palindromic Subsequence, C++ ...\n\n";
    Solution sol;

    string s = "cbbd";  // 2
    s = "bbbab";    // 4

    int r = sol.longestPalindromeSubseq(s);
    cout << r << '\n';

    return 0;
}
