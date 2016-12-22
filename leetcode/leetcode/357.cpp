//
//  357.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/21/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<int> v;
public:
    int countNumbersWithUniqueDigits(int n) {
        if (v.empty()) {
            v.push_back(1);
        }
        for (int i = (int)v.size(); i <= n; i++) {
            cout << "looping\n";
            int tmp = 9;
            for (int j = 0, k = 9; j < i-1; j++ & k--) {
                tmp *= k;
            }
            v.push_back(tmp+v[i-1]);
        }
        return v[n];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 357. Count Numbers with Unique Digits, C++ ...\n\n";
    Solution sol;

    for (int n = 4; n >= 0; n--) {
        int r = sol.countNumbersWithUniqueDigits(n);
        cout << n << ": " << r << '\n';
    }
    
    
    return 0;
}
