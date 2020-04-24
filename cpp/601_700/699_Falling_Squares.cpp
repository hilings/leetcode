//
//  699_Falling_Squares.cpp
//  leetcode
//
//  Created by Hang Zhang on 11/8/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        vector<int> z;
        map<int,pair<int,int>> om;  // start index: (width, height)
        int highest = 0;
        for (pair<int,int> square: positions) {
            printf("%d %d\n", square.first, square.second);
            int h = 0;
            for (pair<int,pair<int,int>> p : om) {
                if (p.first < square.first + square.second && square.first < p.first+p.second.first) {  // overlapping
                    h = max(h, p.second.second);
                }
            }
            om[square.first] = pair<int,int> (square.second, h+square.second);
            highest = max(highest, h+square.second);
            z.push_back(highest);
        }
        return z;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 699. Falling Squares, C++ ...\n\n";
    Solution sol;

    vector<pair<int,int>> positions {
        {1, 2},
        {2, 3},
        {6, 1}  // 2,5,5
    };

    vector<int> z = sol.fallingSquares(positions);
    for (int a: z) {
        cout << a << ' ';
    }
    cout << '\n';

    return 0;
}
