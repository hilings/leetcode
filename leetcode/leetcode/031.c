//
//  031.c
//  leetcode
//
//  Created by Hang Zhang on 5/10/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

void nextPermutation(int* nums, int numsSize) {
    if (numsSize <= 1)
        return;

    int i = numsSize - 2;
    while (nums[i] >= nums[i+1])
        i--;
    if (i >= 0) {
        int next = i+1;
        for (int j = i+1; j < numsSize; j++)
            if (nums[j] > nums[i] && nums[j] < nums[next])
                next = j;
        int tmp = nums[i];
        nums[i] = nums[next];
        nums[next] = tmp;
    }
    qsort(nums+i+1, numsSize-(i+1), sizeof(int), compare);
    return;
}

void printArray(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}
int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 031 Next Permutation, C ...\n\n");

    int nums[] = {5,4,7,5,3,2};
    int numsSize = 6;
    printArray(nums, numsSize);

    for (int i = 0; i < 6; i++) {
        nextPermutation(nums, numsSize);
        printArray(nums, numsSize);
    }

    return 0;
}