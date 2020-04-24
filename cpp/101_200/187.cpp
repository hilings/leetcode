//
//  187.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/16/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
using namespace std;

class Solution {
public:
    int ctoi(char c) {
        switch (c) {
            case 'A': return 0;
            case 'T': return 1;
            case 'C': return 2;
            case 'G': return 3;
        }
        return 0;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        if (s.size() < 10)
            return ret;
        int b = 0, mask = (1 << 20) - 1;
        for (int i = 0; i < 9; i++) {
            b = b<<2 | ctoi(s[i]);
            //cout << i << ' ' << b << '\n';
        }
        bitset<1<<20> bs_visited, bs_repeated;
        for (int i = 9; i < s.size(); i++) {
            b = (b << 2 & mask) | ctoi(s[i]);
            //cout << i << ' ' << b << '\n';
            if (bs_repeated[b])
                continue;
            if (bs_visited[b]) {
                ret.push_back(s.substr(i-9, 10));
                bs_repeated[b] = 1;
            } else {
                bs_visited[b] = 1;
            }
        }
        return ret;
    }

    vector<string> findRepeatedDnaSequences1(string s) {
        vector<string> ret;
        if (s.size() < 10)
            return ret;
        int b = 0, mask = (1 << 20) - 1;
        for (int i = 0; i < 9; i++) {
            b = b<<2 | ctoi(s[i]);
            //cout << i << ' ' << b << '\n';
        }
        unordered_set<int> visited, repeated;
        for (int i = 9; i < s.size(); i++) {
            b = (b << 2 & mask) | ctoi(s[i]);
            //cout << i << ' ' << b << '\n';
            if (repeated.find(b) != repeated.end())
                continue;
            if (visited.find(b) != visited.end()) {
                repeated.insert(b);
                ret.push_back(s.substr(i-9, 10));
            } else {
                visited.insert(b);
            }
        }
        return ret;
    }

    vector<string> findRepeatedDnaSequences0(string s) {
        vector<string> ret;
        unordered_map<string,int> us;
        for (int i = 0; i <= (int)s.size()-10; i++) {
            string cur = s.substr(i, 10);
            if (us.find(cur) != us.end()) {
                us[cur]++;
            } else {
                us[cur] = 1;
            }
        }
        for (pair<string,int> p: us) {
            if (p.second >= 2)
                ret.push_back(p.first);
        }
        return ret;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 187. Repeated DNA Sequences, C++ ...\n\n";
    Solution sol;
    
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    
    vector<string> r = sol.findRepeatedDnaSequences(s);
    for (string ts: r) {
        cout << ts << '\n';
    }
    
    return 0;
}