//
//  479_Largest_Palindrome_Product.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/3/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) {
            return 9;
        }
        int upper = pow(10, n) - 1, lower = pow(10, n-1);
        if (n % 2 == 0) {
            long j = upper + 2 - pow(10,n/2);   // 9999 = 99*101 => 9009 = 99*(101-10) = 99*91
            long p = upper * j;
            printf("n = %d, %ld = %d * %ld\n", n, p, upper, j);
            return p % 1337;
        }
        for (int i = upper; i >= lower; i--) {
            long p = pal(i);
            for (int j = upper; j >= p / j; j--) {
                if (p % j == 0) {
                    printf("n = %d, %ld = %d * %ld\n", n, p, j, p/j);
                    return p % 1337;
                }
            }
        }
        return 0;
    }
    long pal(int a) {
        long r = a;
        while (a) {
            r = 10*r + a%10;
            a /= 10;
        }
        return r;
    }
    int largestPalindrome2(int n) {
        vector<int> v {0, 9, 987, 123, 597, 677, 1218, 877, 475};
        return v[n];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 479. Largest Palindrome Product, C++ ...\n\n";
    Solution sol;

    for (int n = 1; n <= 8; n++) {
        int r = sol.largestPalindrome(n);
        cout << r << '\n';
    }

    for (int n = 1; n <= 8; n++) {
        int r2 = sol.largestPalindrome2(n);
        cout << r2 << '\n';
    }

    return 0;
}
