//
//  329.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/27/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int solve(vector<vector<int>>& matrix, vector<vector<int>>& cache, int i, int j) {
        int rows = (int)matrix.size(), cols = (int)matrix[0].size();
        if (cache[i][j] >= 1)
            return cache[i][j];
        cache[i][j] = 1;
        if (i+1 < rows && matrix[i][j] > matrix[i+1][j])
            cache[i][j] = max(cache[i][j], 1+solve(matrix, cache, i+1, j));
        if (i-1 >= 0 && matrix[i][j] > matrix[i-1][j])
            cache[i][j] = max(cache[i][j], 1+solve(matrix, cache, i-1, j));
        if (j+1 < cols && matrix[i][j] > matrix[i][j+1])
            cache[i][j] = max(cache[i][j], 1+solve(matrix, cache, i, j+1));
        if (j-1 >= 0 && matrix[i][j] > matrix[i][j-1])
            cache[i][j] = max(cache[i][j], 1+solve(matrix, cache, i, j-1));
        return cache[i][j];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return 0;
        int rows = (int)matrix.size(), cols = (int)matrix[0].size();
        vector<vector<int>> cache (rows, vector<int> (cols, 0));
        int myMax = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                myMax = max(myMax, solve(matrix, cache, i, j));
            }
        }
        return myMax;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 329. Longest Increasing Path in a Matrix, C++ ...\n\n";
    Solution sol;

    vector<int> input {
        9,9,4,
        6,6,8,
        2,1,1
    };
    int rows = 3, cols = 3;
    vector<vector<int>> matrix;
    for (int i = 0; i < rows; i++) {
        matrix.push_back(vector<int> (input.begin()+cols*i, input.begin()+cols*(i+1)));
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    
    int r = sol.longestIncreasingPath(matrix);
    cout << r << '\n';
    
    return 0;
}