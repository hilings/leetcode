//
//  396_rotate_function.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/19/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = (int)A.size(), sum_unit = accumulate(A.begin(), A.end(), 0), sum_prev = 0;
        for (int i = 0; i < n; i++) {
            sum_prev += i * A[i];
        }
        int sum_max = sum_prev;
        printf("F(0) = %d\n", sum_prev);
        for (int i = 1; i < n; i++) {
            sum_prev = sum_prev - A[n-i]*n + sum_unit;
            printf("F(%d) = %d\n", i, sum_prev);
            sum_max = max(sum_max, sum_prev);
        }
        return sum_max;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 396. Rotate Function, C++ ...\n\n";
    Solution sol;

    vector<int> A {4, 3, 2, 6};
    int r = sol.maxRotateFunction(A);
    cout << r << '\n';
    
    return 0;
}
