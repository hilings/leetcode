//
//  005.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/9/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
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
public:
    int extend(int P[], int i) {
        return 0;
    }
    
    string longestPalindrome(string s) {
        return "abc";
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "LeetCode 005 Longest Palindromic Substring, C++ ... ...\n";
    
    string s = "";
    s = "a#b#";
    //s = "forgeeksskeegfor";
    //s = "cabcbabcbabcba";
    //s = "habacdedcabag";
    //s = "abacdgfdcaba";
    //s = "ABCBAHELLOHOWRACECARAREYOUIAMAIDOINGGOOD";
    Solution sol;
    
    cout << "s: " << s << "\n";
    cout << "Calculating...\n" << sol.longestPalindrome(s) << "\n";

    return 0;
}
