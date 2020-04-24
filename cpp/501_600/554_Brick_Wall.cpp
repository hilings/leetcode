//
//  554_Brick_Wall.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/10/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int r = 0;
        unordered_map<int,int> um;
        for (auto v: wall) {
            int sum = 0;
            for (int i = 0; i < v.size()-1; i++) {
                sum += v[i];
                um[sum] = um.find(sum) != um.end() ? um[sum]+1 : 1;
                r = max(r, um[sum]);
            }
        }
        return (int)wall.size() - r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 554. Brick Wall, C++ ...\n\n";
    Solution sol;

    vector<vector<int>> wall {
        {1,2,2,1},
        {3,1,2},
        {1,3,2},
        {2,4},
        {3,1,2},
        {1,3,1,1}
    };

    int r = sol.leastBricks(wall);
    cout << r << '\n';

    return 0;
}
