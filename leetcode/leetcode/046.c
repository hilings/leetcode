//
//  046.c
//  leetcode
//
//  Created by Hang Zhang on 6/30/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int *a, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insertIntoArray(int* a, int size, int e, int pos) {
    int i = size-1;
    while (i > pos) {
        a[i] = a[i-1];
        i--;
    }
    a[pos] = e;
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize) {
    int size = 0;
    for (int i = 1, k = 1; i <= numsSize; i++) {
        k *= i;
        size += k;
    }
    //printf("%d\n", size);
    int **v = (int**)malloc(sizeof(int*)*size);

    int *a = (int*)malloc(sizeof(int)*numsSize);
    a[0] = nums[0];
    v[0] = a;
    int l = 0, r = 1;

    for (int i = 1; i < numsSize; i++) {
        int tsize = r;
        for (; l < tsize; l++) {
            for (int j = 0; j <= i; j++) {
                if (j < i && v[l][j] == nums[i])
                    continue;
                int *b = (int*)malloc(sizeof(int)*numsSize);
                memcpy(b, v[l], sizeof(int)*numsSize);
                insertIntoArray(b, numsSize, nums[i], j);
                v[r++] = b;
            }
        }
    }
    *returnSize = r - l;
    for (int i = 0; i < *returnSize; i++) {
        v[i] = v[l+i];
        printArray(v[i], numsSize);
    }
    return v;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 046 Permutations, C ...\n\n");

    int nums[] = {0,1};
    int numsSize = sizeof(nums)/sizeof(int);
    int *returnSize = (int*)malloc(sizeof(int));

    permute(nums, numsSize, returnSize);

    return 0;
}