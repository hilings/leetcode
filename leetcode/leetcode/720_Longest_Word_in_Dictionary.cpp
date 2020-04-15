//
//  720_Longest_Word_in_Dictionary.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/15/20.
//  Copyright © 2020 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestWord(vector<string> &words) {
        unordered_set<string> dict(words.begin(), words.end());
        string r = "";
        for (string word : words) {
            if (word.size() < r.size()) {
                continue;
            }

            bool verified = true;
            for (int l = 1; l <= word.size() && verified; l++) {
                string sub = word.substr(0, l);
                if (dict.find(sub) == dict.end()) {
                    verified = false;
                }
            }

            if (verified) {
                if (word.size() > r.size() ||
                    (word.size() == r.size() && word.compare(r) < 0)) {
                    r = word;
                }
            }
        }
        return r;
    }

    string longestWord2(vector<string> &words) {
        unordered_set<string> dict(words.begin(), words.end()), verified;
        string r = "";
        for (string word : words) {
            if (word.size() < r.size()) {
                continue;
            }
            if (verify(dict, verified, word) && (word.size() > r.size() || (word.size() == r.size() && word.compare(r) < 0))) {
                r = word;
            }
        }
        return r;
    }

    bool verify(unordered_set<string> &dict, unordered_set<string> &verified, string word) {
        if (verified.find(word) != verified.end()) {
            return true;
        }
        if (word.size() == 1) {
            if (dict.find(word) != dict.end()) {
                verified.insert(word);
            }
        } else if (word.size() > 1 && verify(dict, verified, word.substr(0, word.size() - 1)) && dict.find(word) != dict.end()) {
            verified.insert(word);
        }
        return verified.find(word) != verified.end();
    }

    string longestWord3(vector<string> &words) {
        auto cmp = [] (const string& a, const string& b) {
            return a.size() < b.size() || (a.size() == b.size() && a > b);
        };
        sort(words.begin(), words.end(), cmp);

        unordered_set<string> verified {""};
        string r = "";

        for (string& word: words) {
            if (verified.find(word.substr(0, word.size()-1)) != verified.end()) {
                verified.insert(word);
                r = word;
            }
        }

        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 720. Longest Word in Dictionary, C++ ...\n\n";
    Solution sol;
    vector<string> words{
        //   "w", "wo", "wor", "worl", "world"
        "a",  "banana", "app",  "appl", "ap", "apply",  "apple"
    };
    string r = sol.longestWord(words);
    cout << r << '\n';

    r = sol.longestWord2(words);
    cout << r << '\n';

    r = sol.longestWord3(words);
    cout << r << '\n';

    return 0;
}


