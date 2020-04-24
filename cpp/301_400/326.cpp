//
//  326.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/18/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPowerOfThree0(int n) {
        if (n <= 0)
            return false;
        while (n > 1) {
            if (n%3 != 0)
                return false;
            n /= 3;
        }
        return true;
    }
    bool isPowerOfThree1(int n) {
        vector<int> v {
            1,
            3,
            9,
            27,
            81,
            243,
            729,
            2187,
            6561,
            19683,
            59049,
            177147,
            531441,
            1594323,
            4782969,
            14348907,
            43046721,
            129140163,
            387420489,
            1162261467
        };
        return find(v.begin(), v.end(), n) != v.end();
    }
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 326. Power of Three, C++ ...\n\n";
    Solution sol;

    int n = 27;

    bool r0 = sol.isPowerOfThree0(n);
    cout << (r0 ? "true" : "false") << '\n';
    
    bool r1 = sol.isPowerOfThree1(n);
    cout << (r1 ? "true" : "false") << '\n';

    bool r = sol.isPowerOfThree(n);
    cout << (r ? "true" : "false") << '\n';

    return 0;
}