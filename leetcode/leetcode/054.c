//
//  template.c
//  leetcode
//
//  Created by Hang Zhang on 12/8/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printA(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void push(int** matrix, int* v, int* count, int a, int b, int c, int d) {
    if (a > c || b > d)
        return;
    for (int i = b; i <= d; i++)
        v[(*count)++] = matrix[a][i];
    for (int i = a+1; i <= c; i++)
        v[(*count)++] = matrix[i][d];
    if (a == c || b == d)
        return;
    for (int i = d-1; i >= b; i--)
        v[(*count)++] = matrix[c][i];
    for (int i = c-1; i > a; i--)
        v[(*count)++] = matrix[i][b];
    push(matrix, v, count, a+1, b+1, c-1, d-1);
    return;
}

int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int* v = (int*)malloc(sizeof(int)*(matrixRowSize*matrixColSize));
    int* count = (int*)malloc(sizeof(int));
    *count = 0;
    push(matrix, v, count, 0, 0, matrixRowSize-1, matrixColSize-1);
    return v;
}


int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 054 Spiral Matrix, C ...\n\n");

    const int m = 3;
    const int n = 3;
    int a[][n] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };
    int** matrix = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * n);
        memcpy(matrix[i], a[i], sizeof(int)*n);
        printA(matrix[i], n);
    }

    printf("\n");
    printA(spiralOrder(matrix, m, n), m*n);

    return 0;
}