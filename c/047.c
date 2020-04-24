//
//  047.c
//  leetcode
//
//  Created by Hang Zhang on 9/3/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printA(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int next_permutation(int* nums, int numsSize) {
    if (numsSize <= 1)
        return 0;
    int i = numsSize - 2;
    while (i >= 0 && nums[i] >= nums[i+1])
        i--;

    if (i >= 0) {
        int next = i + 1;
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] > nums[i] && nums[j] < nums[next])
                next = j;
        }
        int tmp = nums[i];
        nums[i] = nums[next];
        nums[next] = tmp;
    }
    qsort(nums+i+1, numsSize-(i+1), sizeof(int), compare);

    return i >= 0 ? 1 : 0;
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** permuteUnique(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int i;
    *returnSize = 1;
    for (i = 2; i <= numsSize; i++) {
        (*returnSize) *= i;
    }
    int **v = (int**)malloc(sizeof(int*)*(*returnSize));
    v[0] = (int*)malloc(sizeof(int)*numsSize);
    memcpy(v[0], nums, sizeof(int)*numsSize);

    for (i = 1; next_permutation(nums, numsSize); i++) {
        v[i] = (int*)malloc(sizeof(int)*numsSize);
        memcpy(v[i], nums, sizeof(int)*numsSize);
    }
    *returnSize = i;
    return v;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 047 Permutations II, C...\n\n");

    int nums[] = {0, -1};
    int numsSize = sizeof(nums)/sizeof(int);
    printA(nums, numsSize);

    int *returnSize = (int*)malloc(sizeof(int));
    int **v = permuteUnique(nums, numsSize, returnSize);
    for (int i = 0; i < *returnSize; i++) {
        printA(v[i], numsSize);
    }

    return 0;
}
