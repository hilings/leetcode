//
//  dp.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/27/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
//#include <deque>
//#include <stack>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string& s1, string& s2) {
        int m = (int)s1.size(), n = (int)s2.size();
        vector<vector<int>> matrix (m, vector<int> (n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int left = j-1 >= 0 ? matrix[i][j-1] : 0;
                int up = i >= 1 ? matrix[i-1][j] : 0;
                int upleft = (i-1 >= 0 && j-1 >= 0) ? matrix[i-1][j-1] : 0;
                matrix[i][j] = s1[i] == s2[j] ? upleft+1 : max(left, up);
            }
        }

        cout << "  ";
        for (char c: s2) {
            cout << c << ' ';
        }
        cout << '\n';

        for (int i = 0; i < m; i++) {
            cout << s1[i] << ' ';
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << ' ';
            }
            cout << '\n';
        }

        vector<char> lcs;
        for (int j = n-1, i = m-1; i >= 0 && j >= 0; ) {
            if (s1[i] == s2[j]) {
                lcs.push_back(s1[i]);
                i--;
                j--;
            } else if (i == 0 || (j-1 >= 0 && matrix[i-1][j] <= matrix[i][j-1])) {
                j--;
            } else {
                i--;
            }
        }

        // go backwards for longestCommonSubsequence
        reverse(lcs.begin(), lcs.end());
        for (char c: lcs) {
            cout << c << ' ';
        }
        cout << '\n';

        return matrix[m-1][n-1];
    }

    vector<int> longestIncreasingSubsequence(vector<int>& v) {
        vector<int> r;
        for (int a: v) {
            if (r.empty() || a > r.back()) {
                r.push_back(a);
            } else {
                auto it = lower_bound(r.begin(), r.end(), a);
                r[it - r.begin()] = a;
            }
        }
        return r;
    }

    int longestCommonSubstring(string& s1, string& s2) {
        int lcs = 0, m = (int)s1.size(), n = (int)s2.size(), index = -1;
        vector<vector<int>> matrix (m, vector<int> (n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (s1[i] == s2[j]) {
                    matrix[i][j] = (i==0 || j==0) ? 1 : matrix[i-1][j-1]+1;
                    if (matrix[i][j] > lcs) {
                        lcs = matrix[i][j];
                        index = i;
                    }
                }
            }
        }
        if (index > -1) {
            cout << s1.substr(index+1-lcs, lcs) << '\n';
        }
        return lcs;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 000 XXX, C++ ...\n\n";
    Solution sol;

    cout << "\nlongest Common Subsequence\n";
    string s1 = "XMJYAUZ";
    string s2 = "MZJAWXU";

    int r = sol.longestCommonSubsequence(s1, s2);
    cout << r << '\n';

    cout << "\nlongest Increasing Subsequence\n";
    vector<int> v_lis {5,2,7,4,3,8};
    vector<int> lis = sol.longestIncreasingSubsequence(v_lis);
    for (int a: lis) {
        cout << a << ' ';
    }
    cout << '\n';

    cout << "\nlongest Common Substring\n";
    string s3 = "ABCAB";
    string s4 = "CABA";
    int r2 = sol.longestCommonSubstring(s3, s4);
    cout << r2 << '\n';
    
    return 0;
}
