//
//  027.c
//  leetcode
//
//  Created by Hang Zhang on 5/3/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>

void printFirstN(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int removeElement(int A[], int n, int elem) {
    printFirstN(A, n);
    int k = n - 1;
    for (int i = 0; i <= k; i++) {
        if (A[i] == elem) {
            while (k > i && A[k] == elem)
                k--;
            if (i < k)
                A[i] = A[k];
            k--;
        }
    }
    printFirstN(A, k+1);
    printf("new size = %d\n", k+1);
    return k+1;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 027 Remove Element, C ...\n\n");

    int a[] = {1, 2, 2};
    int n = sizeof(a) / sizeof(int);
    int elem = 2;
    removeElement(a, n, elem);
    return 0;
}