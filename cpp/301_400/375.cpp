//
//  375.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/6/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    int dp(vector<vector<int>>& m, int i, int j) {	// dp helper, top down
        if (i >= j)
            return 0;
        if (m[i][j] > 0)
            return m[i][j];
        int r = INT_MAX;
        for (int k = i; k <= j; k++) {
            r = min(r, k + max(dp(m, i, k-1), dp(m, k+1, j)));
        }
        m[i][j] = r;
        return m[i][j];
    }
public:
    int getMoneyAmount(int n) {	// dp, top down
        vector<vector<int>> m (n+1, vector<int> (n+1, 0));
        return dp(m, 1, n);
    }

    int getMoneyAmount2(int n) {	// dp, bottom up
        vector<vector<int>> m (n+1, vector<int> (n+1, 0));
        for (int l = 2; l <= n; l++) {
            for (int i = 1, j = i+l-1; j <= n; i++, j++) {
                int tmp = INT_MAX;
                for (int k = i+1; k < j; k++) {
                    tmp = min(tmp, k + max(m[i][k-1], m[k+1][j]));
                }
                m[i][j] = i+1==j ? i : tmp;
            }
        }
        return m[1][n];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 375. Guess Number Higher or Lower II, C++ ...\n\n";
    Solution sol;
    
    int n = 20;
    int r = sol.getMoneyAmount(n);
    cout << r << '\n';
    
    int r2 = sol.getMoneyAmount2(n);
    cout << r2 << '\n';
    
    return 0;
}
