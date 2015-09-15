//
//  050.cpp
//  leetcode
//
//  Created by Hang Zhang on 9/11/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <map>
#include <limits>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        if (n < 0)
            x = 1/x;
        double result = 1;
        unsigned int tn = n > 0 ? n : -n;
        while (tn > 0) {
            result *= tn&1 ? x : 1;
            x *= x;
            tn = tn >> 1;
        }
        return result;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 050 Pow(x, n), C++ ...\n\n";

    double x = 34.00515;
    int n = -3;

    Solution sol;
    double result = sol.myPow(x, n);
    cout << x << " ^ " << n << " = " << result;

    return 0;
}