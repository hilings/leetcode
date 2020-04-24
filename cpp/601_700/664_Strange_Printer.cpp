//
//  664_Strange_Printer.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/26/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        if (s.empty()) {
            return 0;
        }
        string ss = s.substr(0,1);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i-1]) {
                ss += s[i];
            }
        }
        s = ss;
        int n = (int)s.size();
        vector<vector<int>> dp (n, vector<int> (n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for (int l = 2; l <= n; l++) {
            for (int i = 0, j = i+l-1; j < n; i++, j++) {
                dp[i][j] = j-i+1;   // print one char each time, at most len step
                for (int k = i+1; k <= j; k++) {    // divide into two substring, possibly save one step if two tail chars are the same
                    dp[i][j] = min(dp[i][j], s[k-1] == s[j] ? dp[i][k-1] + dp[k][j] - 1 : dp[i][k-1] + dp[k][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 664. Strange Printer, C++ ...\n\n";
    Solution sol;

    string s = "aba";   // 2
    s = "abcbc";    // 4
    s = "baacdddaaddaaaaccbddbcabdaabdbbcdcbbbacbddcabcaaa";    // 19
    // abaaba
    int r = sol.strangePrinter(s);
    cout << r << '\n';

    return 0;
}
