//
//  371.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/28/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int r = 0, carry = 0;
        for (int mask = 1; mask > 0 || mask == INT_MIN; mask = mask << 1) {
            int aa = a & mask, bb = b & mask;
            //cout << "mask = " << mask << ", aa = " << aa << ", bb = " << bb << ", carry = " << carry << "\n";
            r |= aa ^ bb ^ (carry ? mask : 0);
            carry = carry ? (aa != 0 || bb != 0) : (aa != 0 && bb != 0);
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 371. Sum of Two Integers, C++ ...\n\n";
    Solution sol;

    int a = INT_MIN, b = INT_MAX;
    int r = sol.getSum(a, b);
    cout << r << '\n';
    
    return 0;
}
