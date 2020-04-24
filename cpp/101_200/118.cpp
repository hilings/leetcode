//
//  118.cpp
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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        if (numRows == 0)
            return v;
        v.push_back(vector<int> {1});
        for (int i = 1; i < numRows; i++) {
            vector<int> tv {1};
            for (int j = 1; j < v[i-1].size(); j++)
                tv.push_back(v[i-1][j-1]+v[i-1][j]);
            tv.push_back(1);
            v.push_back(tv);
        }
        return v;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 118 Pascal's Triangle, C++ ...\n\n";
    Solution sol;

    int numRows = 5;
    vector<vector<int>> r = sol.generate(numRows);

    for (auto v: r) {
        for (auto a: v) {
            cout << a << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}