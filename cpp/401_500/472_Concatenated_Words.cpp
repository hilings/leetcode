//
//  472_Concatenated_Words.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/2/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    bool hasString(unordered_set<string>& us, string s) {
        for (int i = 1; i < s.size(); i++) {
            string s1 = s.substr(0, i), s2 = s.substr(i);
            if (us.find(s1) != us.end() && (us.find(s2) != us.end() || hasString(us, s2))) {
                return true;
            }
        }
        return false;
    }
    bool hasString2(unordered_set<string>& us, string s) {
        for (int i = 1; i < s.size(); i++) {
            string s1 = s.substr(0, i), s2 = s.substr(i);
            if (us.find(s1) != us.end() && (us.find(s2) != us.end() || hasString(us, s2))) {
                us.insert(s2);
                return true;
            }
        }
        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> us (words.begin(), words.end());
        vector<string> r;
        for (string s: words) {
            if (hasString(us, s)) {
                r.push_back(s);
            }
        }
        return r;
    }

    vector<string> findAllConcatenatedWordsInADict2(vector<string>& words) {
        auto cmp = [] (const string& s1, const string& s2) {
            return s1.size() < s2.size();
        };
        sort(words.begin(), words.end(), cmp);
        unordered_set<string> us;
        vector<string> r;
        for (int i = 0; i < words.size(); i++) {
            if (hasString2(us, words[i])) {
                r.push_back(words[i]);
            }
            us.insert(words[i]);
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 472. Concatenated Words, C++ ...\n\n";
    Solution sol;

    vector<string> words {
        "cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"
    };

    vector<string> r = sol.findAllConcatenatedWordsInADict(words);
    for (string s: r) {
        cout << s << '\n';
    }

    vector<string> r2 = sol.findAllConcatenatedWordsInADict2(words);
    for (string s: r2) {
        cout << s << '\n';
    }

    return 0;
}
