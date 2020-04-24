//
//  011.c
//  leetcode
//
//  Created by Hang Zhang on 4/19/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int i = 0, j = heightSize - 1;
    int maxA = 0;
    while (i < j) {
        int tmp = (j-i) * (height[i] < height[j] ? height[i] : height[j]);
        maxA = maxA < tmp ? tmp : maxA;
        height[i] < height[j] ? i++ : j--;
    }
    return maxA;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 011 Container With Most Water, C ... ...\n");
 
    int height[] = {1, 2, 4};
    int heightSize = sizeof(height)/sizeof(int);
    
    printf("%d", maxArea(height, heightSize));
    return 0;
}