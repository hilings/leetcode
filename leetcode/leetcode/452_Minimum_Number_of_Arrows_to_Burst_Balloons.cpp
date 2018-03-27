//
//  452_Minimum_Number_of_Arrows_to_Burst_Balloons.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/23/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(), points.end());
        int r = 0;
        for (int i = (int)points.size()-1, j; i >= 0; i = j) {
            for (j = i-1; j >= 0 && points[j].second >= points[i].first; j--);
            r++;
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 452. Minimum Number of Arrows to Burst Balloons, C++ ...\n\n";
    Solution sol;

    vector<pair<int,int>> points {
        //*
        pair<int,int> (10, 16),
        pair<int,int> (2, 8),
        pair<int,int> (1, 6),
        pair<int,int> (7, 12)   // 2
         //*/
        /*
        pair<int,int> (1,10),
        pair<int,int> (2, 3),
        pair<int,int> (4, 5)    //
         */
    };
    int r = sol.findMinArrowShots(points);
    cout << r << '\n';

    for (auto p: points) {
        printf("(%d, %d)\n", p.first, p.second);
    }
    return 0;
}
