//
//  063.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/16/15.
//  Copyright © 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = (int)obstacleGrid.size();
        int n = (int)obstacleGrid[0].size();

        vector<int> t (n, 0);
        t[0] = 1 - obstacleGrid[0][0];

        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1)
                t[0] = 0;
            for (int j = 1; j < n; j++)
                t[j] = obstacleGrid[i][j] == 1 ? 0 : t[j-1]+t[j];
        }
        return t[n-1];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 063 Unique Paths II, C++ ...\n\n";
    Solution sol;

    vector<vector<int>> obstacleGrid {
        vector<int> {0,0,0},
        vector<int> {0,1,0},
        vector<int> {0,0,0}
    };
    
    int r = sol.uniquePathsWithObstacles(obstacleGrid);
    cout << r;
    
    return 0;
}
