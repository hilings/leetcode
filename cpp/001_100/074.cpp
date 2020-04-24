//
//  074.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/2/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = (int)matrix.size(), n = (int)matrix[0].size(), i = 0, j = m-1;
        while (i < j) {
            int mid = (i+j) / 2;
            if (target > matrix[mid][n-1])
                i = mid+1;
            else
                j = mid;
        }
        int row = i;
        cout << row << '\n';
        i = 0; j = n-1;
        while (i <= j) {
            int mid = (i+j)/2;
            if (target == matrix[row][mid])
                return true;
            else if (target < matrix[row][mid])
                j = mid-1;
            else
                i = mid+1;
        }
        return false;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 074 Search a 2D Matrix, C++ ...\n\n";
    Solution sol;

    vector<vector<int>> matrix {
        vector<int> {1,3,5,7},
        vector<int> {10,11,16,20},
        vector<int> {23,30,34,50}
    };
    int target = 8;
    bool r = sol.searchMatrix(matrix, target);
    cout << (r ? "true" : "false") << '\n';

    return 0;
}