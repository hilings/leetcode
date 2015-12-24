//
//  069.c
//  leetcode
//
//  Created by Hang Zhang on 12/23/15.
//  Copyright © 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int mySqrt(int x) {
    long r = 1;
    while (r*r <= x)
        r = r << 1;
    int step = (int)r >> 1;
    while (step) {
        if ((r-step)*(r-step) > x)
            r -= step;
        step = step >> 1;
    }
    return (int)r-1;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 069 Sqrt(x), C ...\n\n");

    int x = 2147483647;
    int r = mySqrt(x);
    printf("%d\n", r);

    return 0;
}