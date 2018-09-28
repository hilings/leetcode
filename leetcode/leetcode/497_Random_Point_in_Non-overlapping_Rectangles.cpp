//
//  497_Random_Point_in_Non-overlapping_Rectangles.cpp
//  leetcode
//
//  Created by Hang Zhang on 9/17/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
    vector<vector<int>> c_rects;
    vector<int> points {0};
    int np = 0;
public:
    Solution(vector<vector<int>> rects) {
        c_rects = rects;
        for (vector<int> r: rects) {
            np += (r[2]-r[0]+1) * (r[3]-r[1]+1);
            points.push_back(np);
        }
    }

    vector<int> pick() {
        int k = rand() % np;
        int i = (int)(upper_bound(points.begin(), points.end(), k) - points.begin()) - 1;
        k -= points[i];
        int width = c_rects[i][2] - c_rects[i][0] + 1;
        int x = c_rects[i][0] + k % width, y = c_rects[i][1] + k / width;
        return vector<int> {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * vector<int> param_1 = obj.pick();
 */

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 497. Random Point in Non-overlapping Rectangles, C++ ...\n\n";

    vector<vector<int>> rects {
        //vector<int> {1,1,5,5}
        /*
        vector<int> {-2,-2,-1,-1},
        vector<int> {1,0,3,0}
         */

        vector<int> {35330199, -46858448, 35330694, -46856950}
    };
    Solution sol(rects);

    vector<int> r = sol.pick();
    printf("(%d, %d)\n", r[0], r[1]);

    return 0;
}
