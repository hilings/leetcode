//
//  025.cpp
//  leetcode
//
//  Created by Hang Zhang on 4/30/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *l) {
    while (l) {
        cout << l->val << " -> ";
        l = l->next;
    }
    cout << "(null)\n";
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        printList(head);
        if (k == 1)
            return head;

        ListNode *first = new ListNode(0);
        first->next = head;

        ListNode *p0 = first;
        ListNode *p1 = head;

        while (1) {
            ListNode *q = p1;
            for (int i = 1; i < k && q; i++)
                q = q->next;

            if (!q)
                break;  // less than k item

            ListNode *h = p1;
            ListNode *p2 = p1->next;
            while (p2 != q) {
                ListNode *t = p2->next;
                p2->next = p1;
                p1 = p2;
                p2 = t;
            }
            h->next = q->next;
            q->next = p1;
            p0->next = q;

            p0 = h;
            p1 = h->next;
            h = p1;
            q = p1;
        }

        printList(first->next);
        return first->next;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 025 Reverse Nodes in k-Group, C++ ...\n\n";
    
    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(2);
    ListNode *a3 = new ListNode(3);
    ListNode *a4 = new ListNode(4);
    ListNode *a5 = new ListNode(5);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;

    int k = 2;

    Solution sol;
    sol.reverseKGroup(a1, k);

    return 0;
}
