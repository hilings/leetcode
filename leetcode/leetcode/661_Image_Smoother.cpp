//
//  661_Image_Smoother.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/26/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = (int)M.size(), n = (int)M[0].size();
        vector<vector<int>> r (m, vector<int> (n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0, count = 0;
                for (int p = max(i-1, 0); p <= min(i+1, m-1); p++) {
                    for (int q = max(j-1, 0); q <= min(j+1, n-1); q++) {
                        sum += M[p][q];
                        count++;
                    }
                }
                r[i][j] = sum / count;
            }
        }
        return r;
    }

    vector<vector<int>> imageSmoother2(vector<vector<int>>& M) {
        int m = (int)M.size(), n = (int)M[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0, count = 0;
                for (int p = max(i-1, 0); p <= min(i+1, m-1); p++) {
                    for (int q = max(j-1, 0); q <= min(j+1, n-1); q++) {
                        sum += M[p][q] & 255;
                        count++;
                    }
                }
                M[i][j] |= sum / count << 8;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                M[i][j] >>= 8;
            }
        }
        return M;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 661. Image Smoother, C++ ...\n\n";
    Solution sol;

    vector<vector<int>> M {
        /*
        {1,1,1},
        {1,0,1},
        {1,1,1}
         */


        {2,3,4},
        {5,6,7},
        {8,9,10},
        {11,12,13},
        {14,15,16}
    };

    vector<vector<int>> r = sol.imageSmoother(M);
    for (auto v: r) {
        for (int a: v) {
            cout << a << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    vector<vector<int>> r2 = sol.imageSmoother2(M);
    for (auto v: r2) {
        for (int a: v) {
            cout << a << ' ';
        }
        cout << '\n';
    }

    return 0;
}
