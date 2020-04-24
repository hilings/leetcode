//
//  242.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/21/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count (26,0);
        for (char c: s) {
            count[c-'a']++;
        }
        for (char c: t) {
            count[c-'a']--;
        }
        for (int a: count) {
            if (a != 0)
                return false;
        }
        return true;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 242. Valid Anagram, C++ ...\n\n";
    Solution sol;

    string s = "anagram";
    string t = "nagaram";
    
    bool r = sol.isAnagram(s, t);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}