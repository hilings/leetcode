//
//  120.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/18/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (size_t i = 0; i < triangle.size()-1; i++) {
            triangle[i+1].front() += triangle[i].front();
            for (size_t j = 1; j < triangle[i].size(); j++) {
                triangle[i+1][j] += min(triangle[i][j-1], triangle[i][j]);
            }
            triangle[i+1].back() += triangle[i].back();
        }
        int minT = triangle.back().front();
        for (auto a: triangle.back())
            if (a < minT)
                minT = a;
        return minT;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 120 Triangle, C++ ...\n\n";
    Solution sol;

    vector<vector<int>> triangle {
        vector<int> {2},
        vector<int> {3,4},
        vector<int> {6,5,7},
        vector<int> {4,1,8,3}
    };

    int r = sol.minimumTotal(triangle);
    for (auto v: triangle) {
        for (auto a: v) {
            cout << a << ' ';
        }
        cout << '\n';
    }
    cout << r << '\n';
    
    return 0;
}