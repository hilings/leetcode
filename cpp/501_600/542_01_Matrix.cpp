//
//  542_01_Matrix.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/9/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return vector<vector<int>> {};
        }
        int m = (int)matrix.size(), n = (int)matrix[0].size();
        vector<vector<int>> r (m, vector<int> (n, INT_MAX));
        vector<int> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ( matrix[i][j] == 0) {
                    r[i][j] = 0;
                    q.push_back(n*i+j);
                }
            }
        }

        for (int k = 0; k < q.size(); k++) {
            int row = q[k]/n, col = q[k]%n;
            for (vector<int> p: vector<vector<int>> {{row-1, col}, {row+1, col}, {row, col-1}, {row, col+1}}) {
                int i = p[0], j = p[1];
                if (i < 0 || i == m || j < 0 || j == n) {
                    continue;
                }
                if (r[i][j] > r[row][col]+1) {
                    r[i][j] = r[row][col]+1;
                    q.push_back(n*i+j);
                }
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 542. 01 Matrix, C++ ...\n\n";
    Solution sol;

    vector<vector<int>> matrix {
        /*
        {0,0,0},
        {0,1,0},
        {0,0,0}
         */

        {0,0,0},
        {0,1,0},
        {1,1,1}
    };

    vector<vector<int>> r = sol.updateMatrix(matrix);
    for (auto v: r) {
        for (int a: v) {
            cout << a << ' ';
        }
        cout << '\n';
    }

    return 0;
}
