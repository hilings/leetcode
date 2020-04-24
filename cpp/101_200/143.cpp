//
//  143.cpp
//  leetcode
//
//  Created by Hang Zhang on 2/27/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *buildL(vector<int>& nodes) {
        vector<ListNode*> v;
        for (auto a: nodes) {
            v.push_back(new ListNode(a));
        }
        for (size_t i = 0; i < v.size()-1; i++) {
            v[i]->next = v[i+1];
        }
        return v.front();
    }
    void printL(ListNode* head) {
        while (head) {
            cout << head->val << " -> ";
            head = head->next;
        }
        cout << "(null)\n";
    }
    void reorderList(ListNode* head) {
        if (!head)
            return;
        ListNode *p = head, *q = head;
        // find mid node
        while (q->next && q->next->next) {
            p = p->next;
            q = q->next->next;
        }
        q = p->next;
        p->next = NULL;

        //reverse second half nodes
        p = NULL;
        while (q) {
            ListNode *t = q->next;
            q->next = p;
            p = q;
            q = t;
        }
        q = p;
        p = head;

        //join the two half lists starting with p and q
        while (p && q) {
            ListNode *t = q->next;
            q->next = p->next;
            p->next = q;
            p = q->next;
            q = t;
        }
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 143. Reorder List, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {1,2,3,4,5};
    ListNode *head = sol.buildL(nodes);

    sol.printL(head);

    sol.reorderList(head);
    sol.printL(head);

    return 0;
}