//
//  514_Freedom_Trail.cpp
//  leetcode
//
//  Created by Hang Zhang on 9/29/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findRotateSteps0(string ring, string key) {
        int sizer = (int)ring.size(), sizek = (int)key.size();
        vector<vector<int>> dp (sizek+1, vector<int> (sizer, INT_MAX));
        dp[sizek] = vector<int> (sizer, 0);
        for (int i = sizek-1; i >= 0; i--) {
            for (int j = 0; j < sizer; j++) {
                for (int next = 0; next < sizer; next++) {
                    if (ring[next] == key[i]) {
                        int left = (j-next+sizer) % sizer, right = (next-j+sizer) % sizer, step = min(left, right);
                        dp[i][j] = min(dp[i][j], step + dp[i+1][next]); // minimal steps from here through end
                    }
                }
            }
        }
        for (int i = 0; i < sizek; i++) {
            for (int j = 0; j < sizer; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << '\n';
        }
        return dp[0][0] + sizek;
    }

    int findRotateSteps(string ring, string key) {
        vector<vector<int>> v_c_i (26, vector<int> {});
        int sizer = (int)ring.size(), sizek = (int)key.size();
        for (int j = 0; j < sizer; j++) {   // indices of each char in ring
            v_c_i[ring[j]-'a'].push_back(j);
        }
        vector<vector<int>> dp (sizek+1, vector<int> (sizer, INT_MAX));
        dp[sizek] = vector<int> (sizer, 0);
        for (int i = sizek-1; i >= 0; i--) {
            for (int j = 0; j < sizer; j++) {
                for (int next: v_c_i[key[i]-'a']) {
                    int left = (j-next+sizer) % sizer, right = (next-j+sizer) % sizer, step = min(left, right);
                    dp[i][j] = min(dp[i][j], step + dp[i+1][next]);
                }
            }
        }
        return dp[0][0] + sizek;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 514. Freedom Trail, C++ ...\n\n";
    Solution sol;

    string ring = "godding";
    string key = "gd";  // 4
    //key = "godding";    // 13

    /*
    ring = "nyngl";
    key = "ynlg";    // 19
     */

    int r0 = sol.findRotateSteps0(ring, key);
    cout << r0 << '\n';

    int r = sol.findRotateSteps(ring, key);
    cout << r << '\n';

    return 0;
}
