//
//  055.c
//  leetcode
//
//  Created by Hang Zhang on 12/9/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    int til = nums[0];
    for (int i = 0; i <= til; i++) {
        if (i+nums[i] > til)
            til = i+nums[i];
        if (til >= numsSize-1)
            return true;
    }
    return false;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 055 Jump Game, C ...\n\n");

    //int nums[] = {2,3,1,1,4};
    int nums[] = {3,2,1,0,4};
    int numsSize = sizeof(nums)/sizeof(int);

    printf("%s\n", canJump(nums, numsSize) ? "true" : "false");

    return 0;
}