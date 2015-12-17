//
//  060.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/16/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";
        vector<int> digits;
        int f = 1;
        for (int i = 1; i <= n; i++) {
            f *= i;
            digits.push_back(i);
        }
        for (int i = n; i > 0; i--) {
            f /= i;
            int q = (k-1) / f;
            s += '0'+digits[q];
            digits.erase(digits.begin()+q);
            k -= q*f;
        }
        return s;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 060 Permutation Sequence, C++ ...\n\n";

    int n = 3;
    int k = 4;

    Solution sol;
    cout << sol.getPermutation(n, k) << '\n';

    int f = 1;
    for (int i = 1; i <= n; i++) {
        f *= i;
    }
    for (int i = 1; i <= f; i++) {
        cout << i << ' ' << sol.getPermutation(n, i) << '\n';
    }
    
    return 0;
}
