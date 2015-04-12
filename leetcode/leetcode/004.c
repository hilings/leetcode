//
//  004.c
//  leetcode
//
//  Created by Hang Zhang on 4/8/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

double m2(int a, int b) {
    return (a + b) / 2.0;
}

double m3(int a, int b, int c) {
    int tmax = max(a, max(b, c));
    int tmin = min(a, min(b, c));
    return a + b + c - tmax - tmin;
}

double m4(int a, int b, int c, int d) {
    int tmax = max(a, max(b, max(c, d)));
    int tmin = min(a, min(b, min(c, d)));
    return (a + b + c + d - tmax - tmin) / 2.0;
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
    printf("\n");
    printArray(A, m);
    printArray(B, n);
    if (m > n) {
        return findMedianSortedArrays(B, n, A, m);
    }
    if (m == 0) {
        if (n % 2 == 1) {
            return B[(n-1)/2];
        } else {
            return m2(B[(n-1)/2], B[(n-1)/2+1]);
        }
    } else if (m == 1) {
        if (n == 1) {
            return m2(A[0], B[0]);
        } else if (n % 2 == 1) {
            return m2(B[n/2], m3(A[0], B[n/2-1], B[n/2+1]));
        } else {
            return m3(A[0], B[n/2-1], B[n/2]);
        }
    } else if (m == 2) {
        if (n == 2) {
            return m4(A[0], A[1], B[0], B[1]);
        } else if (n % 2 == 1) {
            return m3(max(A[0], B[n/2-1]),  B[n/2], min(A[1], B[n/2+1]));
        } else {
            return m4(max(A[0], B[n/2-2]), B[n/2-1], B[n/2], min(A[1], B[n/2+1]));
        }
    } else {
        int c = (m - 1) / 2;
        if (A[c] < B[(n-1)/2]) {
            return findMedianSortedArrays(A+c, m-c, B, n-c);
        } else {
            if (m % 2 == 0) {
                c++;
            }
            return findMedianSortedArrays(A, c+1, B+m-c-1, n-(m-c-1));
        }
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("LeetCode 004 Median of Two Sorted Arrays, C ... ...\n");
    
    //int a[] = { 1, 2, 4, 8, 9, 10 };
    //int b[] = { 3, 5, 6, 7 };
    //int a[] = {};
    //int b[] = {2, 3};
    //int a[] = {2, 2, 2, 2};
    //int b[] = {2, 2, 2};
    int a[] = {1, 2};
    int b[] = {3, 4, 5};
    
    int m = sizeof(a) / sizeof(int);
    int n = sizeof(b) / sizeof(int);
    
    printArray(a, m);
    printArray(b, n);
    
    printf("\nCalculating...\n%.1f\n", findMedianSortedArrays(a, m, b, n));
    return 0;
}
