//
//  026.c
//  leetcode
//
//  Created by Hang Zhang on 5/2/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\nn = %d\n", n);
}

int removeDuplicates(int A[], int n) {
    printArray(A, n);
    if (n == 0)
        return 0;
    int k = 1;
    for (int i = 1; i < n; i++) {
        if (A[i] != A[i-1]) {
            if (k < i)
                A[k] = A[i];
            k++;
        }
    }
    printf("new size = %d\n", k);
    return k;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 000 XXX, C ...\n\n");

    int a[] = {1, 2, 3, 3};
    int n = sizeof(a) / sizeof(int);

    removeDuplicates(a, n);
    return 0;
}