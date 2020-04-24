//
//  712. Minimum ASCII Delete Sum for Two Strings 712.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/13/19.
//  Copyright © 2019 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = (int)s1.size(), n = (int)s2.size();
        vector<vector<int>> dp (m+1, vector<int> (n+1, 0));
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j-1] + s2[j-1];
        }
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i-1][0] + s1[i-1];
            for (int j = 1; j <= n; j++) {
                dp[i][j] = s1[i-1] == s2[j-1] ? dp[i-1][j-1] : min(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1]);
            }
        }
        return dp[m][n];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 712. Minimum ASCII Delete Sum for Two Strings, C++ ...\n\n";
    Solution sol;

    string s1 = "sea";
    string s2 = "eat";  // 231
    int r = sol.minimumDeleteSum(s1, s2);
    cout << r << '\n';

    s1 = "delete";
    s2 = "leet";
    r = sol.minimumDeleteSum(s1, s2);
    cout << r << '\n';

    return 0;
}
