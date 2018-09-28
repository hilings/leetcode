//
//  430_Flatten_a_Multilevel_Doubly_Linked_List.cpp
//  leetcode
//
//  Created by Hang Zhang on 9/10/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
//#include <deque>
//#include <stack>
//#include <algorithm>
//#include <cmath>
using namespace std;

/*
 // Definition for a Node.
 */

class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node* p = head;
        while (p) {
            if (p->child) {
                Node* q = flatten(p->child);
                while (q->next) {
                    q = q->next;
                }
                if (p->next) {
                    q->next = p->next;
                    p->next->prev = q;
                }
                p->child->prev = p;
                p->next = p->child;
                p->child = NULL;
            }
            p = p->next;
        }
        return head;
    }

    Node* makeList(vector<int> nodes) {
        vector<Node*> v;
        for (int a: nodes) {
            v.push_back(new Node(a, NULL, NULL, NULL));
        }
        for (int i = 0; i < nodes.size(); i++) {
            v[i]->prev = i == 0 ? NULL : v[i-1];
            v[i]->next = i == nodes.size()-1 ? NULL : v[i+1];
        }
        return v[0];
    }

    void printL(Node* head) {
        Node* p = head;
        while (p) {
            cout << p->val << " -> ";
            p = p->next;
        }
        cout << "NULL\n";
    }
};


int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 430. Flatten a Multilevel Doubly Linked List, C++ ...\n\n";
    Solution sol;

    Node* l1 = sol.makeList(vector<int> {1,2,3,4,5,6});
    Node* l2 = sol.makeList(vector<int> {7,8,9,10});
    Node* l3 = sol.makeList(vector<int> {11,12});

    sol.printL(l1);
    sol.printL(l2);
    sol.printL(l3);

    l1->next->next->child = l2;
    l2->next->child = l3;

    sol.flatten(l1);
    sol.printL(l1);

    return 0;
}
