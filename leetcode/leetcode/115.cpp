//
//  115.cpp
//  leetcode
//
//  Created by Hang Zhang on 1/15/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m[t.size()][s.size()];
        m[0][0] = s[0] == t[0] ? 1 : 0;
        for (size_t j = 1; j < s.size(); j++)
            m[0][j] = (s[j] == t[0]) ? m[0][j-1]+1 : m[0][j-1];
        for (size_t i = 1; i < t.size(); i++)
            m[i][0] = 0;
        for (size_t i = 1; i < t.size(); i++)
            for (size_t j = 1; j < s.size(); j++)
                m[i][j] = s[j] == t[i] ? m[i][j-1] + m[i-1][j-1] : m[i][j-1];
        return m[t.size()-1][s.size()-1];
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 115 Distinct Subsequences, C++ ...\n\n";
    Solution sol;
    string s = "rabbbit";
    string t = "rabbit";

    //s = "ccc";
    //t = "c";
    int r = sol.numDistinct(s, t);
    cout << r << '\n';

    return 0;
}