//
//  059.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/15/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m;
        for (int i = 0; i < n; i++) {
            m.push_back(vector<int> (n, 0));
        }
        fill(m, 0, n-1, 0);
        return m;
    }
    void fill(vector<vector<int>> &m, int p, int q, int count) {
        if (p == q) {
            m[p][p] = ++count;
            return;
        } else if (p > q) {
            return;
        }

        for (int i = p; i < q; i++) {
            m[p][i] = ++count;
        }
        for (int i = p; i < q; i++) {
            m[i][q] = ++count;
        }
        for (int i = q; i > p; i--) {
            m[q][i] = ++count;
        }
        for (int i = q; i > p; i--) {
            m[i][p] = ++count;
        }
        fill(m, p+1, q-1, count);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 059 Spiral Matrix II, C++ ...\n\n";

    int n = 3;
    Solution sol;
    vector<vector<int>> m = sol.generateMatrix(n);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            cout << m[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}