//
//  056.c
//  leetcode
//
//  Created by Hang Zhang on 12/10/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
};

void show(struct Interval a) {
    printf("[%d, %d]\n", a.start, a.end);
}

int cmp(const void *a, const void *b) {
    const struct Interval *c = a;
    const struct Interval *d = b;
    return c->start - d->start;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    struct Interval *v = (struct Interval*)malloc(sizeof(struct Interval) * intervalsSize);
    *returnSize = 0;
    if (intervalsSize == 0)
        return v;
    qsort(intervals, intervalsSize, sizeof(struct Interval), cmp);

    while (intervalsSize >= 2) {
        int index;
        for (index = intervalsSize-2; index >= 0; index--) {
            if (intervals[intervalsSize-1].start <= intervals[index].end)
                break;
        }
        if (index < 0) {
            v[(*returnSize)++] = intervals[(intervalsSize--)-1];
        } else {
            struct Interval tmp = {intervals[index].start, intervals[index].end > intervals[intervalsSize-1].end ? intervals[index].end : intervals[intervalsSize-1].end};
            intervals[index] = tmp;
            intervalsSize = index+1;
        }
    }
    v[(*returnSize)++] = intervals[0];
    return v;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 056 Merge Intervals, C ...\n\n");

    int intervalsSize = 3;
    struct Interval* intervals = (struct Interval*)malloc(sizeof(struct Interval) * intervalsSize);
    int *returnSize = (int*)malloc(sizeof(int));

    int a[] = {
        /*
        2, 6,
        1, 3,
        8, 10,
        15, 18
         */

        /*
        1,4,
        2,3
         */

        /*
        2,3,
        4,5,
        6,7,
        8,9,
        1,10
         */

        1,4,
        0,2,
        3,5
    };
    int n = sizeof(a)/sizeof(int);
    for (int i = 0; i < n; i+=2) {
        struct Interval b = {a[i], a[i+1]};
        intervals[i/2] = b;
        //show(intervals[i/2]);
    }

    struct Interval* r = merge(intervals, intervalsSize, returnSize);
    for (int i = 0; i < *returnSize; i++) {
        show(r[i]);
    }

    return 0;
}