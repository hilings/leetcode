//
//  014.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/20/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if (strs.size() == 0)
            return "";
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            vector<string>::iterator it;
            for (it = strs.begin(); it != strs.end(); it++) {
                if (i >= (*it).size() || (*it)[i] != c)
                    return prefix;
            }
            prefix += c;
        }
        return prefix;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 014 Longest Common Prefix, C++ ... ...\n";
    
    vector<string> strs;
    strs.push_back("aa");
    strs.push_back("a");
    //strs.push_back("abe");
    
    for (vector<string>::iterator it = strs.begin(); it < strs.end(); it++) {
        cout << *it << '\n';
    }
    
    Solution sol;
    cout << sol.longestCommonPrefix(strs) << '\n';
    
    return 0;
}