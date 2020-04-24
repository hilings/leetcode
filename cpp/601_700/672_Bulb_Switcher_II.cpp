//
//  672_Bulb_Switcher_II.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/28/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
    void printB(int a, int n = 6) {
        string s = "";
        while (a > 0) {
            s = to_string(a&1 ? 1 : 0) + s;
            a >>= 1;
        }
        if (s.size() < n) {
            s = string(n-s.size(),'0') + s;
        }
        cout << s << '\n';
    }
public:
    int flipLights0(int n, int m) {
        n %= 5;     // bults starting from 5 onward have same status as first 4
        int op1 = (1 << n) - 1;   // button 1, flip all
        int op2 = 0;
        for (int i = n-2; i >= 0; i -= 2) {   // button 2, flip even
            op2 |= 1 << i;
        }
        int op3 = op1 ^ op2;        // button 3, flip odd
        int op4 = 0;
        for (int i = n-1; i >= 0; i -= 3) {   // button 4, flip 3k+1
            op4 |= 1 << i;
        }
        unordered_set<int> ops {op1, op2, op3, op4};
        unordered_set<int> prev {op1};
        for (int i = 0; i < m; i++) {
            unordered_set<int> next;
            for (int state0: prev) {
                for (int op: ops) {
                    next.insert(state0 ^ op);
                }
            }
            if (next.size() == prev.size()) {
                break;
            }
            prev = next;
        }
        return (int)prev.size();
    }

    int flipLights(int n, int m) {
        if (n == 0 || m == 0) {
            return 1;
        }
        n = min(n, 3);
        if (n == 1) {
            return 2;
        } else if (n == 2) {
            return m == 1 ? 3 : 4;
        }
        return m == 1 ? 4 : (m == 2 ? 7 : 8);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 672. Bulb Switcher II, C++ ...\n\n";
    Solution sol;

    int n = 4;
    int m = 3;

    int r0 = sol.flipLights0(n, m);
    cout << r0 << '\n';

    int r = sol.flipLights(n, m);
    cout << r << '\n';

    return 0;
}
