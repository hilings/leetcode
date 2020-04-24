//
//  073.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/1/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void printM(vector<vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.front().size(); j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        size_t m = matrix.size(), n = matrix.front().size();
        bool row = false, column = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0 ; j < n; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0)
                        row = true;
                    if (j == 0)
                        column = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (size_t i = 1; i < m; i++) {
            for (size_t j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if (row) {
            for (size_t j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if (column) {
            for (size_t i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 073 Set Matrix Zeroes, C++ ...\n\n";
    Solution sol;

    vector<vector<int>> matrix {
        vector<int> {0,2,3},
        vector<int> {4,0,6},
        vector<int> {7,8,9}
    };

    printM(matrix);
    sol.setZeroes(matrix);
    printM(matrix);

    return 0;
}