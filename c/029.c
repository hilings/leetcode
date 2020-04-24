//
//  029.c
//  leetcode
//
//  Created by Hang Zhang on 5/4/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int divide(int dividend, int divisor) {
    if (divisor == 0)
        return 0;
    long dividend2 = dividend;
    long divisor2 = divisor;
    bool sign = dividend2 > 0 ^ divisor2 > 0;
    if (dividend2 < 0)
        dividend2 = -dividend2;
    if (divisor2 < 0)
        divisor2 = -divisor2;

    int i;
    long d[32];
    d[0] = divisor2;
    for (i = 1; d[i-1] < dividend2 && d[i-1] < INT_MAX; i++)
        d[i] = d[i-1] + d[i-1];
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

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 029 Divide Two Integers, C ...\n\n");

    int dividend = INT_MIN;
    int divisor = -1;
    printf("%d / %d = %d\n", dividend, divisor, divide(dividend, divisor));

    return 0;
}