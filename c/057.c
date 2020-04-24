//
//  057.c
//  leetcode
//
//  Created by Hang Zhang on 12/14/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
};

void show(struct Interval a) {
    printf("[%d,%d]\n", a.start, a.end);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) {
    int index_start = intervalsSize, index_end = intervalsSize-1;
    for (int i = 0; i < intervalsSize; i++) {
        if (newInterval.start <= intervals[i].end) {
            newInterval.start = intervals[i].start < newInterval.start ? intervals[i].start : newInterval.start;
            index_start = i;
            break;
        }
    }
    for (int i = index_start; i < intervalsSize; i++) {
        if (newInterval.end < intervals[i].start) {
            index_end = i-1;
            break;
        } else if (newInterval.end <= intervals[i].end) {
            index_end = i;
            newInterval.end = intervals[i].end;
            break;
        }
    }
    if (index_start > index_end) {
        *returnSize = intervalsSize+1;
        struct Interval *r = (struct Interval *)malloc(sizeof(struct Interval)*(*returnSize));
        memcpy(r, intervals, sizeof(struct Interval) * (index_start));
        r[index_start] = newInterval;
        memcpy(r+index_start+1, intervals+index_start, sizeof(struct Interval) * (intervalsSize-index_start));
        return r;
    } else if (index_start == index_end) {
        intervals[index_start] = newInterval;
        *returnSize = intervalsSize;
    } else {
        memmove(&intervals[index_start+1], &intervals[index_end+1], sizeof(struct Interval*) * (intervalsSize-index_end));
        intervals[index_start] = newInterval;
        *returnSize = intervalsSize-(index_end-index_start);
    }
    return intervals;
}


int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 057 Insert Interval, C ...\n\n");

    struct Interval intervals[] = {
        /*
         {1,3},
         {6,9}  //[1,5],[6,9]
         */
        /*
         {1,2},
         {3,5},
         {6,7},
         {8,10},
         {12,16},    //[1,2],[3,10],[12,16]
         */
        ///*
        {2,5},
        {6,7},
        {8,9}   //[0,1],[2,5],[6,7],[8,9]
        //*/
    };
    int intervalsSize = sizeof(intervals)/sizeof(struct Interval);
    //struct Interval newInterval = {2,5};
    //struct Interval newInterval = {4,9};
    struct Interval newInterval = {0,1};

    for (int i = 0; i < intervalsSize; i++) {
        //show(intervals[i]);
    }
    //show(newInterval);
    int *returnSize = (int*)malloc(sizeof(int));
    struct Interval *r = insert(intervals, intervalsSize, newInterval, returnSize);
    for (int i = 0; i < *returnSize; i++) {
        show(r[i]);
    }

    return 0;
}