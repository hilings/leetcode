//
//  062.c
//  leetcode
//
//  Created by Hang Zhang on 12/16/15.
//  Copyright © 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int uniquePaths(int m, int n) {
    int *t = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        t[i] = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            t[j] += t[j-1];
        }
    }
    return t[n-1];
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 062 Unique Paths, C ...\n\n");

    int m = 3;
    int n = 7;
    int r = uniquePaths(m, n);
    printf("%d\n", r);

    return 0;
}