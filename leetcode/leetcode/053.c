//
//  053.c
//  leetcode
//
//  Created by Hang Zhang on 12/8/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>

int maxSubArray(int* nums, int numsSize) {
    int sum = nums[0], tmp = nums[0];
    for (int i = 1; i < numsSize; i++) {
        tmp = tmp+nums[i] > nums[i] ? tmp+nums[i] : nums[i];
        sum = sum > tmp ? sum : tmp;
    }
    return sum;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 053 Maximum Subarray, C ...\n\n");

    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int numsSize = sizeof(nums)/sizeof(int);

    printf("%d\n", maxSubArray(nums, numsSize));

    return 0;
}