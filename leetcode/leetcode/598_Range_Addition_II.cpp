//
//  598_Range_Addition_II.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/15/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    void printM(vector<vector<int>>& M) {
        for (auto v: M) {
            for (int a: v) {
                cout << a << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }

public:
    int maxCount0(int m, int n, vector<vector<int>>& ops) {
        vector<vector<int>> M (m, vector<int> (n, 0));
        printM(M);
        for (auto v: ops) {
            for (int i = 0; i < v[0]; i++) {
                for (int j = 0; j < v[1]; j++) {
                    M[i][j]++;
                }
            }
        }
        int maximum = 0;
        unordered_map<int,int> um;
        for (auto v: M) {
            for (int a: v) {
                um[a] = um.find(a) != um.end() ? um[a]+1 : 1;
                maximum = max(maximum, a);
            }
        }
        printM(M);
        return um[maximum];
    }

    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int row = m, col = n;
        for (auto op: ops) {
            row = min(row, op[0]);
            col = min(col, op[1]);
        }
        return row * col;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 598. Range Addition II, C++ ...\n\n";
    Solution sol;

    int m = 3;
    int n = 3;
    vector<vector<int>> ops {
        {2,2},
        {3,3}
    };

    int r0 = sol.maxCount0(m, n, ops);
    cout << r0 << '\n';

    int r = sol.maxCount(m, n, ops);
    cout << r << '\n';

    return 0;
}
