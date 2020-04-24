//
//  066.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/20/15.
//  Copyright © 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        for (int i = (int)digits.size()-1; c == 1 && i >= 0; i--) {
            digits[i]++;
            c = digits[i] / 10;
            digits[i] %= 10;
        }
        if (c == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 066 Plus One, C++ ...\n\n";
    Solution sol;

    vector<int> digits = {
        9,9,9
    };

    vector<int> r = sol.plusOne(digits);
    for (int i = 0; i < r.size(); i++) {
        cout << r[i];
    }

    return 0;
}
