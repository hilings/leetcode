//
//  413_arithmetic_slices.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/6/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int count = 0;
        for (int i = 0; i < A.size(); i++) {
            if (i+2 < A.size() && A[i+2]-A[i+1] == A[i+1]-A[i]) {
                int step = A[i+1]-A[i], j = i+2;
                while (j+1 < A.size() && A[j+1]-A[j] == step) {
                    j++;
                }
                count += (j-i) * (j-i-1) / 2;
                i = j;
            }
        }
        return count;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 413. Arithmetic Slices, C++ ...\n\n";
    Solution sol;

    vector<int> A {
        //1,2,3,4	// 3
        1,2,3,8,9,10	// 2
    };
    int r = sol.numberOfArithmeticSlices(A);
    cout << r << '\n';
    
    return 0;
}
