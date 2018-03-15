//
//  432_all_o_one_data_structure.cpp
//  leetcode
//
//  Created by Hang Zhang on 7/14/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>
using namespace std;

class AllOne {
    list<pair<int,unordered_set<string>>> lset;
    unordered_map<string, list<pair<int,unordered_set<string>>>::iterator> indices;
public:
    /** Initialize your data structure here. */
    AllOne() {

    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        //printf("\nincrementing %s\n", key.c_str());
        if (indices.find(key) == indices.end()) {	// insert "0" set in front
            indices[key] = lset.insert(lset.begin(), pair<int,unordered_set<string>> (0, unordered_set<string> {key}));
        }

        auto cur = indices[key], it = next(cur);
        int count = cur->first + 1;		// updated count
        if (it == lset.end() || count < it->first) {	// insert new set
            it = lset.insert(it, pair<int,unordered_set<string>> (count, unordered_set<string> {key}));
        } else {	// add to existing set
            it->second.insert(key);
        }
        indices[key] = it;	// update lookup index

        cur->second.erase(key);	// cleanup previous value and set
        if (cur->second.empty()) {
            lset.erase(cur);
        }
        //debug();
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        //printf("\ndecrementing %s\n", key.c_str());
        if (indices.find(key) == indices.end()) {	// not exist
            return;
        }

        auto cur = indices[key], it = prev(cur);
        indices.erase(key);
        int count = cur->first - 1;		// updated count
        if (count >= 1) {
            if (cur == lset.begin() || it->first < count) {
                it = lset.insert(cur, pair<int,unordered_set<string>> (count, unordered_set<string> {key}));
            } else {
                it->second.insert(key);
            }
            indices[key] = it;		// update lookup index
        }

        cur->second.erase(key);	// cleanup previous value and set
        if (cur->second.empty()) {
            lset.erase(cur);
        }
        //debug();
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return lset.empty() ? "" : *(lset.back().second.begin());
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return lset.empty() ? "" : *(lset.front().second.begin());
    }

    void debug() {
        printf("lset: \n");
        for (pair<int,unordered_set<string>> p: lset) {
            cout << p.first << ": {";
            for (string s: p.second) {
                cout << ' ' << s;
            }
            cout << " }\n";
        }

        printf("indices: \n");
        for (auto p: indices) {
            cout << p.first << ": ";
            cout << p.second->first << " {";
            for (string s: p.second->second) {
                cout << ' ' << s;
            }
            cout << " }\n";
        }
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */


int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 432. All O`one Data Structure, C++ ...\n\n";
    
    AllOne ao;
    ao.inc("a");
    ao.inc("a");
    ao.inc("b");
    ao.inc("b");
    
    ao.dec("b");
    ao.dec("b");
    
    ao.dec("a");
    ao.dec("a");
    
    printf("Max = %s\n", ao.getMaxKey().c_str());
    printf("Min = %s\n", ao.getMinKey().c_str());

    return 0;
}
