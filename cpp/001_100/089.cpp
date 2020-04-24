//
//  089.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/8/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0)
            return vector<int> {0};
        vector<int> v (grayCode(n-1));
        int f = pow(2, n-1);
        for (size_t k = 0; k < f; k++)
            v.push_back(f+v[f-1-k]);
        return v;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 089 Gray Code, C++ ...\n\n";
    Solution sol;

    int n = 2;
    vector<int> r = sol.grayCode(n);

    for (auto a: r) {
        cout << a << ' ';
    }
    
    return 0;
}