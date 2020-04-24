//
//  042.c
//  leetcode
//
//  Created by Hang Zhang on 5/18/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>

int trap(int* height, int heightSize) {
    if (heightSize == 0)
        return 0;
    int lhigh[heightSize], rhigh[heightSize];
    lhigh[0] = height[0];
    rhigh[heightSize-1] = height[heightSize-1];
    for (int i = 1, j = heightSize-1-i; i < heightSize; i++, j--) {
        lhigh[i] = height[i] > lhigh[i-1] ? height[i] : lhigh[i-1];
        rhigh[j] = height[j] > rhigh[j+1] ? height[j] : rhigh[j+1];
    }
    int sum = 0;
    for (int i = 1; i < heightSize-1; i++) {
        int roof = lhigh[i] < rhigh[i] ? lhigh[i] : rhigh[i];
        if (height[i] < roof)
            sum += roof - height[i];
    }
    return sum;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 042 Trapping Rain Water, C ...\n\n");

    int height[] = {2,6,3,8,2,7,2,5,0};   //11
    int heightSize = sizeof(height)/sizeof(int);

    printf("%d", trap(height, heightSize));

    return 0;
}