//
//  064.c
//  leetcode
//
//  Created by Hang Zhang on 12/17/15.
//  Copyright © 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int *t = (int*)malloc(sizeof(int)*gridColSize);
    t[0] = grid[0][0];
    printf("%d ", t[0]);
    for (int j = 1; j < gridColSize; j++) {
        t[j] = t[j-1] + grid[0][j];
        printf("%d ", t[j]);
    }
    printf("\n");

    for (int i = 1; i < gridRowSize; i++) {
        t[0] = t[0] + grid[i][0];
        printf("%d ", t[0]);
        for (int j = 1; j < gridColSize; j++) {
            t[j] = (t[j-1] < t[j] ? t[j-1] : t[j]) + grid[i][j];
            printf("%d ", t[j]);
        }
        printf("\n");
    }
    printf("\n");
    return t[gridColSize-1];
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 064 Minimum Path Sum, C ...\n\n");

    int a[] = {
        1,2,3,
        4,5,6
    };

    int gridRowSize = 2;
    int gridColSize = 3;
    int **grid = (int**)malloc(sizeof(int*)*gridRowSize);
    for (int i = 0; i < gridRowSize; i++) {
        grid[i] = (int*)malloc(sizeof(int)*gridColSize);
        for (int j = 0; j < gridColSize; j++) {
            grid[i][j] = a[gridColSize*i+j];
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int r = minPathSum(grid, gridRowSize, gridColSize);
    printf("%d\n", r);

    return 0;
}