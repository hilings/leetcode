//
//  566_Reshape_the_Matrix.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/12/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        size_t row = nums.size(), col = nums[0].size();
        if (row * col != r * c) {
            return nums;
        }
        vector<vector<int>> m (r, vector<int> (c, 0));
        for (int i = 0, p = 0, q = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                m[p][q] = nums[i][j];
                q++;
                if (q == c) {
                    q = 0;
                    p++;
                }
            }
        }
        return m;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 566. Reshape the Matrix, C++ ...\n\n";
    Solution sol;

    vector<vector<int>> nums {
        {1,2},
        {3,4}
    };
    int r = 1;
    int c = 4;

    vector<vector<int>> result = sol.matrixReshape(nums, r, c);
    for (auto v: result) {
        for (int a: v) {
            cout << a << ' ';
        }
        cout << '\n';
    }
    return 0;
}
