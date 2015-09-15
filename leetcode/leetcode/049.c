//
//  049.c
//  leetcode
//
//  Created by Hang Zhang on 9/6/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
// unfinished!!!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) {
    char ***v = (char***)malloc(sizeof(char**) * strsSize);
    columnSizes = (int**)malloc(sizeof(int*) * strsSize);

    for (int i = 0; i < strsSize; i++) {
        v[i] = (char**)malloc(sizeof(char*) * strsSize);
        int length = (int)strlen(strs[0]);
        for (int j = 0; j < strsSize; j++) {
            v[i][j] = (char*)malloc(sizeof(char)*(length+1));
        }

        columnSizes[i] = (int*)malloc(sizeof(int));

        char *tmp = (char*)malloc(sizeof(char)*(length+1));
        strcpy(tmp, strs[i]);
        qsort(tmp, length, sizeof(char), compare);



    }

    return v;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 049 Group Anagrams, C ...\n\n");

    char s[][4] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int length = (int)strlen(s[0]);

    int strsSize = sizeof(s)/sizeof(s[0]);
    char **strs = (char**)malloc(sizeof(char*) * strsSize);
    for (int i = 0; i < strsSize; i++) {
        //strs[i] = (char*)malloc(sizeof(char) * (length+1));
        strs[i] = s[i];
    }
    int **columnSizes;
    int *returnSize = (int*)malloc(sizeof(int));

    for (int i = 0; i < strsSize; i++) {
        printf("%s ", strs[i]);
        qsort(strs[i], length, sizeof(char), compare);
        printf("-> %s\n", strs[i]);
    }
    groupAnagrams((char**)strs, strsSize, columnSizes, returnSize);

    return 0;
}