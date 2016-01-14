//
//  096.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/11/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int t[n+1];
        t[0] = 1;
        for (int i = 1; i <= n; i++) {
            t[i] = 0;
            for (int j = 1; j <= i; j++)
                t[i] += t[j-1] * t[i-j];
        }
        return t[n];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 096 Unique Binary Search Trees, C++ ...\n\n";
    Solution sol;

    int n = 19;

    int r = sol.numTrees(n);
    cout << r;

    return 0;
}