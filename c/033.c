//
//  033.c
//  leetcode
//
//  Created by Hang Zhang on 5/11/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize-1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (target < nums[mid])
            if (target >= nums[left] ^ nums[left] > nums[mid])
                right = mid-1;
            else
                left = mid+1;
            else if (target > nums[mid])
                if (target <= nums[right] ^ nums[mid] > nums[right])
                    left = mid+1;
                else
                    right = mid-1;
                else
                    return mid;
    }
    return -1;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 033 Search in Rotated Sorted Array, C...\n\n");

    int nums[] = {4, 5, 6, 7, 8, 1, 2, 3};
    int numsSize = sizeof(nums)/sizeof(int);
    int target = 8;

    printf("%d\n", search(nums, numsSize, target));
    
    return 0;
}