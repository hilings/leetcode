//
//  696_Count_Binary_Substrings.cpp
//  leetcode
//
//  Created by Hang Zhang on 11/7/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int z = 0;
        for (int i = 0, cur = ' ', c0 = 0, c1 = 0; i < s.size(); i++) {
            if (s[i] != cur) {
                cur = s[i];
                c0 = c1;
                c1 = 0;
            }
            c1++;
            if (c1 <= c0) {
                z++;
            }
        }
        return z;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 696. Count Binary Substrings, C++ ...\n\n";
    Solution sol;

    string s = "00110011";  // 6
    s = "10101";    // 4

    int z = sol.countBinarySubstrings(s);
    cout << z << '\n';

    return 0;
}
