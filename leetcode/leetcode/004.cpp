//
//  004.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/7/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

class Solution {
public:
    double m2(int a, int b) {
        //  a
        //  b
        return (a + b) / 2.0;
    }
    
    double m3(int a, int b, int c) {
        //  presume b <= c
        //  a
        // b c
        return (a<b) ? b : ((a<c) ? a : c);
    }
    
    double m4(int a, int b, int c, int d) {
        //  presume a <= b, c <= d
        //  a b
        //  c d
        return m2(max(a, c), min(b, d));
    }
    
    double m5(int a, int b, int c, int d, int e) {
        //  presume a <= b, c <= d <= e
        //  a b
        // c d e
        if (a<c) {
            if (b<e) {
                return m3(b, c, d);
            } else {
                return d;
            }
        } else {
            if (b<e) {
                return m3(d, a, b);
            } else {
                return m3(a, d, e);
            }
        }
    }
    
    double m6(int a, int b, int c, int d, int e, int f) {
        //  presume a <= b, c <= d <= e <= f
        //  a b
        //c d e f
        if (a<c) {
            if (b<f) {
                return m2(d, m3(b, c, e));
            } else {
                return m2(d, e);
            }
        } else {
            if (b<f) {
                return m4(a, b, d, e);
            } else {
                return m2(e, m3(a, d, f));
            }
        }
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        cout << '\n';
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
                cout << "m==1, n==1\n";
                return m2(A[0], B[0]);
            } else if (n % 2 == 1) {
                cout << "m==1, n==odd\n";
                return m2(B[n/2], m3(A[0], B[n/2-1], B[n/2+1]));
            } else {
                cout << "m==1, n==even\n";
                return m3(A[0], B[n/2-1], B[n/2]);
            }
        } else if (m == 2) {
            if (n == 2) {
                cout << "m==2, n==2\n";
                return m4(A[0], A[1], B[0], B[1]);
            } else if (n % 2 == 1) {
                cout << "m==2, n==odd\n";
                return m5(A[0], A[1], B[n/2-1], B[n/2], B[n/2+1]);
            } else {
                cout << "m==2, n==even\n";
                return m6(A[0], A[1], B[n/2-2], B[n/2-1], B[n/2], B[n/2+1]);
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
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "LeetCode 004 Median of Two Sorted Arrays, C++ ... ...\n";

    //int a[] = { 1, 2, 4, 8, 9, 10 };
    //int b[] = { 3, 5, 6, 7 };
    //int a[] = {};
    //int b[] = {2, 3};
    int a[] = {2, 2, 2, 2};
    int b[] = {2, 2, 2};
    
    int m = sizeof(a) / sizeof(int);
    int n = sizeof(b) / sizeof(int);
    
    printArray(a, m);
    printArray(b, n);

    Solution sol;
    cout << "\nCalculating...\n" << sol.findMedianSortedArrays(a, m, b, n) << '\n';

    return 0;
}
