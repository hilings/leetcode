//
//  200.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/23/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void extend(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] == '0' || visited[i][j])
            return;
        visited[i][j] = true;
        extend(grid, visited, i-1, j);
        extend(grid, visited, i+1, j);
        extend(grid, visited, i, j-1);
        extend(grid, visited, i, j+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int M = (int)grid.size(), N = (int)grid[0].size(), ret = 0;
        vector<vector<bool>> visited (M, vector<bool> (N, false));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == '0' || visited[i][j])
                    continue;
                ret++;
                extend(grid, visited, i, j);
            }
        }
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 200. Number of Islands, C++ ...\n\n";
    Solution sol;

    vector<string> grid_0 {
        /*
         "11110",
         "11010",
         "11000",
         "00000"		//1
         */

        ///*
        "11000",
        "11000",
        "00100",
        "00011"		//3
        //*/
    };
    vector<vector<char>> grid;
    for (string s: grid_0) {
        grid.push_back(vector<char> (s.begin(), s.end()));
    }
    
    int r = sol.numIslands(grid);
    cout << r << '\n';
    
    
    return 0;
}