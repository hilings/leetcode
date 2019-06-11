//
//  705_Design_HashSet.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/26/19.
//  Copyright © 2019 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class MyHashSet {
    vector<vector<int>> v;
    int size, lot, index;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        size = 1399;
        v = vector<vector<int>> (size, vector<int>{});
    }

    void add(int key) {
        if (!contains(key)) {
            v[lot].push_back(key);
        }
    }

    void remove(int key) {
        if (contains(key)) {
            v[lot][index] = v[lot].back();
            v[lot].pop_back();
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        lot = key % size;
        index = -1;
        for (int i = 0; i < v[lot].size(); i++) {
            if (v[lot][i] == key) {
                index = i;
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 705. Design HashSet, C++ ...\n\n";

    MyHashSet* obj = new MyHashSet();
    int key = 133;

    obj->add(key);
    bool param_3 = obj->contains(key);
    cout << (param_3 ? "true" : "false") << '\n';

    obj->remove(key);
    param_3 = obj->contains(key);
    cout << (param_3 ? "true" : "false") << '\n';

    return 0;
}
