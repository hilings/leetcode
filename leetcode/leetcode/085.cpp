//
//  085.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/8/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void printV(vector<int> v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        vector<int> height (matrix[0].size(), 0);
        int maxA = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++)
                matrix[i][j] == '1' ? height[j]++ : height[j] = 0;
            maxA = max(maxA, largestRectangleArea(height));
        }
        return maxA;
    }

    int largestRectangleArea(vector<int>& height) {
        stack<int> stk;
        stk.push(0);
        height.push_back(0);
        int maxA = 0, itop;
        for (int i = 0; i < height.size(); i++) {
            while (!stk.empty() && height[i] < height[itop = stk.top()]) {
                stk.pop();
                maxA = max(maxA, height[itop] * (stk.empty() ? i : i-stk.top()-1));
            }
            stk.push(i);
        }
        return maxA;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 085 Maximal rectangle, C++ ...\n\n";
    Solution sol;

    vector<vector<char>> matrix {
        /*
         vector<char> {'1','0','1'},
         vector<char> {'1','1','1'},
         vector<char> {'1','1','1'}
         */

        vector<char> {'1','1','1','1','1','1','1','1'},
        vector<char> {'1','1','1','1','1','1','1','0'},
        vector<char> {'1','1','1','1','1','1','1','0'},
        vector<char> {'1','1','1','1','1','0','0','0'},
        vector<char> {'0','1','1','1','1','0','0','0'}
    };
    
    int r = sol.maximalRectangle(matrix);
    cout << r << '\n';
    
    return 0;
}