//
//  576_Out_of_Boundary_Paths.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/13/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    long update(vector<vector<long>>& dp, int m, int n, int p, int q) {
        long r = 0;
        r += p-1 >= 0 ? dp[p-1][q] : 0;
        r += p+1 < m ? dp[p+1][q] : 0;
        r += q-1 >= 0 ? dp[p][q-1] : 0;
        r += q+1 < n ? dp[p][q+1] : 0;
        return r;
    }
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if (N == 0) {
            return 0;
        }
        vector<vector<long>> dp (m, vector<long> (n, 0));
        for (int p = 0; p < m; p++) {
            dp[p][0]++;
            dp[p][n-1]++;
        }
        for (int q = 0; q < n; q++) {
            dp[0][q]++;
            dp[m-1][q]++;
        }
        for (auto v: dp) {
            for (auto a: v) {
                cout << a << ' ';
            }
            cout << '\n';
        }
        long r = dp[i][j], M = 1000000007;
        for (int k = 2; k <= N; k++) {
            vector<vector<long>> nextdp (m, vector<long> (n, 0));
            for (int p = 0; p < m; p++) {
                for (int q = 0; q < n; q++) {
                    nextdp[p][q] = update(dp, m, n, p, q) % M;
                }
            }
            dp = nextdp;
            for (auto v: dp) {
                for (auto a: v) {
                    cout << a << ' ';
                }
                cout << '\n';
            }
            r = (r + dp[i][j]) % M;
        }
        return (int)r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 576. Out of Boundary Paths, C++ ...\n\n";
    Solution sol;

    int m = 2;
    int n = 2;
    int N = 2;
    int i = 0;
    int j = 0;  // 6

    m = 1; n = 3; N = 3; i = 0; j = 1;  // 12
    m = 8; n = 50; N = 23; i = 5; j = 26;   // 914783380
    int r = sol.findPaths(m, n, N, i, j);
    cout << r << '\n';

    return 0;
}
