//
//  140.cpp
//  leetcode
//
//  Created by Hang Zhang on 2/27/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        unordered_map<int,vector<string>> um;
        return solve(s, (int)s.size()-1, wordDict, um);
    }
    vector<string> solve(string& s, int end, unordered_set<string>& wordDict, unordered_map<int,vector<string>>& um) {
        if (um.find(end) != um.end())
            return um[end];
        if (end == -1)
            return vector<string> {""};
        vector<string> ret;
        for (string word: wordDict) {
            int start = end+1-(int)word.size();
            if (start < 0)
                continue;
            if (s.substr(start, word.size()) == word) {
                for (string sentence: solve(s, start-1, wordDict, um)) {
                    ret.push_back(sentence + (sentence.empty() ? "" : " ") + word);
                }
            }
        }
        um[end] = ret;
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 140. Word Break II, C++ ...\n\n";
    Solution sol;

    string s = "catsanddog";
    //unordered_set<string> wordDict {"cat", "cats", "and", "sand", "dog"};

    //s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    //unordered_set<string> wordDict {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};

    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    unordered_set<string> wordDict {"aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa","ba"};
    
    
    
    vector<string> r = sol.wordBreak(s, wordDict);
    
    for (string str: r) {
        cout << str << '\n';
    }
    
    return 0;
}