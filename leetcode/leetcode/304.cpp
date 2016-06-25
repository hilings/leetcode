//
//  304.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/16/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


class NumMatrix {
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int m = (int)matrix.size(), n = matrix.empty() ? 0 : (int)matrix[0].size();
        sum.push_back(vector<int> (n+1, 0));
        for (int i = 0; i < m; i++) {
            sum.push_back(vector<int> {0});
            for (int j = 0; j < n; j++) {
                sum[i+1].push_back(sum[i][j+1] + sum[i+1][j] - sum[i][j] + matrix[i][j]);
            }
        }
        for (vector<int> v: sum) {
            for (int a: v) {
                cout << a << ' ';
            }
            cout << '\n';
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ret = sum[row2+1][col2+1] - sum[row2+1][col1] - sum[row1][col2+1] + sum[row1][col1];
        cout << ret << '\n';
        return sum[row2+1][col2+1] - sum[row2+1][col1] - sum[row1][col2+1] + sum[row1][col1];
    }
};



int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 304. Range Sum Query 2D - Immutable, C++ ...\n\n";

    // Your NumMatrix object will be instantiated and called as such:
    vector<vector<int>> matrix {
        vector<int> {3,0,1,4,2},
        vector<int> {5,6,3,2,1},
        vector<int> {1,2,0,1,5},
        vector<int> {4,1,0,1,7},
        vector<int> {1,0,3,0,5}
    };

    NumMatrix numMatrix(matrix);

    numMatrix.sumRegion(2, 1, 4, 3);	// 8
    numMatrix.sumRegion(1, 1, 2, 2);	// 11
    numMatrix.sumRegion(1, 2, 2, 4);	// 12
    
    numMatrix.sumRegion(0, 1, 2, 3);	// 19
    numMatrix.sumRegion(1, 2, 3, 4);	// 20
    
    return 0;
}