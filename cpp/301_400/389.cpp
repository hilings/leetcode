//
//  389.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/30/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
//#include <vector>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int count[26] = {0};
        for (char c: t) {
            count[c-'a']++;
        }
        for (char c: s) {
            count[c-'a']--;
        }
        char c = ' ';
        for (int i = 0; i < 26; i++) {
            if (count[i] == 1)
                c = 'a'+i;
        }
        return c;
    }

    char findTheDifference2(string s, string t) {
        char r = 0;
        for (char c: s) {
            r ^= c;
        }
        for (char c: t) {
            r ^= c;
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 389. Find the Difference, C++ ...\n\n";
    Solution sol;

    string s = "abcd";
    string t = "abcde";
    char r = sol.findTheDifference(s, t);
    cout << r << '\n';

    r = sol.findTheDifference2(s, t);
    cout << r << '\n';

    return 0;
}
