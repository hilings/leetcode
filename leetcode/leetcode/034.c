//
//  034.c
//  leetcode
//
//  Created by Hang Zhang on 5/11/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *v = (int*)malloc(sizeof(int));
    int left = 0, right = numsSize-1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (target <= nums[mid])
            right = mid;
        else
            left = mid+1;
    }
    if (nums[left] == target)
        v[0] = left;
    else {
        v[0] = v[1] = -1;
        return v;
    }
    right = numsSize - 1;
    while (left < right) {
        int mid = (left + right + 1) / 2;
        if (target >= nums[mid])
            left = mid;
        else
            right = mid-1;
    }
    v[1] = right;
    return v;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 034 Search for a Range, C ...\n\n");

    int nums[] = {5, 7, 7, 8, 8, 10};
    int numsSize = sizeof(nums) / sizeof(int);
    int target = 8;
    int* returnSize = (int*)malloc(sizeof(int));

    int *v = searchRange(nums, numsSize, target, returnSize);
    printf("%d %d\n", v[0], v[1]);

    return 0;
}