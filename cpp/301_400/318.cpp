//
//  318.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/6/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = (int)words.size();
        vector<int> vc (n, 0);
        for (int i = 0; i < n; i++) {
            //cout << words[i] << ": ";
            for (char c: words[i]) {
                vc[i] |= 1 << (c-'a');
            }
            //cout << vc[i] << '\n';
        }
        int ret = 0;
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if ((vc[i] & vc[j]) == 0)
                    ret = max(ret, (int)words[i].size() * (int)words[j].size());
            }
        }
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 318. Maximum Product of Word Lengths, C++ ...\n\n";
    Solution sol;

    vector<string> words = {
        //"abcw", "baz", "foo", "bar", "xtfn", "abcdef"   // 16
        "a", "ab", "abc", "d", "cd", "bcd", "abcd"  // 4
        //"a", "aa", "aaa", "aaaa"    // 0
    };
    int r = sol.maxProduct(words);
    cout << r << '\n';

    return 0;
}