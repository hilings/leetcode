//
//  319.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/6/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int bulbSwitch0(int n) {
        vector<bool> bulbs (n, false);
        for (int i = 1; i <= n; i++) {
            for (int j = i-1; j < n; j+=i) {
                bulbs[j] = !bulbs[j];
            }
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (bulbs[i] == true)
                ret++;
        }
        return ret;
    }
    int bulbSwitch(int n) {
        return (int)sqrt(n);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 319. Bulb Switcher, C++ ...\n\n";
    Solution sol;

    int n = 3;

    int r0 = sol.bulbSwitch0(n);
    cout << r0 << '\n';

    int r = sol.bulbSwitch(n);
    cout << r << '\n';

    return 0;
}