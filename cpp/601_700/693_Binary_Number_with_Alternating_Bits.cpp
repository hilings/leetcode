//
//  693_Binary_Number_with_Alternating_Bits.cpp
//  leetcode
//
//  Created by Hang Zhang on 11/6/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        for (int prev = n&1, k = n>>1; k > 0; k >>= 1) {
            int cur = k & 1;
            if (cur == prev) {
                return false;
            }
            prev = cur;
        }
        return true;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 693. Binary Number with Alternating Bits, C++ ...\n\n";
    Solution sol;

    int n = 5;  // true
    n = 7;  // false

    bool z = sol.hasAlternatingBits(n);
    cout << (z ? "true" : "false") << '\n';

    return 0;
}
