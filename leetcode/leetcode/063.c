//
//  063.c
//  leetcode
//
//  Created by Hang Zhang on 12/17/15.
//  Copyright © 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int *t = (int*)malloc(sizeof(int)*obstacleGridColSize);
    t[0] = 1 - obstacleGrid[0][0];
    printf("%d ", t[0]);
    for (int i = 1; i < obstacleGridColSize; i++) {
        t[i] = obstacleGrid[0][i] == 1 ? 0 : t[i-1];
        printf("%d ", t[i]);
    }
    printf("\n");
    for (int i = 1; i < obstacleGridRowSize; i++) {
        if (obstacleGrid[i][0] == 1)
            t[0] = 0;
        printf("%d ", t[0]);
        for (int j = 1; j < obstacleGridColSize; j++) {
            t[j] = obstacleGrid[i][j] == 1 ? 0 : t[j-1]+t[j];
            printf("%d ", t[j]);
        }
        printf("\n");
    }
    return t[obstacleGridColSize-1];
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 063 Unique Paths II, C ...\n\n");

    int a[] = {
        0,0,0,
        0,1,0,
        0,0,0
    };

    int obstacleGridRowSize = 3;
    int obstacleGridColSize = 3;
    int **obstacleGrid = (int**)malloc(sizeof(int*) * obstacleGridRowSize);
    for (int i = 0; i < obstacleGridRowSize; i++) {
        obstacleGrid[i] = (int*)malloc(sizeof(int) * obstacleGridColSize);
        for (int j = 0; j < obstacleGridColSize; j++) {
            obstacleGrid[i][j] = a[obstacleGridRowSize*i+j];
            printf("%d ", obstacleGrid[i][j]);
        }
        printf("\n");
    }

    int r = uniquePathsWithObstacles(obstacleGrid, obstacleGridRowSize, obstacleGridColSize);
    printf("%d\n", r);

    return 0;
}
