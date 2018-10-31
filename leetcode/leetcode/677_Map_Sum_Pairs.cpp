//
//  677_Map_Sum_Pairs.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/30/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TrieNode {
    char c;
    int count;
    vector<TrieNode*> children;
    TrieNode(char x) : c(x), count(0), children (vector<TrieNode*> (26, NULL)) {};
};

class MapSum {
    unordered_map<string,int> um;
    bool isSubstr(string s, string sub) {
        for (int i = 0; i < sub.size(); i++) {
            if (sub[i] != s[i]) {
                return false;
            }
        }
        return true;
    }
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode(' ');
    }

    void insert(string key, int val) {
        um[key] = um.find(key) != um.end() ? um[key] : 0;
        TrieNode* cur = root;
        for (char c: key) {
            if (!cur->children[c-'a']) {
                cur->children[c-'a'] = new TrieNode(c);
            }
            cur->children[c-'a']->count += val - um[key];
            cur = cur->children[c-'a'];
        }
        um[key] = val;
    }

    int sum(string prefix) {
        int r = 0;
        for (auto p: um) {
            if (isSubstr(p.first, prefix)) {
                r += p.second;
            }
        }
        TrieNode* cur = root;
        for (char c: prefix) {
            if (cur->children[c-'a']) {
                cur = cur->children[c-'a'];
            } else {
                return 0;
            }
        }
        return cur->count;
        return r;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 677. Map Sum Pairs, C++ ...\n\n";
    MapSum ms;

    ms.insert("apple", 3);

    int r = ms.sum("ap");
    cout << r << '\n';

    ms.insert("app", 2);

    r = ms.sum("ap");
    cout << r << '\n';

    return 0;
}
