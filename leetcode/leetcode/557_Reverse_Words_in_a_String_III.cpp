//
//  557_Reverse_Words_in_a_String_III.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/10/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        for (int i = 0, j; i < s.size(); i++) {
            if (s[i] == ' ') {
                continue;
            }
            for (j = i; j+1 < s.size() && s[j+1] != ' '; j++);
            for (int p = i, q = j; p < q; p++, q--) {
                swap(s[p], s[q]);
            }
            i = j;
        }
        return s;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 557. Reverse Words in a String III, C++ ...\n\n";
    Solution sol;

    string s = "   Let's take LeetCode contest";

    string r = sol.reverseWords(s);
    cout << r << '\n';

    return 0;
}
