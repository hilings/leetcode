//
//  139.cpp
//  leetcode
//
//  Created by Hang Zhang on 2/25/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int maxL = 0;
        for (string word: wordDict) {
            maxL = max(maxL, (int)word.size());
        }
        vector<bool> ret (s.size(), false);
        for (int i = 0; i < s.size(); i++) {
            for (int k = max(0, i-maxL); k <= i; k++) {
                if (wordDict.find(s.substr(k, i+1-k)) != wordDict.end() && (k-1<0 || ret[k-1]) ) {
                    ret[i] = true;
                    break;
                }
            }
        }
        return ret.back();
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 139. Word Break, C++ ...\n\n";
    Solution sol;

    string s = "leetcode";
    //unordered_set<string> wordDict {"leet", "code"};

    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    unordered_set<string> wordDict {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};



    bool r = sol.wordBreak(s, wordDict);
    cout << (r ? "true" : "false") << '\n';

    return 0;
}