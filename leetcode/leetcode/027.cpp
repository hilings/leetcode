//
//  027.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/2/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

void printFirstN(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
}

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        printFirstN(A, n);
        if (n == 0)
            return 0;
        int k = n-1;
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
        cout << "new size = "<<k+1<<'\n';
        return k+1;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 027 Remove Element, C++ ...\n\n";

    int a[] = {2};
    int n = sizeof(a) / sizeof(int);
    int elem = 3;

    Solution sol;
    sol.removeElement(a, n, elem);

    return 0;
}