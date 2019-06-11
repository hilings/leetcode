//
//  706_Design_HashMap.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/2/19.
//  Copyright © 2019 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class MyHashMap {
    vector<vector<int>> v;
    int size, lot, index;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        size = 1399;
        v = vector<vector<int>> (size, vector<int>{});
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        get(key);
        if (index == -1) {
            v[lot].push_back(key);
            v[lot].push_back(value);
        } else {
            v[lot][index+1] = value;
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        lot = key % size;
        index = -1;
        for (int i = 0; i < v[lot].size(); i += 2) {
            if (v[lot][i] == key) {
                index = i;
                return v[lot][i+1];
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        get(key);
        if (index != -1) {
            swap(v[lot][index], v[lot][v[lot].size()-2]);
            swap(v[lot][index+1], v[lot][v[lot].size()-1]);
            v[lot].pop_back();
            v[lot].pop_back();
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 706. Design HashMap, C++ ...\n\n";

    MyHashMap hashMap = MyHashMap();
    hashMap.put(1, 1);
    hashMap.put(2, 2);
    cout << hashMap.get(1) << '\n';            // returns 1
    cout << hashMap.get(3) << '\n';            // returns -1 (not found)
    hashMap.put(2, 1);          // update the existing value
    cout << hashMap.get(2) << '\n';            // returns 1
    hashMap.remove(2);          // remove the mapping for 2
    cout << hashMap.get(2) << '\n';            // returns -1 (not found)

    return 0;
}

