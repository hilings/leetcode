//
//  172.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/9/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n) {
            count += n/5;
            n /= 5;
        }
        return count;
    }
};


int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 172. Factorial Trailing Zeroes, C++ ...\n\n";
    Solution sol;

    int n = 31;
    int r = sol.trailingZeroes(n);
    cout << r << '\n';
    
    return 0;
}