//
//  064.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/17/15.
//  Copyright © 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();

        vector<int> t {grid[0][0]};
        cout << t[0] << ' ';
        for (int j = 1; j < n; j++) {
            t.push_back(t[j-1]+grid[0][j]);
            cout << t[j] << ' ';
        }
        cout << '\n';

        for (int i = 1; i < m; i++) {
            t[0] = t[0]+grid[i][0];
            cout << t[0] << ' ';
            for (int j = 1; j < n; j++) {
                t[j] = min(t[j-1], t[j]) + grid[i][j];
                cout << t[j] << ' ';
            }
            cout << '\n';
        }
        return t[n-1];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 064 Minimum Path Sum, C++ ...\n\n";
    Solution sol;

    vector<vector<int>> grid {
        //vector<int> {1,2,3},
        //vector<int> {4,5,6}
        vector<int> {1,2},
        vector<int> {5,6},
        vector<int> {1,1}
    };
    
    int r = sol.minPathSum(grid);
    cout << r;
    
    return 0;
}