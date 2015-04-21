//
//  010.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/15/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int l1 = (int)s.length();
        int l2 = (int)p.length();
        
        int i = 0, j = 0;
        while (i <= l1 && j < l2) {
            if (p[j+1] == '*') {
                if (s[i] != p[j] && p[j] != '.') {
                    j += 2;
                } else if (isMatch(s.substr(i), p.substr(j+2))) {
                    return true;
                } else if (s[i] == p[j] || p[j] == '.') {
                    i++;
                } else {
                    return false;
                }
            } else if (s[i] == p[j] || p[j] == '.') {
                i++;
                j++;
            } else {
                return false;
            }
        }
        return i == l1 && j == l2;
    }

    bool isMatch2(string s, string p) {
        int l1 = (int)s.length();
        int l2 = (int)p.length();

        bool *m = new bool[l1+1]();
        m[0] = true;

        for (int j = 0; j < l2; j++) {
            if (j+1 < l2 && p[j+1] == '*') {
                continue;
            } else if (p[j] == '*') {
                char c = p[j-1];
                for (int i = 1; i <= l1; i++) {
                    m[i] = m[i] || (m[i-1] && (s[i-1] == c || c == '.'));
                }
            } else {
                char c = p[j];
                for (int i = l1; i > 0; i--) {
                    m[i] = m[i-1] && (s[i-1] == c || c == '.');
                }
                m[0] = false;
            }
        }
        bool r = m[l1];
        delete[] m;
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 010 Regular Expression Matching, C++ ... ...\n";
    /*
    isMatch("aa","a") → false
    isMatch("aa","aa") → true
    isMatch("aaa","aa") → false
    isMatch("aa", "a*") → true
    isMatch("aa", ".*") → true
    isMatch("ab", ".*") → true
    isMatch("aab", "c*a*b") → true
     */
    string s = "";
    string p = "";
    s = "aaa";
    p = "a*a";
    s = "ab";
    p = ".*..c*";
    s = "baccbbcbcacacbbc";
    p = "c*.*b*c*ba*b*b*.a*";

    Solution sol;
    cout << s << ' ' << p << ' ' << (sol.isMatch2(s, p) ? "true" : "false") << '\n';
    
    return 0;
}