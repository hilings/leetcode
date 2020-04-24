//
//  142.cpp
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

    ListNode *detectCycle(ListNode *head) {
        if (!head)
            return NULL;
        ListNode *p = head, *q = head;
        do {
            p = p->next;
            q = q->next;
            if (q)
                q = q->next;
        } while (q && q != p);
        if (!q)
            return q;
        p = head;
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 142. Linked List Cycle II, C++ ...\n\n";
    Solution sol;

    vector<int> nodes {1,2};
    ListNode *head = sol.buildL(nodes);
    head->next->next = head;
    
    //sol.printL(head);
    
    ListNode* r = sol.detectCycle(head);
    if (r)
        cout << r->val << '\n';
    else
        cout << "(null)\n";
    
    return 0;
}