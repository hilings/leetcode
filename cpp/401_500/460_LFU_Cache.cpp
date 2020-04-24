//
//  460_LFU_Cache.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/27/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
    int cap;    // capacity
    int lfu;   // least used frequency
    unordered_map<int,int> kv;   // key => value
    unordered_map<int,int> kf;   // key => frequency
    unordered_map<int,list<int>> fk; // frequency => keys
    unordered_map<int,list<int>::iterator> ki;   // key => iterator
public:
    LFUCache(int capacity) {
        cap = capacity;
        lfu = 0;
    }

    int get(int key) {
        if (kv.find(key) == kv.end()) {
            printf("get %d => %d\n", key, -1);
            return -1;
        }

        fk[kf[key]].erase(ki[key]);
        kf[key]++;
        fk[kf[key]].push_back(key);
        ki[key] = --fk[kf[key]].end();
        if (fk[lfu].empty()) {
            lfu++;
        }
        printf("get %d => %d\n", key, kv[key]);
        return kv[key];
    }

    void put(int key, int value) {
        printf("put %d => %d\n", key, value);
        if (cap <= 0) { // empty capacity
            return ;
        }
        int v = get(key); // checking existence counts as "use"
        if (v != -1) {
            kv[key] = value;
            return;
        }
        if (kv.size() == cap) {
            int k = fk[lfu].front();    // key to be evicted
            fk[lfu].pop_front();
            ki.erase(k);
            kv.erase(k);
            kf.erase(k);
        }
        kv[key] = value;
        kf[key] = 1;
        fk[1].push_back(key);
        ki[key] = --fk[1].end();
        lfu = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 460. LFU Cache, C++ ...\n\n";

    LFUCache cache = LFUCache(2);
    /*
    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // returns 1
    cache.put(3, 3);    // evicts key 2
    cache.get(2);       // returns -1 (not found)
    cache.get(3);       // returns 3.
    cache.put(4, 4);    // evicts key 1.
    cache.get(1);       // returns -1 (not found)
    cache.get(3);       // returns 3
    cache.get(4);       // returns 4
     */

    /*
    cache.put(2, 1);
    cache.put(2, 2);
    cache.get(2);       // returns 2
    cache.put(1, 1);
    cache.put(4, 1);    // eviects key 2
    cache.get(2);       // returns 2
     */

    cache.put(2, 1);
    cache.put(1, 1);
    cache.put(2, 3);
    cache.put(4, 1);    // eviects key -1
    cache.get(1);       // returns -1
    cache.get(2);       // returns 3

    return 0;
}
