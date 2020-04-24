//
//  463_Island_Perimeter.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/27/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                if (i == 0 || grid[i-1][j] == 0) {
                    r++;
                }
                if (i == grid.size()-1 || grid[i+1][j] == 0) {
                    r++;
                }
                if (j == 0 || grid[i][j-1] == 0) {
                    r++;
                }
                if (j == grid[i].size()-1 || grid[i][j+1] == 0) {
                    r++;
                }
            }
        }
        return r;
    }

    int islandPerimeter2(vector<vector<int>>& grid) {
        int c = 0, r = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    c++;
                    if (i > 0 && grid[i-1][j] == 1) {
                        r++;
                    }
                    if (j > 0 && grid[i][j-1] == 1) {
                        r++;
                    }
                }
            }
        }
        return 4*c - 2*r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 463. Island Perimeter, C++ ...\n\n";
    Solution sol;

    vector<vector<int>> grid {
        vector<int> {0,1,0,0},
        vector<int> {1,1,1,0},
        vector<int> {0,1,0,0},
        vector<int> {1,1,0,0}
    };

    int r = sol.islandPerimeter(grid);
    cout << r << '\n';

    int r2 = sol.islandPerimeter2(grid);
    cout << r2 << '\n';

    return 0;
}
