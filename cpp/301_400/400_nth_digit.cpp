//
//  400_nth_digit.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/21/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int k = 1;		// n falls onto a number which has k digits
        while (k * (pow(10,k) - 1) < n) {
            k++;
        }
        printf("n = %d falls onto a %d digits number\n", n, k);

        long int n2 = n;
        for (int i = 1; i < k; i++) {
            n2 += pow(10,i) - 1;	// n shift if all numbers are k digits number with leading 0
        }
        printf("n shift to %ld if all numbers are %d digits with leading 0\n", n2, k);

        int nth = n2/k, pos = n2%k;
        return (pos == 0 ? nth : ((nth+1) / (int)pow(10,k-pos))) % 10;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 400. Nth Digit, C++ ...\n\n";
    Solution sol;

    int n = 11;
    n = 2147483647;
    int r = sol.findNthDigit(n);
    cout << r << '\n';
    
    return 0;
}
