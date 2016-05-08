//
//  216.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/25/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void solve(vector<vector<int>>& ret, vector<int> sol, int k, int n, int t) {
        if (k == 0 && n == 0)
            ret.push_back(sol);
        if (k == 0 || n == 0)
            return;
        for (int i = t; i <= 9; i++) {
            sol.push_back(i);
            solve(ret, sol, k-1, n-i, i+1);
            sol.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        solve(ret, vector<int> {}, k, n, 1);
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 216. Combination Sum III, C++ ...\n\n";
    Solution sol;

    int k = 3, n = 9;
    vector<vector<int>> r = sol.combinationSum3(k, n);
    for (vector<int> v: r) {
        cout << "[ ";
        for (int a: v) {
            cout << a << ' ';
        }
        cout << "]\n";
    }

    return 0;
}