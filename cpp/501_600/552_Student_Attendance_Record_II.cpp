//
//  552_Student_Attendance_Record_II.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/10/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int checkRecord0(int n) {
        vector<vector<long>> dp (n+1, vector<long> (7, 0));
        dp[1] = {1,0,1,1,0,0,0};
        int m = 1000000007;
        for (int i = 2; i <= n; i++) {
            printf("\ni = %d\n", i);
            dp[i] = {
                dp[i-1][0] + dp[i-1][3] + dp[i-1][5],
                dp[i-1][1] + dp[i-1][2] + dp[i-1][4] + dp[i-1][6],
                dp[i-1][0] + dp[i-1][3] + dp[i-1][5],
                dp[i-1][0],
                dp[i-1][1] + dp[i-1][2],
                dp[i-1][3],
                dp[i-1][4]
            };
            for (int j = 0; j < 7; j++) {
                if (dp[i][j] >= m) {
                    dp[i][j] %= m;
                }
                cout << dp[i][j] << '\n';
            }
        }
        return accumulate(dp[n].begin(), dp[n].end(), (long)0) % m;
    }

    int checkRecord(int n) {
        vector<long> dp = {1,0,1,1,0,0,0};
        int m = 1000000007;
        for (int i = 2; i <= n; i++) {
            vector<long> tmp {
                dp[0] + dp[3] + dp[5],
                dp[1] + dp[2] + dp[4] + dp[6],
                dp[0] + dp[3] + dp[5],
                dp[0],
                dp[1] + dp[2],
                dp[3],
                dp[4]
            };
            for (int j = 0; j < 7; j++) {
                dp[j] = tmp[j] %= m;
            }
        }
        return accumulate(dp.begin(), dp.end(), (long)0) % m;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 552. Student Attendance Record II, C++ ...\n\n";
    Solution sol;

    int n = 2;  // 8
    n = 3;  // 19
    n = 4;  // 39
    n = 5;  // 94
    n = 25; // 76585973
    n = 26; // 146210464
    n = 27; // 278757449
    n = 28; // 530803311
    n = 29; // 9569297
    n = 30; // 918080153
    n = 32; // 902845575
    n = 33; // 77069536
    n = 35; // 815593497
    n = 40; // 27329510
    n = 100; // 985598218

    int r0 = sol.checkRecord0(n);
    cout << r0 << "\n\n";

    int r = sol.checkRecord(n);
    cout << r << '\n';

    return 0;
}
