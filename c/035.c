//
//  035.c
//  leetcode
//
//  Created by Hang Zhang on 5/11/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (target <= nums[mid])
            right = mid;
        else
            left = mid+1;
    }
    return target > nums[left] ? left + 1 : left;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 035 Search Insert Position, C ...\n\n");

    int nums[] = {1, 3, 5, 6};
    int target = 8;
    int numsSize = sizeof(nums)/sizeof(int);

    printf("%d", searchInsert(nums, numsSize, target));

    return 0;
}