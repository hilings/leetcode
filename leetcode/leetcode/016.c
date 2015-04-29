//
//  016.c
//  leetcode
//
//  Created by Hang Zhang on 4/22/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int threeSumClosest(int *num, int n, int target) {
    if (n < 3)
        return 0;
    qsort(num, n, sizeof(int), compare);
    int diff = INT_MAX;
    int sum = 0;
    for (int i = 0; i < n-2; i++) {
        if (i-1 >= 0 && num[i] == num[i-1])
            continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int t = num[i] + num[j] + num[k];
            int d = abs(t - target);
            if (d < diff) {
                diff = d;
                sum = t;
            }
            if (t < target)
                j++;
            else if (t > target)
                k--;
            else
                return sum;
        }
    }
    return sum;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 016 3Sum Closest, C ... ...\n");

    int num[] = {-1, 2, 1, -4};
    int n = sizeof(num)/sizeof(int);
    int target = 1;
    printf("%d\n", threeSumClosest(num, n, target));
    return 0;
}