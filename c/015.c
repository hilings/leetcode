//
//  015.c
//  leetcode
//
//  Created by Hang Zhang on 4/21/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int **threeSum(int num[], int n, int *returnSize) {
    int **v;
    if (n < 3) {
        *returnSize = 0;
        return v;
    }
    
    int count = n * 2;
    v = (int**)malloc(sizeof(int*) * count);
    for (int i = 0; i < count; i++){
        v[i] = (int*)malloc(sizeof(int) * 3);
    }
    
    qsort(num, n, sizeof(int), compare);
    
    count = 0;
    for (int i = 0; i < n-2; i++) {
        if (i-1 >= 0 && num[i] == num[i-1])
            continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            if (num[j] + num[k] < -num[i])
                j++;
            else if (num[j] + num[k] > -num[i])
                k--;
            else {
                int *a = (int*)malloc(sizeof(int) * 3);
                a[0] = num[i];
                a[1] = num[j];
                a[2] = num[k];
                v[count] = a;
                count++;
                while (j < k && num[j] == a[1])
                    j++;
            }
        }
    }
    for (int i = 0; i < count; i++) {
        printf("%d %d %d\n", v[i][0], v[i][1], v[i][2]);
    }
    *returnSize = count;
    return v;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 015 3Sum, C ... ...\n");

    //int num[] = {3, 2, 5, -4, -1};
    //int num[] = {-1, 0, 1, 2, -1, 4};
    int num[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
    //int num[] = {11,4,9,-7,-7,4,-6,13,12,-1,-5,-15,-2,-4,7,14,14,13,-2,-11,-9,-3,-15,6,-4,14,-7,-15,2,2,7,-10,13,-6,-1,14,5,8,12,3,14,-15,3,-10,-4,-12,-11,-4,-14,-6,-8,14,6,-15,5,10,14,13,10,-6,-8,-6,-1,-9,3,13,-10,-6,-1,9,4,-2,9,14,3,-9,-13,-1,-6,10,8,-7,9,-8,-7,-1,9,-15,-3,4,-6,5,13,8,3,-6,-1,8,-5,13,2,14,-12,-11,13,-1,-13,8,13,-4,3,-1,-4,-2,-2,5,12,-8,5,-13,3,14};
    //int num[] = {-11,-3,-6,12,-15,-13,-7,-3,13,-2,-10,3,12,-12,6,-6,12,9,-2,-12,14,11,-4,11,-8,8,0,-12,4,-5,10,8,7,11,-3,7,5,-3,-11,3,11,-13,14,8,12,5,-12,10,-8,-7,5,-9,-11,-14,9,-12,1,-6,-8,-10,4,9,6,-3,-3,-12,11,9,1,8,-10,-3,2,-11,-10,-1,1,-15,-6,8,-7,6,6,-10,7,0,-7,-7,9,-8,-9,-9,-14,12,-5,-10,-15,-9,-15,-7,6,-10,5,-7,-14,3,8,2,3,9,-12,4,1,9,1,-15,-13,9,-14,11,9};
    //int num[] = {0, 0, 0, 0};
    //int num[] = {4,0,2,3,-1};
    //int num[] = {0, 0, 0};

    int n = sizeof(num)/sizeof(int);
    int *returnSize = (int*)malloc(sizeof(int));
    
    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("\nn = %d\n\n",n );

    threeSum(num, n, returnSize);
    printf("count=%d\n", *returnSize);

    return 0;
}