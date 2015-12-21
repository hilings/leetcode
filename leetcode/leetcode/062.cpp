//
//  062.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/16/15.
//  Copyright © 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> t (n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                t[j] += t[j-1];
            }
        }
        return t[n-1];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 062 Unique Paths, C++ ...\n\n";
    Solution sol;

    int m = 3;
    int n = 7;

    int r = sol.uniquePaths(m, n);
    cout << r;

    return 0;
}