//
//  409_longest_palindrome.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/29/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int count[52] = {0}, odd = 0, len = 0;
        for (char c: s) {
            if (c >= 'A' && c <= 'Z') {
                count[c-'A']++;
            } else {
                count[26+c-'a']++;
            }
        }
        for (int a: count) {
            if (a % 2 == 0) {
                len += a;
            } else {
                len += a - 1;
                odd = 1;
            }
        }
        return len+odd;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 409. Longest Palindrome, C++ ...\n\n";
    Solution sol;
    
    string s = "abccccdd";	// 7
    s = "ccc";	// 3
    int r = sol.longestPalindrome(s);
    cout << r << '\n';
    
    return 0;
}
