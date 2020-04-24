//
//  647_Palindromic_Substrings.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/25/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int r = 0, n = (int)s.size();
        vector<vector<bool>> dp (n, vector<bool> (n, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (s[j] == s[i] && (j+1 >= i-1 || dp[j+1][i-1])) {
                    dp[j][i] = true;
                    r++;
                }
            }
        }
        return r;
    }

    int countSubstrings2(string s) {
        int r = 0, n = (int)s.size();
        for (int i = 0; i < n; i++) {
            for (int left = i, right = i; left >= 0 && right < n && s[left] == s[right]; left--, right++) {
                r++;
            }
            for (int left = i, right = i+1; left >= 0 && right < n && s[left] == s[right]; left--, right++) {
                r++;
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 647. Palindromic Substrings, C++ ...\n\n";
    Solution sol;

    string s = "abc";   // 3
    s = "aaa";  // 6
    s = "aaaaa";    // 15
    s = "fdsklf";   // 6

    int r = sol.countSubstrings(s);
    cout << r << '\n';

    int r2 = sol.countSubstrings2(s);
    cout << r2 << '\n';

    return 0;
}
