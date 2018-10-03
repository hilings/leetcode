//
//  519_Random_Flip_Matrix.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/3/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<int,int> um;
    int nr, nc, n;
public:
    Solution(int n_rows, int n_cols) {
        nr = n_rows;
        nc = n_cols;
        n = nr * nc;
        um.clear();
    }

    vector<int> flip() {
        int i = rand() % n, j = um.find(i) != um.end() ? um[i] : i;
        printf("i = %d, j = %d\n", i, j);
        n--;
        um[i] = um.find(n) != um.end() ? um[n]: n;
        um[n] = j;  // optimizing
        return vector<int> {j / nc, j % nc};
    }

    void reset() {
        //um.clear();   // optimizing
        n = nr * nc;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj.flip();
 * obj.reset();
 */

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 519. Random Flip Matrix, C++ ...\n\n";

    Solution sol(2, 3);
    for (int i = 0; i < 6; i++) {
        sol.flip();
    }

    return 0;
}
