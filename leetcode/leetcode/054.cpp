//
//  template.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/8/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void printV(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        if (matrix.size() == 0)
            return v;
        push(matrix, v, 0, 0, (int)matrix.size()-1, (int)matrix[0].size()-1);
        return v;
    }
    void push(vector<vector<int>>& matrix, vector<int>& v, int a, int b, int c, int d) {
        if (a > c || b > d)
            return;
        for (int i = b; i <= d; i++)
            v.push_back(matrix[a][i]);
        for (int i = a+1; i <= c; i++)
            v.push_back(matrix[i][d]);
        if (a == c || b == d)
            return;
        for (int i = d-1; i >= b; i--)
            v.push_back(matrix[c][i]);
        for (int i = c-1; i > a; i--)
            v.push_back(matrix[i][b]);
        push(matrix, v, a+1, b+1, c-1, d-1);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 054 Spiral Matrix, C++ ...\n\n";

    const int n = 4;
    const int m = 3;
    int a[][n] = {
        1, 2, 3, 10,
        4, 5, 6, 11,
        7, 8, 9, 12
    };
    vector<vector<int>> matrix;
    for (int i = 0; i < m; i++) {
        matrix.push_back(vector<int> (a[i], a[i]+n));
    }

    Solution sol;
    printV(sol.spiralOrder(matrix));

    return 0;
}