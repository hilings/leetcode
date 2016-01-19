//
//  119.cpp
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
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)
            return vector<int> {1};
        vector<int> v {1,1};
        for (int i = 1; i < rowIndex; i++) {
            for (int j = (int)v.size()-1; j > 0; j--)
                v[j] += v[j-1];
            v.push_back(1);
        }
        return v;
    }
};
int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 119 Pascal's Triangle II, C++ ...\n\n";
    Solution sol;

    int rowIndex = 3;
    vector<int> r = sol.getRow(rowIndex);
    for (auto a: r) {
        cout << a << ' ';
    }
    cout << '\n';
    
    return 0;
}