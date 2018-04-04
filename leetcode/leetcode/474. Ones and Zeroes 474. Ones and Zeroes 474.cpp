//
//  474. Ones and Zeroes 474. Ones and Zeroes 474.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/2/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> v (m+1, vector<int> (n+1, 0));
        for (string s: strs) {
            int c0 = 0, c1 = 0;
            for (char c: s) {
                c == '0' ? c0++ : c1++;
            }
            for (int i = m; i >= c0; i--) {
                for (int j = n; j >= c1; j--) {
                    v[i][j] = max(v[i][j], v[i-c0][j-c1]+1);
                }
            }
        }
        return v[m][n];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 474. Ones and Zeroes, C++ ...\n\n";
    Solution sol;

    vector<string> strs {
        "10", "0001", "111001", "1", "0"
    };
    int m = 5;
    int n = 3;
    int r = sol.findMaxForm(strs, m, n);
    cout << r << '\n';

    return 0;
}
