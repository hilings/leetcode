//
//  221.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/7/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int h[matrix.size()][matrix[0].size()], ret = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '0') {
                    h[i][j] = 0;
                } else {
                    h[i][j] = 1;
                    if (i-1 >= 0 && j-1 >= 0)
                        h[i][j] += min(h[i-1][j-1], min(h[i][j-1], h[i-1][j]));
                }
                ret = max(ret, h[i][j]);
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                cout << h[i][j] << ' ';
            }
            cout << '\n';
        }
        return ret*ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 221. Maximal Square, C++ ...\n\n";
    Solution sol;

    vector<vector<char>> matrix {
        /*
        vector<char> {'1', '0', '1', '0', '0'},
        vector<char> {'1', '0', '1', '1', '1'},
        vector<char> {'1', '1', '1', '1', '1'},
        vector<char> {'1', '0', '0', '1', '0'}  //4
         */

        /*
        vector<char> {'0','0','0','1'},
        vector<char> {'1','1','0','1'},
        vector<char> {'1','1','1','1'},
        vector<char> {'0','1','1','1'},
        vector<char> {'0','1','1','1'}  //9
         */

        ///*
         vector<char> {'1','0','1','1','0','1'},
         vector<char> {'1','1','1','1','1','1'},
         vector<char> {'0','1','1','0','1','1'},
         vector<char> {'1','1','1','0','1','0'},
         vector<char> {'0','1','1','1','1','1'},
         vector<char> {'1','1','0','1','1','1'} //4
         //*/
    };
    int r = sol.maximalSquare(matrix);
    cout << r << '\n';

    return 0;
}