//
//  365.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/22/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z < 0 || z > (long)x+y)
            return false;
        if (z == 0)
            return true;

        if (x > y) {
            int t = x;
            x = y;
            y = t;
        }

        while (x > 0) {	// gcd, Bézout's lemma
            int t = x;
            x = y % x;
            y = t;
        }
        return z % y == 0;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    std::cout << "LeetCode 365. Water and Jug Problem, C++ ...\n\n";
    Solution sol;

    int x = 3, y = 5, z = 4;
    for (int z = 0; z <= x+y; z++) {
        int r = sol.canMeasureWater(x, y, z);
        std::cout << "z = " << z << ", " << (r ? "true" : "false") << '\n';
    }
    
    return 0;
}
