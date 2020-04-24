//
//  005.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/9/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
//#include <string>
using namespace std;

class Solution {
// central expansion
public:
    string longestPalindrome(string s) {
        int slen = (int)s.length();
        if (slen <= 1) {
            return s;
        }

        int longest_start = 0;
        int longest_len = 1;

        for (int i = 1; i < slen; i++) {
            // palindrome even length
            int p = i;
            int q = p - 1;
            while (q >= 0 && p < slen && s[q] == s[p]) {
                p++;
                q--;
            }
            int tlen = p - q - 1;
            if (tlen > longest_len) {
                longest_start = q + 1;
                longest_len = tlen;
            }

            // palindrome odd length
            p = i;
            q = p - 2;
            while (q >= 0 && p < slen && s[q] == s[p]) {
                p++;
                q--;
            }
            tlen = p - q - 1;
            if (tlen > longest_len) {
                longest_start = q + 1;
                longest_len = tlen;
            }
        }
        return s.substr(longest_start, longest_len);
    }
};

class Solution2 {
// Manacher's algorithm
public:
    string longestPalindrome(string s) {
        int slen = (int)s.length();
        if (slen <= 1)
            return s;

        string T = "^#";
        for (int i = 0; i < slen; i++) {
            T += s.substr(i, 1) + "#";
        }
        T += "$";
        
        int tlen = (int)T.length();
        int P[tlen];
        P[0] = 0;
        int R = 0;
        int C = 0;
        int maxC = 0;
        for (int i = 1; i < tlen - 1; i++) {
            P[i] = (i >= R) ? 0 : min(R-i, P[2*C-i]);
            while (T[i+P[i]+1] == T[i-P[i]-1]) {
                P[i]++;
            }
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
                if (P[i] > P[maxC])
                    maxC = C;
            }
        }
        return s.substr((maxC-P[maxC]-1) / 2, P[maxC]);
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "LeetCode 005 Longest Palindromic Substring, C++ ... ...\n";

    string s = "bbbbb";
    //s = "forgeeksskeegfor";
    //s = "cabcbabcbabcba";
    //s = "habacdedcabag";
    //s = "abcbabc";
    //s = "ABCBAHELLOHOWRACECARAREYOUIAMAIDOINGGOOD";
    Solution2 sol;
    
    cout << s << "\n";
    cout << sol.longestPalindrome(s) << "\n";
    return 0;
}