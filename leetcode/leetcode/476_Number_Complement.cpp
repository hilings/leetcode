//
//  476_Number_Complement.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/3/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int r = 0;
        for (int i = 0; num > 0; i++, num >>= 1) {
            r |= ((num&1)^1)<<i;
        }
        return r;
    }

    int findComplement2(int num) {
        int k = ~0;
        while (k & num) {
            k <<= 1;
        }
        return ~k ^ num;
    }
    void pb(int a) {
        for (int i = 31; i >= 0; i--) {
            printf("%d", (1<<i)&a ? 1 : 0);
        }
        cout << '\n';
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 476. Number Complement, C++ ...\n\n";
    Solution sol;

    int num = 5;

    int r = sol.findComplement(num);
    cout << r << '\n';

    int r2 = sol.findComplement2(num);
    cout << r2 << '\n';

    return 0;
}
