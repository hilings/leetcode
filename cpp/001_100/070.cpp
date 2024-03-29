//
//  070.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/23/15.
//  Copyright © 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0)
            return 0;
        int last2 = 1, last1 = 1;
        for (int i = 2; i <= n; i++) {
            int tmp = last1 + last2;
            last2 = last1;
            last1 = tmp;
        }
        return last1;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 070 Climbing Stairs, C++ ...\n\n";
    Solution sol;

    int n = 4;
    int r = sol.climbStairs(n);
    cout << r;
    
    return 0;
}
