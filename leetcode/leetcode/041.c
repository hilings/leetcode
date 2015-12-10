//
//  041.c
//  leetcode
//
//  Created by Hang Zhang on 5/18/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>

int firstMissingPositive(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0 && nums[i] <= numsSize && nums[i]-1 != i) {
            int tmp = nums[nums[i]-1];
            nums[nums[i]-1] = nums[i];
            nums[i] = tmp;
            if (nums[i]-1 < i && nums[nums[i]-1] != nums[i])
                i--;
        }
    }
    for (int i = 0; i < numsSize; i++)
        if (nums[i] != i+1)
            return i+1;
    return numsSize+1;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 041 First Missing Positive, C...\n\n");

    int nums[] = {3, 4, -1, 1};
    int numsSize = sizeof(nums)/sizeof(int);
    printf("%d\n", firstMissingPositive(nums, numsSize));

    return 0;
}