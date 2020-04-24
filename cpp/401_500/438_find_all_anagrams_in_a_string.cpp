//
//  438_find_all_anagrams_in_a_string.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/14/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> um;
        for (char c: p) {
            if (um.find(c) == um.end()) {
                um[c] = 0;
            }
            um[c]++;
        }
        vector<int> v;
        for (int i = 0, j = 0; i < s.size() && j < s.size();) {
            char c = s[j];
            //printf("i=%d, j=%d, c=%c\n", i, j, c);
            if (um.find(c) == um.end()) {   // invalid letter
                while (i < j) {
                    um[s[i++]]++;
                }
                i++;
                j++;
            } else if (um[c] > 0) { // there is quota, continue to parse
                um[c]--;
                if (j+1-i == p.size()) {
                    v.push_back(i);
                    um[s[i++]]++;
                }
                j++;
            } else {    // no quota for the letter, need to free previous one
                um[s[i++]]++;
            }
        }
        return v;
    }

    vector<int> findAnagrams2(string s, string p) { // apply quota to smartly handle invalid letter
        vector<int> um (26, 0);
        for (char c: p) {
            um[c-'a']++;
        }
        vector<int> r;
        for (int i = 0, j = 0, quota = (int)p.size(); j < s.size(); j++) {
            if (um[s[j]-'a']-- >= 1) {
                quota--;
            }
            if (quota == 0) {
                r.push_back(i);
            }
            if (j+1-i == p.size()) {
                if (um[s[i++]-'a']++ >= 0) {
                    quota++;
                }
            }
        }
        return r;
    }

    vector<int> findAnagrams3(string s, string p) { // compare two vectors
        vector<int> r, mp (26, 0), ms (26, 0);
        for (char c: p) {
            mp[c-'a']++;
        }
        for (int i = 0; i < p.size()-1; i++) {
            ms[s[i]-'a']++;
        }
        for (int i = 0, j = (int)p.size()-1; j < s.size(); j++) {
            ms[s[j]-'a']++;
            if (ms == mp) {
                r.push_back(i);
            }
            ms[s[i++]-'a']--;
        }
        return r;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 438. Find All Anagrams in a String, C++ ...\n\n";
    Solution sol;

    string s = "cbaebabacd";
    string p = "abc";   // 0, 6
    //s = "abab";
    //p = "ab";   // 0, 1, 2
    vector<int> r = sol.findAnagrams(s, p);
    for (auto a: r) {
        cout << a << ' ';
    }
    cout << '\n';

    vector<int> r2 = sol.findAnagrams2(s, p);
    for (auto a: r2) {
        cout << a << ' ';
    }
    cout << '\n';

    vector<int> r3 = sol.findAnagrams3(s, p);
    for (auto a: r3) {
        cout << a << ' ';
    }

    return 0;
}
