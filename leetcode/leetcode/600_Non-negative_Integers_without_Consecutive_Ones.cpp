//
//  600_Non-negative_Integers_without_Consecutive_Ones.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/16/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
    string itob(int n) {
        string r = "";
        for (int pos = 31; pos >= 0; pos--) {
            if (n & (1<<pos)) {
                r += '1';
            } else if (r != "") {
                r += '0';
            }
        }
        return r != "" ? r : "0";
    }
public:
    int findIntegers0(int num) {
        int r = 0, bits = (int)ceil(log2(num+1));
        dfs(0, 0, bits-1, num, r);
        return r;
    }
    void dfs(int cur, int left, int pos, int& num, int& r) {
        if (cur > num) {
            return ;
        }
        if (pos == -1) {
            //printf("cur = %d, %s\n", cur, itob(cur).c_str());
            r++;
            return ;
        }
        if (left == 0) {
            dfs(cur | (1 << pos), 1, pos-1, num, r);
        }
        dfs(cur, 0, pos-1, num, r);
    }

    int findIntegers(int num) {
        vector<int> fib {1, 2}; // valid integers with n bits
        for (int i = 2; i < 32; i++) {
            fib.push_back(fib[i-1] + fib[i-2]);
        }
        int r = 0;
        for (int pos = 31, prev = 0; pos >= 0; pos--) {
            int cur = num & (1<<pos) ? 1 : 0;
            if (cur) {
                r += fib[pos];
                if (prev == 1) {    // consecutive 1's, the rest are invalid
                    return r;
                }
            }
            prev = cur;
        }
        return r+1;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 600. Non-negative Integers without Consecutive Ones, C++ ...\n\n";
    Solution sol;

    int num = 5;    //

    int r0 = sol.findIntegers0(num);
    cout << r0 << '\n';

    int r = sol.findIntegers(num);
    cout << r << '\n';

    return 0;
}
