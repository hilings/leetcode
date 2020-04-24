//
//  459_Repeated_Substring_Pattern.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/26/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int size = (int)s.size(), l = size / 2; l >= 1; l--) {
            if (size % l != 0) {
                continue;
            }
            int m = size / l, j; // number of repeats
            string sub = s.substr(0, l);
            for (j = 0; j < m; j++) {
                if (s.substr(l*j, l) != sub) {
                    break;
                }
            }
            if (j == m) {
                return true;
            }
        }
        return false;
    }
    bool repeatedSubstringPattern2(string s) {
        return (s+s).substr(1, s.size()*2-2).find(s) != string::npos;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 459. Repeated Substring Pattern, C++ ...\n\n";
    Solution sol;

    string s = "abcabcs";

    bool r = sol.repeatedSubstringPattern(s);
    cout << (r ? "true" : "false") << '\n';

    bool r2 = sol.repeatedSubstringPattern2(s);
    cout << (r2 ? "true" : "false") << '\n';

    return 0;
}
