//
//  397_integer_replacement.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/19/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int integerReplacement(int n) {	// recursive
        if (n == 1) {
            return 0;
        } else if (n % 2 == 0) {
            return 1 + integerReplacement(n/2);
        } else if (n == INT_MAX) {
            return 2 + integerReplacement(n/2+1);
        } else {
            return 1 + min(integerReplacement(n+1), integerReplacement(n-1));
        }
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 397. Integer Replacement, C++ ...\n\n";
    Solution sol;

    int n = 7;
    n = 2147483647;
    int r = sol.integerReplacement(n);
    cout << r << '\n';
    
    return 0;
}
