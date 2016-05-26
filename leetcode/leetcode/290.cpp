//
//  290.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/25/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string,char> um_wp;
        unordered_map<char,string> um_pw;
        int index = 0;
        for (size_t i = 0; i < (int)str.size(); i++) {
            size_t tmpos = str.find_first_of(' ', i);
            //cout << tmpos << '\n';
            string word;
            if (tmpos == string::npos) {
                word = str.substr(i);
                i = str.size()-1;
            } else {
                word = str.substr(i, tmpos-i);
                i = tmpos;
            }

            if (um_wp.find(word) == um_wp.end() && um_pw.find(pattern[index]) == um_pw.end()) {
                um_wp[word] = pattern[index];
                um_pw[pattern[index]] = word;
            } else if (um_wp.find(word) == um_wp.end() ^ um_pw.find(pattern[index]) == um_pw.end()) {
                return false;
            }

            index++;
        }
        return index == (int)pattern.size();
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 290. Word Pattern, C++ ...\n\n";
    Solution sol;
    
    string pattern = "abba";
    string str = "dog cat cat dog";
    
    pattern = "jquery";
    str = "jquery";
    
    bool r = sol.wordPattern(pattern, str);
    cout << (r ? "true" : "false") << '\n';
    
    return 0;
}