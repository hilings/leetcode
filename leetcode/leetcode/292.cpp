//
//  292.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/25/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n%4 != 0;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 292. Nim Game, C++ ...\n\n";
    Solution sol;

    int n = 4;

    bool r = sol.canWinNim(n);
    cout << (r ? "true" : "false") << '\n';

    return 0;
}