//
//  146.cpp
//  leetcode
//
//  Created by Hang Zhang on 2/29/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct MyListNode {
    int key, val;
    MyListNode *next, *prev;
    MyListNode(int x, int y) : key(x), val(y), next(NULL), prev(NULL) {}
};

class LRUCache{
    int cap;
    MyListNode *head, *tail;
    unordered_map<int,MyListNode*> um;
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new MyListNode(-1, -1);
        tail = new MyListNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        cout << "getting key " << key << '\n';
        if (um.find(key) == um.end())
            return -1;
        MyListNode *cur = um[key];
        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;

        cur->next = head->next;
        head->next->prev = cur;
        head->next = cur;
        cur->prev = head;
        //printL(head);
        return cur->val;
    }

    void set(int key, int value) {
        cout << "setting " << key << ": " << value << "\n";
        MyListNode *cur = NULL;
        if (um.find(key) != um.end()) {	//found
            cur = um[key];
            //cout << "refreshing " << key << '\n';
        } else if (um.size() == cap) {	//invalidate oldest
            cur = tail->prev;
            um.erase(cur->key);
            //cout << "erasing " << cur->key << '\n';
        }
        if (cur) {
            cur->next->prev = cur->prev;
            cur->prev->next = cur->next;
        }

        cur = new MyListNode(key, value);

        cur->next = head->next;
        head->next->prev = cur;
        head->next = cur;
        cur->prev = head;

        um[key] = cur;

        //printL(head);
    }

    void printL(MyListNode* head) {
        MyListNode *p = head;
        while (p) {
            cout << p->val << ' ';
            p = p->next;
        }
        cout << '\n';
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 146. LRU Cache, C++ ...\n\n";
    LRUCache lru(5);
    
    lru.set(1, 1);
    lru.set(2, 2);
    lru.set(3, 3);
    lru.set(4, 4);
    lru.get(1);
    lru.set(5, 5);
    lru.set(6, 6);
    
    lru.get(1);
    
    return 0;
}