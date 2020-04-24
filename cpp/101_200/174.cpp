//
//  174.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/14/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int M = (int)dungeon.size(), N = (int)dungeon[0].size();
        vector<int> hv (N+1, INT_MAX);
        hv[N-1] = 1;
        for (int i = M-1; i >= 0; i--) {
            for (int j = N-1; j >= 0; j--) {
                hv[j] = max(1, min(hv[j+1], hv[j]) - dungeon[i][j]);
            }
        }
        return hv[0];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 174. Dungeon Game, C++ ...\n\n";
    Solution sol;

    vector<vector<int>> dungeon {
        vector<int> {-2,-3,3},
        vector<int> {-5,-10,1},
        vector<int> {10,30,-5}
    };
    
    int r = sol.calculateMinimumHP(dungeon);
    cout << r << '\n';
    
    return 0;
}