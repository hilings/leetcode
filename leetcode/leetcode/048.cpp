//
//  048.cpp
//  leetcode
//
//  Created by Hang Zhang on 9/6/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void printV(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        for (int row = 0; row < n/2; row++) {
            for (int col = 0; col < (n+1)/2; col++) {
                int tmp = matrix[row][col];
                matrix[row][col] = matrix[n-1-col][row];
                matrix[n-1-col][row] = matrix[n-1-row][n-1-col];
                matrix[n-1-row][n-1-col] = matrix[col][n-1-row];
                matrix[col][n-1-row] = tmp;
            }
        }
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 048 Rotate Image, C++ ...\n\n";

    const int n = 3;
    int nums[][n] = {
        1,2,3,
        4,5,6,
        7,8,9
    };

    vector<vector<int>> image;
    for (int i = 0; i < n; i++) {
        image.push_back(vector<int> (nums[i], nums[i]+n));
        printV(image[i]);
    }
    
    Solution sol;
    sol.rotate(image);
    
    for (int i = 0; i < n; i++) {
        printV(image[i]);
    }
    
    return 0;
}