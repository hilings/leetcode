//
//  060.c
//  leetcode
//
//  Created by Hang Zhang on 12/16/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getPermutation(int n, int k) {
    char* s = (char*)malloc(sizeof(char)*n);
    char* digits = (char*)malloc(sizeof(char)*n);
    int f = 1;
    for (int i = 1; i <= n; i++) {
        f *= i;
        digits[i-1] = '0'+i;
    }
    for (int i = n; i > 0; i--) {
        f /= i;
        int q = (k-1) / f;
        strncat(s, digits+q, 1);
        memmove(digits+q, digits+q+1, n-1-q);
        k -= q * f;
    }
    return s;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 060 Permutation Sequence, C ...\n\n");

    int n = 3;
    int k = 6;
    char *s = getPermutation(n, k);
    printf("%s\n", s);

    return 0;
}
