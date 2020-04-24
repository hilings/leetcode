//
//  447_Number_of_Boomerangs.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/21/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    int dis(pair<int,int> a, pair<int,int> b) {
        return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
    }
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int r = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<int,int> um;  // distance between points[i] and all others
            for (int j = 0; j < points.size(); j++) {
                um[dis(points[i], points[j])]++;
            }
            for (auto p: um) {
                r += p.second*(p.second-1);
            }
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 447. Number of Boomerangs, C++ ...\n\n";
    Solution sol;

    vector<pair<int,int>> points {
        pair<int,int> (0,0),
        pair<int,int> (1,0),
        pair<int,int> (2,0)
    };
    int r = sol.numberOfBoomerangs(points);
    cout << r << '\n';

    return 0;
}
