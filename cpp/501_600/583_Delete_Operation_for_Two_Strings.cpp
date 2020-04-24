//
//  583_Delete_Operation_for_Two_Strings.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/13/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = (int)word1.size(), n = (int)word2.size();
        if (m == 0 || n == 0) {
            return m+n;
        }
        vector<vector<int>> dp (m, vector<int> (n, 0));
        dp[0][0] = word1[0] == word2[0] ? 1 : 0;
        for (int j = 1; j < n; j++) {
            dp[0][j] = (word1[0] == word2[j] || dp[0][j-1] == 1) ? 1 : 0;
        }
        for (int i = 1; i < m; i++) {
            dp[i][0] = (word1[i] == word2[0] || dp[i-1][0] == 1) ? 1 : 0;
            for (int j = 1; j < n; j++) {
                dp[i][j] = word1[i] == word2[j] ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return m-dp[m-1][n-1] + n-dp[m-1][n-1];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 583. Delete Operation for Two Strings, C++ ...\n\n";
    Solution sol;

    string word1 = "sea";
    string word2 = "eat";

    int r = sol.minDistance(word1, word2);
    cout << r << '\n';

    return 0;
}
