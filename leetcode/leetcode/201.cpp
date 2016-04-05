//
//  201.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/24/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int bit = n - m, mask = -1;
        while (bit > 0) {
            mask <<= 1;
            bit >>= 1;
        }
        return m & n & mask;
    }
    int rangeBitwiseAnd0(int m, int n) {
        int mask_h = 2147483647, bit = m, mask = 1;
        while (mask > 0 && mask <= n) {
            int tmp = (mask_h & m) + mask;
            if ((m & mask) > 0 && tmp > 0 && tmp <= n)
                bit ^= mask;
            mask_h -= mask;
            mask <<= 1;
        }
        return bit;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 201. Bitwise AND of Numbers Range, C++ ...\n\n";
    Solution sol;

    int m = 5, n = 7;	// 4
    //m = 3, n = 3;	// 3
    //m = 3, n = 4;	// 0
    //m = 0, n = 2147483647;	// 0
    m = 2147483646, n = 2147483647;	// 2147483646
    int r = sol.rangeBitwiseAnd(m, n);
    cout << "(" << m << ", " << n << ") => " << r << '\n';
    
    
    return 0;
}