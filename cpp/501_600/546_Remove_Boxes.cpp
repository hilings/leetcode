//
//  546_Remove_Boxes.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/9/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeBoxes0(vector<int>& boxes) {
        int r = 0;
        helper(boxes, r, 0);
        return r;
    }
    void helper(vector<int>& boxes, int& r, int sum) {
        if (boxes.empty()) {
            r = max(r, sum);
        }
        for (int i = 0, j = 0; i < boxes.size(); i = j) {
            for (j = i+1; j < boxes.size() && boxes[j] == boxes[i]; j++);
            int k = j-i, color = boxes[i];
            boxes.erase(boxes.begin()+i, boxes.begin()+j);
            helper(boxes, r, sum + k*k);
            boxes.insert(boxes.begin()+i, k, color);
        }
    }

    int removeBoxes(vector<int>& boxes) {
        int n = (int)boxes.size();
        vector<vector<vector<int>>> dp (n, vector<vector<int>> (n, vector<int> (n, 0)));
        return helper(boxes, dp, 0, n-1, 0);
    }
    int helper(vector<int>& boxes, vector<vector<vector<int>>>& dp, int i, int j, int k) {
        if (i > j) {
            return 0;
        }
        if (dp[i][j][k] > 0) {
            return dp[i][j][k];
        }
        for (; i+1 <= j && boxes[i+1] == boxes[i]; i++, k++);
        int r = (k+1)*(k+1) + helper(boxes, dp, i+1, j, 0); // remove first box
        for (int m = i+1; m <= j; m++) {    // hold first box i, and remove some boxes i+1 ~ m-1,
            if (boxes[m] == boxes[i]) {     // in order to attach same color boxes m for potential more points
                r = max(r, helper(boxes, dp, i+1, m-1, 0) + helper(boxes, dp, m, j, k+1));
            }
        }
        dp[i][j][k] = r;
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 546. Remove Boxes, C++ ...\n\n";
    Solution sol;

    vector<int> boxes {
        1, 3, 2, 2, 2, 3, 4, 3, 1   // 23
        //3, 8, 8, 5, 5, 3, 9, 2, 4, 4, 6, 5, 8, 4, 8, 6, 9, 6, 2, 8, 6, 4, 1, 9, 5, 3, 10, 5, 3, 3, 9, 8, 8, 6, 5, 3, 7, 4, 9, 6, 3, 9, 4, 3, 5, 10, 7, 6, 10, 7

    };

    int r0 = sol.removeBoxes0(boxes);
    cout << r0 << '\n';

    int r = sol.removeBoxes(boxes);
    cout << r << '\n';

    return 0;
}
