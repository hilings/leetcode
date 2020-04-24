//
//  680_Valid_Palindrome_II.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/31/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        string::size_type i = 0, j = s.size()-1, ii, jj;
        for ( ; i < j && s[i] == s[j]; i++, j--);
        if (i >= j) {   // palindrome already
            return true;
        }
        for (ii = i, jj = j-1; ii < jj && s[ii] == s[jj]; ii++, jj--);  // delete s[j]
        if (ii >= jj) {
            return true;
        }
        for (ii = i+1, jj = j; ii < jj && s[ii] == s[jj]; ii++, jj--);  // delete s[i]
        return ii >= jj;
     }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 680. Valid Palindrome II, C++ ...\n\n";
    Solution sol;

    string s = "abca";  // true

    bool r = sol.validPalindrome(s);
    cout << (r ? "true" : "false") << '\n';

    return 0;
}
