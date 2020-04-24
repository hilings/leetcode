//
//  190.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/21/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        for (int i = 0; i < 32; i++) {
            ret <<= 1;
            ret |= n & 1;
            n >>= 1;
        }
        return ret;
    }

    uint32_t reverseBits0(uint32_t n) {
        int left = 31, right = 0;
        while (left > right) {
            if ((n >> left) & 1  ^ (n >> right) & 1) {
                n ^= 1 << left;
                n ^= 1 << right;
            }
            left--;
            right++;
        }
        return n;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 190. Reverse Bits, C++ ...\n\n";
    Solution sol;
    
    uint32_t n = 43261596;
    cout << n << '\n';
    
    uint32_t r = sol.reverseBits(n);
    cout << r << '\n';
    
    return 0;
}