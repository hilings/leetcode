//
//  650_2_Keys_Keyboard.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/25/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
//#include <vector>
using namespace std;

class Solution {
    int greatestFactor(int n) {
        for (int i = 2; i*i <= n; i++) {
            if (n % i == 0) {
                return n/i;
            }
        }
        return 1;
    }
public:
    int minSteps(int n) {
        if (n == 1) {
            return 0;
        }
        int gf = greatestFactor(n);
        return minSteps(gf) + n / gf;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 650. 2 Keys Keyboard, C++ ...\n\n";
    Solution sol;

    int n = 3;

    int r = sol.minSteps(n);
    cout << r << '\n';

    return 0;
}
