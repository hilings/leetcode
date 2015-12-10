//
//  051.cpp
//  leetcode
//
//  Created by Hang Zhang on 9/14/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void printV(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }
    cout << '\n';
}
void printV(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutionset;
        solve(solutionset, "", n, 0, 0, 0);
        cout << '\n' << solutionset.size();
        return solutionset;
    }
    void solve(vector<vector<string>> &solutionset, string solution, int n, int c, int d1, int d2) {
        if (solution.size() == n) {
            vector<string> ts;
            for (int i = 0; i < n; i++) {
                string line (n, '.');
                line[solution[i]-'0'] = 'Q';
                ts.push_back(line);
            }
            solutionset.push_back(ts);
            return;
        }
        int row = (int)solution.size();
        for (int i = 0; i < n; i++) {
            if (validate3(solution, n, i, c, d1, d2)) {
                string tmp (solution);
                tmp += '0'+i;
                solve(solutionset, tmp, n, c|(1<<i), d1|(1<<(row-i+n)), d2|(1<<(row+i)));
            }
        }
    }
    //solution is a string indicating which column the queen locates for each row
    //a complete solution has a length of n
    bool validate(string solution, int col) {
        int row = (int)solution.size();
        for (int i = 0; i < row; i++) {
            int j = solution[i]-'0';
            if (j == col || i+j == row+col || row-i == col-j)
                return false;
        }
        return true;
    }
    bool validate3(string solution, int n, int col, int c, int d1, int d2) {
        int row = (int)solution.size();
        if (((1<<col) & c) || ((1<<(row-col+n)) & d1) || ((1<<(row+col)) & d2))
            return false;
        return true;
    }


    vector<vector<string>> solveNQueens2(int n) {
        vector<vector<string>> v;
        if (n == 1) {
            v.push_back(vector<string> {"Q"});
            return v;
        }
        vector<int> myset;
        for (int i = 0; i < n; i++) {
            myset.push_back(i);
        }
        string str (n, '.');
        while (next_permutation(myset.begin(), myset.end())) {
            if (validate2(myset)) {
                //printV(myset);
                vector<string> solution;
                for (int i = 0; i < n; i++) {
                    string line (str);
                    line[myset[i]] = 'Q';
                    solution.push_back(line);
                }
                v.push_back(solution);
            }
        }
        cout << v.size();
        return v;
    }
    bool validate2(vector<int> v) {
        for (int i = 0; i < v.size()-1; i++) {
            for (int j = i+1; j < v.size(); j++) {
                if (i+v[i]==j+v[j] || i-j == v[i]-v[j])
                    return false;
            }
        }
        return true;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 051 N-Queens, C++ ...\n\n";
/*
 [
 [".Q..",  // Solution 1
 "...Q",
 "Q...",
 "..Q."],

 ["..Q.",  // Solution 2
 "Q...",
 "...Q",
 ".Q.."]
 ]
 */
    int n = 8;
    Solution sol;
    sol.solveNQueens(n);
    //sol.solveNQueens2(n);

    return 0;
}