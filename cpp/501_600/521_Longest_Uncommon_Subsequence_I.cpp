//
//  521_Longest_Uncommon_Subsequence_I.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/3/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a == b) {
            return -1;
        }
        return (int)max(a.size(), b.size());
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 521. Longest Uncommon Subsequence I, C++ ...\n\n";
    Solution sol;

    string a = "aba";
    string b = "cdc";

    int r = sol.findLUSlength(a, b);
    cout << r << '\n';

    return 0;
}
