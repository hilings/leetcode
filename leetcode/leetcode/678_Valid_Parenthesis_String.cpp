//
//  678_Valid_Parenthesis_String.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/30/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;      // least possible open (, most possible open (
        for (char c: s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low = max(low-1, 0);
                high--;
            } else {    // *
                low = max(low-1, 0);  // as ), canceling a previous (
                high++; // as (, appending an open (
            }
            if (high < 0) {     // too many ), high must be >= 0 at all time
                return false;
            }
        }
        return low == 0;    // no open (
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 678. Valid Parenthesis String, C++ ...\n\n";
    Solution sol;

    string s = "(*))";  // true
    s = "(())((())()()(*)(*()(())())())()()((()())((()))(*";    // false

    bool r = sol.checkValidString(s);
    cout << (r ? "true" : "false") << '\n';

    return 0;
}
