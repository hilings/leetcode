//
//  695_Max_Area_of_Island.cpp
//  leetcode
//
//  Created by Hang Zhang on 11/6/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = (int)grid.size(), n = (int)grid[0].size(), z = 0;
        vector<vector<bool>> visited (m, vector<bool> (n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 || visited[i][j]) {
                    continue;
                }
                vector<pair<int,int>> v {pair<int,int> (i,j)};    // queue for dfs
                visited[i][j] = true;   // mark visited as soon as queued
                int t = 0;
                while (!v.empty()) {
                    int ii = v.back().first, jj = v.back().second;
                    v.pop_back();
                    t++;
                    if (ii-1 >= 0 && grid[ii-1][jj] && !visited[ii-1][jj]) {
                        v.push_back(pair<int,int> (ii-1,jj));
                        visited[ii-1][jj] = true;   // so that an item can be queued at most once
                    }
                    if (ii+1 < m && grid[ii+1][jj] && !visited[ii+1][jj]) {
                        v.push_back(pair<int,int> (ii+1,jj));
                        visited[ii+1][jj] = true;
                    }
                    if (jj-1 >= 0 && grid[ii][jj-1] && !visited[ii][jj-1]) {
                        v.push_back(pair<int,int> (ii,jj-1));
                        visited[ii][jj-1] = true;
                    }
                    if (jj+1 < n && grid[ii][jj+1] && !visited[ii][jj+1]) {
                        v.push_back(pair<int,int> (ii,jj+1));
                        visited[ii][jj+1] = true;
                    }
                }
                z = max(z,t);
            }
        }
        return z;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 695. Max Area of Island, C++ ...\n\n";
    Solution sol;

    vector<vector<int>> grid {
        //*
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}     // 6
         //*/

        /*
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,0,1,1},
        {0,0,0,1,1}     // 4
         */
    };

    int z = sol.maxAreaOfIsland(grid);
    cout << z << '\n';

    return 0;
}
