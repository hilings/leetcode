//
//  231.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/12/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        //cout << n << '\n';
        if (n <= 0)
            return false;
        while (n > 1) {
            if ((n & 1) == 1)
                return false;
            n = n >> 1;
        }
        return true;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 231. Power of Two, C++ ...\n\n";
    Solution sol;

    int n = 9;

    bool r = sol.isPowerOfTwo(n);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}