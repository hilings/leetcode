//
//  148.cpp
//  leetcode
//
//  Created by Hang Zhang on 2/29/16.
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
        if (nodes.empty())
            return NULL;
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *p = head, *q = head;
        while (q->next && q->next->next) {
            p = p->next;
            q = q->next->next;
        }
        q = sortList(p->next);
        p->next = NULL;
        p = sortList(head);
        return merge(p, q);
    }
    ListNode* merge(ListNode* h1, ListNode* h2) {
        ListNode *head = new ListNode(0), *p = head;
        while (h1 && h2) {
            if (h1->val < h2->val) {
                p->next = h1;
                h1 = h1->next;
            } else {
                p->next = h2;
                h2 = h2->next;
            }
            p = p->next;
        }
        p->next = h1 ? h1 : h2;
        return head->next;
    }
    
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 148. Sort List, C++ ...\n\n";
    Solution sol;
    
    vector<int> nodes {3,2,4};
    ListNode *head = sol.buildL(nodes);
    sol.printL(head);
    
    ListNode * r = sol.sortList(head);
    sol.printL(r);
    
    return 0;
}