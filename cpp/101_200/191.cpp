//
//  191.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/21/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if ((n & 1) == 1)
                count ++;
            n >>= 1;
        }
        return count;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 191. Number of 1 Bits, C++ ...\n\n";
    Solution sol;

    uint32_t n = 11;
    int r = sol.hammingWeight(n);
    cout << r << '\n';
    
    return 0;
}