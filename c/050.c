//
//  050.c
//  leetcode
//
//  Created by Hang Zhang on 9/14/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>

double myPow(double x, int n) {
    if (n == 0)
        return 1;
    if (n < 0)
        x = 1/x;
    double result = 1;
    unsigned int tn = n > 0 ? n : -n;
    while (tn) {
        result *= tn&1 ? x : 1;
        x *= x;
        tn = tn >> 1;
    }
    return result;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 050 Pow(x, n), C ...\n\n");

    double x = 0.5;
    int n = 2;
    double result = myPow(x, n);
    printf("%f ^ %d = %f\n", x, n, result);
    return 0;
}