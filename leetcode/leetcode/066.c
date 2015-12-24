//
//  066.c
//  leetcode
//
//  Created by Hang Zhang on 12/20/15.
//  Copyright © 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int c = 1;
    int *r = digits;
    *returnSize = digitsSize;
    for (int i = digitsSize-1; c == 1 && i >= 0; i--) {
        digits[i]++;
        c = digits[i] / 10;
        digits[i] %= 10;
    }
    if (c == 1) {
        (*returnSize)++;
        r = (int*)malloc(sizeof(int)*(*returnSize));
        r[0] = 1;
        memcpy(r+1, digits, sizeof(int)*digitsSize);
    }
    return r;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 066 Plus One, C ...\n\n");

    int digitsSize = 3;
    int digits[] = {9,9,9};
    int *returnSize = (int*)malloc(sizeof(int));

    int *r = plusOne(digits, digitsSize, returnSize);
    for (int i = 0; i < *returnSize; i++) {
        printf("%d", r[i]);
    }


    return 0;
}