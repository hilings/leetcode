//
//  541_Reverse_String_II.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/9/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0, j = min(k-1, (int)s.size()-1); i < (int)s.size(); i += 2*k, j = min(i+k-1, (int)s.size()-1)) {
            for (int p = i, q = j; p < q; p++, q--) {
                swap(s[p], s[q]);
            }
        }
        return s;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 541. Reverse String II, C++ ...\n\n";
    Solution sol;

    string s = "abcdefg";
    int k = 2;

    string r = sol.reverseStr(s, k);
    cout << r << '\n';

    return 0;
}
