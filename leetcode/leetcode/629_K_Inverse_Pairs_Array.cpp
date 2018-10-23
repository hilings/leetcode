//
//  629_K_Inverse_Pairs_Array.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/22/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int kInversePairs0(int n, int k) {  // bottom up, full
        int maxK = n*(n-1)/2;
        if (k > maxK) {
            return 0;
        } else if (k == 0 || k == maxK) {
            return 1;
        }
        vector<vector<int>> dp (n+1, {});
        dp[1].push_back(1);
        for (int i = 2; i <= n; i++) {
            maxK = i*(i-1)/2;
            for (int j = 0; j <= maxK && j <= k; j++) {
                int sum = 0;
                for (int p = 0; p <= i-1; p++) {
                    if (j-p < 0 || j-p >= dp[i-1].size()) {
                        continue;
                    }
                    sum += dp[i-1][j-p];
                }
                dp[i].push_back(sum);
                printf("%d %d: %d\n", i, j, dp[i][j]);
            }
            cout << '\n';
        }
        return dp[n][k];
    }

    int kInversePairs(int n, int k) {   // bottom up, nkk
        int maxK = n*(n-1)/2;
        if (k > maxK) {
            return 0;
        } else if (k == 0 || k == maxK) {
            return 1;
        }
        vector<vector<int>> dp (n+1, vector<int> (k+1, 0));
        dp[1][0] = 1;
        int M = 1000000007;
        for (int i = 2; i <= n; i++) {
            int maxK = i*(i-1)/2;
            for (int j = 0; j <= k && j <= maxK; j++) {
                long sum = 0;
                for (int p = j; p >= 0 && p >= j - (i-1); p--) {
                    sum += dp[i-1][p];
                }
                dp[i][j] = sum % M;
            }
        }
        return dp[n][k];
    }

    int kInversePairs2(int n, int k) {   // bottom up, optimized
        int maxK = n*(n-1)/2;
        if (k > maxK) {
            return 0;
        } else if (k == 0 || k == maxK) {
            return 1;
        }
        vector<vector<int>> dp (n+1, vector<int> (k+1, 0));
        dp[1][0] = 1;
        long M = 1000000007;    // otherwise overflow
        for (int i = 2; i <= n; i++) {
            dp[i][0] = 1;
            maxK = i*(i-1)/2;
            for (int j = 1; j <= k && j <= maxK; j++) {
                /*
                 (n,k)   = (n-1,k) + (n-1,k-1) + (n-1,k-2) + ... + (n-1,k-n+1)
                 (n,k-1) =           (n-1,k-1) + (n-1,k-2) + ... + (n-1,k-n+1) + (n-1,k-n)
                 (n,k) = (n-1,k) + (n,k-1) - (n-1,k-n)
                 (i,j) = (i-1,j) + (i,j-1) - (i-1,j-i)  // if j-i >= 0
                 */
                dp[i][j] = (int)((dp[i-1][j] + dp[i][j-1] - (j >= i ? dp[i-1][j-i] : 0) + M) % M);
            }
        }
        return dp[n][k];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 629. K Inverse Pairs Array, C++ ...\n\n";
    Solution sol;

    int n = 4;
    int k = 2;  // 5
    n = 10;
    k = 3;  // 155
    n = 1000;
    k = 1000;   // 663677020

    //int r0 = sol.kInversePairs0(n, k);
    //cout << r0 << "\n\n";

    int r = sol.kInversePairs(n, k);
    cout << r << "\n\n";

    int r2 = sol.kInversePairs2(n, k);
    cout << r2 << "\n\n";

    return 0;
}
