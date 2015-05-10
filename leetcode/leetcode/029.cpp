//
//  029.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/3/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
//#include <limits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        cout << dividend << " / " << divisor << " = \n";
        if (divisor == 0)
            return 0;

        long dividend2 = dividend;
        long divisor2 = divisor;
        bool sign = dividend2 > 0 xor divisor2 > 0;
        if (dividend2 < 0)
            dividend2 = -dividend2;
        if (divisor2 < 0)
            divisor2 = -divisor2;

        long d[32];
        d[0] = divisor2;
        int i;
        for (i = 1; d[i-1] < dividend2 && d[i-1] < INT_MAX; i++) {
            d[i] = d[i-1] + d[i-1];
            cout << i << ' ' << d[i]<< '\n';
        }
        i--;
        long res = 0;
        while (dividend2 >= divisor2) {
            while (d[i] > dividend2 && i > 0)
                i--;
            long r = 1;
            for (int j = 0; j < i; j++)
                r += r;
            res += r;
            dividend2 -= d[i];
        }
        if (sign)
            res = -res;
        return res > INT_MAX ? INT_MAX : (int)res;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 029 Divide Two Integers, C++ ...\n\n";

    int dividend = INT_MAX;
    int divisor = -1;

    Solution sol;
    int res = sol.divide(dividend, divisor);
    cout << res;

    return 0;
}