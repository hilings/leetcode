//
//  233.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/12/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int countDigitOne0(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 10 == 1)
                count++;
            if (i / 10 % 10 == 1)
                count++;
            if (i / 100 % 10 == 1)
                count++;
            if (i / 1000 % 10 == 1)
                count++;
            if (i / 10000 % 10 == 1)
                count++;
            if (i / 100000 % 10 == 1)
                count++;
            if (i / 1000000 % 10 == 1)
                count++;
            if (i / 10000000 % 10 == 1)
                count++;
            if (i / 100000000 % 10 == 1)
                count++;
            if (i / 1000000000 % 10 == 1)
                count++;
        }
        return count;
    }
    int countDigitOne(int n) {
        if (n < 1)
            return 0;
        if (n < 10)
            return 1;
        int count = 0, mask = 1000000000;
        while (n < mask)
            mask = mask / 10;
        //cout << "mask = " << mask << '\n';

        count += (n >= 2*mask) ? mask : n % mask + 1;	// num of 1 on mask bit
        count += n/mask * countDigitOne(mask-1);	// complete set of f(mask-1)
        count += countDigitOne(n % mask);	// remainder
        return count;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 233. Number of Digit One, C++ ...\n\n";
    Solution sol;
    
    int n = 13;
    
    int r0 = sol.countDigitOne0(n);
    cout << r0 << '\n';
    
    int r = sol.countDigitOne(n);
    cout << r << '\n';
    
    return 0;
}