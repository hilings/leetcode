//
//  059.c
//  leetcode
//
//  Created by Hang Zhang on 12/15/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void fill(int** m, int p, int q, int count) {
    if (p == q) {
        m[p][p] = ++count;
        return;
    } else if (p > q) {
        return;
    }
    for (int i = p; i < q; i++) {
        m[p][i] = ++count;
    }
    for (int i = p; i < q; i++) {
        m[i][q] = ++count;
    }
    for (int i = q; i > p; i--) {
        m[q][i] = ++count;
    }
    for (int i = q; i > p; i--) {
        m[i][p] = ++count;
    }
    fill(m, p+1, q-1, count);
}

int** generateMatrix(int n) {
    int **m = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        m[i] = (int*)malloc(sizeof(int)*n);
        for (int j = 0; j < n; j++) {
            m[i][j] = 0;
        }
    }
    fill(m, 0, n-1, 0);
    return m;
}


int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 059 Spiral Matrix II, C ...\n\n");

    int n = 3;
    int **m = generateMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}