//
//  007.c
//  leetcode
//
//  Created by Hang Zhang on 4/12/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <limits.h>

int reverse(int x) {
    long int z = 0;
    while (x != 0) {
        z = z * 10 + x % 10;
        x /= 10;
    }
    if (z > INT_MAX || z < INT_MIN) {
        return 0;
    }
    return (int)z;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 007 Reverse Integer, C ... ...\n");
    
    int x = -1000000003;
    printf("%d\n", x);
    printf("%d\n", reverse(x));
    
    printf("%d\n", INT_MAX);
    printf("%d\n", INT_MIN);

    return 0;
}