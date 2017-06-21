//
//  392_is_subsequence.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/15/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<int> cache;
public:
    bool isSubsequence0(string s, string t) {
        for (int i = 0, j = 0; i < s.size(); i++, j++) {
            while (j < t.size() && t[j] != s[i]) {
                j++;
            }
            if (j == t.size()) {
                return false;
            }
        }
        return true;
    }

    bool isSubsequence(string s, string t) {
        if (cache.empty()) {
            cache.insert(cache.end(), 26, 0);
            for (char c: t) {
                cache[c-'a']++;
            }
        }
        vector<int> mycache (cache);
        for (int i = 0, j = 0; i < s.size(); i++, j++) {
            if (mycache[s[i]-'a'] == 0) {
                return false;
            }
            while (j < t.size() && t[j] != s[i]) {
                j++;
            }
            if (j == t.size()) {
                return false;
            }
            mycache[s[i]-'a']--;
        }
        return true;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 392. Is Subsequence, C++ ...\n\n";
    Solution sol;
    
    string s = "abc";
    string t = "ahbgcd";
    bool r = sol.isSubsequence0(s, t);
    cout << (r ? "true" : "false") << '\n';
    
    s = "abd";
    r = sol.isSubsequence(s, t);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}
