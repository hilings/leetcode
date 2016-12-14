//
//  345.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/13/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;

class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
public:
    string reverseVowels1(string s) {
        for (int i = 0, j = (int)s.size()-1; i < j; i++ & j--) {
            while (!isVowel(s[i]))
                i++;
            while (!isVowel(s[j]))
                j--;
            if (i < j) {
                char c = s[i];
                s[i] = s[j];
                s[j] = c;
            }
        }
        return s;
    }

    string reverseVowels(string s) {
        for (int i = 0, j = (int)s.size()-1; i < j;) {
            if (!isVowel(s[i])) {
                i++;
            } else if (!isVowel(s[j])) {
                j--;
            } else {
                char c = s[i];
                s[i++] = s[j];
                s[j--] = c;
            }
        }
        return s;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 345. Reverse Vowels of a String, C++ ...\n\n";
    Solution sol;
    
    string s = "hello";
    
    string r = sol.reverseVowels(s);
    cout << r << '\n';
    
    cout << sol.reverseVowels1("leetcode") << '\n';
    cout << sol.reverseVowels("leetcode") << '\n';
    
    return 0;
}
