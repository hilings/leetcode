//
//  498_Diagonal_Traverse.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/11/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> r;
        if (matrix.empty()) {
            return r;
        }
        int m = (int)matrix.size(), n = (int)matrix[0].size();
        for (int i = 0, j = 0, d = 1; r.size() < m*n; ) {
            r.push_back(matrix[i][j]);
            if (d == 1 && (i == 0 || j == n-1)) {
                if (j+1 < n) {
                    j++;
                } else {
                    i++;
                }
                d *= -1;
            } else if (d == -1 && (j == 0 || i == m-1)) {
                if (i+1 < m) {
                    i++;
                } else {
                    j++;
                }
                d *= -1;
            } else {
                i -= d;
                j += d;
            }
        }
        return r;
    }
    vector<int> findDiagonalOrder2(vector<vector<int>>& matrix) {
        vector<int> r;
        if (matrix.empty()) {
            return r;
        }
        int m = (int)matrix.size(), n = (int)matrix[0].size();
        for (int i = 0, j = 0, d = 1; r.size() < m*n; ) {
            r.push_back(matrix[i][j]);
            i -= d;
            j += d;
            if (j == n) {
                i += 2;
                j--;
                d *= -1;
            } else if (i == m) {
                i--;
                j += 2;
                d *= -1;
            } else if (i < 0) {
                i++;
                d *= -1;
            } else if (j < 0) {
                j++;
                d *= -1;
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 498. Diagonal Traverse, C++ ...\n\n";
    Solution sol;

    vector<vector<int>> matrix {
        vector<int> {1,2,3},
        vector<int> {4,5,6},
        vector<int> {7,8,9} // 1,2,4,7,5,3,6,8,9

        /*
        vector<int> {1,2,3,4},
        vector<int> {5,6,7,8},
        vector<int> {9,10,11,12} // 1,2,5,9,6,3,4,7,10,11,8,12
         */

        /*
        vector<int> {1,2,3},
        vector<int> {4,5,6},
        vector<int> {7,8,9},
        vector<int> {10,11,12} // 1,2,4,7,5,3,6,8,10,11,9,12
         */
    };

    vector<int> r = sol.findDiagonalOrder(matrix);
    for (int a: r) {
        cout << a << ' ';
    }
    cout << '\n';

    vector<int> r2 = sol.findDiagonalOrder2(matrix);
    for (int a: r2) {
        cout << a << ' ';
    }
    cout << '\n';
    return 0;
}
