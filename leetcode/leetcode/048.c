//
//  048.c
//  leetcode
//
//  Created by Hang Zhang on 9/6/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printA(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    for (int row = 0; row < matrixRowSize/2; row++) {
        for (int col = 0; col < (matrixColSize+1)/2; col++) {
            int tmp = matrix[row][col];
            matrix[row][col] = matrix[matrixRowSize-1-col][row];
            matrix[matrixRowSize-1-col][row] = matrix[matrixRowSize-1-row][matrixColSize-1-col];
            matrix[matrixRowSize-1-row][matrixColSize-1-col] = matrix[col][matrixColSize-1-row];
            matrix[col][matrixColSize-1-row] = tmp;
        }
    }
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 048 Rotate Image, C...\n\n");

    int m[][3] = {
        1,2,3,
        4,5,6,
        7,8,9
    };
    int n = 3;
    int **matrix = (int**)malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(sizeof(int)*n);
        memcpy(matrix[i], m[i], sizeof(int)*n);
        printA(matrix[i], n);
    }

    rotate(matrix, n, n);

    for (int i = 0; i < n; i++) {
        printA(matrix[i], n);
    }

    return 0;
}