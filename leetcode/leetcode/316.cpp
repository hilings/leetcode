//
//  316.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/6/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> vc (26, 0);
        for (char c: s) {
            vc[c-'a']++;
        }
        string ret = "";
        for (char c: s) {
            vc[c-'a']--;
            if (ret.find(c) != string::npos)
                continue;
            while (!ret.empty() && c < ret.back() && vc[ret.back()-'a'] > 0) {
                ret.pop_back();
            }
            ret += c;
        }
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 316. Remove Duplicate Letters, C++ ...\n\n";
    Solution sol;

    string s = "bcabc"; // abc
    s = "cbacdcbc"; // acdb

    string r = sol.removeDuplicateLetters(s);
    cout << r << '\n';

    return 0;
}