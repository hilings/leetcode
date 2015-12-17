//
//  052.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/6/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<vector<string>> solutionset;
        solve(count, "", n, 0, 0, 0);
        return count;
    }
    void solve(int &count, string solution, int n, int c, int d1, int d2) {
        if (solution.size() == n) {
            count++;
            return;
        }
        int row = (int)solution.size();
        for (int i = 0; i < n; i++) {
            if (validate(solution, n, i, c, d1, d2)) {
                string tmp (solution);
                tmp += '0'+i;
                solve(count, tmp, n, c|(1<<i), d1|(1<<(row-i+n)), d2|(1<<(row+i)));
            }
        }
    }
    //solution is a string indicating which column the queen locates for each row
    //a complete solution has a length of n
    bool validate(string solution, int n, int col, int c, int d1, int d2) {
        int row = (int)solution.size();
        if (((1<<col) & c) || ((1<<(row-col+n)) & d1) || ((1<<(row+col)) & d2))
            return false;
        return true;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 052 N-Queens II, C++ ...\n\n";

    Solution sol;
    cout << sol.totalNQueens(8) << '\n';

    return 0;
}