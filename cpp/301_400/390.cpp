//
//  390.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/30/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int lastRemaining0(int n) {
        vector<int> v (n, 0);
        iota(v.begin(), v.end(), 1);

        while (v.size() > 1) {
            for (int i = 0; i < v.size(); i++) {
                v.erase(v.begin()+i);
            }

            /*
            for (int a: v) {
                cout << a << ' ';
            }
            cout << '\n';
             */

            if (v.size() == 1)
                break;

            for (int i = (int)v.size()-1; i >= 0; i-=2) {
                v.erase(v.begin()+i);
            }

            /*
            for (int a: v) {
                cout << a << ' ';
            }
            cout << '\n';
             */
        }
        return v.front();
    }

    int lastRemaining(int n) {
        if (n == 1) {
            return 1;
        }
        if (n <= 4) {
            return 2;
        }
        if (n%2 == 1) { // last odd number will be eliminated anyway
            return lastRemaining(n-1);
        }

        if (n%4 == 0) {
        // f(12) = f(2,6,10) = 2*f(1,3,5) = 2*(f(2,4,6)-1) = 2*(2*f(1,2,3)-1) = 2*(2*f(3)-1) = 4*f(3)-2
            return 4*lastRemaining(n/4) - 2;
        }

        // f(10) = f(4,8) = 4*f(1,2) = 4*f(2)
        return 4*lastRemaining(n/4);
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 390. Elimination Game, C++ ...\n\n";
    Solution sol;

    int n = 15;
    int r = sol.lastRemaining(n);
    cout << r << '\n';

    for (int i = 2; i <= n; i+=2) {
        //cout << i << " => " << sol.lastRemaining(i) << '\n';
    }

    return 0;
}
